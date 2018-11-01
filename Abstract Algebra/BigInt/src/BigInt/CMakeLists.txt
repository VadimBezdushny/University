project(BigInt)

set(HEADER_FILES BigInt.h)

set(SOURCE_FILES BigInt.cpp BigUint.cc BigUint.h)

add_library(BigInt STATIC ${SOURCE_FILES} ${HEADER_FILES})
