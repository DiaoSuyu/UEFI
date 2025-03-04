# Build Instructions

**Build the UefiLessonsPkg package:**

   ```sh
   build -p edk2/UefiLessonsPkg/UefiLessonsPkg.dsc -t GCC5 -a X64 -b RELEASE
   build -p edk2/UefiLessonsPkg/UefiLessonsPkg.dsc -t VS2022 -a X64 -b RELEASE
   ```
