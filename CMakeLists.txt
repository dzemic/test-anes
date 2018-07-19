# Specify the minimum version for CMake

# Sanity check
IF(COMMAND CMAKE_MINIMUM_REQUIRED)
  CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4)
ENDIF(COMMAND CMAKE_MINIMUM_REQUIRED)

INCLUDE(StripFile.cmake)

SET(PROGRAM_NAME testtest)

# Default build type is "PRODUCTIONRELEASE"
# Supported CMAKE_BUILD_TYPEs are "DEBUG", "RELEASE", "DEVELOPERRELEASE", and "PRODUCTIONRELEASE".

#IF(DEFINED ENV{CMAKE_BUILD_TYPE})
#     MESSAGE("...CMAKE_BUILD_TYPE is defined -> ${CMAKE_BUILD_TYPE}")
#ELSE(DEFINED ENV{CMAKE_BUILD_TYPE})
#    # optimized code with debug symbols
#    MESSAGE("ups...CMAKE_BUILD_TYPE not defined - > Use RelWithDebInfo")
#    SET(CMAKE_BUILD_TYPE "RelWithDebInfo")
#ENDIF(DEFINED ENV{CMAKE_BUILD_TYPE})

MESSAGE("INFO - BUILD TYPE IS : ${CMAKE_BUILD_TYPE}")

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set (CMAKE_CXX_STANDARD 11)


# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
#include_directories("${PROJECT_SOURCE_DIR}")
MESSAGE("INFO - MY default directory : ${PROJECT_SOURCE_DIR}")

#include_directories("${PROJECT_SOURCE_DIR}/src/include")
# Include directories
INCLUDE_DIRECTORIES(
  ${PROJECT_SOURCE_DIR}/src/common
  ${PROJECT_SOURCE_DIR}
)

# Set the source files
FILE(GLOB ${PROGRAM_NAME}_SOURCE_FILES src/*.c src/*.cpp src/include/*.c src/include/*.cpp src/common/*.hpp)

# Create the executable (object)
ADD_EXECUTABLE(${PROGRAM_NAME}
  ${${PROGRAM_NAME}_SOURCE_FILES}
)

StripFile(${PROGRAM_NAME} "${PROJECT_SOURCE_DIR}/bin/")
