
# UEFI Work Space

## 1. Environment Configuration

- This part is used for environment configuration of edk2 under windows and linux

### 1.1 Windows

- Install Visual Studio and the corresponding SDK
- Check your visual studio install path and update `VS_ROOT_PATH` in the `win_build.bat`, like below:

```shell
set VS_ROOT_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community
```

- 1). Run `win_init.bat` with administrator privileges, only in the first time when you clone this repository

```shell
# set system path, download submodule and make build tool
win_init.bat
```

- 2). Run `win_build.bat` to set Environment variable

```shell
win_build.bat
```

- 3). Start your Build

### 1.2 Linux

- Run `linux_init.sh`, only in the first time when you clone this repository

```shell
# install essential tools, download submodule and make build tool
source linux_init.sh
```

- Run `linux_build.sh` to set Environment variable

```shell
source linux_build.sh
```

## 2. Folders

### 2.1 `Individual`

- This part is used to record my own learning process in docs and store some install packages, etc.

### 2.2 `Tools`

- This part is used store some essential build tools of edk2 and others debug tools.
