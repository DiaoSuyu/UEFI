#include <Uefi.h>
#include <Library/DebugLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

#include <Protocol/HiiConfigKeyword.h>
#include <Protocol/HiiConfigRouting.h>
#include <Protocol/HiiDatabase.h>
#include <Protocol/HiiFont.h>
#include <Protocol/HiiImageEx.h>
#include <Protocol/HiiString.h>


#define offsetof(a, b) ((UINTN)&(((a*)0)->b))
#if defined(_MSC_VER)
    #define container_of(ptr, type, member) \
            ((type*)((char*)(ptr) - offsetof(type, member)))
#elif defined(__GNUC__)
    #define container_of(ptr, type, member) ({                   \
            const typeof(((type *)0)->member) *__mptr = (ptr);   \
            (type *)((char *)(__mptr) - offsetof(type, member)); \
            })
#endif


#define HII_FORMSET_STORAGE_SIGNATURE  SIGNATURE_32 ('H', 'S', 'T', 'G')
typedef struct {
  UINTN             Signature;
  LIST_ENTRY        Entry;
  EFI_HII_HANDLE    HiiHandle;
  EFI_HANDLE        DriverHandle;
  UINT8             Type;     // EFI_HII_VARSTORE_BUFFER, EFI_HII_VARSTORE_NAME_VALUE, EFI_HII_VARSTORE_EFI_VARIABLE
  EFI_GUID          Guid;
  CHAR16            *Name;
  UINT16            Size;
} HII_FORMSET_STORAGE;

//
// String Package definitions
//
#define HII_STRING_PACKAGE_SIGNATURE  SIGNATURE_32 ('h','i','s','p')
typedef struct _HII_STRING_PACKAGE_INSTANCE {
  UINTN                         Signature;
  EFI_HII_STRING_PACKAGE_HDR    *StringPkgHdr;
  UINT8                         *StringBlock;
  LIST_ENTRY                    StringEntry;
  LIST_ENTRY                    FontInfoList;          // local font info list
  UINT8                         FontId;
  EFI_STRING_ID                 MaxStringId;           // record StringId
} HII_STRING_PACKAGE_INSTANCE;

//
// Form Package definitions
//
#define HII_IFR_PACKAGE_SIGNATURE  SIGNATURE_32 ('h','f','r','p')
typedef struct _HII_IFR_PACKAGE_INSTANCE {
  UINTN                     Signature;
  EFI_HII_PACKAGE_HEADER    FormPkgHdr;
  UINT8                     *IfrData;
  LIST_ENTRY                IfrEntry;
} HII_IFR_PACKAGE_INSTANCE;

//
// Simple Font Package definitions
//
#define HII_S_FONT_PACKAGE_SIGNATURE  SIGNATURE_32 ('h','s','f','p')
typedef struct _HII_SIMPLE_FONT_PACKAGE_INSTANCE {
  UINTN                              Signature;
  EFI_HII_SIMPLE_FONT_PACKAGE_HDR    *SimpleFontPkgHdr;
  LIST_ENTRY                         SimpleFontEntry;
} HII_SIMPLE_FONT_PACKAGE_INSTANCE;

//
// Font Package definitions
//
#define HII_FONT_PACKAGE_SIGNATURE  SIGNATURE_32 ('h','i','f','p')
typedef struct _HII_FONT_PACKAGE_INSTANCE {
  UINTN                       Signature;
  EFI_HII_FONT_PACKAGE_HDR    *FontPkgHdr;
  UINT16                      Height;
  UINT16                      BaseLine;
  UINT8                       *GlyphBlock;
  LIST_ENTRY                  FontEntry;
  LIST_ENTRY                  GlyphInfoList;
} HII_FONT_PACKAGE_INSTANCE;

#define HII_GLYPH_INFO_SIGNATURE  SIGNATURE_32 ('h','g','i','s')
typedef struct _HII_GLYPH_INFO {
  UINTN                 Signature;
  LIST_ENTRY            Entry;
  CHAR16                CharId;
  EFI_HII_GLYPH_INFO    Cell;
} HII_GLYPH_INFO;

#define HII_FONT_INFO_SIGNATURE  SIGNATURE_32 ('h','l','f','i')
typedef struct _HII_FONT_INFO {
  UINTN         Signature;
  LIST_ENTRY    Entry;
  LIST_ENTRY    *GlobalEntry;
  UINT8         FontId;
} HII_FONT_INFO;

#define HII_GLOBAL_FONT_INFO_SIGNATURE  SIGNATURE_32 ('h','g','f','i')
typedef struct _HII_GLOBAL_FONT_INFO {
  UINTN                        Signature;
  LIST_ENTRY                   Entry;
  HII_FONT_PACKAGE_INSTANCE    *FontPackage;
  UINTN                        FontInfoSize;
  EFI_FONT_INFO                *FontInfo;
} HII_GLOBAL_FONT_INFO;

//
// Image Package definitions
//
typedef struct _HII_IMAGE_PACKAGE_INSTANCE {
  EFI_HII_IMAGE_PACKAGE_HDR    ImagePkgHdr;
  UINT32                       ImageBlockSize;
  UINT32                       PaletteInfoSize;
  EFI_HII_IMAGE_BLOCK          *ImageBlock;
  UINT8                        *PaletteBlock;
} HII_IMAGE_PACKAGE_INSTANCE;

//
// Keyboard Layout Package definitions
//
#define HII_KB_LAYOUT_PACKAGE_SIGNATURE  SIGNATURE_32 ('h','k','l','p')
typedef struct _HII_KEYBOARD_LAYOUT_PACKAGE_INSTANCE {
  UINTN         Signature;
  UINT8         *KeyboardPkg;
  LIST_ENTRY    KeyboardEntry;
} HII_KEYBOARD_LAYOUT_PACKAGE_INSTANCE;

//
// Guid Package definitions
//
#define HII_GUID_PACKAGE_SIGNATURE  SIGNATURE_32 ('h','i','g','p')
typedef struct _HII_GUID_PACKAGE_INSTANCE {
  UINTN         Signature;
  UINT8         *GuidPkg;
  LIST_ENTRY    GuidEntry;
} HII_GUID_PACKAGE_INSTANCE;

//
// A package list can contain only one or less than one device path package.
// This rule also applies to image package since ImageId can not be duplicate.
//
typedef struct _HII_DATABASE_PACKAGE_LIST_INSTANCE {
  EFI_HII_PACKAGE_LIST_HEADER    PackageListHdr;
  LIST_ENTRY                     GuidPkgHdr;
  LIST_ENTRY                     FormPkgHdr;
  LIST_ENTRY                     KeyboardLayoutHdr;
  LIST_ENTRY                     StringPkgHdr;
  LIST_ENTRY                     FontPkgHdr;
  HII_IMAGE_PACKAGE_INSTANCE     *ImagePkg;
  LIST_ENTRY                     SimpleFontPkgHdr;
  UINT8                          *DevicePathPkg;
} HII_DATABASE_PACKAGE_LIST_INSTANCE;

#define HII_HANDLE_SIGNATURE  SIGNATURE_32 ('h','i','h','l')
typedef struct {
  UINTN         Signature;
  LIST_ENTRY    Handle;
  UINTN         Key;
} HII_HANDLE;

#define HII_DATABASE_RECORD_SIGNATURE  SIGNATURE_32 ('h','i','d','r')
typedef struct _HII_DATABASE_RECORD {
  UINTN                                 Signature;
  HII_DATABASE_PACKAGE_LIST_INSTANCE    *PackageList;
  EFI_HANDLE                            DriverHandle;
  EFI_HII_HANDLE                        Handle;
  LIST_ENTRY                            DatabaseEntry;
} HII_DATABASE_RECORD;

#define HII_DATABASE_NOTIFY_SIGNATURE  SIGNATURE_32 ('h','i','d','n')
typedef struct _HII_DATABASE_NOTIFY {
  UINTN                           Signature;
  EFI_HANDLE                      NotifyHandle;
  UINT8                           PackageType;
  EFI_GUID                        *PackageGuid;
  EFI_HII_DATABASE_NOTIFY         PackageNotifyFn;
  EFI_HII_DATABASE_NOTIFY_TYPE    NotifyType;
  LIST_ENTRY                      DatabaseNotifyEntry;
} HII_DATABASE_NOTIFY;

#define HII_DATABASE_PRIVATE_DATA_SIGNATURE  SIGNATURE_32 ('H', 'i', 'D', 'p')
typedef struct _HII_DATABASE_PRIVATE_DATA {
  UINTN                                  Signature;
  LIST_ENTRY                             DatabaseList;
  LIST_ENTRY                             DatabaseNotifyList;
  EFI_HII_FONT_PROTOCOL                  HiiFont;
  EFI_HII_IMAGE_PROTOCOL                 HiiImage;
  EFI_HII_IMAGE_EX_PROTOCOL              HiiImageEx;
  EFI_HII_STRING_PROTOCOL                HiiString;
  EFI_HII_DATABASE_PROTOCOL              HiiDatabase;
  EFI_HII_CONFIG_ROUTING_PROTOCOL        ConfigRouting;
  EFI_CONFIG_KEYWORD_HANDLER_PROTOCOL    ConfigKeywordHandler;
  LIST_ENTRY                             HiiHandleList;
  INTN                                   HiiHandleCount;
  LIST_ENTRY                             FontInfoList; // global font info list
  UINTN                                  Attribute;    // default system color
  EFI_GUID                               CurrentLayoutGuid;
  EFI_HII_KEYBOARD_LAYOUT                *CurrentLayout;
} HII_DATABASE_PRIVATE_DATA;


EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{

    EFI_STATUS Status;
    EFI_HII_DATABASE_PROTOCOL *HiiDbProtocol;
    Status = gBS->LocateProtocol (
        &gEfiHiiDatabaseProtocolGuid,
        NULL,
        (VOID**)&HiiDbProtocol
    );
    if (EFI_ERROR(Status)) {
        Print(L"ERROR: Could not find HII Database protocol: %r\n", Status);
        return Status;
    }

    Print(L"=== HiiDataBasePrivateDataPointer List Start ===\n");
    HII_DATABASE_PRIVATE_DATA *HiiDataBasePrivateDataPointer = container_of(HiiDbProtocol, HII_DATABASE_PRIVATE_DATA, HiiDatabase);
    Print(L"Address                        = 0x%08x\n", HiiDataBasePrivateDataPointer);
    Print(  \
            L"Signature                      = %c %c %c %c\n", \
            (HiiDataBasePrivateDataPointer->Signature >>  0) & 0xFF, \
            (HiiDataBasePrivateDataPointer->Signature >>  8) & 0xFF, \
            (HiiDataBasePrivateDataPointer->Signature >> 16) & 0xFF, \
            (HiiDataBasePrivateDataPointer->Signature >> 24) & 0xFF  \
    );
    Print(L"DatabaseList.ForwardLink       = 0x%08x\n", HiiDataBasePrivateDataPointer->DatabaseList.ForwardLink);
    Print(L"DatabaseList.BackLink          = 0x%08x\n", HiiDataBasePrivateDataPointer->DatabaseList.BackLink);
    Print(L"DatabaseNotifyList.ForwardLink = 0x%08x\n", HiiDataBasePrivateDataPointer->DatabaseNotifyList.ForwardLink);
    Print(L"DatabaseNotifyList.BackLink    = 0x%08x\n", HiiDataBasePrivateDataPointer->DatabaseNotifyList.BackLink);
    Print(L"HiiFont                        = 0x%08x\n", HiiDataBasePrivateDataPointer->HiiFont);
    Print(L"HiiImage                       = 0x%08x\n", HiiDataBasePrivateDataPointer->HiiImage);
    Print(L"HiiImageEx                     = 0x%08x\n", HiiDataBasePrivateDataPointer->HiiImageEx);
    Print(L"HiiString                      = 0x%08x\n", HiiDataBasePrivateDataPointer->HiiString);
    Print(L"HiiDatabase                    = 0x%08x\n", HiiDataBasePrivateDataPointer->HiiDatabase);
    Print(L"ConfigRouting                  = 0x%08x\n", HiiDataBasePrivateDataPointer->ConfigRouting);
    Print(L"ConfigKeywordHandler           = 0x%08x\n", HiiDataBasePrivateDataPointer->ConfigKeywordHandler);
    Print(L"HiiHandleList.ForwardLink      = 0x%08x\n", HiiDataBasePrivateDataPointer->HiiHandleList.ForwardLink);
    Print(L"HiiHandleList.BackLink         = 0x%08x\n", HiiDataBasePrivateDataPointer->HiiHandleList.BackLink);
    Print(L"HiiHandleCount                 = 0x%08x\n", HiiDataBasePrivateDataPointer->HiiHandleCount);
    Print(L"FontInfoList.ForwardLink       = 0x%08x\n", HiiDataBasePrivateDataPointer->FontInfoList.ForwardLink);
    Print(L"FontInfoList.BackLink          = 0x%08x\n", HiiDataBasePrivateDataPointer->FontInfoList.BackLink);
    Print(L"Attribute                      = 0x%08x\n", HiiDataBasePrivateDataPointer->Attribute);
    Print(L"CurrentLayoutGuid              = 0x%08x\n", HiiDataBasePrivateDataPointer->CurrentLayoutGuid);
    Print(L"CurrentLayout                  = 0x%08x\n", HiiDataBasePrivateDataPointer->CurrentLayout);
    Print(L"=== HiiDataBasePrivateDataPointer List End ===\n");

    Print(L"\n");

    // HiiDataBasePrivateDataPointer->DatabaseList <-> (HII_DATABASE_RECORD)LIST_ENTRY DatabaseEntry
    UINTN HiiDataBaseRecordNumber = 0;
    LIST_ENTRY *HiiDataBaseRecordFirstLink = &HiiDataBasePrivateDataPointer->DatabaseList;
    LIST_ENTRY *HiiDataBaseRecordCurrentLink = HiiDataBaseRecordFirstLink->ForwardLink;
    if (HiiDataBaseRecordCurrentLink == NULL || HiiDataBaseRecordCurrentLink == HiiDataBaseRecordFirstLink) {
        Print(L"=== HiiDataBaseRecordList: Empty! ===\n");
        Print(L"\n");
    } else {
        Print(L"=== HiiDataBaseRecordPointer List Start ===\n");
        do {
            HII_DATABASE_RECORD *HiiDataBaseRecordPointer = container_of(HiiDataBaseRecordCurrentLink, HII_DATABASE_RECORD, DatabaseEntry);
            Print(L"Number = %04d, Address                   = 0x%08x\n", ++HiiDataBaseRecordNumber, HiiDataBaseRecordPointer);
            Print(  \
                    L"               Signature                 = %c %c %c %c\n", \
                    (HiiDataBaseRecordPointer->Signature >>  0) & 0xFF, \
                    (HiiDataBaseRecordPointer->Signature >>  8) & 0xFF, \
                    (HiiDataBaseRecordPointer->Signature >> 16) & 0xFF, \
                    (HiiDataBaseRecordPointer->Signature >> 24) & 0xFF  \
            );
            Print(L"               PackageList               = 0x%08x\n", HiiDataBaseRecordPointer->PackageList);
            HII_DATABASE_PACKAGE_LIST_INSTANCE *HiiDataBasePackageListInstancePointer = HiiDataBaseRecordPointer->PackageList;
            Print(L"                           PackageListGuid             = %g\n", HiiDataBasePackageListInstancePointer->PackageListHdr.PackageListGuid);
            Print(L"                           PackageLength               = 0x%08x\n", HiiDataBasePackageListInstancePointer->PackageListHdr.PackageLength);

            UINTN GuidPkgHdrNumber = 0;
            LIST_ENTRY *GuidPkgHdrFirstLink = &HiiDataBasePackageListInstancePointer->GuidPkgHdr;
            LIST_ENTRY *GuidPkgHdrCurrentLink = GuidPkgHdrFirstLink->ForwardLink;
            if (GuidPkgHdrCurrentLink == NULL || GuidPkgHdrCurrentLink == GuidPkgHdrFirstLink) {
                Print(L"                           === GuidPkgHdr List: Empty! ===\n");
            } else {
                Print(L"                           === GuidPkgHdr List Start ===\n");
                do {
                    Print(L"                           Number = %04d, Address = 0x%08x\n", ++GuidPkgHdrNumber, GuidPkgHdrCurrentLink);
                    Print(L"                           GuidPkgHdrCurrentLink.ForwardLink = 0x%08x\n", GuidPkgHdrCurrentLink->ForwardLink);
                    Print(L"                           GuidPkgHdrCurrentLink.BackLink    = 0x%08x\n", GuidPkgHdrCurrentLink->BackLink);
                    GuidPkgHdrCurrentLink = GuidPkgHdrCurrentLink->ForwardLink;
                } while (GuidPkgHdrCurrentLink != GuidPkgHdrFirstLink);
                Print(L"                           === GuidPkgHdr List End ===\n");
            }

            UINTN FormPkgHdrNumber = 0;
            LIST_ENTRY *FormPkgHdrFirstLink = &HiiDataBasePackageListInstancePointer->FormPkgHdr;
            LIST_ENTRY *FormPkgHdrCurrentLink = FormPkgHdrFirstLink->ForwardLink;
            if (FormPkgHdrCurrentLink == NULL || FormPkgHdrCurrentLink == FormPkgHdrFirstLink) {
                Print(L"                           === FormPkgHdr List: Empty! ===\n");
            } else {
                Print(L"                           === FormPkgHdr List Start ===\n");
                do {
                    Print(L"                           Number = %04d, Address = 0x%08x\n", ++FormPkgHdrNumber, FormPkgHdrCurrentLink);
                    Print(L"                           FormPkgHdrCurrentLink.ForwardLink = 0x%08x\n", FormPkgHdrCurrentLink->ForwardLink);
                    Print(L"                           FormPkgHdrCurrentLink.BackLink    = 0x%08x\n", FormPkgHdrCurrentLink->BackLink);
                    FormPkgHdrCurrentLink = FormPkgHdrCurrentLink->ForwardLink;
                } while (FormPkgHdrCurrentLink != FormPkgHdrFirstLink);
                Print(L"                           === FormPkgHdr List End ===\n");
            }

            UINTN KeyboardLayoutHdrNumber = 0;
            LIST_ENTRY *KeyboardLayoutHdrFirstLink = &HiiDataBasePackageListInstancePointer->KeyboardLayoutHdr;
            LIST_ENTRY *KeyboardLayoutHdrCurrentLink = KeyboardLayoutHdrFirstLink->ForwardLink;
            if (KeyboardLayoutHdrCurrentLink == NULL || KeyboardLayoutHdrCurrentLink == KeyboardLayoutHdrFirstLink) {
                Print(L"                           === KeyboardLayoutHdr List: Empty! ===\n");
            } else {
                Print(L"                           === KeyboardLayoutHdr List Start ===\n");
                do {
                    Print(L"                           Number = %04d, Address = 0x%08x\n", ++KeyboardLayoutHdrNumber, KeyboardLayoutHdrCurrentLink);
                    Print(L"                           KeyboardLayoutHdrCurrentLink.ForwardLink = 0x%08x\n", KeyboardLayoutHdrCurrentLink->ForwardLink);
                    Print(L"                           KeyboardLayoutHdrCurrentLink.BackLink    = 0x%08x\n", KeyboardLayoutHdrCurrentLink->BackLink);
                    KeyboardLayoutHdrCurrentLink = KeyboardLayoutHdrCurrentLink->ForwardLink;
                } while (KeyboardLayoutHdrCurrentLink != KeyboardLayoutHdrFirstLink);
                Print(L"                           === KeyboardLayoutHdr List End ===\n");
            }

            UINTN StringPkgHdrNumber = 0;
            LIST_ENTRY *StringPkgHdrFirstLink = &HiiDataBasePackageListInstancePointer->StringPkgHdr;
            LIST_ENTRY *StringPkgHdrCurrentLink = StringPkgHdrFirstLink->ForwardLink;
            if (StringPkgHdrCurrentLink == NULL || StringPkgHdrCurrentLink == StringPkgHdrFirstLink) {
                Print(L"                           === StringPkgHdr List: Empty! ===\n");
            } else {
                Print(L"                           === StringPkgHdr List Start ===\n");
                do {
                    Print(L"                           Number = %04d, Address = 0x%08x\n", ++StringPkgHdrNumber, StringPkgHdrCurrentLink);
                    Print(L"                           StringPkgHdrCurrentLink.ForwardLink = 0x%08x\n", StringPkgHdrCurrentLink->ForwardLink);
                    Print(L"                           StringPkgHdrCurrentLink.BackLink    = 0x%08x\n", StringPkgHdrCurrentLink->BackLink);
                    StringPkgHdrCurrentLink = StringPkgHdrCurrentLink->ForwardLink;
                } while (StringPkgHdrCurrentLink != StringPkgHdrFirstLink);
                Print(L"                           === StringPkgHdr List End ===\n");
            }

            UINTN FontPkgHdrNumber = 0;
            LIST_ENTRY *FontPkgHdrFirstLink = &HiiDataBasePackageListInstancePointer->FontPkgHdr;
            LIST_ENTRY *FontPkgHdrCurrentLink = FontPkgHdrFirstLink->ForwardLink;
            if (FontPkgHdrCurrentLink == NULL || FontPkgHdrCurrentLink == FontPkgHdrFirstLink) {
                Print(L"                           === FontPkgHdr List: Empty! ===\n");
            } else {
                Print(L"                           === FontPkgHdr List Start ===\n");
                do {
                    Print(L"                           Number = %04d, Address = 0x%08x\n", ++FontPkgHdrNumber, FontPkgHdrCurrentLink);
                    Print(L"                           FontPkgHdrCurrentLink.ForwardLink = 0x%08x\n", FontPkgHdrCurrentLink->ForwardLink);
                    Print(L"                           FontPkgHdrCurrentLink.BackLink    = 0x%08x\n", FontPkgHdrCurrentLink->BackLink);
                    FontPkgHdrCurrentLink = FontPkgHdrCurrentLink->ForwardLink;
                } while (FontPkgHdrCurrentLink != FontPkgHdrFirstLink);
                Print(L"                           === FontPkgHdr List End ===\n");
            }

            Print(L"                           ImagePkg                    = 0x%08x\n", HiiDataBasePackageListInstancePointer->ImagePkg);

            UINTN SimpleFontPkgHdrNumber = 0;
            LIST_ENTRY *SimpleFontPkgHdrFirstLink = &HiiDataBasePackageListInstancePointer->SimpleFontPkgHdr;
            LIST_ENTRY *SimpleFontPkgHdrCurrentLink = SimpleFontPkgHdrFirstLink->ForwardLink;
            if (SimpleFontPkgHdrCurrentLink == NULL || SimpleFontPkgHdrCurrentLink == SimpleFontPkgHdrFirstLink) {
                Print(L"                           === SimpleFontPkgHdr List: Empty! ===\n");
            } else {
                Print(L"                           === SimpleFontPkgHdr List Start ===\n");
                do {
                    Print(L"                           Number = %04d, Address = 0x%08x\n", ++SimpleFontPkgHdrNumber, SimpleFontPkgHdrCurrentLink);
                    Print(L"                           SimpleFontPkgHdrCurrentLink.ForwardLink = 0x%08x\n", SimpleFontPkgHdrCurrentLink->ForwardLink);
                    Print(L"                           SimpleFontPkgHdrCurrentLink.BackLink    = 0x%08x\n", SimpleFontPkgHdrCurrentLink->BackLink);
                    SimpleFontPkgHdrCurrentLink = SimpleFontPkgHdrCurrentLink->ForwardLink;
                } while (SimpleFontPkgHdrCurrentLink != SimpleFontPkgHdrFirstLink);
                Print(L"                           === SimpleFontPkgHdr List End ===\n");
            }

            Print(L"                           DevicePathPkg               = 0x%08x\n", HiiDataBasePackageListInstancePointer->DevicePathPkg);

            Print(L"               DriverHandle              = 0x%08x\n", HiiDataBaseRecordPointer->DriverHandle);
            Print(L"               Handle                    = 0x%08x\n", HiiDataBaseRecordPointer->Handle);
            Print(L"               DatabaseEntry.ForwardLink = 0x%08x\n", HiiDataBaseRecordPointer->DatabaseEntry.ForwardLink);
            Print(L"               DatabaseEntry.BackLink    = 0x%08x\n", HiiDataBaseRecordPointer->DatabaseEntry.BackLink);
            HiiDataBaseRecordCurrentLink = HiiDataBaseRecordPointer->DatabaseEntry.ForwardLink;
        } while (HiiDataBaseRecordCurrentLink != HiiDataBaseRecordFirstLink);
        Print(L"=== HiiDataBaseRecordPointer List End ===\n");
        Print(L"\n");
    }

    // HiiDataBasePrivateDataPointer->DatabaseNotifyList <-> (HII_DATABASE_NOTIFY)LIST_ENTRY DatabaseNotifyEntry
    UINTN HiiDataBaseNotifyNumber = 0;
    LIST_ENTRY *HiiDataBaseNotifyFirstLink = &HiiDataBasePrivateDataPointer->DatabaseNotifyList;
    LIST_ENTRY *HiiDataBaseNotifyCurrentLink = HiiDataBaseNotifyFirstLink->ForwardLink;
    if (HiiDataBaseNotifyCurrentLink == NULL || HiiDataBaseNotifyCurrentLink == HiiDataBaseNotifyFirstLink) {
        Print(L"=== HiiDataaseNotifyList: Empty! ===\n");
        Print(L"\n");
    } else {
        Print(L"=== HiiDataBaseNotifyPointer List Start ===\n");
        do {
            HII_DATABASE_NOTIFY *HiiDataBaseNotifyPointer = container_of(HiiDataBaseNotifyCurrentLink, HII_DATABASE_NOTIFY, DatabaseNotifyEntry);
            Print(L"Number = %04d, Address                         = 0x%08x\n", ++HiiDataBaseNotifyNumber, HiiDataBaseNotifyPointer);
            Print(  \
                    L"               Signature                       = %c %c %c %c\n", \
                    (HiiDataBaseNotifyPointer->Signature >>  0) & 0xFF, \
                    (HiiDataBaseNotifyPointer->Signature >>  8) & 0xFF, \
                    (HiiDataBaseNotifyPointer->Signature >> 16) & 0xFF, \
                    (HiiDataBaseNotifyPointer->Signature >> 24) & 0xFF  \
            );
            Print(L"               NotifyHandle                    = 0x%08x\n", HiiDataBaseNotifyPointer->NotifyHandle);
            Print(L"               PackageType                     = 0x%08x\n", HiiDataBaseNotifyPointer->PackageType);
            Print(L"               PackageGuid                     = %g\n"    , HiiDataBaseNotifyPointer->PackageGuid);
            Print(L"               PackageNotifyFn                 = 0x%08x\n", HiiDataBaseNotifyPointer->PackageNotifyFn);
            Print(L"               NotifyType                      = 0x%08x\n", HiiDataBaseNotifyPointer->NotifyType);
            Print(L"               DatabaseNotifyEntry.ForwardLink = 0x%08x\n", HiiDataBaseNotifyPointer->DatabaseNotifyEntry.ForwardLink);
            Print(L"               DatabaseNotifyEntry.BackLink    = 0x%08x\n", HiiDataBaseNotifyPointer->DatabaseNotifyEntry.BackLink);
            HiiDataBaseNotifyCurrentLink = HiiDataBaseNotifyPointer->DatabaseNotifyEntry.ForwardLink;
        } while (HiiDataBaseNotifyCurrentLink != HiiDataBaseNotifyFirstLink);
        Print(L"=== HiiDataBaseNotifyPointer List List End ===\n");
        Print(L"\n");
    }

    // HiiDataBasePrivateDataPointer->HiiHandleList <-> (HII_HANDLE)LIST_ENTRY Handle
    UINTN HiiHandleNumber = 0;
    LIST_ENTRY *HiiHandleFirstLink = &HiiDataBasePrivateDataPointer->HiiHandleList;
    LIST_ENTRY *HiiHandleCurrentLink = HiiHandleFirstLink->ForwardLink;
    if (HiiHandleCurrentLink == NULL || HiiHandleCurrentLink == HiiHandleFirstLink) {
        Print(L"=== HiiHandleList: Empty! ===\n");
        Print(L"\n");
    } else {
        Print(L"=== HiiHandlePointer List Start ===\n");
        do {
            HII_HANDLE *HiiHandlePointer = container_of(HiiHandleCurrentLink, HII_HANDLE, Handle);
            Print(L"Number = %04d, Address             = 0x%08x\n", ++HiiHandleNumber, HiiHandlePointer);
            Print(  \
                    L"               Signature          = %c %c %c %c\n", \
                    (HiiHandlePointer->Signature >>  0) & 0xFF, \
                    (HiiHandlePointer->Signature >>  8) & 0xFF, \
                    (HiiHandlePointer->Signature >> 16) & 0xFF, \
                    (HiiHandlePointer->Signature >> 24) & 0xFF  \
            );
            Print(L"               Handle.ForwardLink = 0x%08x\n", HiiHandlePointer->Handle.ForwardLink);
            Print(L"               Handle.BackLink    = 0x%08x\n", HiiHandlePointer->Handle.BackLink);
            Print(L"               Key                = 0x%08x\n", HiiHandlePointer->Key);
            HiiHandleCurrentLink = HiiHandlePointer->Handle.ForwardLink;
        } while (HiiHandleCurrentLink != HiiHandleFirstLink);
        Print(L"=== HiiHandlePointer List End ===\n");
        Print(L"\n");
    }

    // HiiDataBasePrivateDataPointer->FontInfoList <-> (HII_FONT_INFO)LIST_ENTRY GlobalEntry
    UINTN HiiFontInfoNumber = 0;
    LIST_ENTRY *HiiFontInfoFirstLink = &HiiDataBasePrivateDataPointer->FontInfoList;
    LIST_ENTRY *HiiFontInfoCurrentLink = HiiFontInfoFirstLink->ForwardLink;
    if (HiiFontInfoCurrentLink == NULL || HiiFontInfoCurrentLink == HiiFontInfoFirstLink) {
        Print(L"=== HiiFontInfoList: Empty! ===\n");
        Print(L"\n");
    } else {
        Print(L"=== HiiFontInfoPointer List Start ===\n");
        do {
            HII_FONT_INFO *HiiFontInfoPointer = container_of(HiiFontInfoCurrentLink, HII_FONT_INFO, Entry);
            Print(L"Number = %04d, Address         = 0x%08x\n", ++HiiFontInfoNumber, HiiFontInfoPointer);
            Print(  \
                    L"               Signature       = %c %c %c %c\n", \
                    (HiiFontInfoPointer->Signature >>  0) & 0xFF, \
                    (HiiFontInfoPointer->Signature >>  8) & 0xFF, \
                    (HiiFontInfoPointer->Signature >> 16) & 0xFF, \
                    (HiiFontInfoPointer->Signature >> 24) & 0xFF  \
            );
            Print(L"               Entry.ForwardLink = 0x%08x\n", HiiFontInfoPointer->Entry.ForwardLink);
            Print(L"               Entry.BackLink    = 0x%08x\n", HiiFontInfoPointer->Entry.BackLink);
            Print(L"               GlobalEntry       = 0x%08x\n", HiiFontInfoPointer->GlobalEntry);
            Print(L"               GlobalEntry       = 0x%08x\n", HiiFontInfoPointer->GlobalEntry);
            Print(L"               FontId            = 0x%08x\n", HiiFontInfoPointer->FontId);
            HiiFontInfoCurrentLink = HiiFontInfoPointer->Entry.ForwardLink;
        } while (HiiFontInfoCurrentLink != HiiFontInfoFirstLink);
        Print(L"=== HiiFontInfoPointer List End ===\n");
        Print(L"\n");
    }

    return EFI_SUCCESS;
}
