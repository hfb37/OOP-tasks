cmake_minimum_required(VERSION 3.28)

project(AddingNumbers)

set(SOURCE_LIB AddingNum.cpp)

add_library(AddingNum STATIC ${SOURCE_LIB})
