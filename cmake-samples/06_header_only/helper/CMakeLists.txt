add_library(myhelper INTERFACE) # or SHARED

target_sources(myhelper INTERFACE
               PUBLIC FILE_SET HEADERS 
               BASE_DIRS ${PROJECT_SOURCE_DIR} # this is the project root path
               FILES util.h)