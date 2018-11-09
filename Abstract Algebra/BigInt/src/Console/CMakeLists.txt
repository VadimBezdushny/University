project(Console)

set(HEADER_FILES Console.h)
set(SOURCE_FILES Console.cc)
add_library(Console STATIC ${SOURCE_FILES})

target_link_libraries(Console Algorithms)