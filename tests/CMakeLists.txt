cmake_minimum_required(VERSION 3.5)

set(CurrentDir    "${CMAKE_CURRENT_SOURCE_DIR}")
set(RootDir       "${CurrentDir}/..")
set(IncludeDir    "${RootDir}/include")
set(SourceDir     "${RootDir}/src")
set(SimpleJsonDir "${SourceDir}/SimpleJson")

link_directories   ("${CurrentDir}/gtest")
include_directories(
  "${SourceDir}"
  "${IncludeDir}"
  )

set(CMAKE_CXX_FLAGS "-g -W -Wall -Wextra -std=c++1y")

aux_source_directory("${SourceDir}" sources)
aux_source_directory("${SimpleJsonDir}" SJD)

add_library(simple_json
  ${SJD}
  )

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
  ${SourceDir}/Option.cpp
  ${SourceDir}/Converter.cpp
  ${SourceDir}/ConvertHandler.cpp
  ${SourceDir}/EventLooker.cpp
  ${SourceDir}/TagHistory.cpp
  )

target_link_libraries(converter_test
  simple_json
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

##################################################################
add_executable(handler_test
  handler_test.cpp
  )

target_link_libraries(handler_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(converthandler_test
  converthandler_test.cpp
  ${SourceDir}/Option.cpp
  ${SourceDir}/ConvertHandler.cpp
  ${SourceDir}/EventLooker.cpp
  ${SourceDir}/TagHistory.cpp
  )

target_link_libraries(converthandler_test
  simple_json
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(eventlooker_test
  eventlooker_test.cpp
  ${SourceDir}/EventLooker.cpp
  )

target_link_libraries(eventlooker_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(taghistory_test
  taghistory_test.cpp
  ${SourceDir}/TagHistory.cpp
  )

target_link_libraries(taghistory_test
  gtest_main
  gtest
  pthread
  )
##################################################################
