cmake_minimum_required(VERSION 3.24)
project(sechw)

set(CMAKE_CXX_STANDARD 20)

add_executable(sechw main.cpp MyMatrix.cpp MyMatrix.h Course.cpp Course.h Student.cpp Student.h)
