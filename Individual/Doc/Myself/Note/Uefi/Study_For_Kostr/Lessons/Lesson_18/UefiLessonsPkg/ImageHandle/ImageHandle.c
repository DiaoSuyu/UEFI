#include <Uefi.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

#define offsetof(a, b) ((UINTN)&(((a*)0)->b))
#if defined(_MSC_VER)
    #define container_of(ptr, type, member) \
            ((type*)((char*)(ptr) - offsetof(type, member)))
#elif defined(__GNUC__)
    #define container_of(ptr, type, member) ({                 \
            const typeof(((type *)0)->member) *__mptr = (ptr); \
            (type *)((char *)(__mptr) - offsetof(type,member));   \
            })
#endif


///
/// IHANDLE - contains a list of protocol handles
///
typedef struct {
  UINTN         Signature;
  /// All handles list of IHANDLE
  LIST_ENTRY    AllHandles;
  /// List of PROTOCOL_INTERFACE's for this handle
  LIST_ENTRY    Protocols;
  UINTN         LocateRequest;
  /// The Handle Database Key value when this handle was last created or modified
  UINT64        Key;
} IHANDLE;


///
/// PROTOCOL_ENTRY - each different protocol has 1 entry in the protocol
/// database.  Each handler that supports this protocol is listed, along
/// with a list of registered notifies.
///
typedef struct {
  UINTN         Signature;
  /// Link Entry inserted to mProtocolDatabase
  LIST_ENTRY    AllEntries;
  /// ID of the protocol
  EFI_GUID      ProtocolID;
  /// All protocol interfaces
  LIST_ENTRY    Protocols;
  /// Registerd notification handlers
  LIST_ENTRY    Notify;
} PROTOCOL_ENTRY;


///
/// PROTOCOL_INTERFACE - each protocol installed on a handle is tracked
/// with a protocol interface structure
///
typedef struct {
  UINTN             Signature;
  /// Link on IHANDLE.Protocols
  LIST_ENTRY        Link;
  /// Back pointer
  IHANDLE           *Handle;
  /// Link on PROTOCOL_ENTRY.Protocols
  LIST_ENTRY        ByProtocol;
  /// The protocol ID
  PROTOCOL_ENTRY    *Protocol;
  /// The interface value
  VOID              *Interface;
  /// OPEN_PROTOCOL_DATA list
  LIST_ENTRY        OpenList;
  UINTN             OpenListCount;
} PROTOCOL_INTERFACE;


EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  IHANDLE *MyHandle = ImageHandle;

  Print(L"MyHandle: 0x%p\n", MyHandle);

  Print(L"MyHandle: Signature: %c %c %c %c\n", (MyHandle->Signature >>  0) & 0xff,
                                     (MyHandle->Signature >>  8) & 0xff,
                                     (MyHandle->Signature >> 16) & 0xff,
                                     (MyHandle->Signature >> 24) & 0xff);

  Print(L"MyHandle: Forward Protocol Interface Link: 0x%p\n", MyHandle->Protocols.ForwardLink);
  Print(L"MyHandle: Back Protocol Interface Link: 0x%p\n", MyHandle->Protocols.BackLink);

  LIST_ENTRY *FirstLink = MyHandle->Protocols.ForwardLink;
  LIST_ENTRY *CurrentLink = FirstLink;
  do {
        PROTOCOL_INTERFACE *MyProtocolInterface = container_of(CurrentLink, PROTOCOL_INTERFACE, Link);
        Print(L"\n");
        Print(L"MyProtocolInterface: Current Link: 0x%p\n", CurrentLink);
        Print(L"MyProtocolInterface: Signature: %c %c %c %c\n", (MyProtocolInterface->Signature >>  0) & 0xff,
                                           (MyProtocolInterface->Signature >>  8) & 0xff,
                                           (MyProtocolInterface->Signature >> 16) & 0xff,
                                           (MyProtocolInterface->Signature >> 24) & 0xff);
        Print(L"MyProtocolInterface: Forward Link: 0x%p\n", MyProtocolInterface->Link.ForwardLink);
        Print(L"MyProtocolInterface: Back Link: 0x%p\n", MyProtocolInterface->Link.BackLink);
        CurrentLink = MyProtocolInterface->Link.ForwardLink;

        PROTOCOL_ENTRY *MyProtocolEntry = MyProtocolInterface->Protocol;
        Print(L"MyProtocolEntry: 0x%p\n", MyProtocolEntry);
        Print(L"MyProtocolEntry: Protocol ID GUID: %g\n", MyProtocolEntry->ProtocolID);

  } while (CurrentLink != FirstLink);

  Print(L"________\n");
  EFI_GUID **ProtocolGuidArray;
  UINTN ArrayCount;
  EFI_STATUS Status = gBS->ProtocolsPerHandle (
      NULL,
      &ProtocolGuidArray,
      &ArrayCount
  );

  if (!EFI_ERROR(Status)) {
    for (int i=0; i < ArrayCount; i++) {
      Print(L"%g\n", ProtocolGuidArray[i]);
    }
    FreePool(ProtocolGuidArray);
  } else {
      Print(L"ProtocolsPerHandle error: %r\n", Status);
  }

  return EFI_SUCCESS;
}
