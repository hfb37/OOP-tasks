cmake_minimum_required(VERSION 3.28)

project(BigInt)

set(SOURCE_LIB BigInt.cpp)

add_library(BigInt STATIC ${SOURCE_LIB})