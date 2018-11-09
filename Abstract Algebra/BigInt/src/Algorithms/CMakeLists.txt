project(Algorithms)

set(HEADER_FILES Algorithms.h)

set(SOURCE_FILES Algorithms.cc)

add_library(Algorithms STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(Algorithms Console)