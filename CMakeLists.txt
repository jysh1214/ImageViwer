CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

PROJECT(ImageViwer C CXX)

SET(CMAKE_C_STANDARD 99)
SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

IF(MSVC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:AVX2")
ENDIF()

IF(MSVC)
    # Use windows application instead of console one.
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
ENDIF()

FIND_PACKAGE(wxWidgets REQUIRED)
INCLUDE(${wxWidgets_USE_FILE})

# Find threads.
SET(CMAKE_THREAD_PREFER_PTHREAD ON)
FIND_PACKAGE(Threads REQUIRED)

# Include config.
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/include")

ADD_SUBDIRECTORY(src)
# ADD_SUBDIRECTORY(lib)

