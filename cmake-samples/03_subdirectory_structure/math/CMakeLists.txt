target_sources(app PRIVATE arithmetic.cpp arithmetic.h)
set(QINGYI "Qingyi" CACHE STRING "me")
# This allows to set the prefix path of the headers to be included
# to the target.
# target_sources(app PRIVATE arithmetic.cpp
#                 PUBLIC FILE_SET HEADERS 
#                 BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
#                 FILES arithmetic.h)