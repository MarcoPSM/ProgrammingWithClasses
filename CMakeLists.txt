cmake_minimum_required(VERSION 3.24)
project(ProgramacaoComClasses)

set(CMAKE_CXX_STANDARD 23)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)