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

#include <../MdeModulePkg/Universal/HiiDatabaseDxe/HiiDatabase.h>


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


CHAR16*
GetType (
  IN  UINT32 Type
  ) 
{
    CHAR16 *TyptString = NULL;

    switch (Type) {
        case EFI_HII_PACKAGE_TYPE_ALL:
            TyptString = L"ALL";
            break;
        case EFI_HII_PACKAGE_TYPE_GUID:
            TyptString = L"GUID";
            break;
        case EFI_HII_PACKAGE_FORMS:
            TyptString = L"FORMS";
            break;
        case EFI_HII_PACKAGE_STRINGS:
            TyptString = L"STRINGS";
            break;
        case EFI_HII_PACKAGE_FONTS:
            TyptString = L"FONTS";
            break;
        case EFI_HII_PACKAGE_IMAGES:
            TyptString = L"IMAGES";
            break;
        case EFI_HII_PACKAGE_SIMPLE_FONTS:
            TyptString = L"SIMPLE_FONTS";
            break;
        case EFI_HII_PACKAGE_DEVICE_PATH:
            TyptString = L"DEVICE_PATH";
            break;
        case EFI_HII_PACKAGE_KEYBOARD_LAYOUT:
            TyptString = L"KEYBOARD_LAYOUT";
            break;
        case EFI_HII_PACKAGE_ANIMATIONS:
            TyptString = L"ANIMATIONS";
            break;
        case EFI_HII_PACKAGE_END:
            TyptString = L"END";
            break;
        case EFI_HII_PACKAGE_TYPE_SYSTEM_BEGIN:
            TyptString = L"TYPE_SYSTEM_BEGIN";
            break;
        case EFI_HII_PACKAGE_TYPE_SYSTEM_END:
            TyptString = L"TYPE_SYSTEM_END";
            break;
        default:
            TyptString = L"UNKNOWN";
            break;
    }

    return TyptString;
}


/*
Memory Address 0000000006608E18 200 Bytes
  06608E18: 14 46 00 72 00 65 00 6E-00 63 00 68 00 00 00 14  *.F.r.e.n.c.h....*
  06608E28: 42 00 6F 00 6E 00 6A 00-6F 00 75 00 72 00 00 00  *B.o.n.j.o.u.r...*
  06608E38: 00 AF AF AF AF AF AF AF-70 74 61 6C AF AF AF AF  *........ptal....*
  06608E48: 50 00 00 00 00 00 00 00-AF AF AF AF AF AF AF AF  *P...............*
  06608E58: AF AF AF AF AF AF AF AF-AF AF AF AF AF AF AF AF  *................*
  06608E68: AF AF AF AF AF AF AF AF-AF AF AF AF AF AF AF AF  *................*
  06608E78: AF AF AF AF AF AF AF AF-70 68 64 30 00 00 00 00  *........phd0....*
  06608E88: 04 00 00 00 00 00 00 00-60 00 00 00 00 00 00 00  *........`.......*
  06608E98: 55 00 00 04 34 00 00 00-34 00 00 00 00 00 00 00  *U...4...4.......*
  06608EA8: 00 00 00 00 00 00 00 00-00 00 00 00 00 00 00 00  *................*
  06608EB8: 00 00 00 00 00 00 00 00-00 00 00 00 01 00 66 72  *..............fr*
  06608EC8: 2D 46 52 00 AF AF AF AF-70 74 61 6C AF AF AF AF  *-FR.....ptal....*
  06608ED8: 60 00 00 00 00 00 00 00-AF AF AF AF AF AF AF AF  *`...............*
  06608EE8: AF AF AF AF AF AF AF AF-AF AF AF AF AF AF AF AF  *................*
  06608EF8: AF AF AF AF AF AF AF AF-70 68 64 30 01 00 00 00  *........phd0....*
  06608F08: 04 00 00 00 00 00 00 00-60 00 00 00 00 00 00 00  *........`.......*
  06608F18: 53 00 00 04 34 00 00 00-34 00 00 00 00 00 00 00  *S...4...4.......*
  06608F28: 00 00 00 00 00 00 00 00-00 00 00 00 00 00 00 00  *................*
  06608F38: 00 00 00 00 00 00 00 00-00 00 00 00 01 00 65 6E  *..............en*
  06608F48: 2D 55 53 00 AF AF AF AF-70 74 61 6C AF AF AF AF  *-US.....ptal....*
  06608F58: 60 00 00 00 00 00 00 00-AF AF AF AF AF AF AF AF  *`...............*
  06608F68: AF AF AF AF AF AF AF AF-AF AF AF AF AF AF AF AF  *................*
  06608F78: AF AF AF AF AF AF AF AF-70 68 64 30 00 00 00 00  *........phd0....*
  06608F88: 04 00 00 00 00 00 00 00-48 00 00 00 00 00 00 00  *........H.......*
  06608F98: 14 45 00 6E 00 67 00 6C-00 69 00 73 00 68 00 00  *.E.n.g.l.i.s.h..*
  06608FA8: 00 14 48 00 65 00 6C 00-6C 00 6F 00 00 00 00 AF  *..H.e.l.l.o.....*
  06608FB8: 70 74 61 6C AF AF AF AF-48 00 00 00 00 00 00 00  *ptal....H.......*
  06608FC8: AF AF AF AF AF AF AF AF-AF AF AF AF AF AF AF AF  *................*
  06608FD8: AF AF AF AF AF AF AF AF-AF AF AF AF AF AF AF AF  *................*
  06608FE8: AF AF AF AF AF AF AF AF-AF AF AF AF AF AF AF AF  *................*
  06608FF8: AF AF AF AF AF AF AF AF-70 68 64 30 00 00 00 00  *........phd0....*
  06609008: 04 00 00 00 00 00 00 00-40 00 00 00 00 00 00 00  *........@.......*
*/

VOID
printStringsFromPtr (
  IN UINT8  *ptr
  )
{
    if (ptr == NULL) {
        return;
    }

    UINTN stringIndex = 1;
    BOOLEAN endFlag = FALSE;

    while (*ptr && !endFlag) {
        if (*ptr == 0x14) {
            ptr++;
            for (UINTN i = 0; i < 110; i++) {
                Print(L" ");
            }
            Print(L"String %d: ", stringIndex++);
            while (1) {
                if (*ptr == 0x00 && *(ptr + 1) == 0x00) {
                    if (*(ptr + 2) == 0x00 && *(ptr + 3) == 0xAF) {
                        endFlag = TRUE;
                        break;
                    }
                    ptr += 2;
                    while (*ptr == 0x00 && *(ptr + 1) == 0x00) {
                        ptr += 2;
                    }
                    break;
                }
                if (*ptr != 0x00) {
                    Print(L"%c", *ptr);
                }
                ptr += 2;
            }
            Print(L"\n");
        } else {
            ptr++;
        }
    }
}


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
            Print(L"-------------------------------------------------------------------------------\n");
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

                    HII_GUID_PACKAGE_INSTANCE *HiiGuidPackageInstancePointer = container_of(GuidPkgHdrCurrentLink, HII_GUID_PACKAGE_INSTANCE, GuidEntry);
                    Print(  \
                        L"               HiiGuidPackageInstancePointer->Signature                 = %c %c %c %c\n", \
                        (HiiGuidPackageInstancePointer->Signature >>  0) & 0xFF, \
                        (HiiGuidPackageInstancePointer->Signature >>  8) & 0xFF, \
                        (HiiGuidPackageInstancePointer->Signature >> 16) & 0xFF, \
                        (HiiGuidPackageInstancePointer->Signature >> 24) & 0xFF  \
                    );
                    Print(L"                           HiiGuidPackageInstancePointer->GuidEntry.ForwardLink = 0x%08x\n", HiiGuidPackageInstancePointer->GuidEntry.ForwardLink);
                    Print(L"                           HiiGuidPackageInstancePointer->GuidPkg               = 0x%08x\n", HiiGuidPackageInstancePointer->GuidPkg);
                    Print(L"                           HiiGuidPackageInstancePointer->GuidEntry.BackLink    = 0x%08x\n", HiiGuidPackageInstancePointer->GuidEntry.BackLink);
                    
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

                    HII_IFR_PACKAGE_INSTANCE *HiiIfrPackageInstancePointer = container_of(FormPkgHdrCurrentLink, HII_IFR_PACKAGE_INSTANCE, IfrEntry);
                    Print(  \
                        L"                              HiiIfrPackageInstancePointer->Signature            = %c %c %c %c\n", \
                        (HiiIfrPackageInstancePointer->Signature >>  0) & 0xFF, \
                        (HiiIfrPackageInstancePointer->Signature >>  8) & 0xFF, \
                        (HiiIfrPackageInstancePointer->Signature >> 16) & 0xFF, \
                        (HiiIfrPackageInstancePointer->Signature >> 24) & 0xFF  \
                    );
                    Print(L"                              HiiIfrPackageInstancePointer->FormPkgHdr           = 0x%08x\n", HiiIfrPackageInstancePointer->FormPkgHdr);
                    Print(L"                              HiiIfrPackageInstancePointer->FormPkgHdr.Length    = 0x%08x\n", HiiIfrPackageInstancePointer->FormPkgHdr.Length);
                    Print(L"                              HiiIfrPackageInstancePointer->FormPkgHdr.Type      = 0x%08x\n", HiiIfrPackageInstancePointer->FormPkgHdr.Type);
                    // Print(L"                              HiiIfrPackageInstancePointer->FormPkgHdr.Data[]    = 0x%08x\n", );
                    Print(L"                              HiiIfrPackageInstancePointer->IfrData              = 0x%08x\n", HiiIfrPackageInstancePointer->IfrData);
                    Print(L"                              HiiIfrPackageInstancePointer->IfrEntry.ForwardLink = 0x%08x\n", HiiIfrPackageInstancePointer->IfrEntry.ForwardLink);
                    Print(L"                              HiiIfrPackageInstancePointer->IfrEntry.BackLink    = 0x%08x\n", HiiIfrPackageInstancePointer->IfrEntry.BackLink);

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
                    
                    HII_KEYBOARD_LAYOUT_PACKAGE_INSTANCE *HiiKeyboardLayoutPackageInstancePointer = container_of(KeyboardLayoutHdrCurrentLink, HII_KEYBOARD_LAYOUT_PACKAGE_INSTANCE, KeyboardEntry);
                    Print(  \
                        L"                              HiiKeyboardLayoutPackageInstancePointer->Signature                 = %c %c %c %c\n", \
                        (HiiKeyboardLayoutPackageInstancePointer->Signature >>  0) & 0xFF, \
                        (HiiKeyboardLayoutPackageInstancePointer->Signature >>  8) & 0xFF, \
                        (HiiKeyboardLayoutPackageInstancePointer->Signature >> 16) & 0xFF, \
                        (HiiKeyboardLayoutPackageInstancePointer->Signature >> 24) & 0xFF  \
                    );
                    Print(L"                              HiiKeyboardLayoutPackageInstancePointer->KeyboardPkg               = 0x%08x\n", HiiKeyboardLayoutPackageInstancePointer->KeyboardPkg);
                    Print(L"                              HiiKeyboardLayoutPackageInstancePointer->KeyboardEntry.ForwardLink = 0x%08x\n", HiiKeyboardLayoutPackageInstancePointer->KeyboardEntry.ForwardLink);
                    Print(L"                              HiiKeyboardLayoutPackageInstancePointer->KeyboardEntry.BackLink    = 0x%08x\n", HiiKeyboardLayoutPackageInstancePointer->KeyboardEntry.BackLink);

                    KeyboardLayoutHdrCurrentLink = KeyboardLayoutHdrCurrentLink->ForwardLink;
                } while (KeyboardLayoutHdrCurrentLink != KeyboardLayoutHdrFirstLink);
                Print(L"                           === KeyboardLayoutHdr List End ===\n");
            }

            UINTN HiiStringPackageInstanceNumber = 0;
            LIST_ENTRY *StringPkgHdrFirstLink = &HiiDataBasePackageListInstancePointer->StringPkgHdr;
            LIST_ENTRY *StringPkgHdrCurrentLink = StringPkgHdrFirstLink->ForwardLink;
            if (StringPkgHdrCurrentLink == NULL || StringPkgHdrCurrentLink == StringPkgHdrFirstLink) {
                Print(L"                           === StringPkgHdr List: Empty! ===\n");
            } else {
                Print(L"                           === StringPkgHdr List Start ===\n");
                do {
                    Print(L"                           Number = %04d, Address = 0x%08x\n", ++HiiStringPackageInstanceNumber, StringPkgHdrCurrentLink);
                    Print(L"                           StringPkgHdrCurrentLink.ForwardLink = 0x%08x\n", StringPkgHdrCurrentLink->ForwardLink);
                    Print(L"                           StringPkgHdrCurrentLink.BackLink    = 0x%08x\n", StringPkgHdrCurrentLink->BackLink);

                    HII_STRING_PACKAGE_INSTANCE *HiiStringPackageInstancePointer = container_of(StringPkgHdrCurrentLink, HII_STRING_PACKAGE_INSTANCE, StringEntry);
                    Print(  \
                            L"                              HiiStringPackageInstancePointer->Signature                = %c %c %c %c\n", \
                            (HiiStringPackageInstancePointer->Signature >>  0) & 0xFF, \
                            (HiiStringPackageInstancePointer->Signature >>  8) & 0xFF, \
                            (HiiStringPackageInstancePointer->Signature >> 16) & 0xFF, \
                            (HiiStringPackageInstancePointer->Signature >> 24) & 0xFF  \
                    );
                    Print(L"                              HiiStringPackageInstancePointer->StringPkgHdr             = 0x%08x\n", HiiStringPackageInstancePointer->StringPkgHdr);
                        EFI_HII_STRING_PACKAGE_HDR *HiiStringPackageHdrPointer = HiiStringPackageInstancePointer->StringPkgHdr;
                        Print(L"                                  HiiStringPackageHdrPointer->Header                          = 0x%08x\n", HiiStringPackageHdrPointer->Header);
                            EFI_HII_PACKAGE_HEADER HiiPackageHeaderPointer = HiiStringPackageHdrPointer->Header;
                            Print(L"                                      HiiPackageHeaderPointer->Length                               = 0x%08x\n", HiiPackageHeaderPointer.Length);
                            Print(L"                                      HiiPackageHeaderPointer->Type                                 = 0x%08x(%s)\n", HiiPackageHeaderPointer.Type, GetType(HiiPackageHeaderPointer.Type));
                        Print(L"                                  HiiStringPackageHdrPointer->HdrSize                         = 0x%08x\n", HiiStringPackageHdrPointer->HdrSize);
                        Print(L"                                  HiiStringPackageHdrPointer->StringInfoOffset                = 0x%08x\n", HiiStringPackageHdrPointer->StringInfoOffset);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[0]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[0]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[1]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[1]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[2]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[2]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[3]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[3]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[4]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[4]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[5]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[5]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[6]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[6]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[7]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[7]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[8]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[8]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[9]               = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[9]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[10]              = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[10]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[11]              = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[11]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[12]              = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[12]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[13]              = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[13]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[14]              = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[14]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageWindow[15]              = 0x%x\n", HiiStringPackageHdrPointer->LanguageWindow[15]);
                        Print(L"                                  HiiStringPackageHdrPointer->LanguageName                    = 0x%08x\n", HiiStringPackageHdrPointer->LanguageName);
                        Print(L"                                  HiiStringPackageHdrPointer->Language                        = 0x%08x(buffer address of Language)", HiiStringPackageHdrPointer->Language);
                                                                  for (UINTN i = 0; *(HiiStringPackageHdrPointer->Language + i) != 0x00; i++) {
                                                                      Print(L"%c", *(HiiStringPackageHdrPointer->Language + i));
                                                                  }
                                                                  Print(L"\n");
                    Print(L"                              HiiStringPackageInstancePointer->StringBlock              = 0x%08x(buffer address of Strings)\n", HiiStringPackageInstancePointer->StringBlock);
                                                          UINT8 *ptr = HiiStringPackageInstancePointer->StringBlock;
                                                          printStringsFromPtr(ptr);
                    Print(L"                              HiiStringPackageInstancePointer->StringEntry              = 0x%08x\n", HiiStringPackageInstancePointer->StringEntry);
                    Print(L"                              HiiStringPackageInstancePointer->StringEntry.ForwardLink  = 0x%08x\n", HiiStringPackageInstancePointer->StringEntry.ForwardLink);
                    Print(L"                              HiiStringPackageInstancePointer->StringEntry.BackLink     = 0x%08x\n", HiiStringPackageInstancePointer->StringEntry.BackLink);
                    Print(L"                              HiiStringPackageInstancePointer->FontInfoList             = 0x%08x\n", HiiStringPackageInstancePointer->FontInfoList);
                    Print(L"                              HiiStringPackageInstancePointer->FontInfoList.ForwardLink = 0x%08x\n", HiiStringPackageInstancePointer->FontInfoList.ForwardLink);
                    Print(L"                              HiiStringPackageInstancePointer->FontInfoList.BackLink    = 0x%08x\n", HiiStringPackageInstancePointer->FontInfoList.BackLink);
                    Print(L"                              HiiStringPackageInstancePointer->FontId                   = 0x%08x\n", HiiStringPackageInstancePointer->FontId);
                    Print(L"                              HiiStringPackageInstancePointer->MaxStringId              = %d\n",     HiiStringPackageInstancePointer->MaxStringId);


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

                    HII_FONT_PACKAGE_INSTANCE *HiiFontPackageInstancePointer = container_of(FontPkgHdrCurrentLink, HII_FONT_PACKAGE_INSTANCE, FontEntry);
                    Print(  \
                            L"                              HiiFontPackageInstancePointer->Signature                = %c %c %c %c\n", \
                            (HiiFontPackageInstancePointer->Signature >>  0) & 0xFF, \
                            (HiiFontPackageInstancePointer->Signature >>  8) & 0xFF, \
                            (HiiFontPackageInstancePointer->Signature >> 16) & 0xFF, \
                            (HiiFontPackageInstancePointer->Signature >> 24) & 0xFF  \
                    );
                    Print(L"                              HiiFontPackageInstancePointer->FontPkgHdr                = 0x%08x\n", HiiFontPackageInstancePointer->FontPkgHdr);
                    Print(L"                              HiiFontPackageInstancePointer->Height                    = 0x%08x\n", HiiFontPackageInstancePointer->Height);
                    Print(L"                              HiiFontPackageInstancePointer->BaseLine                  = 0x%08x\n", HiiFontPackageInstancePointer->BaseLine);
                    Print(L"                              HiiFontPackageInstancePointer->GlyphBlock                = 0x%08x\n", HiiFontPackageInstancePointer->GlyphBlock);
                    Print(L"                              HiiFontPackageInstancePointer->FontEntry                 = 0x%08x\n", HiiFontPackageInstancePointer->FontEntry);
                    Print(L"                              HiiFontPackageInstancePointer->FontInfoList.ForwardLink  = 0x%08x\n", HiiFontPackageInstancePointer->FontEntry.ForwardLink);
                    Print(L"                              HiiFontPackageInstancePointer->FontInfoList.BackLink     = 0x%08x\n", HiiFontPackageInstancePointer->FontEntry.BackLink);
                    Print(L"                              HiiFontPackageInstancePointer->GlyphInfoList             = 0x%08x\n", HiiFontPackageInstancePointer->GlyphInfoList);
                    Print(L"                              HiiFontPackageInstancePointer->GlyphInfoList.ForwardLink = 0x%08x\n", HiiFontPackageInstancePointer->GlyphInfoList.ForwardLink);
                    Print(L"                              HiiFontPackageInstancePointer->GlyphInfoList.BackLink    = 0x%08x\n", HiiFontPackageInstancePointer->GlyphInfoList.BackLink);

                    FontPkgHdrCurrentLink = FontPkgHdrCurrentLink->ForwardLink;
                } while (FontPkgHdrCurrentLink != FontPkgHdrFirstLink);
                Print(L"                           === FontPkgHdr List End ===\n");
            }

            Print(L"                           ImagePkg                    = 0x%08x\n", HiiDataBasePackageListInstancePointer->ImagePkg);
            if (HiiDataBasePackageListInstancePointer->ImagePkg != 0x0) {
                HII_IMAGE_PACKAGE_INSTANCE *HiiImagePackageInstancePointer  = HiiDataBasePackageListInstancePointer->ImagePkg;
                EFI_HII_IMAGE_PACKAGE_HDR HiiImagePackageHdrPointer = HiiImagePackageInstancePointer->ImagePkgHdr;
                Print(L"                                HiiImagePackageHdrPointer                       = 0x%08x\n", HiiImagePackageHdrPointer);
                Print(L"                                     HiiImagePackageHdrPointer.Header                    = 0x%08x\n", HiiImagePackageHdrPointer.Header);
                    EFI_HII_PACKAGE_HEADER HiiPackageHeaderPointer = HiiImagePackageHdrPointer.Header;
                    Print(L"                                          HiiPackageHeaderPointer->Length                      = 0x%08x\n", HiiPackageHeaderPointer.Length);
                    Print(L"                                          HiiPackageHeaderPointer->Type                        = 0x%08x(%s)\n", HiiPackageHeaderPointer.Type, GetType(HiiPackageHeaderPointer.Type));
                Print(L"                                     HiiImagePackageHdrPointer.ImageInfoOffset           = 0x%08x\n", HiiImagePackageHdrPointer.ImageInfoOffset);
                Print(L"                                     HiiImagePackageHdrPointer.PaletteInfoOffset         = 0x%08x\n", HiiImagePackageHdrPointer.PaletteInfoOffset);
                    HiiImagePackageHdrPointer = HiiImagePackageInstancePointer->ImagePkgHdr;
                Print(L"                                HiiImagePackageInstancePointer->ImageBlockSize  = 0x%08x\n", HiiImagePackageInstancePointer->ImageBlockSize);
                Print(L"                                HiiImagePackageInstancePointer->PaletteInfoSize = 0x%08x\n", HiiImagePackageInstancePointer->PaletteInfoSize);
                Print(L"                                HiiImagePackageInstancePointer->ImageBlock      = 0x%08x\n", HiiImagePackageInstancePointer->ImageBlock);
                    EFI_HII_IMAGE_BLOCK *HiiImageBlockPointer = HiiImagePackageInstancePointer->ImageBlock;
                Print(L"                                     HiiImageBlockPointer->BlockType                     = 0x%08x\n", HiiImageBlockPointer->BlockType);
                Print(L"                                HiiImagePackageInstancePointer->PaletteBlock    = 0x%08x\n", HiiImagePackageInstancePointer->PaletteBlock);
            }

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

                    HII_SIMPLE_FONT_PACKAGE_INSTANCE *HiiSimpleFontPackageInstancePointer = container_of(SimpleFontPkgHdrCurrentLink, HII_SIMPLE_FONT_PACKAGE_INSTANCE, SimpleFontEntry);
                    Print(  \
                            L"                              HiiSimpleFontPackageInstancePointer->Signature                   = %c %c %c %c\n", \
                            (HiiSimpleFontPackageInstancePointer->Signature >>  0) & 0xFF, \
                            (HiiSimpleFontPackageInstancePointer->Signature >>  8) & 0xFF, \
                            (HiiSimpleFontPackageInstancePointer->Signature >> 16) & 0xFF, \
                            (HiiSimpleFontPackageInstancePointer->Signature >> 24) & 0xFF  \
                    );
                    Print(L"                              HiiSimpleFontPackageInstancePointer->SimpleFontPkgHdr            = 0x%08x\n", HiiSimpleFontPackageInstancePointer->SimpleFontPkgHdr);
                        EFI_HII_SIMPLE_FONT_PACKAGE_HDR *HiiSimpleFontPackageHdrPointer = HiiSimpleFontPackageInstancePointer->SimpleFontPkgHdr;
                        Print(L"                              HiiSimpleFontPackageHdrPointer->Header                                  = 0x%08x\n", HiiSimpleFontPackageHdrPointer->Header);
                        EFI_HII_PACKAGE_HEADER HiiPackageHeaderPointer = HiiSimpleFontPackageHdrPointer->Header;
                        Print(L"                                   HiiPackageHeaderPointer->Length                                          = 0x%08x\n", HiiPackageHeaderPointer.Length);
                        Print(L"                                   HiiPackageHeaderPointer->Type                                            = 0x%08x(%s)\n", HiiPackageHeaderPointer.Type, GetType(HiiPackageHeaderPointer.Type));
                        Print(L"                              HiiSimpleFontPackageHdrPointer->NumberOfNarrowGlyphs                    = 0x%08x\n", HiiSimpleFontPackageHdrPointer->NumberOfNarrowGlyphs);
                        Print(L"                              HiiSimpleFontPackageHdrPointer->NumberOfWideGlyphs                      = 0x%08x\n", HiiSimpleFontPackageHdrPointer->NumberOfWideGlyphs);
                    Print(L"                              HiiSimpleFontPackageInstancePointer->SimpleFontEntry             = 0x%08x\n", HiiSimpleFontPackageInstancePointer->SimpleFontEntry);
                    Print(L"                              HiiSimpleFontPackageInstancePointer->SimpleFontEntry.ForwardLink = 0x%08x\n", HiiSimpleFontPackageInstancePointer->SimpleFontEntry.ForwardLink);
                    Print(L"                              HiiSimpleFontPackageInstancePointer->SimpleFontEntry.BackLink    = 0x%08x\n", HiiSimpleFontPackageInstancePointer->SimpleFontEntry.BackLink);

                    SimpleFontPkgHdrCurrentLink = SimpleFontPkgHdrCurrentLink->ForwardLink;
                } while (SimpleFontPkgHdrCurrentLink != SimpleFontPkgHdrFirstLink);
                Print(L"                           === SimpleFontPkgHdr List End ===\n");
            }

            Print(L"                           DevicePathPkg               = 0x%08x\n", HiiDataBasePackageListInstancePointer->DevicePathPkg);
                    if (HiiDataBasePackageListInstancePointer->DevicePathPkg != 0x0) {
                        EFI_HII_PACKAGE_HEADER *HiiPackageHeaderPointer = (EFI_HII_PACKAGE_HEADER*)HiiDataBasePackageListInstancePointer->DevicePathPkg;
                        Print(L"                                HiiPackageHeaderPointer->Length                    = 0x%08x\n", HiiPackageHeaderPointer->Length);
                        Print(L"                                HiiPackageHeaderPointer->Type                      = 0x%08x(%s)\n", HiiPackageHeaderPointer->Type, GetType(HiiPackageHeaderPointer->Type));
                    }
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
            Print(L"Number = %04d, Address            = 0x%08x\n", ++HiiHandleNumber, HiiHandlePointer);
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
