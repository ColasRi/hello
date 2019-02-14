cmake_minimum_required(VERSION 3.9)

include_directories(include)

file(GLOB MYPROJECT_BASE_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cc)
add_library(MyProject_base STATIC ${MYPROJECT_BASE_SRC})

file(GLOB MYPROJECT_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)

add_executable (MyProject ${MYPROJECT_SRC})

target_link_libraries(MyProject_base
    # nothing
)
target_link_libraries(MyProject
    MyProject_base
)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (include ${Boost_INCLUDE_DIRS})

file(GLOB MYPROJECT_TEST_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/test/*.cpp)

add_executable (MyProject_Test ${MYPROJECT_TEST_SRC})

target_link_libraries (MyProject_Test
    MyProject_base
    # ${Boost_LIBRARIES}
)

#Setup CMake to run tests
enable_testing()
add_test(COMMAND MyProject_Test)
