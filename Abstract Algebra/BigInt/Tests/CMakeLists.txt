project(BigIntTests)

add_subdirectory(lib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)

add_executable(runBigIntTests InitTests.cpp ArithmeticTests.cpp AlgoTests.cc)

target_link_libraries(runBigIntTests BigInt Algorithms)
target_link_libraries(runBigIntTests gtest gtest_main)


