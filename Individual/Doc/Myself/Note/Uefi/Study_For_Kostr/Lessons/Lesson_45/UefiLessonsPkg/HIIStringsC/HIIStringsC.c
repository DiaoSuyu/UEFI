#include <Uefi.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiHiiServicesLib.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
    CHAR8* Data = (CHAR8*)AllocateZeroPool(200);          // CHEAT! NEEDS CORRECTION FOR YOUR OWN PACKAGES!
    UINT32 offset = 0;
    EFI_HII_PACKAGE_LIST_HEADER* PackageListHdr = (EFI_HII_PACKAGE_LIST_HEADER*)&Data[offset];
    PackageListHdr->PackageListGuid = gHIIStringsCGuid;
    offset += sizeof(EFI_HII_PACKAGE_LIST_HEADER);

    <...>     // Fill String Packages in the memory starting from &Data[offset]
    offset += <...>	// Add packages size to the 'offset' variable

    EFI_HII_PACKAGE_HEADER* HIIEndPackageHdr = (EFI_HII_PACKAGE_HEADER*)&Data[offset];
    HIIEndPackageHdr->Type = EFI_HII_PACKAGE_END;
    HIIEndPackageHdr->Length = sizeof(EFI_HII_PACKAGE_HEADER);
    offset += sizeof(EFI_HII_PACKAGE_HEADER);

    PackageListHdr->PackageLength = offset;

    <...>   // Add new package to the HII Database

    FreePool(Data);

    return EFI_SUCCESS;
}
