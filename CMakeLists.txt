cmake_minimum_required(VERSION 3.28)

project(task2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(SOURCE_EXE main.cpp)

include_directories(./AddingNumbers)
include_directories(./BigInt)

add_executable(adding ${SOURCE_EXE})

add_subdirectory(./AddingNumbers)
add_subdirectory(./BigInt)

enable_testing()
add_subdirectory(./tests)

target_link_libraries(adding AddingNum)
target_link_libraries(adding BigInt)