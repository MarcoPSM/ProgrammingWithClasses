set(BINARY ${CMAKE_PROJECT_NAME}_vectors_test)

# file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp) set(SOURCE
# ${TEST_SOURCES})
add_executable(${BINARY} VectorsTest.cpp)

# add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_vectors_lib gtest)
