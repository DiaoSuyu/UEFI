#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  
  Print(L"SystemTable->NumberOfTableEntries = %d\n", SystemTable->NumberOfTableEntries);
  for (UINTN i = 0; i < SystemTable->NumberOfTableEntries; i++) {
    Print(L"%g, %p\n", SystemTable->ConfigurationTable[i].VendorGuid, \
                       SystemTable->ConfigurationTable[i].VendorTable);
  }
  return EFI_SUCCESS;

/*
    SystemTable->NumberOfTableEntries = 10
    EE4E5898-3914-4259-9D6E-DC7BD79403CF, 74EBE98   // gLzmaCustomDecompressGuid:     MdeModulePkg/Include/Guid/LzmaDecompress.h
    05AD34BA-6F02-4214-952E-4DA0398E2BB9, 7EB75E0   // gEfiDxeServicesTableGuid:      MdePkg/Include/Guid/DxeServices.h (DXE Services Table)
    7739F24C-93D7-11D4-9A3A-0090273FC14D, 74E7018   // gEfiHobListGuid:               MdePkg/Include/Guid/HobList.h
    4C19049F-4137-4DD3-9C10-8B97A83FFDFA, 7EB6F40   // gEfiMemoryTypeInformationGuid: MdeModulePkg/Include/Guid/MemoryTypeInformation.h
    49152E77-1ADA-4764-B7A2-7AFEFED95E8B, 7EB93D0   // gEfiDebugImageInfoTableGuid:   MdePkg/Include/Guid/Debug/ImageInfoTable.h
    060CC026-4C0D-4DDA-8F41-595FEF00A502, 7540018   // gMemoryStatusCodeRecordGuid:   MdeModulePkg/Include/Guid/MemoryStatusCodeRecord.h
    EB9D2D31-2D88-11D3-9A16-0090273FC14D, 753F000   // gEfiSmbiosTableGuid:           MdePkg/Include/Guid/SmBios.h
    EB9D2D30-2D88-11D3-9A16-0090273FC14D, 777E000   // gEfiAcpi10TableGuid:           MdePkg/Include/Guid/Acpi.h
    8868E871-E4F1-11D3-BC22-0080C73C8881, 777E014   // gEfiAcpi20TableGuid:           MdePkg/Include/Guid/Acpi.h
    DCFA911D-26EB-469F-A220-38B7DC461220, 699E018   // gEfiMemoryAttributesTableGuid: MdePkg/Include/Guid/MemoryAttributesTable.h
*/

}