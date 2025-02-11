#include <Uefi.h>
#include <Library/CommonLib.h>
#include <Library/DevicePathLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PrintLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>


#define DEBUG_ONLY 1


EFI_STATUS
GetNvramVariable (
  IN     CHAR16   *VariableName,
  IN     EFI_GUID *VariableOwnerGuid,
  IN OUT VOID     **Buffer,
  OUT    UINTN    *BufferSize
  )
{
    UINTN Size = 0;
    *BufferSize = 0;

    EFI_STATUS Status = gRT->GetVariable (
        VariableName,
        VariableOwnerGuid,
        NULL,
        &Size,
        NULL
    );
    if (Status != EFI_BUFFER_TOO_SMALL) {
        Print(L"Error! 'gRT->GetVariable' call returned %r\n", Status);
        return Status;
    }

    *Buffer = AllocateZeroPool(Size);
    if (!Buffer) {
        Print(L"Error! 'AllocateZeroPool' call returned %r\n", Status);
        return EFI_OUT_OF_RESOURCES;
    }

    Status = gRT->GetVariable (
        VariableName,
        VariableOwnerGuid,
        NULL,
        &Size,
        *Buffer
    );
    if (Status == EFI_SUCCESS) {
        *BufferSize = Size;
    } else {
        FreePool( *Buffer );
        *Buffer = NULL;
    }

    return Status;
}


VOID
PrintBootOption (
  CHAR16* BootOptionName
  )
{
  UINTN OptionSize;
  UINT8 *Buffer;

    EFI_STATUS Status = GetNvramVariable (
        BootOptionName,
        &gEfiGlobalVariableGuid,
        (VOID**)&Buffer,
        &OptionSize
    );
    if (Status == EFI_SUCCESS) {
        
        #if DEBUG_ONLY
            PrintBytes(OptionSize, Buffer);
        #endif
        
        EFI_LOAD_OPTION *LoadOption = (EFI_LOAD_OPTION*)Buffer;
        CHAR16 *Description = (CHAR16*)(Buffer + sizeof (EFI_LOAD_OPTION));
        UINTN DescriptionSize = StrSize(Description);
        Print(L"%s\n", Description);

        #if DEBUG_ONLY
            PrintBytes(DescriptionSize, (UINT8*)Description);
        #endif

        if (LoadOption->FilePathListLength != 0) {
            VOID* FilePathList = (UINT8 *)Description + DescriptionSize;
            CHAR16* DevPathString = ConvertDevicePathToText(FilePathList, TRUE, FALSE);
            Print(L"%s\n", DevPathString);
            #if DEBUG_ONLY
                PrintBytes(OptionSize - sizeof (EFI_LOAD_OPTION) - DescriptionSize, (UINT8*)FilePathList);
            #endif
        }
    } else {
      Print(L"Can't get %s variable\n", BootOptionName);
    }
}


UINTN
EFIAPI
ShellAppMain (
  IN UINTN   Argc,
  IN CHAR16  **Argv
  )
{
    UINTN OptionSize;
    EFI_STATUS Status;

    UINT16* BootCurrent;
    Status = GetNvramVariable (
        L"BootCurrent",
        &gEfiGlobalVariableGuid,
        (VOID**)&BootCurrent,
        &OptionSize
    );
    if (Status == EFI_SUCCESS) {
        Print(L"BootCurrent = %d, OptionSize = %d\n", *BootCurrent, OptionSize);
    } else {
        Print(L"Can't get BootCurrent variable\n");
    }

    UINT16* BootOrderArray;
    Status = GetNvramVariable (
        L"BootOrder",
        &gEfiGlobalVariableGuid,
        (VOID**)&BootOrderArray,
        &OptionSize
    );
    if (Status == EFI_SUCCESS) {
        #if DEBUG_ONLY
            Print(L"\n");
            Print(L"sizeof(Boot####) = %x\n", sizeof("Boot####"));
            Print(L"\n");
        #endif
        for (UINTN i = 0; i < (OptionSize / sizeof(UINT16)); i++) {
            CHAR16 BootOptionStr[sizeof("Boot####")];
            UnicodeSPrint(BootOptionStr, sizeof("Boot####") * sizeof(CHAR16), L"Boot%04x", BootOrderArray[i]);
            Print(L"%s%s\n", BootOptionStr, (BootOrderArray[i] == *BootCurrent)? L"*" : L"" );
            PrintBootOption(BootOptionStr);
            Print(L"\n");
        }
    } else {
      Print(L"Can't get BootOrder variable\n");
    }

  return EFI_SUCCESS;
}