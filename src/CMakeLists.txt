set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCE ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})


#add_test(NAME ${BINARY} COMMAND ${BINARY})
#target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)
#add_executable(ProgramacaoComClasses src/main.cpp src/Point.cpp src/Point.h src/Triangle.cpp src/Triangle.h src/Line.cpp src/Line.h src/Polygon.cpp src/Polygon.h tests/PointTest.cpp)
