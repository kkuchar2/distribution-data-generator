cmake_minimum_required(VERSION 3.9)

project(DistributionGenerator)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11")
set(CMAKE_CXX_STANDARD 17)

find_package(cxxopts REQUIRED)
include_directories(${CXXOPTS_INCLUDE_DIR})

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(distribution-generator ${SRC_FILES} src/Distribution/Distribution.h)

target_link_libraries(distribution-generator LINK_PUBLIC ${CXXOPTS_LIBRARIES})