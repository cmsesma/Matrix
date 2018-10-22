cmake_minimum_required(VERSION 3.8)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)
set(GPP_ENABLE_WARNINGS "-O0 -Wall -Werror -Wno-unused-result")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPP_ENABLE_WARNINGS}")

set(SOURCE_FILES main.cpp ColElementItr.cpp ColElementItr.h ColItr.cpp ColItr.h Matrix.cpp Matrix.h MatrixError.cpp MatrixError.h MatrixInnerDimensionMism.cpp MatrixInnerDimensionMism.h MatrixSizeError.cpp MatrixSizeError.h MatrixSizeMismatchError.cpp MatrixSizeMismatchError.h RowElementItr.cpp RowElementItr.h RowItr.cpp RowItr.h)
add_executable(Matrix ${SOURCE_FILES})