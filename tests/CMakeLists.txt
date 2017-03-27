cmake_minimum_required(VERSION 3.5)

set(CurrentDir   "${CMAKE_CURRENT_SOURCE_DIR}")
set(RootDir      "${CurrentDir}/..")
set(IncludeDir   "${RootDir}/include")
set(SourceDir    "${RootDir}/src")

link_directories   ("${CurrentDir}/gtest")
include_directories(
  "${IncludeDir}"
  )

set(CMAKE_CXX_FLAGS "-g -W -Wall -Wextra -std=c++1y")

aux_source_directory("${SourceDir}" sources)

#add_library(xml
#  ${sd}
#  ${xd}
#  )

##################################################################
add_executable(one_test
  one_test.cpp
  )

target_link_libraries(one_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(converter_test
  converter_test.cpp
  )

target_link_libraries(converter_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(option_test
  option_test.cpp
  ${SourceDir}/Option.cpp
  )

target_link_libraries(option_test
  gtest_main
  gtest
  pthread
  )
##################################################################
