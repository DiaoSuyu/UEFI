
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
1. update submodule
git submodule update --init --recursive
2. set environment variable to system path
run uefi-work-space\Tools\EnvConfig\WinEnvConfig.ps1 in PowerShare with administrator
3. run win_build.bat in CMD with administrator
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
