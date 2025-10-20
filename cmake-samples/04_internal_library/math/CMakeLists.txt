add_library(mymath STATIC)  # or SHARED

target_sources(mymath PRIVATE arithmetic.cpp
               PUBLIC FILE_SET HEADERS 
               BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} # this is the math subdirectory
               FILES arithmetic.h)

install(TARGETS mymath)               