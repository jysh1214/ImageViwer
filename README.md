# Image Viwer

## Windows

### Requirements
- [CMake](https://cmake.org/)
- [vcpkg](https://github.com/microsoft/vcpkg)
- [wxWidgets](https://wxwidgets.org/blog/2019/01/wxwidgets-and-vcpkg/)
- [Visual Studio 2019](https://docs.microsoft.com/en-us/visualstudio/releases/2019/release-notes)

### Build(with CMake)
```
cmake `
    -G "Visual Studio 16 2019" `
    -A x64 `
    -D CMAKE_TOOLCHAIN_FILE=path/to/vcpkg/scripts/buildsystems/vcpkg.cmake `
    ..
```

## Linux

### Requirements
- [CMake](https://cmake.org/)
- [wxWidgets](https://www.wxwidgets.org/)

