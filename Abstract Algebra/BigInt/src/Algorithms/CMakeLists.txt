project(Algorithms)

set(HEADER_FILES Algorithms.h ElipticCurve.h ElipticCurveNumber.h)

set(SOURCE_FILES Algorithms.cc ElipticCurveNumber.cc)

add_library(Algorithms STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(Algorithms Console)