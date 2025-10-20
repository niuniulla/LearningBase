add_library(myhelper SHARED) # or STATIC

target_sources(myhelper PRIVATE util.cpp
               PUBLIC FILE_SET HEADERS 
               BASE_DIRS ${PROJECT_SOURCE_DIR} # this is the project root path
               FILES util.h)

install(TARGETS myhelper FILE_SET HEADERS)