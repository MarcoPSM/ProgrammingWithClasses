cmake_minimum_required(VERSION 3.22)
project(ProgramacaoComClasses)

set(CMAKE_CXX_STANDARD 23)

include_directories(src)
include_directories(src/models)

add_subdirectory(src)
add_subdirectory(tests)

add_subdirectory(lib/googletest)
