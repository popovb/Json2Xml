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
  ${SourceDir}/ObjectHandlerFabric.cpp
  ${SourceDir}/ObjectStartHandler.cpp
  ${SourceDir}/ObjectEndHandler.cpp
  ${SourceDir}/ArrayStartHandler.cpp
  ${SourceDir}/ArrayEndHandler.cpp
  ${SourceDir}/RegularWorker.cpp
  ${SourceDir}/KeyHandler.cpp
  ${SourceDir}/ValueHandler.cpp
  ${SourceDir}/PlaceLooker.cpp
  ${SourceDir}/TestHandler.cpp
  ${SourceDir}/PrettyXMLHandler.cpp
  ${SourceDir}/Shifter.cpp
  ${SourceDir}/TagBuilder.cpp
  ${SourceDir}/AVBuilder.cpp
  ${SourceDir}/Encoder.cpp
  ${SourceDir}/myXML_Mirroring.cpp
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
  ${SourceDir}/PlaceLooker.cpp
  ${SourceDir}/ObjectHandlerFabric.cpp
  ${SourceDir}/ObjectStartHandler.cpp
  ${SourceDir}/ObjectEndHandler.cpp
  ${SourceDir}/ArrayStartHandler.cpp
  ${SourceDir}/ArrayEndHandler.cpp
  ${SourceDir}/RegularWorker.cpp
  ${SourceDir}/KeyHandler.cpp
  ${SourceDir}/ValueHandler.cpp
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

##################################################################
add_executable(placelooker_test
  placelooker_test.cpp
  ${SourceDir}/PlaceLooker.cpp
  )

target_link_libraries(placelooker_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(regularworker_test
  regularworker_test.cpp
  ${SourceDir}/RegularWorker.cpp
  )

target_link_libraries(regularworker_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(objectstarthandler_test
  objectstarthandler_test.cpp
  ${SourceDir}/ObjectStartHandler.cpp
  ${SourceDir}/TagHistory.cpp
  ${SourceDir}/Option.cpp
  ${SourceDir}/PlaceLooker.cpp
  ${SourceDir}/Instructions.cpp
  )

target_link_libraries(objectstarthandler_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(arraystarthandler_test
  arraystarthandler_test.cpp
  ${SourceDir}/ArrayStartHandler.cpp
  ${SourceDir}/TagHistory.cpp
  ${SourceDir}/Option.cpp
  ${SourceDir}/PlaceLooker.cpp
  ${SourceDir}/Instructions.cpp
  )

target_link_libraries(arraystarthandler_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(objectendhandler_test
  objectendhandler_test.cpp
  ${SourceDir}/ObjectStartHandler.cpp
  ${SourceDir}/ObjectEndHandler.cpp
  ${SourceDir}/TagHistory.cpp
  ${SourceDir}/Option.cpp
  ${SourceDir}/PlaceLooker.cpp
  ${SourceDir}/Instructions.cpp
  )

target_link_libraries(objectendhandler_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(keyhandler_test
  keyhandler_test.cpp
  ${SourceDir}/ObjectStartHandler.cpp
  ${SourceDir}/ObjectEndHandler.cpp
  ${SourceDir}/KeyHandler.cpp
  ${SourceDir}/TagHistory.cpp
  ${SourceDir}/Option.cpp
  ${SourceDir}/PlaceLooker.cpp
  ${SourceDir}/Instructions.cpp
  )

target_link_libraries(keyhandler_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(valuehandler_test
  valuehandler_test.cpp
  ${SourceDir}/ValueHandler.cpp
  ${SourceDir}/TagHistory.cpp
  ${SourceDir}/Option.cpp
  ${SourceDir}/PlaceLooker.cpp
  ${SourceDir}/Instructions.cpp
  )

target_link_libraries(valuehandler_test
  gtest_main
  gtest
  pthread
  )
##################################################################

##################################################################
add_executable(avbuilder_test
  avbuilder_test.cpp
  ${SourceDir}/AVBuilder.cpp
  )

target_link_libraries(avbuilder_test
  gtest_main
  gtest
  pthread
  )
##################################################################
