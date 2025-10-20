target_sources(app PRIVATE util.cpp util.h)

# This allows to set the prefix path of the headers to be included
# to the target.
# target_sources(app PRIVATE util.cpp
#                 PUBLIC FILE_SET HEADERS 
#                 BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
#                 FILES util.h)