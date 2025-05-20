
# UEFI Work Space

## 1. Environment Configuration

- This part is used for environment configuration of edk2 under windows and linux

### 1.1 Windows

- 1). Run `win_init.bat` with administrator privileges in `cmd`, only in the first time when you clone this repository

```shell
# set system path, download submodule and make build tool
win_init.bat
```

- 2). Run `win_build_x86.bat` or `win_build_x64.bat` in `cmd`to set Environment variable

```shell
# if you want to build a 32-bit UEFI program, please run this script
win_build_x86.bat
# If you want to build a 64-bit UEFI program, please run this script
win_build_x64.bat
```

- 3). Start your Build

### 1.2 Linux

- 1). Run `linux_init.sh`, only in the first time when you clone this repository

```shell
# install essential tools, download submodule and make build tool
source linux_init.sh
```

- 2). Run `linux_build.sh` to set Environment variable

```shell
source linux_build.sh
```

- 3). Start your Build

## 2. Folders

### 2.1 `Individual`

- This part is used to record my own learning process in docs and store some install packages, etc.

### 2.2 `Tools`

- This part is used store some essential build tools of edk2 and others debug tools.

## 3. Help

- If you encounter this error `/usr/bin/env: 锟斤拷bash\r锟斤拷: No such file or directory` during compilation under `Linux`, please execute the following command:

```shell
find . -type f -exec dos2unix {} +
```
