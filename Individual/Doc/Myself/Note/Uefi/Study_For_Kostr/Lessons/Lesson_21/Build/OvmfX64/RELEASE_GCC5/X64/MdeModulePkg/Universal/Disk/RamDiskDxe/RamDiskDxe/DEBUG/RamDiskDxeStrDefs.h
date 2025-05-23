/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    RamDiskDxeStrDefs.h
  Abstract:       Auto-generated RamDiskDxeStrDefs.h for building module or library.
**/

#ifndef _STRDEFS_28A03FF4_12B3_4305_A417_BB1A4F94081E
#define _STRDEFS_28A03FF4_12B3_4305_A417_BB1A4F94081E


//
//Unicode String ID
//
// #define $LANGUAGE_NAME                                       0x0000 // not referenced
// #define $PRINTABLE_LANGUAGE_NAME                             0x0001 // not referenced
#define STR_FORM_SET_TITLE                                   0x0002
#define STR_FORM_SET_TITLE_HELP                              0x0003
#define STR_MAIN_FORM_TITLE                                  0x0004
#define STR_RAM_DISK_NULL_STRING                             0x0005
#define STR_RAM_DISK_LIST_TEXT                               0x0006
#define STR_RAM_DISK_LIST_HELP                               0x0007
#define STR_GOTO_ADD_RAW_FORM                                0x0008
#define STR_GOTO_ADD_RAW_FORM_HELP                           0x0009
#define STR_GOTO_ADD_FROM_FILE_FORM                          0x000A
#define STR_GOTO_ADD_FROM_FILE_FORM_HELP                     0x000B
#define STR_REMOVE_SEL_HELP                                  0x000C
#define STR_REMOVE_SEL_TEXT                                  0x000D
#define STR_ADD_RAW_FORM_TITLE                               0x000E
#define STR_SIZE_PROMPT                                      0x000F
#define STR_SIZE_HELP                                        0x0010
#define STR_MEMORY_TYPE_PROMPT                               0x0011
#define STR_MEMORY_TYPE_HELP                                 0x0012
#define STR_RAM_DISK_BOOT_SERVICE_DATA_MEMORY                0x0013
#define STR_RAM_DISK_RESERVED_MEMORY                         0x0014
#define STR_CREATE_AND_EXIT_HELP                             0x0015
#define STR_CREATE_AND_EXIT_PROMPT                           0x0016
#define STR_DISCARD_AND_EXIT_HELP                            0x0017
#define STR_DISCARD_AND_EXIT_PROMPT                          0x0018
// #define STR_ADD_RAW_FORM_SUBTITLE_TEXT                       0x0019 // not referenced

extern unsigned char RamDiskDxeStrings[];


#define STRING_ARRAY_NAME RamDiskDxeStrings

#ifdef VFRCOMPILE
#define gEfiIfrTianoGuid { 0xf0b1735, 0x87a0, 0x4193, {0xb2, 0x66, 0x53, 0x8c, 0x38, 0xaf, 0x48, 0xce }}
#define gRamDiskFormSetGuid { 0x2a46715f, 0x3581, 0x4a55, { 0x8e, 0x73, 0x2b, 0x76, 0x9a, 0xaa, 0x30, 0xc5 }}
#define gEfiVirtualDiskGuid { 0x77AB535A, 0x45FC, 0x624B, {0x55, 0x60, 0xF7, 0xB2, 0x81, 0xD1, 0xF9, 0x6E }}
#define gEfiFileInfoGuid { 0x09576E92, 0x6D3F, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }}
#define gEfiMdePkgTokenSpaceGuid { 0x914AEBE7, 0x4635, 0x459b, { 0xAA, 0x1C, 0x11, 0xE2, 0x19, 0xB0, 0x3A, 0x10 }}
#define gUefiOvmfPkgTokenSpaceGuid {0x93bb96af, 0xb9f2, 0x4eb8, {0x94, 0x62, 0xe0, 0xba, 0x74, 0x56, 0x42, 0x36}}
#define gEfiEventReadyToBootGuid { 0x7CE88FB3, 0x4BD7, 0x4679, { 0x87, 0xA8, 0xA8, 0xD8, 0xDE, 0xE5, 0x0D, 0x2B }}
#define gEfiEventAfterReadyToBootGuid { 0x3a2a00ad, 0x98b9, 0x4cdf, { 0xa4, 0x78, 0x70, 0x27, 0x77, 0xf1, 0xc1, 0x0b }}
#define gEfiEventLegacyBootGuid { 0x2A571201, 0x4966, 0x47F6, { 0x8B, 0x86, 0xF3, 0x1E, 0x41, 0xF3, 0x2F, 0x10 }}
#define gEfiGlobalVariableGuid { 0x8BE4DF61, 0x93CA, 0x11D2, { 0xAA, 0x0D, 0x00, 0xE0, 0x98, 0x03, 0x2B, 0x8C }}
#define gEfiAcpi20TableGuid { 0x8868E871, 0xE4F1, 0x11D3, { 0xBC, 0x22, 0x00, 0x80, 0xC7, 0x3C, 0x88, 0x81 }}
#define gEfiAcpi10TableGuid { 0xEB9D2D30, 0x2D88, 0x11D3, { 0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }}
#define gEdkiiIfrBitVarstoreGuid {0x82DDD68B, 0x9163, 0x4187, {0x9B, 0x27, 0x20, 0xA8, 0xFD, 0x60,0xA7, 0x1D}}
#define gEfiHobListGuid { 0x7739F24C, 0x93D7, 0x11D4, { 0x9A, 0x3A, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }}
#define gEfiFileSystemVolumeLabelInfoIdGuid { 0xDB47D7D3, 0xFE81, 0x11D3, { 0x9A, 0x35, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D }}
#define gEfiRamDiskProtocolGuid { 0xab38a0df, 0x6873, 0x44a9, { 0x87, 0xe6, 0xd4, 0xeb, 0x56, 0x14, 0x84, 0x49 }}
#define gEfiHiiConfigAccessProtocolGuid {0x330d4706, 0xf2a0, 0x4e4f, {0xa3, 0x69, 0xb6, 0x6f, 0xa8, 0xd5, 0x43, 0x85}}
#define gEfiDevicePathProtocolGuid { 0x09576E91, 0x6D3F, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }}
#define gEfiBlockIoProtocolGuid { 0x964E5B21, 0x6459, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }}
#define gEfiBlockIo2ProtocolGuid { 0xa77b2472, 0xe282, 0x4e9f, {0xa2, 0x45, 0xc2, 0xc0, 0xe2, 0x7b, 0xbc, 0xc1 }}
#define gEfiAcpiTableProtocolGuid { 0xFFE06BDD, 0x6107, 0x46A6, { 0x7B, 0xB2, 0x5A, 0x9C, 0x7E, 0xC5, 0x27, 0x5C }}
#define gEfiAcpiSdtProtocolGuid { 0xeb97088e, 0xcfdf, 0x49c6, { 0xbe, 0x4b, 0xd9, 0x6, 0xa5, 0xb2, 0xe, 0x86 }}
#define FixedPcdGetBool(TokenName) _PCD_VALUE_##TokenName
#define FixedPcdGet8(TokenName) _PCD_VALUE_##TokenName
#define FixedPcdGet16(TokenName) _PCD_VALUE_##TokenName
#define FixedPcdGet32(TokenName) _PCD_VALUE_##TokenName
#define FixedPcdGet64(TokenName) _PCD_VALUE_##TokenName
#define FeaturePcdGet(TokenName) _PCD_VALUE_##TokenName
#define _PCD_VALUE_PcdAcpiDefaultOemId "INTEL "
#define _PCD_VALUE_PcdAcpiDefaultOemTableId 0x20202020324B4445
#define _PCD_VALUE_PcdAcpiDefaultOemRevision 0x00000002
#define _PCD_VALUE_PcdAcpiDefaultCreatorId 0x20202020
#define _PCD_VALUE_PcdAcpiDefaultCreatorRevision 0x01000013
#endif

#endif
