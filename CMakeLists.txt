cmake_minimum_required(VERSION 3.9)

project(DDGenerator)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

file(GLOB_RECURSE SRC_FILES src/*.cpp)
set(SOURCE_FILES ${SRC_FILES} src/TreeNode.h)

add_executable(ddgenerator ${SOURCE_FILES})

target_link_libraries(ddgenerator LINK_PUBLIC ${Boost_LIBRARIES})