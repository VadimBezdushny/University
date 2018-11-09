project(BigInt)

set(HEADER_FILES BigInt.h BigUint.h)

set(SOURCE_FILES BigInt.cpp BigUint.cc)

add_library(BigInt STATIC ${SOURCE_FILES} ${HEADER_FILES})
