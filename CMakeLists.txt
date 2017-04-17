cmake_minimum_required(VERSION 3.5)

set(CurrentDir    "${CMAKE_CURRENT_SOURCE_DIR}")
set(RootDir       "${CurrentDir}")
set(IncludeDir    "${RootDir}/include")
set(SourceDir1    "${RootDir}/src")
set(SourceDir2    "${RootDir}/src/SimpleJson")

include_directories(
  "${IncludeDir}"
  "${SourceDir1}"
  )

set(CMAKE_CXX_FLAGS "-g -W -Wall -Wextra -std=c++1y")

aux_source_directory("${SourceDir1}" sources1)
aux_source_directory("${SourceDir2}" sources2)

add_library(json2xml
  ${sources1}
  ${sources2}
  )
