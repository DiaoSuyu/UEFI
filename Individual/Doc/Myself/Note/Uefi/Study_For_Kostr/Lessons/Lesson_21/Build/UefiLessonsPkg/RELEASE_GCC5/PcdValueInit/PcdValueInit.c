
/**
  DO NOT EDIT
  FILE auto-generated
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <PcdValueCommon.h>
#include <CustomPcdTypes.h>

static CustomStruct gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_INIT_Value = 
    {
      0x11,
      {0x22334455, 0x66778899},
      {
        {0xf1740707, 0x691d, 0x4203, {0xbf, 0xab, 0x99, 0xe1, 0x32, 0xfa, 0x41, 0x66}},
        {0x0048, 0x0065, 0x006c, 0x006c, 0x006f, 0x0000}
      },
      {{0x1, 0x7, 0xF}}
    }
   ;
static UINT32 gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_INIT_Value[] = {0x11223344, 0x55667788, 0x99aabbcc};
// Default Value in Dec 
void Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_Size(UINT32 *Size){
  *Size = (sizeof (UINT8[12]) > *Size ? sizeof (UINT8[12]) : *Size);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  *Size = (3 > *Size ? 3 : *Size); // The Pcd maxsize is 3 
}
// Default value in Dec 
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_Default_Value(UINT8 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
__STATIC_ASSERT(3 <= 12 * sizeof(UINT8), "Pcd gUefiLessonsPkgTokenSpaceGuid.PcdArrayWithFixedSize Value in Dec exceed the array capability UINT8[12]"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 108 
 PcdArraySize = 3;
  Value     = "\x01\x02\x03"; // From DEC Default Value {0x01, 0x02, 0x03}
  memcpy (Pcd, Value, PcdArraySize);
}
// Value in Fdf
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_Fdf_Value(UINT8 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in CommandLine
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_CommandLine_Value(UINT8 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in Dsc for Sku: DEFAULT, DefaultStore STANDARD
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_DEFAULT_STANDARD_Value(UINT8 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
}
// Value in Dsc Module scope 
void
Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize(
  void
  )
{
  UINT32  Size;
  UINT32  FieldSize;
  CHAR8   *Value;
  UINT32  OriginalSize;
  VOID    *OriginalPcd;
  UINT8      *Pcd;  // From UefiLessonsPkg/UefiLessonsPkg.dec Line 108 

  OriginalPcd = PcdGetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize, &OriginalSize);
  Size = sizeof(UINT8[12]);
  Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_Size(&Size);
  OriginalSize = OriginalSize < sizeof(UINT8) * 12? OriginalSize:sizeof(UINT8) * 12; 
  Size = sizeof(UINT8) * 12; 
  Size = (OriginalSize > Size ? OriginalSize : Size);
  Pcd     = (UINT8 *)malloc (Size);
  memset (Pcd, 0, Size);
  memcpy (Pcd, OriginalPcd, OriginalSize);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_Default_Value(Pcd);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_DEFAULT_STANDARD_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_Fdf_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_CommandLine_Value(Pcd);
  PcdSetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize, Size, (void *)Pcd);
  free (Pcd);
}

// Default Value in Dec 
void Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_Size(UINT32 *Size){
  *Size = (sizeof (UINT32[3]) > *Size ? sizeof (UINT32[3]) : *Size);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  *Size = (2 > *Size ? 2 : *Size); // The Pcd maxsize is 2 
}
// Default value in Dec 
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_Default_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
__STATIC_ASSERT(2 <= 3 * sizeof(UINT32), "Pcd gUefiLessonsPkgTokenSpaceGuid.PcdArrayWithFixedSize_1 Value in Dec exceed the array capability UINT32[3]"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 110 
 PcdArraySize = 2;
  Value     = "\x11\x12"; // From DEC Default Value {0x11, 0x12}
  memcpy (Pcd, Value, PcdArraySize);
}
// Value in Fdf
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_Fdf_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in CommandLine
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_CommandLine_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in Dsc for Sku: DEFAULT, DefaultStore STANDARD
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_DEFAULT_STANDARD_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
}
// Value in Dsc Module scope 
void
Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1(
  void
  )
{
  UINT32  Size;
  UINT32  FieldSize;
  CHAR8   *Value;
  UINT32  OriginalSize;
  VOID    *OriginalPcd;
  UINT32      *Pcd;  // From UefiLessonsPkg/UefiLessonsPkg.dec Line 110 

  OriginalPcd = PcdGetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize_1, &OriginalSize);
  Size = sizeof(UINT32[3]);
  Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_Size(&Size);
  OriginalSize = OriginalSize < sizeof(UINT32) * 3? OriginalSize:sizeof(UINT32) * 3; 
  Size = sizeof(UINT32) * 3; 
  Size = (OriginalSize > Size ? OriginalSize : Size);
  Pcd     = (UINT32 *)malloc (Size);
  memset (Pcd, 0, Size);
  memcpy (Pcd, OriginalPcd, OriginalSize);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_Default_Value(Pcd);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_DEFAULT_STANDARD_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_Fdf_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1_CommandLine_Value(Pcd);
  PcdSetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize_1, Size, (void *)Pcd);
  free (Pcd);
}

// Default Value in Dec 
void Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_Size(UINT32 *Size){
  *Size = (sizeof (UINT32[3]) > *Size ? sizeof (UINT32[3]) : *Size);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  *Size = (12 > *Size ? 12 : *Size); // The Pcd maxsize is 12 
}
// Default value in Dec 
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_Default_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
__STATIC_ASSERT(12 <= 3 * sizeof(UINT32), "Pcd gUefiLessonsPkgTokenSpaceGuid.PcdArrayWithFixedSize_2 Value in Dec exceed the array capability UINT32[3]"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 112 
 PcdArraySize = 12;
  Value     = "\x44\x33\x22\x11\x88\x77\x66\x55\xcc\xbb\xaa\x99"; // From DEC Default Value {0x44, 0x33, 0x22, 0x11, 0x88, 0x77, 0x66, 0x55, 0xCC, 0xBB, 0xAA, 0x99}
  memcpy (Pcd, Value, PcdArraySize);
}
// Value in Fdf
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_Fdf_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in CommandLine
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_CommandLine_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in Dsc for Sku: DEFAULT, DefaultStore STANDARD
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_DEFAULT_STANDARD_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
}
// Value in Dsc Module scope 
void
Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2(
  void
  )
{
  UINT32  Size;
  UINT32  FieldSize;
  CHAR8   *Value;
  UINT32  OriginalSize;
  VOID    *OriginalPcd;
  UINT32      *Pcd;  // From UefiLessonsPkg/UefiLessonsPkg.dec Line 112 

  OriginalPcd = PcdGetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize_2, &OriginalSize);
  Size = sizeof(UINT32[3]);
  Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_Size(&Size);
  OriginalSize = OriginalSize < sizeof(UINT32) * 3? OriginalSize:sizeof(UINT32) * 3; 
  Size = sizeof(UINT32) * 3; 
  Size = (OriginalSize > Size ? OriginalSize : Size);
  Pcd     = (UINT32 *)malloc (Size);
  memset (Pcd, 0, Size);
  memcpy (Pcd, OriginalPcd, OriginalSize);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_Default_Value(Pcd);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_DEFAULT_STANDARD_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_Fdf_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2_CommandLine_Value(Pcd);
  PcdSetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize_2, Size, (void *)Pcd);
  free (Pcd);
}

// Default Value in Dec 
void Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_Size(UINT32 *Size){
  *Size = (sizeof (UINT32[3]) > *Size ? sizeof (UINT32[3]) : *Size);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  *Size = (3 > *Size ? 3 : *Size); // The Pcd maxsize is 3 
}
// Default value in Dec 
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_Default_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
__STATIC_ASSERT(sizeof(gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_INIT_Value) <= 3 * sizeof(UINT32), "Pcd gUefiLessonsPkgTokenSpaceGuid.PcdArrayWithFixedSize_3 Value in Dec exceed the array capability UINT32[3]"); // From  UefiLessonsPkg/UefiLessonsPkg.dec Line 114 
  PcdArraySize = sizeof(gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_INIT_Value);
   memcpy (Pcd, gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_INIT_Value,PcdArraySize);
 }
// Value in Fdf
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_Fdf_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in CommandLine
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_CommandLine_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in Dsc for Sku: DEFAULT, DefaultStore STANDARD
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_DEFAULT_STANDARD_Value(UINT32 *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
}
// Value in Dsc Module scope 
void
Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3(
  void
  )
{
  UINT32  Size;
  UINT32  FieldSize;
  CHAR8   *Value;
  UINT32  OriginalSize;
  VOID    *OriginalPcd;
  UINT32      *Pcd;  // From UefiLessonsPkg/UefiLessonsPkg.dec Line 114 

  OriginalPcd = PcdGetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize_3, &OriginalSize);
  Size = sizeof(UINT32[3]);
  Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_Size(&Size);
  OriginalSize = OriginalSize < sizeof(UINT32) * 3? OriginalSize:sizeof(UINT32) * 3; 
  Size = sizeof(UINT32) * 3; 
  Size = (OriginalSize > Size ? OriginalSize : Size);
  Pcd     = (UINT32 *)malloc (Size);
  memset (Pcd, 0, Size);
  memcpy (Pcd, OriginalPcd, OriginalSize);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_Default_Value(Pcd);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_DEFAULT_STANDARD_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_Fdf_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3_CommandLine_Value(Pcd);
  PcdSetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize_3, Size, (void *)Pcd);
  free (Pcd);
}

// Default Value in Dec 
void Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_Size(UINT32 *Size){
  *Size = (sizeof (CustomStruct[2]) > *Size ? sizeof (CustomStruct[2]) : *Size);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  *Size = (1 > *Size ? 1 : *Size); // The Pcd maxsize is 1 
}
// Default value in Dec 
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_Default_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
__STATIC_ASSERT(1 <= 2 * sizeof(CustomStruct), "Pcd gUefiLessonsPkgTokenSpaceGuid.PcdArrayWithFixedSize_4 Value in Dec exceed the array capability CustomStruct[2]"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 118 
 PcdArraySize = 1;
  Value     = "\x00"; // From DEC Default Value {0x0}
  memcpy (Pcd, Value, PcdArraySize);
}
// Value in Fdf
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_Fdf_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in CommandLine
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_CommandLine_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in Dsc for Sku: DEFAULT, DefaultStore STANDARD
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_DEFAULT_STANDARD_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
}
// Value in Dsc Module scope 
void
Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4(
  void
  )
{
  UINT32  Size;
  UINT32  FieldSize;
  CHAR8   *Value;
  UINT32  OriginalSize;
  VOID    *OriginalPcd;
  CustomStruct      *Pcd;  // From UefiLessonsPkg/UefiLessonsPkg.dec Line 118 

  OriginalPcd = PcdGetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize_4, &OriginalSize);
  Size = sizeof(CustomStruct[2]);
  Cal_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_Size(&Size);
  OriginalSize = OriginalSize < sizeof(CustomStruct) * 2? OriginalSize:sizeof(CustomStruct) * 2; 
  Size = sizeof(CustomStruct) * 2; 
  Size = (OriginalSize > Size ? OriginalSize : Size);
  Pcd     = (CustomStruct *)malloc (Size);
  memset (Pcd, 0, Size);
  memcpy (Pcd, OriginalPcd, OriginalSize);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_Default_Value(Pcd);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_DEFAULT_STANDARD_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_Fdf_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4_CommandLine_Value(Pcd);
  PcdSetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdArrayWithFixedSize_4, Size, (void *)Pcd);
  free (Pcd);
}

// Default Value in Dec 
void Cal_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_Size(UINT32 *Size){
  __FLEXIBLE_SIZE(*Size, CustomStruct, Val32, 1); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 79 Value 0x22334455
  __FLEXIBLE_SIZE(*Size, CustomStruct, Val32, 2); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 80 Value 0x66778899
  __FLEXIBLE_SIZE(*Size, CustomStruct, ValStruct.Name, 10 / __ARRAY_ELEMENT_SIZE(CustomStruct, ValStruct.Name) + ((10 % __ARRAY_ELEMENT_SIZE(CustomStruct, ValStruct.Name)) ? 1 : 0));  // From UefiLessonsPkg/UefiLessonsPkg.dec Line 82 Value L'Hello' 
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  __FLEXIBLE_SIZE(*Size, CustomStruct, Val32, 1); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 79 Value 0x22334455 
  __FLEXIBLE_SIZE(*Size, CustomStruct, Val32, 2); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 80 Value 0x66778899 
  __FLEXIBLE_SIZE(*Size, CustomStruct, ValStruct.Name, 10 / __ARRAY_ELEMENT_SIZE(CustomStruct, ValStruct.Name) + ((10 % __ARRAY_ELEMENT_SIZE(CustomStruct, ValStruct.Name)) ? 1 : 0)); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 82 Value L'Hello'
  *Size = (1 > *Size ? 1 : *Size); // The Pcd maxsize is 1 
}
// Default value in Dec 
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_Default_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
  Value     = "\x00"; // From DEC Default Value {0x00}
  memcpy (Pcd, Value, 1);
  Pcd->Val8 = 17; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 78 Value 0x11
  __STATIC_ASSERT((0 < __ARRAY_SIZE(Pcd->Val32)) || (__ARRAY_SIZE(Pcd->Val32) == 0), "array index exceeds the array number"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 79 Index of Val32[0]
  Pcd->Val32[0] = 573785173; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 79 Value 0x22334455
  __STATIC_ASSERT((1 < __ARRAY_SIZE(Pcd->Val32)) || (__ARRAY_SIZE(Pcd->Val32) == 0), "array index exceeds the array number"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 80 Index of Val32[1]
  Pcd->Val32[1] = 1719109785; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 80 Value 0x66778899
  FieldSize = __FIELD_SIZE(CustomStruct, ValStruct.Guid);
  Value     = "\x07\x07\x74\xf1\x1d\x69\x03\x42\xbf\xab\x99\xe1\x32\xfa\x41\x66"; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 81 Value {0x07, 0x07, 0x74, 0xF1, 0x1D, 0x69, 0x03, 0x42, 0xBF, 0xAB, 0x99, 0xE1, 0x32, 0xFA, 0x41, 0x66}
  __STATIC_ASSERT((__FIELD_SIZE(CustomStruct, ValStruct.Guid) >= 16) || (__FIELD_SIZE(CustomStruct, ValStruct.Guid) == 0), "Input buffer exceeds the buffer array"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 81 Value {0x07, 0x07, 0x74, 0xF1, 0x1D, 0x69, 0x03, 0x42, 0xBF, 0xAB, 0x99, 0xE1, 0x32, 0xFA, 0x41, 0x66}
  memcpy (&Pcd->ValStruct.Guid, Value, (FieldSize > 0 && FieldSize < 16) ? FieldSize : 16);
  FieldSize = __FIELD_SIZE(CustomStruct, ValStruct.Name);
  Value     = "\x48\x00\x65\x00\x6c\x00\x6c\x00\x6f\x00"; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 82 Value {0x48,0x00,0x65,0x00,0x6C,0x00,0x6C,0x00,0x6F,0x00}
  __STATIC_ASSERT((__FIELD_SIZE(CustomStruct, ValStruct.Name) >= 10) || (__FIELD_SIZE(CustomStruct, ValStruct.Name) == 0), "Input buffer exceeds the buffer array"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 82 Value {0x48,0x00,0x65,0x00,0x6C,0x00,0x6C,0x00,0x6F,0x00}
  memcpy (&Pcd->ValStruct.Name, Value, (FieldSize > 0 && FieldSize < 10) ? FieldSize : 10);
  Pcd->ValUnion.BitFields.Field1 = 1; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 83 Value 0x1
  Pcd->ValUnion.BitFields.Field2 = 7; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 84 Value 0x7
  Pcd->ValUnion.BitFields.Field3 = 15; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 85 Value 0xF
}
// Value in Fdf
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_Fdf_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in CommandLine
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_CommandLine_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in Dsc for Sku: DEFAULT, DefaultStore STANDARD
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_DEFAULT_STANDARD_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  Pcd->Val8 = 17; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 78 Value 0x11
  __STATIC_ASSERT((0 < __ARRAY_SIZE(Pcd->Val32)) || (__ARRAY_SIZE(Pcd->Val32) == 0), "array index exceeds the array number"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 79 Index of Val32[0]
  Pcd->Val32[0] = 573785173; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 79 Value 0x22334455
  __STATIC_ASSERT((1 < __ARRAY_SIZE(Pcd->Val32)) || (__ARRAY_SIZE(Pcd->Val32) == 0), "array index exceeds the array number"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 80 Index of Val32[1]
  Pcd->Val32[1] = 1719109785; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 80 Value 0x66778899
  FieldSize = __FIELD_SIZE(CustomStruct, ValStruct.Guid);
  Value     = "\x07\x07\x74\xf1\x1d\x69\x03\x42\xbf\xab\x99\xe1\x32\xfa\x41\x66"; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 81 Value {0x07, 0x07, 0x74, 0xF1, 0x1D, 0x69, 0x03, 0x42, 0xBF, 0xAB, 0x99, 0xE1, 0x32, 0xFA, 0x41, 0x66}
  __STATIC_ASSERT((__FIELD_SIZE(CustomStruct, ValStruct.Guid) >= 16) || (__FIELD_SIZE(CustomStruct, ValStruct.Guid) == 0), "Input buffer exceeds the buffer array"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 81 Value {0x07, 0x07, 0x74, 0xF1, 0x1D, 0x69, 0x03, 0x42, 0xBF, 0xAB, 0x99, 0xE1, 0x32, 0xFA, 0x41, 0x66}
  memcpy (&Pcd->ValStruct.Guid, Value, (FieldSize > 0 && FieldSize < 16) ? FieldSize : 16);
  FieldSize = __FIELD_SIZE(CustomStruct, ValStruct.Name);
  Value     = "\x48\x00\x65\x00\x6c\x00\x6c\x00\x6f\x00"; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 82 Value {0x48,0x00,0x65,0x00,0x6C,0x00,0x6C,0x00,0x6F,0x00}
  __STATIC_ASSERT((__FIELD_SIZE(CustomStruct, ValStruct.Name) >= 10) || (__FIELD_SIZE(CustomStruct, ValStruct.Name) == 0), "Input buffer exceeds the buffer array"); // From UefiLessonsPkg/UefiLessonsPkg.dec Line 82 Value {0x48,0x00,0x65,0x00,0x6C,0x00,0x6C,0x00,0x6F,0x00}
  memcpy (&Pcd->ValStruct.Name, Value, (FieldSize > 0 && FieldSize < 10) ? FieldSize : 10);
  Pcd->ValUnion.BitFields.Field1 = 1; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 83 Value 0x1
  Pcd->ValUnion.BitFields.Field2 = 7; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 84 Value 0x7
  Pcd->ValUnion.BitFields.Field3 = 15; // From UefiLessonsPkg/UefiLessonsPkg.dec Line 85 Value 0xF
}
// Value in Dsc Module scope 
void
Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1(
  void
  )
{
  UINT32  Size;
  UINT32  FieldSize;
  CHAR8   *Value;
  UINT32  OriginalSize;
  VOID    *OriginalPcd;
  CustomStruct      *Pcd;  // From UefiLessonsPkg/UefiLessonsPkg.dec Line 72 

  OriginalPcd = PcdGetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdCustomStruct_Type1, &OriginalSize);
  Size = sizeof(CustomStruct);
  Cal_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_Size(&Size);
  Size = (OriginalSize > Size ? OriginalSize : Size);
  Pcd     = (CustomStruct *)malloc (Size);
  memset (Pcd, 0, Size);
  memcpy (Pcd, OriginalPcd, OriginalSize);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_Default_Value(Pcd);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_DEFAULT_STANDARD_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_Fdf_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1_CommandLine_Value(Pcd);
  PcdSetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdCustomStruct_Type1, Size, (void *)Pcd);
  free (Pcd);
}

// Default Value in Dec 
void Cal_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_Size(UINT32 *Size){
  *Size = (sizeof (gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_INIT_Value) > *Size ? sizeof (gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_INIT_Value) : *Size);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  *Size = (23 > *Size ? 23 : *Size); // The Pcd maxsize is 23 
}
// Default value in Dec 
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_Default_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
  PcdArraySize = sizeof(gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_INIT_Value);
   memcpy (Pcd, &gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_INIT_Value,PcdArraySize);
 }
// Value in Fdf
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_Fdf_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in CommandLine
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_CommandLine_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
}
// Value in Dsc for Sku: DEFAULT, DefaultStore STANDARD
void Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_DEFAULT_STANDARD_Value(CustomStruct *Pcd){
  UINT32  FieldSize;
  CHAR8   *Value;
 UINT32 PcdArraySize;
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
}
// Value in Dsc Module scope 
void
Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2(
  void
  )
{
  UINT32  Size;
  UINT32  FieldSize;
  CHAR8   *Value;
  UINT32  OriginalSize;
  VOID    *OriginalPcd;
  CustomStruct      *Pcd;  // From UefiLessonsPkg/UefiLessonsPkg.dec Line 89 

  OriginalPcd = PcdGetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdCustomStruct_Type2, &OriginalSize);
  Size = sizeof(CustomStruct);
  Cal_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_Size(&Size);
  Size = (OriginalSize > Size ? OriginalSize : Size);
  Pcd     = (CustomStruct *)malloc (Size);
  memset (Pcd, 0, Size);
  memcpy (Pcd, OriginalPcd, OriginalSize);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_Default_Value(Pcd);
// SkuName: DEFAULT,  DefaultStoreName: STANDARD 
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_DEFAULT_STANDARD_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_Fdf_Value(Pcd);
  Assign_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2_CommandLine_Value(Pcd);
  PcdSetPtr (DEFAULT, STANDARD, gUefiLessonsPkgTokenSpaceGuid, PcdCustomStruct_Type2, Size, (void *)Pcd);
  free (Pcd);
}

VOID
PcdEntryPoint(
  VOID
  )
{
  Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type1();
  Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdCustomStruct_Type2();
  Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize();
  Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_1();
  Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_2();
  Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_3();
  Initialize_DEFAULT_STANDARD_gUefiLessonsPkgTokenSpaceGuid_PcdArrayWithFixedSize_4();
}

int
main (
  int   argc,
  char  *argv[]
  )
{
  return PcdValueMain (argc, argv);
}

