#include <Uefi.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PrintLib.h>
#include <Library/ShellLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Protocol/AcpiSystemDescriptionTable.h>
#include <Protocol/PciRootBridgeIo.h>
#include <IndustryStandard/PciExpress60.h>


#define DESCRIPTOR_STR_MAX_SIZE 200

CHAR8 *FileBuffer = NULL;
UINT64 FileSize;
SHELL_FILE_HANDLE FileHandle = NULL;



VOID
ToLowerASCII (
  IN CHAR8*  Str,
  IN UINTN   Size
  )
{
    for (UINT8 i=0; i < Size; i++) {
        if ((Str[i] >= 'A') && (Str[i] <= 'Z')) {
          Str[i] += 32;
        }
    }
}


UINT64
PciConfigurationAddress (
  IN UINT8   Bus,
  IN UINT8   Device,
  IN UINT8   Function,
  IN UINT32  Register
  )
{
    UINT64 Address = (((UINT64)Bus) << 24) + (((UINT64)Device) << 16) + (((UINT64)Function) << 8);
    if (Register & 0xFFFFFF00) {
        Address += (((UINT64)Register) << 32);
    } else {
        Address += (((UINT64)Register) << 0);
    }
    return Address;
}


EFI_STATUS
FindPCIDevDescription (
  IN UINT16    VendorId,
  IN UINT16    DeviceId,
  OUT CHAR16*  VendorDesc,
  OUT CHAR16*  DeviceDesc,
  IN UINTN     DescBufferSize
  )
{
    EFI_STATUS Status;
    BOOLEAN Vendor_found = FALSE;
    BOOLEAN Device_found = FALSE;
    CHAR8 VendorStr[5];
    CHAR8 DeviceStr[5];
    Status = AsciiValueToStringS (
        VendorStr,
        5,
        RADIX_HEX | PREFIX_ZERO,
        VendorId,
        4
    );
    if (EFI_ERROR(Status)) {
        return Status;
    }

    Status = AsciiValueToStringS (
        DeviceStr,
        5,
        RADIX_HEX | PREFIX_ZERO,
        DeviceId,
        4
    );
    if (EFI_ERROR(Status)) {
        return Status;
    }

    ToLowerASCII(VendorStr, 4);
    ToLowerASCII(DeviceStr, 4);

    for (UINTN i = 0; i < FileSize; i++) {
        if (FileBuffer[i] == '\n') {
            if (Vendor_found == FALSE) {
                //  0123456        7
                // \nVVVV  |<desc>|\n
                if (
                    (FileBuffer[i + 1] == VendorStr[0]) &&
                    (FileBuffer[i + 2] == VendorStr[1]) &&
                    (FileBuffer[i + 3] == VendorStr[2]) &&
                    (FileBuffer[i + 4] == VendorStr[3])
                ) {
                      UINTN nextLineIdx = i + 1;
                      while (FileBuffer[nextLineIdx] != '\n' && FileBuffer[nextLineIdx] != '\0') {
                          nextLineIdx++;
                      }
                      // 7 = '\n' + '*' + '*'+ '*'+ '*' + ' ' + ' '
                      UnicodeSPrintAsciiFormat(VendorDesc, (nextLineIdx - i - 6) * sizeof(CHAR16), "%a", &FileBuffer[i + 7]);
                      Vendor_found = TRUE;
                }
            } else {
                //  0 1234567        8
                // \n\tDDDD  |<desc>|\n
                if (
                    (FileBuffer[i + 1] == '\t') &&
                    (FileBuffer[i + 2] == DeviceStr[0]) &&
                    (FileBuffer[i + 3] == DeviceStr[1]) &&
                    (FileBuffer[i + 4] == DeviceStr[2]) &&
                    (FileBuffer[i + 5] == DeviceStr[3])
                ) {
                  UINTN nextLineIdx = i + 1;
                  while (FileBuffer[nextLineIdx] != '\n' && FileBuffer[nextLineIdx] != '\0') {
                      nextLineIdx++;
                  }
                   // 8 = '\n' + '\t' + '*' + '*'+ '*'+ '*' + ' ' + ' '
                  UnicodeSPrintAsciiFormat(DeviceDesc, (nextLineIdx - i - 7) * sizeof(CHAR16), "%a", &FileBuffer[i + 8]);
                  Device_found = TRUE;
                  goto end;
                }
            }
        }
    }

end:
    if (Vendor_found == FALSE) {
      UnicodeSPrint(VendorDesc, DescBufferSize, L"Undefined");
    }
    if (Device_found == FALSE) {
      UnicodeSPrint(DeviceDesc, DescBufferSize, L"Undefined");
    }

    return EFI_SUCCESS;

}


EFI_STATUS
PrintRootBridge (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *PciRootBridgeIo
  )
{
    EFI_ACPI_ADDRESS_SPACE_DESCRIPTOR* AddressDescriptor;
    EFI_STATUS Status;
    UINTN  Index = 0;
    Status = PciRootBridgeIo->Configuration (
        PciRootBridgeIo,
        (VOID**)&AddressDescriptor
    );
    if (EFI_ERROR(Status)) {
        Print(L"Error! Can't get EFI_ACPI_ADDRESS_SPACE_DESCRIPTOR: %r\n", Status);
        return Status;
    }

    while (AddressDescriptor->Desc != ACPI_END_TAG_DESCRIPTOR) {
        if (AddressDescriptor->ResType == ACPI_ADDRESS_SPACE_TYPE_BUS) {

            Print(L"AddressDescriptor                        = 0x%x\n"  , AddressDescriptor                       );
            Print(L"AddressDescriptor->Desc                  = 0x%02x\n", AddressDescriptor->Desc                 );
            Print(L"AddressDescriptor->Len                   = 0x%04x\n", AddressDescriptor->Len                  );
            Print(L"AddressDescriptor->ResType               = 0x%02x\n", AddressDescriptor->ResType              );
            Print(L"AddressDescriptor->GenFlag               = 0x%02x\n", AddressDescriptor->GenFlag              );
            Print(L"AddressDescriptor->SpecificFlag          = 0x%02x\n", AddressDescriptor->SpecificFlag         );
            Print(L"AddressDescriptor->AddrSpaceGranularity  = 0x%016lx\n", AddressDescriptor->AddrSpaceGranularity );
            Print(L"AddressDescriptor->AddrRangeMin          = 0x%016lx\n", AddressDescriptor->AddrRangeMin         );
            Print(L"AddressDescriptor->AddrRangeMax          = 0x%016lx\n", AddressDescriptor->AddrRangeMax         );
            Print(L"AddressDescriptor->AddrTranslationOffset = 0x%016lx\n", AddressDescriptor->AddrTranslationOffset);
            Print(L"AddressDescriptor->AddrLen               = 0x%016lx\n", AddressDescriptor->AddrLen              );


            Print(L"================================================================================\n");
            Print(L"Index  Bus  Dev  Fun\n");
            for (UINT8 Bus = AddressDescriptor->AddrRangeMin; Bus <= AddressDescriptor->AddrRangeMax; Bus++) {
                for (UINT8 Device = 0; Device <= PCI_MAX_DEVICE; Device++) {
                    for (UINT8 Func = 0; Func <= PCI_MAX_FUNC; Func++) {
                        UINT64 Address = PciConfigurationAddress(Bus, Device, Func, 0);
                        PCI_DEVICE_INDEPENDENT_REGION PCIConfHdr;
                        Status = PciRootBridgeIo->Pci.Read (
                            PciRootBridgeIo,
                            EfiPciWidthUint8,
                            Address,
                            sizeof(PCI_DEVICE_INDEPENDENT_REGION),
                            &PCIConfHdr
                        );
                        if (!EFI_ERROR(Status)) {
                            if (PCIConfHdr.VendorId != 0xFFFF) {
                                CHAR16 VendorDesc[DESCRIPTOR_STR_MAX_SIZE];
                                CHAR16 DeviceDesc[DESCRIPTOR_STR_MAX_SIZE];
                                Status = FindPCIDevDescription (
                                    PCIConfHdr.VendorId,
                                    PCIConfHdr.DeviceId,
                                    VendorDesc,
                                    DeviceDesc,
                                    DESCRIPTOR_STR_MAX_SIZE
                                );
                                if (!EFI_ERROR(Status)) {
                                    Print(L"--------------------\n");
                                    Print(L" %04d   %02x   %02x   %02x\n", Index++, Bus, Device, Func);
                                    Print(L"                       1. VendorId: %04x, %s\n", PCIConfHdr.VendorId, VendorDesc);
                                    Print(L"                       2. DeviceId: %04x, %s\n", PCIConfHdr.DeviceId, DeviceDesc);
                                } else {
                                    Print(L"\n");
                                }
                            }
                        } else {
                            Print(L"Error in PCI read: %r\n", Status);
                        }
                    }
                }
            }
            Print(L"================================================================================\n");
        }

        AddressDescriptor++;

    }

    return Status;
}


EFI_STATUS
OpenFile (
  IN CHAR16  *FileName
  )
{
    EFI_STATUS Status;

    // https://pci-ids.ucw.cz/v2.2/pci.ids
    Status = ShellFileExists(FileName);
    if (EFI_ERROR(Status)) {
        Print(L"No file pci.ids: %r\n", Status);
        return Status;
    }

    Status = ShellOpenFileByName (
        FileName,
        &FileHandle,
        EFI_FILE_MODE_READ,
        0
    );
    if (EFI_ERROR(Status)) {
        Print(L"Can't open file pci.ids: %r\n", Status);
        return Status;
    }

    Status = ShellGetFileSize (
        FileHandle,
        &FileSize
    );
    if (EFI_ERROR(Status)) {
        Print(L"Can't get file size for file pci.ids: %r\n", Status);
    }

    gBS->AllocatePool (
      EfiBootServicesData,
      (UINTN)FileSize,
      (VOID **)&FileBuffer
    );

    Status = ShellReadFile(FileHandle, &FileSize, FileBuffer);
    if (EFI_ERROR(Status)) {
        Print(L"Can't read file pci.ids: %r\n", Status);
        return Status;
    }

    return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
    EFI_STATUS             Status;

    Status = OpenFile(L"pci.ids");
    if (EFI_ERROR(Status)) {
      Print(L"Can't open file: %r\n", Status);
      return Status;
    }

    UINTN                  HandleCount;
    EFI_HANDLE             *HandleBuffer;
    Status = gBS->LocateHandleBuffer (
        ByProtocol,
        &gEfiPciRootBridgeIoProtocolGuid,
        NULL,
        &HandleCount,
        &HandleBuffer
    );
    if (EFI_ERROR(Status)) {
      Print(L"Can't locate EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL: %r\n", Status);
      return Status;
    }

    Print(L"Number of PCI root bridges in the system: %d\n", HandleCount);
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL* PciRootBridgeIo;
    for (UINTN Index = 0; Index < HandleCount; Index++) {
        Status = gBS->OpenProtocol (
            HandleBuffer[Index],
            &gEfiPciRootBridgeIoProtocolGuid,
            (VOID **)&PciRootBridgeIo,
            ImageHandle,
            NULL,
            EFI_OPEN_PROTOCOL_GET_PROTOCOL
        );
        if (EFI_ERROR(Status)) {
          Print(L"Can't open protocol: %r\n", Status);
          return Status;
        }

        Print(L"PCI Root Bridge : %d\n", Index);

        Status = PrintRootBridge(PciRootBridgeIo);
        if (EFI_ERROR(Status)) {
          Print(L"Error in PCI Root Bridge printing\n");
        }
    }

    if (HandleBuffer != NULL) {
        FreePool(HandleBuffer);
    }

    if (FileHandle != NULL) {
        ShellCloseFile(&FileHandle);
    }

    return EFI_SUCCESS;
}