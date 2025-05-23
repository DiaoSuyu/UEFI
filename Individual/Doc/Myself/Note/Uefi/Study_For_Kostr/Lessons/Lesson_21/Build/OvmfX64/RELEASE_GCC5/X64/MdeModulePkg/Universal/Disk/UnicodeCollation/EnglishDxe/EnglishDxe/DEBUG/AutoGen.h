/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_CD3BAFB6_50FB_4fe8_8E4E_AB74D2C1A600
#define _AUTOGENH_CD3BAFB6_50FB_4fe8_8E4E_AB74D2C1A600

#ifdef __cplusplus
extern "C" {
#endif

#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xCD3BAFB6, 0x50FB, 0x4fe8, {0x8E, 0x4E, 0xAB, 0x74, 0xD2, 0xC1, 0xA6, 0x00}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x5a9e7754, 0xd81b, 0x49ea, {0x85, 0xad, 0x69, 0xea, 0xa7, 0xb1, 0x53, 0x9b}}
#define STACK_COOKIE_VALUE 0xD1DCA9F5FB959750ULL

// Guids
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gUefiOvmfPkgTokenSpaceGuid;

// Protocols
extern EFI_GUID gEfiUnicodeCollationProtocolGuid;
extern EFI_GUID gEfiUnicodeCollation2ProtocolGuid;
extern EFI_GUID gPcdProtocolGuid;
extern EFI_GUID gEfiPcdProtocolGuid;
extern EFI_GUID gGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdUnicodeCollationSupport  0U
#define _PCD_SIZE_PcdUnicodeCollationSupport 1
#define _PCD_GET_MODE_SIZE_PcdUnicodeCollationSupport  _PCD_SIZE_PcdUnicodeCollationSupport 
#define _PCD_VALUE_PcdUnicodeCollationSupport  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUnicodeCollationSupport;
#define _PCD_GET_MODE_BOOL_PcdUnicodeCollationSupport  _gPcd_FixedAtBuild_PcdUnicodeCollationSupport
//#define _PCD_SET_MODE_BOOL_PcdUnicodeCollationSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUnicodeCollation2Support  0U
#define _PCD_SIZE_PcdUnicodeCollation2Support 1
#define _PCD_GET_MODE_SIZE_PcdUnicodeCollation2Support  _PCD_SIZE_PcdUnicodeCollation2Support 
#define _PCD_VALUE_PcdUnicodeCollation2Support  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUnicodeCollation2Support;
#define _PCD_GET_MODE_BOOL_PcdUnicodeCollation2Support  _gPcd_FixedAtBuild_PcdUnicodeCollation2Support
//#define _PCD_SET_MODE_BOOL_PcdUnicodeCollation2Support  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
InitializeUnicodeCollationEng (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
