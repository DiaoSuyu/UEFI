#include <Uefi.h>
#include <Library/BaseMemoryLib.h>
#include <Library/ShellLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Protocol/AcpiSystemDescriptionTable.h>
#include <IndustryStandard/Bmp.h>


EFI_STATUS
WriteFile (
  IN CHAR16*  FileName,
  IN VOID*    Data,
  IN UINTN*   Size
  )
{
    SHELL_FILE_HANDLE FileHandle;
    EFI_STATUS Status;
    Status = ShellOpenFileByName (
          FileName,
          &FileHandle,
          EFI_FILE_MODE_CREATE | EFI_FILE_MODE_WRITE | EFI_FILE_MODE_READ,
          0
    );
    if (!EFI_ERROR(Status)) {
        Print(L"Save it to %s\n", FileName);
        UINTN ToWrite = *Size;
        Status = ShellWriteFile (
          FileHandle,
          Size,
          Data
        );
        if (EFI_ERROR(Status)) {
            Print(L"Can't write file: %r\n", Status);
        }
        if (*Size != ToWrite) {
            Print(L"Error! Not all data was written\n");
        }
        Status = ShellCloseFile(&FileHandle);
        if (EFI_ERROR(Status)) {
          Print(L"Can't close file: %r\n", Status);
        }
    } else {
      Print(L"Can't open file: %r\n", Status);
    }
    return Status;
}


EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
    EFI_STATUS Status;
    EFI_ACPI_SDT_PROTOCOL *AcpiSdtProtocol;
    Status = gBS->LocateProtocol (
        &gEfiAcpiSdtProtocolGuid,
        NULL,
        (VOID**)&AcpiSdtProtocol
    );
    if (EFI_ERROR (Status)) {
      return Status;
    }

    BOOLEAN BGRT_found = FALSE;
    UINTN Index = 0;
    EFI_ACPI_SDT_HEADER *Table;
    EFI_ACPI_TABLE_VERSION Version;
    UINTN TableKey;
    while (TRUE) {
        Status = AcpiSdtProtocol->GetAcpiTable (
            Index,
            &Table,
            &Version,
            &TableKey
        );
        if (EFI_ERROR(Status)) {
            break;
        }
        if (
            ((CHAR8)((Table->Signature >>  0) & 0xFF) == 'B') &&
            ((CHAR8)((Table->Signature >>  8) & 0xFF) == 'G') &&
            ((CHAR8)((Table->Signature >> 16) & 0xFF) == 'R') &&
            ((CHAR8)((Table->Signature >> 24) & 0xFF) == 'T')
        ) {
            Print(L"Index = %x\n", Index);
            Print(L"BGRT table is founded: 0x%x, Version: 0x%x, TableKey: 0x%x\n", Table, Version, TableKey);
            BGRT_found = TRUE;
            break;
        }
        Index++;
    }
    if (!BGRT_found) {
        Print(L"BGRT table is not present in the system\n");
        return EFI_UNSUPPORTED;
    }

    EFI_ACPI_6_5_BOOT_GRAPHICS_RESOURCE_TABLE *BGRT = (EFI_ACPI_6_5_BOOT_GRAPHICS_RESOURCE_TABLE*)Table;
    if (BGRT->ImageType == 0) { // 0 = Bitmap
        BMP_IMAGE_HEADER *BMP = (BMP_IMAGE_HEADER*)(BGRT->ImageAddress);
        if ((BMP->CharB != 'B') || (BMP->CharM != 'M')) {
          Print(L"BMP image has wrong signature!\n");
          return EFI_UNSUPPORTED;
        }
        Print(L"BGRT conatins BMP image with %dx%d resolution\n", BMP->PixelWidth, BMP->PixelHeight);
        UINTN Size = BMP->Size;
        Status = WriteFile(L"BGRT.bmp", BMP, &Size);
        if (EFI_ERROR(Status)) {
          Print(L"Error! Can't write BGRT.bmp file\n");
        }
    }

    return EFI_SUCCESS;
}