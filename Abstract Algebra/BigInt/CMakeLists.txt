cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)
project(BigInt_project)

set(SOURCE_FILES main.cpp src/Console/Console.cc src/Console/Console.h)
add_executable(BigInt_project_run ${SOURCE_FILES})

include_directories(src)

add_subdirectory(src)
add_subdirectory(Tests)

target_link_libraries(BigInt_project_run BigInt)
