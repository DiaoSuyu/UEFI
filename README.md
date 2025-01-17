
# UEFI Work Space under windows and linux

- This branch is used to development of UEFI/EDK2 series under windows and linux

## Environment Variable Configuration in windows

- Install Visual Studio and the corresponding SDK
- Check your visual studio install path and update `VS_ROOT_PATH` in the `win_build.bat`, like below:

```shell
set VS_ROOT_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community
```

- Run the following steps of command to finish the configuration

```shell
# 1. update submodule in root path and edk2
cd UEFI: git submodule update --init
cd edk2: git submodule update --init
# 2. set environment variable to system path(in PowerShell with administrator)
./uefi-work-space/Tools/EnvConfig/WinEnvConfig.ps1
# 3. set build variable(in CMD/PowerShell)
./win_build.bat
```

## Environment Variable Configuration under linux

- Run linux_init.sh, only in the first time when you clone this repository

```shell
# download source and make build tool
source linux_init.sh
```

- Run linux_build.sh to set Environment variable

```shell
source linux_build.sh
```
