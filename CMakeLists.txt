cmake_minimum_required(VERSION 3.5)

set(CurrentDir    "${CMAKE_CURRENT_SOURCE_DIR}")
set(RootDir       "${CurrentDir}")
set(IncludeDir    "${RootDir}/include")
set(SourceDir     "${RootDir}/src")

include_directories(
  "${IncludeDir}"
  )

set(CMAKE_CXX_FLAGS "-g -W -Wall -Wextra -std=c++1y")

aux_source_directory("${SourceDir}" sources)

add_library(json2xml
  ${sources}
  )
