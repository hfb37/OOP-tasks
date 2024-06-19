cmake_minimum_required(VERSION 3.28)

project(BitArray LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_EXE main.cpp)

include_directories(./bitarray)

add_executable(bitarr ${SOURCE_EXE})

add_subdirectory(./bitarray)

enable_testing()
add_subdirectory(./tests)

target_link_libraries(bitarr BitArray)