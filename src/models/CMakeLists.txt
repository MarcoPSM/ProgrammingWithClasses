file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCE ${SOURCES})
add_library(models_lib STATIC ${SOURCES})

target_include_directories( models_lib
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )
