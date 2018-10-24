cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project(BigInt_project)

set(SOURCE_FILES main.cpp)
add_executable(BigInt_project_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(Tests)

target_link_libraries(BigInt_project_run BigInt)

#add_subdirectory(lib/googletest)
#include_directories(lib/googletest/googletest/include)
#include_directories(lib/googletest/googlemock/include)
#
#
#
#add_executable(BigIntTests Tests/BigIntTests.cpp)
#add_executable(BigInt main.cpp src/BigInt.cpp src/BigInt.h)
#target_link_libraries(BigIntTests gtest gtest_main)
#target_link_libraries(BigIntTests BigInt)
