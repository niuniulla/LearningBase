add_library(mymath INTERFACE)  # or SHARED

target_sources(mymath INTERFACE
               PUBLIC FILE_SET HEADERS 
               BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} # this is the math subdirectory
               FILES arithmetic.h)