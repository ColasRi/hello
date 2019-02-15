cmake_minimum_required(VERSION 3.0)

# The flags needed for coverage
SET(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

# Adding them
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

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
)

#Setup CMake to run tests
enable_testing()
add_test(COMMAND MyProject_Test)
