cmake_minimum_required(VERSION 4.5.0)

project(Compressor-LZ78 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Compressor
    src/main.cpp
    src/LZ78.cpp
    src/Str_dicio.cpp
)

target_include_directories(Compressor PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)