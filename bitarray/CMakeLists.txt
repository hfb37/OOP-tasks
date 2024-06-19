cmake_minimum_required(VERSION 3.28)

project(bitarray)

set(SOURCE_LIB BitArray.cpp)

add_library(BitArray STATIC ${SOURCE_LIB})
