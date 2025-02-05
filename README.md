
# UEFI Work Space under windows and linux

- This branch is used to development of UEFI/EDK2 series under windows and linux

## Environment Variable Configuration in windows

- Install Visual Studio and the corresponding SDK
- Check your visual studio install path and update `VS_ROOT_PATH` in the `win_build.bat`, like below:

```shell
set VS_ROOT_PATH=C:\Program Files\Microsoft Visual Studio\2022\Community
```

- Check your git install path and update `GIT_ROOT_PATH` in the `win_init.bat`, like below:

```shell
set GIT_ROOT_PATH=C:\Software\Git
```

- Run `win_init.bat` with administrator privileges, only in the first time when you clone this repository

```shell
# set system path, download submodule and make build tool
win_init.bat
```

- Run `win_build.bat` to set Environment variable

```shell
win_build.bat
```

## Environment Variable Configuration under linux

- Run `linux_init.sh`, only in the first time when you clone this repository

```shell
# install essential tools, download submodule and make build tool
source linux_init.sh
```

- Run `linux_build.sh` to set Environment variable

```shell
source linux_build.sh
```
