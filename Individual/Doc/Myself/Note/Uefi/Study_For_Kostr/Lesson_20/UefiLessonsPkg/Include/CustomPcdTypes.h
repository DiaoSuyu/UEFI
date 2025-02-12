#ifndef CUSTOM_PCD_TYPES_H
#define CUSTOM_PCD_TYPES_H

#include <Uefi.h>


typedef struct {
  EFI_GUID Guid;
  CHAR16 Name[6];
} InnerCustomStruct;

typedef struct {
  UINT8 Val8;
  UINT32 Val32[2];
  InnerCustomStruct ValStruct;
  union {
    struct {
      UINT8 Field1:1;
      UINT8 Field2:3;
      UINT8 Field3:4;
    } BitFields;
    UINT8 Byte;
  } ValUnion;
} CustomStruct;

#endif