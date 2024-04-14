cmake_minimum_required(VERSION 3.22)
project(ProgramacaoComClasses)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)
include_directories(src/models)
include_directories(src/vectors)

add_subdirectory(src)
add_subdirectory(tests)

add_subdirectory(lib/googletest)
