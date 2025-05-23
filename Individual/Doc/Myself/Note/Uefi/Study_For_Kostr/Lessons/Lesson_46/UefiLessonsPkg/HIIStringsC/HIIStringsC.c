#include <Uefi.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiHiiServicesLib.h>


UINT32 InitStringPackage (
  IN CHAR8*    Ptr,
  IN CHAR8*    Language,
  IN CHAR16**  Strings,
  IN UINTN     StringsLen
  )
{
    UINT32 Size = 0;
    EFI_HII_STRING_PACKAGE_HDR *HIIStringPackageHdr = (EFI_HII_STRING_PACKAGE_HDR*)&Ptr[0];
    HIIStringPackageHdr->Header.Type = EFI_HII_PACKAGE_STRINGS;
    UINT32 HeaderSize = (UINT32)(AsciiStrSize(Language) - 1 + sizeof (EFI_HII_STRING_PACKAGE_HDR));
    HIIStringPackageHdr->HdrSize = HeaderSize;
    HIIStringPackageHdr->StringInfoOffset = HeaderSize;
    HIIStringPackageHdr->LanguageName = 1;                // <--- the String[0] should be a full language name string!
    AsciiStrCpyS (
        HIIStringPackageHdr->Language,
        (HeaderSize - OFFSET_OF(EFI_HII_STRING_PACKAGE_HDR,Language)) / sizeof (CHAR8),
        Language
    );
    Size += HeaderSize;

    for (UINTN i = 0; i < StringsLen; i++) {
      EFI_HII_SIBT_STRING_UCS2_BLOCK *StrBlock = (EFI_HII_SIBT_STRING_UCS2_BLOCK*)&Ptr[Size];
      StrBlock->Header.BlockType = EFI_HII_SIBT_STRING_UCS2;
      StrCpyS (
          StrBlock->StringText,
          StrLen(Strings[i]) + 1,
          Strings[i]
      );
      Size += sizeof(EFI_HII_SIBT_STRING_UCS2_BLOCK) + StrLen(Strings[i]) * 2;
    }

  EFI_HII_SIBT_END_BLOCK* EndBlock = (EFI_HII_SIBT_END_BLOCK*)&Ptr[Size];
  EndBlock->Header.BlockType = EFI_HII_SIBT_END;
  Size += sizeof(EFI_HII_SIBT_END_BLOCK);

  HIIStringPackageHdr->Header.Length = Size;

  return Size;
}


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

    CHAR16* EnStrings[] = {
        L"English",
        L"Hello",
    };
    offset += InitStringPackage(&Data[offset], "en-US", EnStrings, sizeof(EnStrings)/sizeof(EnStrings[0]));

    CHAR16* FrStrings[] = {
      L"French",
      L"Bonjour",
    };
    offset += InitStringPackage(&Data[offset], "fr-FR", FrStrings, sizeof(FrStrings)/sizeof(FrStrings[0]));


    EFI_HII_PACKAGE_HEADER* HIIEndPackageHdr = (EFI_HII_PACKAGE_HEADER*)&Data[offset];
    HIIEndPackageHdr->Type = EFI_HII_PACKAGE_END;
    HIIEndPackageHdr->Length = sizeof(EFI_HII_PACKAGE_HEADER);
    offset += sizeof(EFI_HII_PACKAGE_HEADER);

    PackageListHdr->PackageLength = offset;

    <...>   // Add new package to the HII Database

    FreePool(Data);

    return EFI_SUCCESS;
}
