project(BigInt)

set(HEADER_FILES BigInt.h)

set(SOURCE_FILES BigInt.cpp)

add_library(BigInt STATIC ${SOURCE_FILES} ${HEADER_FILES})
