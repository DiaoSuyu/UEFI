# Debug Log of Lesson 21

## Overriding PCD via command-line argument when build .dsc(module)

```bash
build --platform=edk2/OvmfPkg/OvmfPkgX64.dsc \
      --arch=X64 \
      --buildtarget=RELEASE \
      --tagname=GCC5 \
      --pcd="gUefiLessonsPkgTokenSpaceGuid.PcdInt32Override=49"

build --platform=edk2/UefiLessonsPkg/UefiLessonsPkg.dsc \
      --arch=X64 \
      --buildtarget=RELEASE \
      --tagname=GCC5 \
      --pcd="gUefiLessonsPkgTokenSpaceGuid.PcdInt32Override=50"
```
