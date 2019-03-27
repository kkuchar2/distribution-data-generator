cmake_minimum_required(VERSION 3.9)

project(DDGenerator)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
set(SOURCE_FILES ${SRC_FILES})

add_executable(ddgenerator ${SOURCE_FILES})
