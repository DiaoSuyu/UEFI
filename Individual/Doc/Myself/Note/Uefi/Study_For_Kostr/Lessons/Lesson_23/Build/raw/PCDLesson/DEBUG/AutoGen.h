/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_19460a32_9899_44bc_9619_2e55a4dd9367
#define _AUTOGENH_19460a32_9899_44bc_9619_2e55a4dd9367

#ifdef __cplusplus
extern "C" {
#endif

#include <Uefi.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0x19460a32, 0x9899, 0x44bc, {0x96, 0x19, 0x2e, 0x55, 0xa4, 0xdd, 0x93, 0x67}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x3db7270f, 0xffac, 0x4139, {0x90, 0xa4, 0x0a, 0xe6, 0x8f, 0x3f, 0x81, 0x67}}
#define STACK_COOKIE_VALUE 0xCCEBD65F6437244CULL

// Guids
extern EFI_GUID gUefiLessonsPkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gEfiVTUTF8Guid;
extern EFI_GUID gEfiVT100Guid;
extern EFI_GUID gEfiVT100PlusGuid;
extern EFI_GUID gEfiPcAnsiGuid;
extern EFI_GUID gEfiUartDevicePathGuid;
extern EFI_GUID gEfiSasDevicePathGuid;
extern EFI_GUID gEfiVirtualDiskGuid;
extern EFI_GUID gEfiVirtualCdGuid;
extern EFI_GUID gEfiPersistentVirtualDiskGuid;
extern EFI_GUID gEfiPersistentVirtualCdGuid;
extern EFI_GUID gEfiEventReadyToBootGuid;
extern EFI_GUID gEfiEventAfterReadyToBootGuid;
extern EFI_GUID gEfiEventLegacyBootGuid;
extern EFI_GUID gEfiGlobalVariableGuid;
extern EFI_GUID gEfiAcpi20TableGuid;
extern EFI_GUID gEfiAcpi10TableGuid;

// Protocols
extern EFI_GUID gEfiDevicePathProtocolGuid;
extern EFI_GUID gEfiDebugPortProtocolGuid;
extern EFI_GUID gEfiDriverBindingProtocolGuid;
extern EFI_GUID gEfiSimpleTextOutProtocolGuid;
extern EFI_GUID gEfiGraphicsOutputProtocolGuid;
extern EFI_GUID gEfiHiiFontProtocolGuid;
extern EFI_GUID gEfiSimpleFileSystemProtocolGuid;
extern EFI_GUID gEfiUgaDrawProtocolGuid;
extern EFI_GUID gEfiComponentNameProtocolGuid;
extern EFI_GUID gEfiComponentName2ProtocolGuid;
extern EFI_GUID gEfiDriverConfigurationProtocolGuid;
extern EFI_GUID gEfiDriverConfiguration2ProtocolGuid;
extern EFI_GUID gEfiDriverDiagnosticsProtocolGuid;
extern EFI_GUID gEfiDriverDiagnostics2ProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdInt8  0U
#define _PCD_SIZE_PcdInt8 1
#define _PCD_GET_MODE_SIZE_PcdInt8  _PCD_SIZE_PcdInt8 
#define _PCD_VALUE_PcdInt8  0x88U
extern const  UINT8  _gPcd_FixedAtBuild_PcdInt8;
#define _PCD_GET_MODE_8_PcdInt8  _gPcd_FixedAtBuild_PcdInt8
//#define _PCD_SET_MODE_8_PcdInt8  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdInt16  0U
#define _PCD_SIZE_PcdInt16 2
#define _PCD_GET_MODE_SIZE_PcdInt16  _PCD_SIZE_PcdInt16 
#define _PCD_VALUE_PcdInt16  0x1616U
extern const  UINT16  _gPcd_FixedAtBuild_PcdInt16;
#define _PCD_GET_MODE_16_PcdInt16  _gPcd_FixedAtBuild_PcdInt16
//#define _PCD_SET_MODE_16_PcdInt16  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdInt32  0U
#define _PCD_SIZE_PcdInt32 4
#define _PCD_GET_MODE_SIZE_PcdInt32  _PCD_SIZE_PcdInt32 
#define _PCD_VALUE_PcdInt32  0x32323232U
extern const  UINT32  _gPcd_FixedAtBuild_PcdInt32;
#define _PCD_GET_MODE_32_PcdInt32  _gPcd_FixedAtBuild_PcdInt32
//#define _PCD_SET_MODE_32_PcdInt32  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdInt64  0U
#define _PCD_SIZE_PcdInt64 8
#define _PCD_GET_MODE_SIZE_PcdInt64  _PCD_SIZE_PcdInt64 
#define _PCD_VALUE_PcdInt64  0x6464646464646464ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdInt64;
#define _PCD_GET_MODE_64_PcdInt64  _gPcd_FixedAtBuild_PcdInt64
//#define _PCD_SET_MODE_64_PcdInt64  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBool  0U
#define _PCD_SIZE_PcdBool 1
#define _PCD_GET_MODE_SIZE_PcdBool  _PCD_SIZE_PcdBool 
#define _PCD_VALUE_PcdBool  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdBool;
#define _PCD_GET_MODE_BOOL_PcdBool  _gPcd_FixedAtBuild_PcdBool
//#define _PCD_SET_MODE_BOOL_PcdBool  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdExpression  0U
#define _PCD_SIZE_PcdExpression 4
#define _PCD_GET_MODE_SIZE_PcdExpression  _PCD_SIZE_PcdExpression 
#define _PCD_VALUE_PcdExpression  4294967295U
extern const  UINT32  _gPcd_FixedAtBuild_PcdExpression;
#define _PCD_GET_MODE_32_PcdExpression  _gPcd_FixedAtBuild_PcdExpression
//#define _PCD_SET_MODE_32_PcdExpression  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdExpression_1  0U
#define _PCD_SIZE_PcdExpression_1 4
#define _PCD_GET_MODE_SIZE_PcdExpression_1  _PCD_SIZE_PcdExpression_1 
#define _PCD_VALUE_PcdExpression_1  65331U
extern const  UINT32  _gPcd_FixedAtBuild_PcdExpression_1;
#define _PCD_GET_MODE_32_PcdExpression_1  _gPcd_FixedAtBuild_PcdExpression_1
//#define _PCD_SET_MODE_32_PcdExpression_1  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdExpression_2  0U
#define _PCD_SIZE_PcdExpression_2 4
#define _PCD_GET_MODE_SIZE_PcdExpression_2  _PCD_SIZE_PcdExpression_2 
#define _PCD_VALUE_PcdExpression_2  1048576U
extern const  UINT32  _gPcd_FixedAtBuild_PcdExpression_2;
#define _PCD_GET_MODE_32_PcdExpression_2  _gPcd_FixedAtBuild_PcdExpression_2
//#define _PCD_SET_MODE_32_PcdExpression_2  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdExpression_3  0U
#define _PCD_SIZE_PcdExpression_3 1
#define _PCD_GET_MODE_SIZE_PcdExpression_3  _PCD_SIZE_PcdExpression_3 
#define _PCD_VALUE_PcdExpression_3  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdExpression_3;
#define _PCD_GET_MODE_BOOL_PcdExpression_3  _gPcd_FixedAtBuild_PcdExpression_3
//#define _PCD_SET_MODE_BOOL_PcdExpression_3  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAsciiStr  0U
#define _PCD_VALUE_PcdAsciiStr  _gPcd_FixedAtBuild_PcdAsciiStr
extern const UINT8 _gPcd_FixedAtBuild_PcdAsciiStr[6];
#define _PCD_GET_MODE_PTR_PcdAsciiStr  _gPcd_FixedAtBuild_PcdAsciiStr
#define _PCD_SIZE_PcdAsciiStr 6
#define _PCD_GET_MODE_SIZE_PcdAsciiStr  _PCD_SIZE_PcdAsciiStr 
//#define _PCD_SET_MODE_PTR_PcdAsciiStr  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUCS2Str  0U
#define _PCD_VALUE_PcdUCS2Str  _gPcd_FixedAtBuild_PcdUCS2Str
extern const UINT16 _gPcd_FixedAtBuild_PcdUCS2Str[6];
#define _PCD_GET_MODE_PTR_PcdUCS2Str  _gPcd_FixedAtBuild_PcdUCS2Str
#define _PCD_SIZE_PcdUCS2Str 12
#define _PCD_GET_MODE_SIZE_PcdUCS2Str  _PCD_SIZE_PcdUCS2Str 
//#define _PCD_SET_MODE_PTR_PcdUCS2Str  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArray  0U
#define _PCD_VALUE_PcdArray  (VOID *)_gPcd_FixedAtBuild_PcdArray
extern const UINT8 _gPcd_FixedAtBuild_PcdArray[3];
#define _PCD_GET_MODE_PTR_PcdArray  (VOID *)_gPcd_FixedAtBuild_PcdArray
#define _PCD_SIZE_PcdArray 3
#define _PCD_GET_MODE_SIZE_PcdArray  _PCD_SIZE_PcdArray 
//#define _PCD_SET_MODE_PTR_PcdArray  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGuidInBytes  0U
#define _PCD_VALUE_PcdGuidInBytes  (VOID *)_gPcd_FixedAtBuild_PcdGuidInBytes
extern const UINT8 _gPcd_FixedAtBuild_PcdGuidInBytes[16];
#define _PCD_GET_MODE_PTR_PcdGuidInBytes  (VOID *)_gPcd_FixedAtBuild_PcdGuidInBytes
#define _PCD_SIZE_PcdGuidInBytes 16
#define _PCD_GET_MODE_SIZE_PcdGuidInBytes  _PCD_SIZE_PcdGuidInBytes 
//#define _PCD_SET_MODE_PTR_PcdGuidInBytes  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdGuid  0U
#define _PCD_VALUE_PcdGuid  (VOID *)_gPcd_FixedAtBuild_PcdGuid
extern const UINT8 _gPcd_FixedAtBuild_PcdGuid[16];
#define _PCD_GET_MODE_PTR_PcdGuid  (VOID *)_gPcd_FixedAtBuild_PcdGuid
#define _PCD_SIZE_PcdGuid 16
#define _PCD_GET_MODE_SIZE_PcdGuid  _PCD_SIZE_PcdGuid 
//#define _PCD_SET_MODE_PTR_PcdGuid  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDevicePath  0U
#define _PCD_VALUE_PcdDevicePath  (VOID *)_gPcd_FixedAtBuild_PcdDevicePath
extern const UINT8 _gPcd_FixedAtBuild_PcdDevicePath[30];
#define _PCD_GET_MODE_PTR_PcdDevicePath  (VOID *)_gPcd_FixedAtBuild_PcdDevicePath
#define _PCD_SIZE_PcdDevicePath 30
#define _PCD_GET_MODE_SIZE_PcdDevicePath  _PCD_SIZE_PcdDevicePath 
//#define _PCD_SET_MODE_PTR_PcdDevicePath  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIntCasts  0U
#define _PCD_VALUE_PcdIntCasts  (VOID *)_gPcd_FixedAtBuild_PcdIntCasts
extern const UINT8 _gPcd_FixedAtBuild_PcdIntCasts[15];
#define _PCD_GET_MODE_PTR_PcdIntCasts  (VOID *)_gPcd_FixedAtBuild_PcdIntCasts
#define _PCD_SIZE_PcdIntCasts 15
#define _PCD_GET_MODE_SIZE_PcdIntCasts  _PCD_SIZE_PcdIntCasts 
//#define _PCD_SET_MODE_PTR_PcdIntCasts  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdWithLabels  0U
#define _PCD_VALUE_PcdWithLabels  (VOID *)_gPcd_FixedAtBuild_PcdWithLabels
extern const UINT8 _gPcd_FixedAtBuild_PcdWithLabels[8];
#define _PCD_GET_MODE_PTR_PcdWithLabels  (VOID *)_gPcd_FixedAtBuild_PcdWithLabels
#define _PCD_SIZE_PcdWithLabels 8
#define _PCD_GET_MODE_SIZE_PcdWithLabels  _PCD_SIZE_PcdWithLabels 
//#define _PCD_SET_MODE_PTR_PcdWithLabels  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArrayExt  0U
#define _PCD_VALUE_PcdArrayExt  (VOID *)_gPcd_FixedAtBuild_PcdArrayExt
extern const UINT8 _gPcd_FixedAtBuild_PcdArrayExt[42];
#define _PCD_GET_MODE_PTR_PcdArrayExt  (VOID *)_gPcd_FixedAtBuild_PcdArrayExt
#define _PCD_SIZE_PcdArrayExt 42
#define _PCD_GET_MODE_SIZE_PcdArrayExt  _PCD_SIZE_PcdArrayExt 
//#define _PCD_SET_MODE_PTR_PcdArrayExt  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCustomStruct_Type1  0U
#define _PCD_VALUE_PcdCustomStruct_Type1  (VOID *)_gPcd_FixedAtBuild_PcdCustomStruct_Type1
extern const UINT8 _gPcd_FixedAtBuild_PcdCustomStruct_Type1[44];
#define _PCD_GET_MODE_PTR_PcdCustomStruct_Type1  (VOID *)_gPcd_FixedAtBuild_PcdCustomStruct_Type1
#define _PCD_SIZE_PcdCustomStruct_Type1 44
#define _PCD_GET_MODE_SIZE_PcdCustomStruct_Type1  _PCD_SIZE_PcdCustomStruct_Type1 
//#define _PCD_SET_MODE_PTR_PcdCustomStruct_Type1  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCustomStruct_Type2  0U
#define _PCD_VALUE_PcdCustomStruct_Type2  (VOID *)_gPcd_FixedAtBuild_PcdCustomStruct_Type2
extern const UINT8 _gPcd_FixedAtBuild_PcdCustomStruct_Type2[44];
#define _PCD_GET_MODE_PTR_PcdCustomStruct_Type2  (VOID *)_gPcd_FixedAtBuild_PcdCustomStruct_Type2
#define _PCD_SIZE_PcdCustomStruct_Type2 44
#define _PCD_GET_MODE_SIZE_PcdCustomStruct_Type2  _PCD_SIZE_PcdCustomStruct_Type2 
//#define _PCD_SET_MODE_PTR_PcdCustomStruct_Type2  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArrayWithFixedSize  0U
#define _PCD_VALUE_PcdArrayWithFixedSize  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize
extern const UINT8 _gPcd_FixedAtBuild_PcdArrayWithFixedSize[12];
#define _PCD_GET_MODE_PTR_PcdArrayWithFixedSize  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize
#define _PCD_SIZE_PcdArrayWithFixedSize 12
#define _PCD_GET_MODE_SIZE_PcdArrayWithFixedSize  _PCD_SIZE_PcdArrayWithFixedSize 
//#define _PCD_SET_MODE_PTR_PcdArrayWithFixedSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArrayWithFixedSize_1  0U
#define _PCD_VALUE_PcdArrayWithFixedSize_1  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize_1
extern const UINT8 _gPcd_FixedAtBuild_PcdArrayWithFixedSize_1[12];
#define _PCD_GET_MODE_PTR_PcdArrayWithFixedSize_1  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize_1
#define _PCD_SIZE_PcdArrayWithFixedSize_1 12
#define _PCD_GET_MODE_SIZE_PcdArrayWithFixedSize_1  _PCD_SIZE_PcdArrayWithFixedSize_1 
//#define _PCD_SET_MODE_PTR_PcdArrayWithFixedSize_1  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArrayWithFixedSize_2  0U
#define _PCD_VALUE_PcdArrayWithFixedSize_2  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize_2
extern const UINT8 _gPcd_FixedAtBuild_PcdArrayWithFixedSize_2[12];
#define _PCD_GET_MODE_PTR_PcdArrayWithFixedSize_2  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize_2
#define _PCD_SIZE_PcdArrayWithFixedSize_2 12
#define _PCD_GET_MODE_SIZE_PcdArrayWithFixedSize_2  _PCD_SIZE_PcdArrayWithFixedSize_2 
//#define _PCD_SET_MODE_PTR_PcdArrayWithFixedSize_2  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArrayWithFixedSize_3  0U
#define _PCD_VALUE_PcdArrayWithFixedSize_3  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize_3
extern const UINT8 _gPcd_FixedAtBuild_PcdArrayWithFixedSize_3[12];
#define _PCD_GET_MODE_PTR_PcdArrayWithFixedSize_3  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize_3
#define _PCD_SIZE_PcdArrayWithFixedSize_3 12
#define _PCD_GET_MODE_SIZE_PcdArrayWithFixedSize_3  _PCD_SIZE_PcdArrayWithFixedSize_3 
//#define _PCD_SET_MODE_PTR_PcdArrayWithFixedSize_3  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdArrayWithFixedSize_4  0U
#define _PCD_VALUE_PcdArrayWithFixedSize_4  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize_4
extern const UINT8 _gPcd_FixedAtBuild_PcdArrayWithFixedSize_4[88];
#define _PCD_GET_MODE_PTR_PcdArrayWithFixedSize_4  (VOID *)_gPcd_FixedAtBuild_PcdArrayWithFixedSize_4
#define _PCD_SIZE_PcdArrayWithFixedSize_4 88
#define _PCD_GET_MODE_SIZE_PcdArrayWithFixedSize_4  _PCD_SIZE_PcdArrayWithFixedSize_4 
//#define _PCD_SET_MODE_PTR_PcdArrayWithFixedSize_4  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdInt32Override  0U
#define _PCD_SIZE_PcdInt32Override 4
#define _PCD_GET_MODE_SIZE_PcdInt32Override  _PCD_SIZE_PcdInt32Override 
#define _PCD_VALUE_PcdInt32Override  48U
extern const  UINT32  _gPcd_FixedAtBuild_PcdInt32Override;
#define _PCD_GET_MODE_32_PcdInt32Override  _gPcd_FixedAtBuild_PcdInt32Override
//#define _PCD_SET_MODE_32_PcdInt32Override  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPatchableInt32  0U
#define _PCD_PATCHABLE_VALUE_PcdPatchableInt32  ((UINT32)0x31313131U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPatchableInt32;
#define _PCD_GET_MODE_32_PcdPatchableInt32  _gPcd_BinaryPatch_PcdPatchableInt32
#define _PCD_PATCHABLE_PcdPatchableInt32_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPatchableInt32  _gPcd_BinaryPatch_Size_PcdPatchableInt32 
extern UINTN _gPcd_BinaryPatch_Size_PcdPatchableInt32; 
#define _PCD_SET_MODE_32_PcdPatchableInt32(Value)  (_gPcd_BinaryPatch_PcdPatchableInt32 = (Value))
#define _PCD_SET_MODE_32_S_PcdPatchableInt32(Value)  ((_gPcd_BinaryPatch_PcdPatchableInt32 = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdFeatureFlag  0U
#define _PCD_SIZE_PcdFeatureFlag 1
#define _PCD_GET_MODE_SIZE_PcdFeatureFlag  _PCD_SIZE_PcdFeatureFlag 
#define _PCD_VALUE_PcdFeatureFlag  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdFeatureFlag;
#define _PCD_GET_MODE_BOOL_PcdFeatureFlag  _gPcd_FixedAtBuild_PcdFeatureFlag
//#define _PCD_SET_MODE_BOOL_PcdFeatureFlag  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
