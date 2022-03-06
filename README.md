# Image Viwer

## Windows

### Requirements
- [CMake](https://cmake.org/)
- [vcpkg]()
- [wxWidgets](https://wxwidgets.org/blog/2019/01/wxwidgets-and-vcpkg/)
- [Visual Studio 2019]()

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
- [wxWidgets]()


### Use
```
D:\CMake\bin\cmake.exe `
    -D 
    -D CMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
    ..
```
