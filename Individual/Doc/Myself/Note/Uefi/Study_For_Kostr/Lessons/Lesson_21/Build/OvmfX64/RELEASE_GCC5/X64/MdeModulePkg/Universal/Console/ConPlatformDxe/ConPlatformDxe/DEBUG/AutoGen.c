/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.c
  Abstract:       Auto-generated AutoGen.c for building module or library.
**/
#include <Uefi.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiDriverEntryPoint.h>

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEfiCallerIdGuid = {0x51ccf399, 0x4fdf, 0x4e55, {0xa4, 0x5b, 0xe1, 0x23, 0xf8, 0x4d, 0x45, 0x6a}};

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEdkiiDscPlatformGuid = {0x5a9e7754, 0xd81b, 0x49ea, {0x85, 0xad, 0x69, 0xea, 0xa7, 0xb1, 0x53, 0x9b}};

GLOBAL_REMOVE_IF_UNREFERENCED CHAR8 *gEfiCallerBaseName = "ConPlatformDxe";

// Guids
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGlobalVariableGuid = { 0x8BE4DF61, 0x93CA, 0x11D2, { 0xAA, 0x0D, 0x00, 0xE0, 0x98, 0x03, 0x2B, 0x8C }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiStandardErrorDeviceGuid = { 0xD3B36F2D, 0xD551, 0x11D4, { 0x9A, 0x46, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiConsoleOutDeviceGuid = { 0xD3B36F2C, 0xD551, 0x11D4, { 0x9A, 0x46, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiConsoleInDeviceGuid = { 0xD3B36F2B, 0xD551, 0x11D4, { 0x9A, 0x46, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdePkgTokenSpaceGuid = { 0x914AEBE7, 0x4635, 0x459b, { 0xAA, 0x1C, 0x11, 0xE2, 0x19, 0xB0, 0x3A, 0x10 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUefiOvmfPkgTokenSpaceGuid = {0x93bb96af, 0xb9f2, 0x4eb8, {0x94, 0x62, 0xe0, 0xba, 0x74, 0x56, 0x42, 0x36}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiEventReadyToBootGuid = { 0x7CE88FB3, 0x4BD7, 0x4679, { 0x87, 0xA8, 0xA8, 0xD8, 0xDE, 0xE5, 0x0D, 0x2B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiEventAfterReadyToBootGuid = { 0x3a2a00ad, 0x98b9, 0x4cdf, { 0xa4, 0x78, 0x70, 0x27, 0x77, 0xf1, 0xc1, 0x0b }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiEventLegacyBootGuid = { 0x2A571201, 0x4966, 0x47F6, { 0x8B, 0x86, 0xF3, 0x1E, 0x41, 0xF3, 0x2F, 0x10 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiAcpi20TableGuid = { 0x8868E871, 0xE4F1, 0x11D3, { 0xBC, 0x22, 0x00, 0x80, 0xC7, 0x3C, 0x88, 0x81 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiAcpi10TableGuid = { 0xEB9D2D30, 0x2D88, 0x11D3, { 0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHobListGuid = { 0x7739F24C, 0x93D7, 0x11D4, { 0x9A, 0x3A, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEdkiiIfrBitVarstoreGuid = {0x82DDD68B, 0x9163, 0x4187, {0x9B, 0x27, 0x20, 0xA8, 0xFD, 0x60,0xA7, 0x1D}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiStatusCodeSpecificDataGuid = { 0x335984BD, 0xE805, 0x409A, { 0xB8, 0xF8, 0xD2, 0x7E, 0xCE, 0x5F, 0xF7, 0xA6 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiStatusCodeDataTypeDebugGuid = { 0x9A4E9246, 0xD553, 0x11D5, { 0x87, 0xE2, 0x00, 0x06, 0x29, 0x45, 0xC3, 0xB9 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiFileInfoGuid = { 0x09576E92, 0x6D3F, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDxeServicesTableGuid = { 0x05AD34BA, 0x6F02, 0x4214, { 0x95, 0x2E, 0x4D, 0xA0, 0x39, 0x8E, 0x2B, 0xB9 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMemoryTypeInformationGuid = { 0x4C19049F, 0x4137, 0x4DD3, { 0x9C, 0x10, 0x8B, 0x97, 0xA8, 0x3F, 0xFD, 0xFA }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEdkiiStatusCodeDataTypeVariableGuid = { 0xf6ee6dbb, 0xd67f, 0x4ea0, { 0x8b, 0x96, 0x6a, 0x71, 0xb1, 0x9d, 0x84, 0xad }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDiskInfoAhciInterfaceGuid = { 0x9e498932, 0x4abc, 0x45af, { 0xa3, 0x4d, 0x02, 0x47, 0x78, 0x7b, 0xe7, 0xc6 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDiskInfoIdeInterfaceGuid = { 0x5E948FE3, 0x26D3, 0x42B5, { 0xAF, 0x17, 0x61, 0x02, 0x87, 0x18, 0x8D, 0xEC }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDiskInfoScsiInterfaceGuid = { 0x08F74BAA, 0xEA36, 0x41D9, { 0x95, 0x21, 0x21, 0xA7, 0x0F, 0x87, 0x80, 0xBC }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDiskInfoSdMmcInterfaceGuid = { 0x8deec992, 0xd39c, 0x4a5c, { 0xab, 0x6b, 0x98, 0x6e, 0x14, 0x24, 0x2b, 0x9d }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDiskInfoUfsInterfaceGuid = { 0x4b3029cc, 0x6b98, 0x47fb, { 0xbc, 0x96, 0x76, 0xdc, 0xb8, 0x4, 0x41, 0xf0 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdeModulePkgTokenSpaceGuid = { 0xA1AFF049, 0xFDEB, 0x442a, { 0xB3, 0x20, 0x13, 0xAB, 0x4C, 0xB7, 0x2B, 0xBC }};

// Protocols
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDevicePathProtocolGuid = { 0x09576E91, 0x6D3F, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiSimpleTextInProtocolGuid = { 0x387477C1, 0x69C7, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiSimpleTextOutProtocolGuid = { 0x387477C2, 0x69C7, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiPciIoProtocolGuid = { 0x4CF5B200, 0x68B8, 0x4CA5, { 0x9E, 0xEC, 0xB2, 0x3E, 0x3F, 0x50, 0x02, 0x9A }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGraphicsOutputProtocolGuid = { 0x9042A9DE, 0x23DC, 0x4A38, { 0x96, 0xFB, 0x7A, 0xDE, 0xD0, 0x80, 0x51, 0x6A }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiUsbIoProtocolGuid = { 0x2B2F68D6, 0x0CD2, 0x44CF, { 0x8E, 0x8B, 0xBB, 0xA2, 0x0B, 0x1B, 0x5B, 0x75 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPcdProtocolGuid = { 0x11B34006, 0xD85B, 0x4D0A, { 0xA2, 0x90, 0xD5, 0xA5, 0x71, 0x31, 0x0E, 0xF7 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiPcdProtocolGuid = { 0x13a3f0f6, 0x264a, 0x3ef0, { 0xf2, 0xe0, 0xde, 0xc5, 0x12, 0x34, 0x2f, 0x34 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gGetPcdInfoProtocolGuid = { 0x5be40f57, 0xfa68, 0x4610, { 0xbb, 0xbf, 0xe9, 0xc5, 0xfc, 0xda, 0xd3, 0x65 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGetPcdInfoProtocolGuid = { 0xfd0f4478,  0xefd, 0x461d, { 0xba, 0x2d, 0xe5, 0x8c, 0x45, 0xfd, 0x5f, 0x5e } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDevicePathUtilitiesProtocolGuid = { 0x0379BE4E, 0xD706, 0x437D, { 0xB0, 0x37, 0xED, 0xB8, 0x2F, 0xB7, 0x72, 0xA4 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDevicePathToTextProtocolGuid = { 0x8B843E20, 0x8132, 0x4852, { 0x90, 0xCC, 0x55, 0x1A, 0x4E, 0x4A, 0x7F, 0x1C }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDevicePathFromTextProtocolGuid = { 0x05C99A21, 0xC70F, 0x4AD2, { 0x8A, 0x5F, 0x35, 0xDF, 0x33, 0x43, 0xF5, 0x1E }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDriverBindingProtocolGuid = { 0x18A031AB, 0xB443, 0x4D1A, { 0xA5, 0xC0, 0x0C, 0x09, 0x26, 0x1E, 0x9F, 0x71 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHiiFontProtocolGuid = {0xe9ca4775, 0x8657, 0x47fc, {0x97, 0xe7, 0x7e, 0xd6, 0x5a, 0x08, 0x43, 0x24}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiSimpleFileSystemProtocolGuid = { 0x964E5B22, 0x6459, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiUgaDrawProtocolGuid = { 0x982C298B, 0xF4FA, 0x41CB, { 0xB8, 0x38, 0x77, 0xAA, 0x68, 0x8F, 0xB8, 0x39 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiComponentNameProtocolGuid = { 0x107A772C, 0xD5E1, 0x11D4, { 0x9A, 0x46, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiComponentName2ProtocolGuid = { 0x6A7A5CFF, 0xE8D9, 0x4F70, { 0xBA, 0xDA, 0x75, 0xAB, 0x30, 0x25, 0xCE, 0x14 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDriverConfigurationProtocolGuid = { 0x107A772B, 0xD5E1, 0x11D4, { 0x9A, 0x46, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDriverConfiguration2ProtocolGuid = { 0xBFD7DC1D, 0x24F1, 0x40D9, { 0x82, 0xE7, 0x2E, 0x09, 0xBB, 0x6B, 0x4E, 0xBE }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDriverDiagnosticsProtocolGuid = { 0x0784924F, 0xE296, 0x11D4, { 0x9A, 0x49, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDriverDiagnostics2ProtocolGuid = { 0x4D330321, 0x025F, 0x4AAC, { 0x90, 0xD8, 0x5E, 0xD9, 0x00, 0x17, 0x3B, 0x63 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHiiStringProtocolGuid = {0x0fd96974, 0x23aa, 0x4cdc, {0xb9, 0xcb, 0x98, 0xd1, 0x77, 0x50, 0x32, 0x2a}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHiiImageProtocolGuid = {0x31a6406a, 0x6bdf, 0x4e46, {0xb2, 0xa2, 0xeb, 0xaa, 0x89, 0xc4, 0x09, 0x20}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHiiDatabaseProtocolGuid = {0xef9fc172, 0xa1b2, 0x4693, {0xb3, 0x27, 0x6d, 0x32, 0xfc, 0x41, 0x60, 0x42}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHiiConfigRoutingProtocolGuid = {0x587e72d7, 0xcc50, 0x4f79, {0x82, 0x09, 0xca, 0x29, 0x1f, 0xc1, 0xa1, 0x0f}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiUnicodeCollation2ProtocolGuid = {0xa4c751fc, 0x23ae, 0x4c3e, { 0x92, 0xe9, 0x49, 0x64, 0xcf, 0x63, 0xf3, 0x49 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiFormBrowser2ProtocolGuid = {0xb9d4c360, 0xbcfb, 0x4f9b, {0x92, 0x98, 0x53, 0xc1, 0x36, 0x98, 0x22, 0x58}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiStatusCodeRuntimeProtocolGuid = { 0xD2B2B828, 0x0826, 0x48A7, { 0xB3, 0xDF, 0x98, 0x3C, 0x00, 0x60, 0x24, 0xF0 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiFirmwareVolume2ProtocolGuid = { 0x220e73b6, 0x6bdb, 0x4413, { 0x84, 0x5, 0xb9, 0x74, 0xb1, 0x8, 0x61, 0x9a } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiLoadedImageProtocolGuid = { 0x5B1B31A1, 0x9562, 0x11D2, { 0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiLoadFileProtocolGuid = { 0x56EC3091, 0x954C, 0x11D2, { 0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiLoadFile2ProtocolGuid = { 0x4006c0c1, 0xfcb3, 0x403e, {0x99, 0x6d, 0x4a, 0x6c, 0x87, 0x24, 0xe0, 0x6d }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiPciRootBridgeIoProtocolGuid = { 0x2F707EBB, 0x4A1A, 0x11D4, { 0x9A, 0x38, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiSimpleNetworkProtocolGuid = { 0xA19832B9, 0xAC25, 0x11D3, { 0x9A, 0x2D, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiBlockIoProtocolGuid = { 0x964E5B21, 0x6459, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiBootLogoProtocolGuid = { 0xcdea2bd3, 0xfc25, 0x4c1c, { 0xb9, 0x7c, 0xb3, 0x11, 0x86, 0x6, 0x49, 0x90 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiSimpleTextInputExProtocolGuid = {0xdd9e7534, 0x7762, 0x4698, { 0x8c, 0x14, 0xf5, 0x85, 0x17, 0xa6, 0x25, 0xaa } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEdkiiVariablePolicyProtocolGuid = { 0x81D1675C, 0x86F6, 0x48DF, { 0xBD, 0x95, 0x9A, 0x6E, 0x4F, 0x09, 0x25, 0xC3 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiNvmExpressPassThruProtocolGuid = { 0x52c78312, 0x8edc, 0x4233, { 0x98, 0xf2, 0x1a, 0x1a, 0xa5, 0xe3, 0x88, 0xa5 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDiskInfoProtocolGuid = { 0xD432A67F, 0x14DC, 0x484B, { 0xB3, 0xBB, 0x3F, 0x02, 0x91, 0x84, 0x93, 0x27 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDriverHealthProtocolGuid = { 0x2a534210, 0x9280, 0x41d8, {0xae, 0x79, 0xca, 0xda, 0x1, 0xa2, 0xb1, 0x27 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiRamDiskProtocolGuid = { 0xab38a0df, 0x6873, 0x44a9, { 0x87, 0xe6, 0xd4, 0xeb, 0x56, 0x14, 0x84, 0x49 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiDeferredImageLoadProtocolGuid = { 0x15853d7c, 0x3ddf, 0x43e0, {0xa1, 0xcb, 0xeb, 0xf8, 0x5b, 0x8f, 0x87, 0x2c }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEdkiiPlatformBootManagerProtocolGuid = { 0xaa17add4, 0x756c, 0x460d, { 0x94, 0xb8, 0x43, 0x88, 0xd7, 0xfb, 0x3e, 0x59 } };

// Definition of SkuId Array
GLOBAL_REMOVE_IF_UNREFERENCED UINT64 _gPcd_SkuId_Array[] = {0x0};

// Definition of PCDs used in libraries

#define _PCD_TOKEN_PcdVerifyNodeInList  0U
#define _PCD_SIZE_PcdVerifyNodeInList 1
#define _PCD_GET_MODE_SIZE_PcdVerifyNodeInList  _PCD_SIZE_PcdVerifyNodeInList 
#define _PCD_VALUE_PcdVerifyNodeInList  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifyNodeInList = _PCD_VALUE_PcdVerifyNodeInList;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifyNodeInList;
#define _PCD_GET_MODE_BOOL_PcdVerifyNodeInList  _gPcd_FixedAtBuild_PcdVerifyNodeInList
//#define _PCD_SET_MODE_BOOL_PcdVerifyNodeInList  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumLinkedListLength  0U
#define _PCD_SIZE_PcdMaximumLinkedListLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumLinkedListLength  _PCD_SIZE_PcdMaximumLinkedListLength 
#define _PCD_VALUE_PcdMaximumLinkedListLength  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumLinkedListLength = _PCD_VALUE_PcdMaximumLinkedListLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength;
#define _PCD_GET_MODE_32_PcdMaximumLinkedListLength  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength
//#define _PCD_SET_MODE_32_PcdMaximumLinkedListLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumAsciiStringLength  0U
#define _PCD_SIZE_PcdMaximumAsciiStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumAsciiStringLength  _PCD_SIZE_PcdMaximumAsciiStringLength 
#define _PCD_VALUE_PcdMaximumAsciiStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength = _PCD_VALUE_PcdMaximumAsciiStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength;
#define _PCD_GET_MODE_32_PcdMaximumAsciiStringLength  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength
//#define _PCD_SET_MODE_32_PcdMaximumAsciiStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumUnicodeStringLength  0U
#define _PCD_SIZE_PcdMaximumUnicodeStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumUnicodeStringLength  _PCD_SIZE_PcdMaximumUnicodeStringLength 
#define _PCD_VALUE_PcdMaximumUnicodeStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength = _PCD_VALUE_PcdMaximumUnicodeStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength;
#define _PCD_GET_MODE_32_PcdMaximumUnicodeStringLength  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength
//#define _PCD_SET_MODE_32_PcdMaximumUnicodeStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdControlFlowEnforcementPropertyMask  0U
#define _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 4
#define _PCD_GET_MODE_SIZE_PcdControlFlowEnforcementPropertyMask  _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 
#define _PCD_VALUE_PcdControlFlowEnforcementPropertyMask  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask = _PCD_VALUE_PcdControlFlowEnforcementPropertyMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask;
#define _PCD_GET_MODE_32_PcdControlFlowEnforcementPropertyMask  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask
//#define _PCD_SET_MODE_32_PcdControlFlowEnforcementPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpeculationBarrierType  0U
#define _PCD_SIZE_PcdSpeculationBarrierType 1
#define _PCD_GET_MODE_SIZE_PcdSpeculationBarrierType  _PCD_SIZE_PcdSpeculationBarrierType 
#define _PCD_VALUE_PcdSpeculationBarrierType  0x01U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdSpeculationBarrierType = _PCD_VALUE_PcdSpeculationBarrierType;
extern const  UINT8  _gPcd_FixedAtBuild_PcdSpeculationBarrierType;
#define _PCD_GET_MODE_8_PcdSpeculationBarrierType  _gPcd_FixedAtBuild_PcdSpeculationBarrierType
//#define _PCD_SET_MODE_8_PcdSpeculationBarrierType  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPrintErrorLevel  0U
#define _PCD_SIZE_PcdDebugPrintErrorLevel 4
#define _PCD_GET_MODE_SIZE_PcdDebugPrintErrorLevel  _PCD_SIZE_PcdDebugPrintErrorLevel 
#define _PCD_VALUE_PcdDebugPrintErrorLevel  0x8000004FU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdDebugPrintErrorLevel = _PCD_VALUE_PcdDebugPrintErrorLevel;
extern const  UINT32  _gPcd_FixedAtBuild_PcdDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdDebugPrintErrorLevel  _gPcd_FixedAtBuild_PcdDebugPrintErrorLevel
//#define _PCD_SET_MODE_32_PcdDebugPrintErrorLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugIoPort  0U
#define _PCD_SIZE_PcdDebugIoPort 2
#define _PCD_GET_MODE_SIZE_PcdDebugIoPort  _PCD_SIZE_PcdDebugIoPort 
#define _PCD_VALUE_PcdDebugIoPort  0x402U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT16 _gPcd_FixedAtBuild_PcdDebugIoPort = _PCD_VALUE_PcdDebugIoPort;
extern const  UINT16  _gPcd_FixedAtBuild_PcdDebugIoPort;
#define _PCD_GET_MODE_16_PcdDebugIoPort  _gPcd_FixedAtBuild_PcdDebugIoPort
//#define _PCD_SET_MODE_16_PcdDebugIoPort  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugClearMemoryValue  0U
#define _PCD_SIZE_PcdDebugClearMemoryValue 1
#define _PCD_GET_MODE_SIZE_PcdDebugClearMemoryValue  _PCD_SIZE_PcdDebugClearMemoryValue 
#define _PCD_VALUE_PcdDebugClearMemoryValue  0xAFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugClearMemoryValue = _PCD_VALUE_PcdDebugClearMemoryValue;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue;
#define _PCD_GET_MODE_8_PcdDebugClearMemoryValue  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue
//#define _PCD_SET_MODE_8_PcdDebugClearMemoryValue  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPropertyMask  0U
#define _PCD_SIZE_PcdDebugPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdDebugPropertyMask  _PCD_SIZE_PcdDebugPropertyMask 
#define _PCD_VALUE_PcdDebugPropertyMask  0x2FU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugPropertyMask = _PCD_VALUE_PcdDebugPropertyMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugPropertyMask;
#define _PCD_GET_MODE_8_PcdDebugPropertyMask  _gPcd_FixedAtBuild_PcdDebugPropertyMask
//#define _PCD_SET_MODE_8_PcdDebugPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFixedDebugPrintErrorLevel  0U
#define _PCD_SIZE_PcdFixedDebugPrintErrorLevel 4
#define _PCD_GET_MODE_SIZE_PcdFixedDebugPrintErrorLevel  _PCD_SIZE_PcdFixedDebugPrintErrorLevel 
#define _PCD_VALUE_PcdFixedDebugPrintErrorLevel  0xFFFFFFFFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel = _PCD_VALUE_PcdFixedDebugPrintErrorLevel;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdFixedDebugPrintErrorLevel  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel
//#define _PCD_SET_MODE_32_PcdFixedDebugPrintErrorLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdOvmfWorkAreaBase  0U
#define _PCD_SIZE_PcdOvmfWorkAreaBase 4
#define _PCD_GET_MODE_SIZE_PcdOvmfWorkAreaBase  _PCD_SIZE_PcdOvmfWorkAreaBase 
#define _PCD_VALUE_PcdOvmfWorkAreaBase  0x0080B000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdOvmfWorkAreaBase = _PCD_VALUE_PcdOvmfWorkAreaBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdOvmfWorkAreaBase;
#define _PCD_GET_MODE_32_PcdOvmfWorkAreaBase  _gPcd_FixedAtBuild_PcdOvmfWorkAreaBase
//#define _PCD_SET_MODE_32_PcdOvmfWorkAreaBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumDevicePathNodeCount  0U
#define _PCD_SIZE_PcdMaximumDevicePathNodeCount 4
#define _PCD_GET_MODE_SIZE_PcdMaximumDevicePathNodeCount  _PCD_SIZE_PcdMaximumDevicePathNodeCount 
#define _PCD_VALUE_PcdMaximumDevicePathNodeCount  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumDevicePathNodeCount = _PCD_VALUE_PcdMaximumDevicePathNodeCount;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumDevicePathNodeCount;
#define _PCD_GET_MODE_32_PcdMaximumDevicePathNodeCount  _gPcd_FixedAtBuild_PcdMaximumDevicePathNodeCount
//#define _PCD_SET_MODE_32_PcdMaximumDevicePathNodeCount  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDriverDiagnosticsDisable  0U
#define _PCD_SIZE_PcdDriverDiagnosticsDisable 1
#define _PCD_GET_MODE_SIZE_PcdDriverDiagnosticsDisable  _PCD_SIZE_PcdDriverDiagnosticsDisable 
#define _PCD_VALUE_PcdDriverDiagnosticsDisable  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdDriverDiagnosticsDisable = _PCD_VALUE_PcdDriverDiagnosticsDisable;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdDriverDiagnosticsDisable;
#define _PCD_GET_MODE_BOOL_PcdDriverDiagnosticsDisable  _gPcd_FixedAtBuild_PcdDriverDiagnosticsDisable
//#define _PCD_SET_MODE_BOOL_PcdDriverDiagnosticsDisable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdComponentNameDisable  0U
#define _PCD_SIZE_PcdComponentNameDisable 1
#define _PCD_GET_MODE_SIZE_PcdComponentNameDisable  _PCD_SIZE_PcdComponentNameDisable 
#define _PCD_VALUE_PcdComponentNameDisable  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdComponentNameDisable = _PCD_VALUE_PcdComponentNameDisable;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdComponentNameDisable;
#define _PCD_GET_MODE_BOOL_PcdComponentNameDisable  _gPcd_FixedAtBuild_PcdComponentNameDisable
//#define _PCD_SET_MODE_BOOL_PcdComponentNameDisable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDriverDiagnostics2Disable  0U
#define _PCD_SIZE_PcdDriverDiagnostics2Disable 1
#define _PCD_GET_MODE_SIZE_PcdDriverDiagnostics2Disable  _PCD_SIZE_PcdDriverDiagnostics2Disable 
#define _PCD_VALUE_PcdDriverDiagnostics2Disable  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdDriverDiagnostics2Disable = _PCD_VALUE_PcdDriverDiagnostics2Disable;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdDriverDiagnostics2Disable;
#define _PCD_GET_MODE_BOOL_PcdDriverDiagnostics2Disable  _gPcd_FixedAtBuild_PcdDriverDiagnostics2Disable
//#define _PCD_SET_MODE_BOOL_PcdDriverDiagnostics2Disable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdComponentName2Disable  0U
#define _PCD_SIZE_PcdComponentName2Disable 1
#define _PCD_GET_MODE_SIZE_PcdComponentName2Disable  _PCD_SIZE_PcdComponentName2Disable 
#define _PCD_VALUE_PcdComponentName2Disable  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdComponentName2Disable = _PCD_VALUE_PcdComponentName2Disable;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdComponentName2Disable;
#define _PCD_GET_MODE_BOOL_PcdComponentName2Disable  _gPcd_FixedAtBuild_PcdComponentName2Disable
//#define _PCD_SET_MODE_BOOL_PcdComponentName2Disable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUgaConsumeSupport  0U
#define _PCD_SIZE_PcdUgaConsumeSupport 1
#define _PCD_GET_MODE_SIZE_PcdUgaConsumeSupport  _PCD_SIZE_PcdUgaConsumeSupport 
#define _PCD_VALUE_PcdUgaConsumeSupport  ((BOOLEAN)1U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdUgaConsumeSupport = _PCD_VALUE_PcdUgaConsumeSupport;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUgaConsumeSupport;
#define _PCD_GET_MODE_BOOL_PcdUgaConsumeSupport  _gPcd_FixedAtBuild_PcdUgaConsumeSupport
//#define _PCD_SET_MODE_BOOL_PcdUgaConsumeSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUefiLibMaxPrintBufferSize  0U
#define _PCD_SIZE_PcdUefiLibMaxPrintBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdUefiLibMaxPrintBufferSize  _PCD_SIZE_PcdUefiLibMaxPrintBufferSize 
#define _PCD_VALUE_PcdUefiLibMaxPrintBufferSize  320U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdUefiLibMaxPrintBufferSize = _PCD_VALUE_PcdUefiLibMaxPrintBufferSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdUefiLibMaxPrintBufferSize;
#define _PCD_GET_MODE_32_PcdUefiLibMaxPrintBufferSize  _gPcd_FixedAtBuild_PcdUefiLibMaxPrintBufferSize
//#define _PCD_SET_MODE_32_PcdUefiLibMaxPrintBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdReportStatusCodePropertyMask  0U
#define _PCD_SIZE_PcdReportStatusCodePropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdReportStatusCodePropertyMask  _PCD_SIZE_PcdReportStatusCodePropertyMask 
#define _PCD_VALUE_PcdReportStatusCodePropertyMask  0x07U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdReportStatusCodePropertyMask = _PCD_VALUE_PcdReportStatusCodePropertyMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdReportStatusCodePropertyMask;
#define _PCD_GET_MODE_8_PcdReportStatusCodePropertyMask  _gPcd_FixedAtBuild_PcdReportStatusCodePropertyMask
//#define _PCD_SET_MODE_8_PcdReportStatusCodePropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPerformanceLibraryPropertyMask  0U
#define _PCD_SIZE_PcdPerformanceLibraryPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdPerformanceLibraryPropertyMask  _PCD_SIZE_PcdPerformanceLibraryPropertyMask 
#define _PCD_VALUE_PcdPerformanceLibraryPropertyMask  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask = _PCD_VALUE_PcdPerformanceLibraryPropertyMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask;
#define _PCD_GET_MODE_8_PcdPerformanceLibraryPropertyMask  _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask
//#define _PCD_SET_MODE_8_PcdPerformanceLibraryPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdResetOnMemoryTypeInformationChange  0U
#define _PCD_SIZE_PcdResetOnMemoryTypeInformationChange 1
#define _PCD_GET_MODE_SIZE_PcdResetOnMemoryTypeInformationChange  _PCD_SIZE_PcdResetOnMemoryTypeInformationChange 
#define _PCD_VALUE_PcdResetOnMemoryTypeInformationChange  0U
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdResetOnMemoryTypeInformationChange = _PCD_VALUE_PcdResetOnMemoryTypeInformationChange;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdResetOnMemoryTypeInformationChange;
#define _PCD_GET_MODE_BOOL_PcdResetOnMemoryTypeInformationChange  _gPcd_FixedAtBuild_PcdResetOnMemoryTypeInformationChange
//#define _PCD_SET_MODE_BOOL_PcdResetOnMemoryTypeInformationChange  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdProgressCodeOsLoaderLoad  0U
#define _PCD_SIZE_PcdProgressCodeOsLoaderLoad 4
#define _PCD_GET_MODE_SIZE_PcdProgressCodeOsLoaderLoad  _PCD_SIZE_PcdProgressCodeOsLoaderLoad 
#define _PCD_VALUE_PcdProgressCodeOsLoaderLoad  0x03058000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdProgressCodeOsLoaderLoad = _PCD_VALUE_PcdProgressCodeOsLoaderLoad;
extern const  UINT32  _gPcd_FixedAtBuild_PcdProgressCodeOsLoaderLoad;
#define _PCD_GET_MODE_32_PcdProgressCodeOsLoaderLoad  _gPcd_FixedAtBuild_PcdProgressCodeOsLoaderLoad
//#define _PCD_SET_MODE_32_PcdProgressCodeOsLoaderLoad  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdProgressCodeOsLoaderStart  0U
#define _PCD_SIZE_PcdProgressCodeOsLoaderStart 4
#define _PCD_GET_MODE_SIZE_PcdProgressCodeOsLoaderStart  _PCD_SIZE_PcdProgressCodeOsLoaderStart 
#define _PCD_VALUE_PcdProgressCodeOsLoaderStart  0x03058001U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdProgressCodeOsLoaderStart = _PCD_VALUE_PcdProgressCodeOsLoaderStart;
extern const  UINT32  _gPcd_FixedAtBuild_PcdProgressCodeOsLoaderStart;
#define _PCD_GET_MODE_32_PcdProgressCodeOsLoaderStart  _gPcd_FixedAtBuild_PcdProgressCodeOsLoaderStart
//#define _PCD_SET_MODE_32_PcdProgressCodeOsLoaderStart  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdErrorCodeSetVariable  0U
#define _PCD_SIZE_PcdErrorCodeSetVariable 4
#define _PCD_GET_MODE_SIZE_PcdErrorCodeSetVariable  _PCD_SIZE_PcdErrorCodeSetVariable 
#define _PCD_VALUE_PcdErrorCodeSetVariable  0x03058002U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdErrorCodeSetVariable = _PCD_VALUE_PcdErrorCodeSetVariable;
extern const  UINT32  _gPcd_FixedAtBuild_PcdErrorCodeSetVariable;
#define _PCD_GET_MODE_32_PcdErrorCodeSetVariable  _gPcd_FixedAtBuild_PcdErrorCodeSetVariable
//#define _PCD_SET_MODE_32_PcdErrorCodeSetVariable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBootManagerMenuFile  0U
#define _PCD_VALUE_PcdBootManagerMenuFile  (VOID *)_gPcd_FixedAtBuild_PcdBootManagerMenuFile
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdBootManagerMenuFile[16] = { 0x21, 0xaa, 0x2c, 0x46, 0x14, 0x76, 0x03, 0x45, 0x83, 0x6e, 0x8a, 0xb6, 0xf4, 0x66, 0x23, 0x31 };
extern const UINT8 _gPcd_FixedAtBuild_PcdBootManagerMenuFile[16];
#define _PCD_GET_MODE_PTR_PcdBootManagerMenuFile  (VOID *)_gPcd_FixedAtBuild_PcdBootManagerMenuFile
#define _PCD_SIZE_PcdBootManagerMenuFile 16
#define _PCD_GET_MODE_SIZE_PcdBootManagerMenuFile  _PCD_SIZE_PcdBootManagerMenuFile 
GLOBAL_REMOVE_IF_UNREFERENCED const UINTN _gPcd_FixedAtBuild_Size_PcdBootManagerMenuFile = 16;
//#define _PCD_SET_MODE_PTR_PcdBootManagerMenuFile  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDriverHealthConfigureForm  0U
#define _PCD_VALUE_PcdDriverHealthConfigureForm  (VOID *)_gPcd_FixedAtBuild_PcdDriverHealthConfigureForm
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDriverHealthConfigureForm[16] = { 0xf4, 0xd9, 0x96, 0x42, 0xfc, 0xf6, 0xde, 0x4d, 0x86, 0x85, 0x8c, 0xe2, 0xd7, 0x9d, 0x90, 0xf0 };
extern const UINT8 _gPcd_FixedAtBuild_PcdDriverHealthConfigureForm[16];
#define _PCD_GET_MODE_PTR_PcdDriverHealthConfigureForm  (VOID *)_gPcd_FixedAtBuild_PcdDriverHealthConfigureForm
#define _PCD_SIZE_PcdDriverHealthConfigureForm 16
#define _PCD_GET_MODE_SIZE_PcdDriverHealthConfigureForm  _PCD_SIZE_PcdDriverHealthConfigureForm 
GLOBAL_REMOVE_IF_UNREFERENCED const UINTN _gPcd_FixedAtBuild_Size_PcdDriverHealthConfigureForm = 16;
//#define _PCD_SET_MODE_PTR_PcdDriverHealthConfigureForm  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaxRepairCount  0U
#define _PCD_SIZE_PcdMaxRepairCount 4
#define _PCD_GET_MODE_SIZE_PcdMaxRepairCount  _PCD_SIZE_PcdMaxRepairCount 
#define _PCD_VALUE_PcdMaxRepairCount  0x00U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaxRepairCount = _PCD_VALUE_PcdMaxRepairCount;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaxRepairCount;
#define _PCD_GET_MODE_32_PcdMaxRepairCount  _gPcd_FixedAtBuild_PcdMaxRepairCount
//#define _PCD_SET_MODE_32_PcdMaxRepairCount  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


RETURN_STATUS
EFIAPI
PlatformDebugLibIoPortConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
DxeCcProbeLibConstructor (
  VOID
  );

EFI_STATUS
EFIAPI
UefiBootServicesTableLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
UefiRuntimeServicesTableLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
DevicePathLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
UefiLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
UefiHiiServicesLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
HobLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );

EFI_STATUS
EFIAPI
DxeServicesTableLibConstructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );


VOID
EFIAPI
ProcessLibraryConstructorList (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;

  Status = PlatformDebugLibIoPortConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = DxeCcProbeLibConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = UefiBootServicesTableLibConstructor (ImageHandle, SystemTable);
  ASSERT_EFI_ERROR (Status);

  Status = UefiRuntimeServicesTableLibConstructor (ImageHandle, SystemTable);
  ASSERT_EFI_ERROR (Status);

  Status = DevicePathLibConstructor (ImageHandle, SystemTable);
  ASSERT_EFI_ERROR (Status);

  Status = UefiLibConstructor (ImageHandle, SystemTable);
  ASSERT_EFI_ERROR (Status);

  Status = UefiHiiServicesLibConstructor (ImageHandle, SystemTable);
  ASSERT_EFI_ERROR (Status);

  Status = HobLibConstructor (ImageHandle, SystemTable);
  ASSERT_EFI_ERROR (Status);

  Status = DxeServicesTableLibConstructor (ImageHandle, SystemTable);
  ASSERT_EFI_ERROR (Status);

}



VOID
EFIAPI
ProcessLibraryDestructorList (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{

}

const UINT32 _gUefiDriverRevision = 0x00000000U;
const UINT32 _gDxeRevision = 0x00000000U;


EFI_STATUS
EFIAPI
ProcessModuleEntryPointList (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )

{
  return InitializeConPlatform (ImageHandle, SystemTable);
}

VOID
EFIAPI
ExitDriver (
  IN EFI_STATUS  Status
  )
{
  if (EFI_ERROR (Status)) {
    ProcessLibraryDestructorList (gImageHandle, gST);
  }
  gBS->Exit (gImageHandle, Status, 0, NULL);
}

GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gDriverUnloadImageCount = 0U;

EFI_STATUS
EFIAPI
ProcessModuleUnloadList (
  IN EFI_HANDLE        ImageHandle
  )
{
  return EFI_SUCCESS;
}
