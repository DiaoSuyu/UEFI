#ifndef __SIMPLE_CLASS_PROTOCOL_H__
#define __SIMPLE_CLASS_PROTOCOL_H__

#include <Uefi.h>

typedef struct _SIMPLE_CLASS_PROTOCOL SIMPLE_CLASS_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *SIMPLE_CLASS_SET_NUMBER) (
  UINTN Number
  );

typedef
EFI_STATUS
(EFIAPI *SIMPLE_CLASS_GET_NUMBER) (
  UINTN *Number
  );

struct _SIMPLE_CLASS_PROTOCOL {
  SIMPLE_CLASS_GET_NUMBER GetNumber;
  SIMPLE_CLASS_SET_NUMBER SetNumber;
};

extern EFI_GUID gSimpleClassProtocolGuid;

#endif