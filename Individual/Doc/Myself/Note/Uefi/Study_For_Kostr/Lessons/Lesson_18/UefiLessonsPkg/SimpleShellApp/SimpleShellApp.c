#include <Uefi.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>


UINTN
EFIAPI
ShellAppMain (
  IN UINTN   Argc,
  IN CHAR16  **Argv
  )
{
  EFI_GUID VendorGuid;
  UINTN Number = 0;
  UINTN VariableNameSize = sizeof (CHAR16);
  CHAR16* VariableName = AllocateZeroPool(sizeof(CHAR16));
  if (VariableName == NULL) {
      Print(L"Error on AllocateZeroPool call\n");
      return EFI_OUT_OF_RESOURCES;
  }



  while (TRUE) {

    UINTN VariableNameSizeOld = VariableNameSize;
    EFI_STATUS Status = gRT->GetNextVariableName (
        &VariableNameSize,
        VariableName,
        &VendorGuid
    );
    if (Status == EFI_SUCCESS) {
        Print(L"[%03d] %g: %s\n", Number++, VendorGuid, VariableName);
    } else if (Status == EFI_BUFFER_TOO_SMALL) {
        VariableName = ReallocatePool(VariableNameSizeOld, VariableNameSize, VariableName);
        if (VariableName == NULL) {
            Print(L"Error on ReallocatePool call\n");
            return EFI_OUT_OF_RESOURCES;
        }
        Status = gRT->GetNextVariableName (
            &VariableNameSize,
            VariableName,
            &VendorGuid
        );
        if (Status == EFI_SUCCESS) {
            Print(L"[%03d] %g: %s\n", Number++, VendorGuid, VariableName);
        } else {
            Print(L"1. Error on 'gRT->GetNextVariableName' call: %r\n", Status);
            return Status;
        }
    } else if (Status == EFI_NOT_FOUND) {
        FreePool(VariableName);
        return EFI_SUCCESS;
    } else {
        Print(L"2. Error on 'gRT->GetNextVariableName' call: %r\n", Status);
        return Status;
    }
  }

  return EFI_SUCCESS;
}