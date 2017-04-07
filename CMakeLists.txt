cmake_minimum_required(VERSION 3.6)
project(ZMPODateTime)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DateTime.cpp DateTime.h DateConstants.h)
add_executable(ZMPODateTime ${SOURCE_FILES})