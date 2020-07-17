##  
##  @file       CMakeLists.txt
##  @brief      Set of instructions describing this project's sources/targets
##
##  @author     Gemuele Aludino
##  @date       28 Jun 2020
##

###########################################################################
##                                                                       ##
##  How to define a variable:                                            ##
##                                                                       ##
##  For a variable VAR_NAME,                                             ##
##  that is to have the value 'desired_value':                           ##
##                                                                       ##
##      set(VAR_NAME desired_value)                                      ##
##                                                                       ##
##  To use VAR_NAME as part of an argument,                              ##
##  such as in another variable's name or value,                         ##
##  you may do this (for a variable OTHER_NAME):                         ##
##                                                                       ##
##      set(OTHER_NAME, ${VAR_NAME}/the_other_part)                      ##
##                                                                       ##
###########################################################################

###########################################################################
##  Variables                                                            ##
###########################################################################

## --------------------------------------------------------------------- ##
## CMake version number, C++ version number
## --------------------------------------------------------------------- ##

set(CMAKE_VERSION_NUMBER "3.8")
set(CXX_STD "17")

## --------------------------------------------------------------------- ##
## Title for this project
## --------------------------------------------------------------------- ##

set(PROJECT_TITLE "gcs_graph")

## --------------------------------------------------------------------- ##
## Top-level directory (folder) names
## (be sure to prefix ${DIR_*} to subdirectories within)
## --------------------------------------------------------------------- ##

set(DIR_INCLUDE "include")
set(DIR_CLIENT "client")        
set(DIR_SRC "src")
set(DIR_LIB "lib")
set(DIR_TESTS "tests")

## --------------------------------------------------------------------- ##
## Header file names (files within DIR_INCLUDE)
## --------------------------------------------------------------------- ##

##
## To add a header file,
## start with:
##      set(FILENAME_NEW_HEADER "header_name.hpp")
##
## Then add FILENAME_NEW_HEADER to ALL_HEADERS as another element:
##      "${DIR_INCLUDE}/${FILENAME_NEW_HEADER}"
##
## It would look like this:
##      set(ALL_HEADERS
##          "${DIR_INCLUDE}/${FILENAME_HEADER}"
##          "${DIR_INCLUDE}/${FILENAME_NEW_HEADER}"
##      )
##
## If there are subdirectories between DIR_INCLUDE and your header file,
## be sure to specify those.
##

set(FILENAME_HEADER_HPP "header.hpp")
set(FILENAME_POINT_HPP "point.hpp")
set(FILENAME_VEC_HPP "vec.hpp")

## Use ${ALL_HEADERS} to reference all .hpp files in DIR_INCLUDE
set(ALL_HEADERS 
    "${DIR_INCLUDE}/${FILENAME_HEADER_HPP}"
    "${DIR_INCLUDE}/${FILENAME_POINT_HPP}"
    "${DIR_INCLUDE}/${FILENAME_VEC_HPP}"
)

## --------------------------------------------------------------------- ##
## Source file names (files within DIR_SRC)
## --------------------------------------------------------------------- ##

set(FILENAME_SOURCE_CPP "source.cpp")
set(FILENAME_POINT_CPP "point.cpp")
set(FILENAME_VEC_CPP "vec.cpp")

## All .cpp files in DIR_SRC
set(ALL_SOURCES 
    "${DIR_SRC}/${FILENAME_SOURCE_CPP}"
    "${DIR_SRC}/${FILENAME_POINT_CPP}"
    "${DIR_SRC}/${FILENAME_VEC_CPP}"
)

## --------------------------------------------------------------------- ##
## Client source file names (files within DIR_CLIENT)
## --------------------------------------------------------------------- ##

set(FILENAME_MAIN "main.cpp")

## Full relative path of FILENAME_MAIN
set(MAIN "${DIR_CLIENT}/${FILENAME_MAIN}")

## --------------------------------------------------------------------- ##
## Application (binary) title
## --------------------------------------------------------------------- ##

set(BIN_TITLE "GCSGraph_main")

## --------------------------------------------------------------------- ##
## Installation folder names
## --------------------------------------------------------------------- ##

set(DIR_BIN_INSTALL "bin")
set(DIR_SRC_INSTALL "src")

## --------------------------------------------------------------------- ##
## Test case titles
## --------------------------------------------------------------------- ##

set(TEST_TITLE_PASS "_test_pass")
set(TEST_TITLE_FAIL "_test_fail")

## --------------------------------------------------------------------- ##
## Flags
## --------------------------------------------------------------------- ##

set(WALL "-Wall")
#set(WERR "-Werror")    ## Won't work in Windows 10. 
                        ## Need different build options for Windows
#set(WEXTRA "-Wextra")

set(PEDANTIC "-pedantic-errors")

set(CFLAGS "${WALL} ${WERR} ${PEDANTIC}")
#set(CFLAGS "${WALL} ${WERR} ${WEXTRA} ${PEDANTIC}")

###########################################################################
##  Configuration                                                        ##
###########################################################################

## --------------------------------------------------------------------- ##
## CMake version
## --------------------------------------------------------------------- ##

cmake_minimum_required(VERSION "${CMAKE_VERSION_NUMBER}")

## --------------------------------------------------------------------- ##
## C++ standard (-std=c++17)
## --------------------------------------------------------------------- ##

set(CMAKE_CXX_STANDARD "${CXX_STD}")

## --------------------------------------------------------------------- ##
## Compiler flags
## --------------------------------------------------------------------- ##

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS}")

## --------------------------------------------------------------------- ##
## Project name (access via PROJECT_NAME)
## --------------------------------------------------------------------- ##

project("${PROJECT_TITLE}")

## --------------------------------------------------------------------- ##
## Header file path (.h/.hpp/.tpp)
## --------------------------------------------------------------------- ##

include_directories("${DIR_INCLUDE}")

## --------------------------------------------------------------------- ##
## Executables
## --------------------------------------------------------------------- ##

add_executable("${BIN_TITLE}" "${MAIN}" "${ALL_HEADERS}" "${ALL_SOURCES}")

## --------------------------------------------------------------------- ##
## Installation directories (relative to CMAKE_INSTALL_PREFIX)
## --------------------------------------------------------------------- ##

### Binary
install(TARGETS ${BIN_TITLE} DESTINATION "${DIR_BIN_INSTALL}")

### Sources
install(FILES "${ALL_HEADERS}" "${MAIN}" "${ALL_SOURCES}" DESTINATION "${DIR_SRC_INSTALL}")

## --------------------------------------------------------------------- ##
## CTest module
## --------------------------------------------------------------------- ##

include(CTest)

## --------------------------------------------------------------------- ##
## Practice test case, it's just this project's binary.
## --------------------------------------------------------------------- ##

add_test("${TEST_TITLE_PASS}" ${CMAKE_CURRENT_BINARY_DIR}/${BIN_TITLE})

## --------------------------------------------------------------------- ##
## Just like _test_pass, but designed to fail purposely (to demonstrate failure)
## --------------------------------------------------------------------- ##

#add_test("${TEST_TITLE_FAIL}" ${CMAKE_CURRENT_BINARY_DIR}/${BIN_TITLE} "Makes argc == 2")

## --------------------------------------------------------------------- ##
## CPack module (CPack depends on install statements)
## --------------------------------------------------------------------- ##

#set(CPACK_BUNDLE_NAME desired title for .app file)
#set(CPACK_BUNDLE_PLIST path to a file that will become the bundle plist)
#set(CPACK_BUNDLE_ICON path to an icon file)

include(CPack)
