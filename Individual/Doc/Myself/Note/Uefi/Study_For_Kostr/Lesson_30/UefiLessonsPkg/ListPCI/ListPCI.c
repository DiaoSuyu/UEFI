#include <Uefi.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/ShellLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Protocol/AcpiSystemDescriptionTable.h>
#include <Protocol/PciRootBridgeIo.h>
#include <IndustryStandard/Bmp.h>
#include <IndustryStandard/PciExpress60.h>



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
PrintRootBridge (
  IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *PciRootBridgeIo
  )
{
    EFI_ACPI_ADDRESS_SPACE_DESCRIPTOR* AddressDescriptor;
    EFI_STATUS Status;
    Status = PciRootBridgeIo->Configuration (
        PciRootBridgeIo,
        (VOID**)&AddressDescriptor
    );
    if (EFI_ERROR(Status)) {
        Print(L"\tError! Can't get EFI_ACPI_ADDRESS_SPACE_DESCRIPTOR: %r\n", Status);
        return Status;
    }

    while (AddressDescriptor->Desc != ACPI_END_TAG_DESCRIPTOR) {
        if (AddressDescriptor->ResType == ACPI_ADDRESS_SPACE_TYPE_BUS) {

            Print(L"\tAddressDescriptor                        = 0x%x\n"  , AddressDescriptor                       );
            Print(L"\tAddressDescriptor->Desc                  = 0x%02x\n", AddressDescriptor->Desc                 );
            Print(L"\tAddressDescriptor->Len                   = 0x%04x\n", AddressDescriptor->Len                  );
            Print(L"\tAddressDescriptor->ResType               = 0x%02x\n", AddressDescriptor->ResType              );
            Print(L"\tAddressDescriptor->GenFlag               = 0x%02x\n", AddressDescriptor->GenFlag              );
            Print(L"\tAddressDescriptor->SpecificFlag          = 0x%02x\n", AddressDescriptor->SpecificFlag         );
            Print(L"\tAddressDescriptor->AddrSpaceGranularity  = 0x%016lx\n", AddressDescriptor->AddrSpaceGranularity );
            Print(L"\tAddressDescriptor->AddrRangeMin          = 0x%016lx\n", AddressDescriptor->AddrRangeMin         );
            Print(L"\tAddressDescriptor->AddrRangeMax          = 0x%016lx\n", AddressDescriptor->AddrRangeMax         );
            Print(L"\tAddressDescriptor->AddrTranslationOffset = 0x%016lx\n", AddressDescriptor->AddrTranslationOffset);
            Print(L"\tAddressDescriptor->AddrLen               = 0x%016lx\n", AddressDescriptor->AddrLen              );

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
                                Print (
                                    L"\tBus: %02x, Dev: %02x, Func: %02x - Vendor:%04x, Device:%04x\n",
                                    Bus, Device, Func, PCIConfHdr.VendorId, PCIConfHdr.DeviceId
                                );
                            }
                        } else {
                            Print(L"\tError in PCI read: %r\n", Status);
                        }
                    }
                }
            }
        }

        AddressDescriptor++;

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
    EFI_STATUS             Status;
    UINTN                  HandleCount;
    EFI_HANDLE             *HandleBuffer;
    Status = gBS->LocateHandleBuffer (
        ByProtocol,
        &gEfiPciRootBridgeIoProtocolGuid,
        NULL,
        &HandleCount,
        &HandleBuffer
    );
    if (EFI_ERROR (Status)) {
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
        Print(L"\nPCI Root Bridge Index: %d\n", Index);

        Status = PrintRootBridge(PciRootBridgeIo);
        if (EFI_ERROR(Status)) {
          Print(L"Error in PCI Root Bridge printing\n");
        }
    }
    FreePool(HandleBuffer);

    return EFI_SUCCESS;
}