/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_408edcec_cf6d_477c_a5a8_b4844e3de281
#define _AUTOGENH_408edcec_cf6d_477c_a5a8_b4844e3de281

#ifdef __cplusplus
extern "C" {
#endif

#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x408edcec, 0xcf6d, 0x477c, {0xa5, 0xa8, 0xb4, 0x84, 0x4e, 0x3d, 0xe2, 0x81}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x5a9e7754, 0xd81b, 0x49ea, {0x85, 0xad, 0x69, 0xea, 0xa7, 0xb1, 0x53, 0x9b}}
#define STACK_COOKIE_VALUE 0xA397DDBF2A679DULL

// Guids
extern EFI_GUID gEfiConsoleInDeviceGuid;
extern EFI_GUID gEfiStandardErrorDeviceGuid;
extern EFI_GUID gEfiConsoleOutDeviceGuid;
extern EFI_GUID gConnectConInEventGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gUefiOvmfPkgTokenSpaceGuid;
extern EFI_GUID gEfiEventReadyToBootGuid;
extern EFI_GUID gEfiEventAfterReadyToBootGuid;
extern EFI_GUID gEfiEventLegacyBootGuid;
extern EFI_GUID gEfiGlobalVariableGuid;
extern EFI_GUID gEfiAcpi20TableGuid;
extern EFI_GUID gEfiAcpi10TableGuid;

// Protocols
extern EFI_GUID gEfiSimplePointerProtocolGuid;
extern EFI_GUID gEfiAbsolutePointerProtocolGuid;
extern EFI_GUID gEfiSimpleTextInProtocolGuid;
extern EFI_GUID gEfiSimpleTextInputExProtocolGuid;
extern EFI_GUID gEfiSimpleTextOutProtocolGuid;
extern EFI_GUID gEfiGraphicsOutputProtocolGuid;
extern EFI_GUID gEfiUgaDrawProtocolGuid;
extern EFI_GUID gPcdProtocolGuid;
extern EFI_GUID gEfiPcdProtocolGuid;
extern EFI_GUID gGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiDevicePathProtocolGuid;
extern EFI_GUID gEfiDevicePathUtilitiesProtocolGuid;
extern EFI_GUID gEfiDevicePathToTextProtocolGuid;
extern EFI_GUID gEfiDevicePathFromTextProtocolGuid;
extern EFI_GUID gEfiDriverBindingProtocolGuid;
extern EFI_GUID gEfiHiiFontProtocolGuid;
extern EFI_GUID gEfiSimpleFileSystemProtocolGuid;
extern EFI_GUID gEfiComponentNameProtocolGuid;
extern EFI_GUID gEfiComponentName2ProtocolGuid;
extern EFI_GUID gEfiDriverConfigurationProtocolGuid;
extern EFI_GUID gEfiDriverConfiguration2ProtocolGuid;
extern EFI_GUID gEfiDriverDiagnosticsProtocolGuid;
extern EFI_GUID gEfiDriverDiagnostics2ProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdConOutGopSupport  0U
#define _PCD_SIZE_PcdConOutGopSupport 1
#define _PCD_GET_MODE_SIZE_PcdConOutGopSupport  _PCD_SIZE_PcdConOutGopSupport 
#define _PCD_VALUE_PcdConOutGopSupport  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdConOutGopSupport;
#define _PCD_GET_MODE_BOOL_PcdConOutGopSupport  _gPcd_FixedAtBuild_PcdConOutGopSupport
//#define _PCD_SET_MODE_BOOL_PcdConOutGopSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdConOutUgaSupport  0U
#define _PCD_SIZE_PcdConOutUgaSupport 1
#define _PCD_GET_MODE_SIZE_PcdConOutUgaSupport  _PCD_SIZE_PcdConOutUgaSupport 
#define _PCD_VALUE_PcdConOutUgaSupport  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdConOutUgaSupport;
#define _PCD_GET_MODE_BOOL_PcdConOutUgaSupport  _gPcd_FixedAtBuild_PcdConOutUgaSupport
//#define _PCD_SET_MODE_BOOL_PcdConOutUgaSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUgaConsumeSupport  0U
#define _PCD_SIZE_PcdUgaConsumeSupport 1
#define _PCD_GET_MODE_SIZE_PcdUgaConsumeSupport  _PCD_SIZE_PcdUgaConsumeSupport 
#define _PCD_VALUE_PcdUgaConsumeSupport  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdUgaConsumeSupport;
#define _PCD_GET_MODE_BOOL_PcdUgaConsumeSupport  _gPcd_FixedAtBuild_PcdUgaConsumeSupport
//#define _PCD_SET_MODE_BOOL_PcdUgaConsumeSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdConOutRow  27U
#define _PCD_GET_MODE_32_PcdConOutRow  LibPcdGet32(_PCD_TOKEN_PcdConOutRow)
#define _PCD_GET_MODE_SIZE_PcdConOutRow  LibPcdGetSize(_PCD_TOKEN_PcdConOutRow)
#define _PCD_SET_MODE_32_PcdConOutRow(Value)  LibPcdSet32(_PCD_TOKEN_PcdConOutRow, (Value))
#define _PCD_SET_MODE_32_S_PcdConOutRow(Value)  LibPcdSet32S(_PCD_TOKEN_PcdConOutRow, (Value))

#define _PCD_TOKEN_PcdConOutColumn  26U
#define _PCD_GET_MODE_32_PcdConOutColumn  LibPcdGet32(_PCD_TOKEN_PcdConOutColumn)
#define _PCD_GET_MODE_SIZE_PcdConOutColumn  LibPcdGetSize(_PCD_TOKEN_PcdConOutColumn)
#define _PCD_SET_MODE_32_PcdConOutColumn(Value)  LibPcdSet32(_PCD_TOKEN_PcdConOutColumn, (Value))
#define _PCD_SET_MODE_32_S_PcdConOutColumn(Value)  LibPcdSet32S(_PCD_TOKEN_PcdConOutColumn, (Value))

#define _PCD_TOKEN_PcdConInConnectOnDemand  0U
#define _PCD_SIZE_PcdConInConnectOnDemand 1
#define _PCD_GET_MODE_SIZE_PcdConInConnectOnDemand  _PCD_SIZE_PcdConInConnectOnDemand 
#define _PCD_VALUE_PcdConInConnectOnDemand  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdConInConnectOnDemand;
#define _PCD_GET_MODE_BOOL_PcdConInConnectOnDemand  _gPcd_FixedAtBuild_PcdConInConnectOnDemand
//#define _PCD_SET_MODE_BOOL_PcdConInConnectOnDemand  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
ConSplitterDriverEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
