cmake_minimum_required(VERSION 3.6)

project(SDiZO_2 C CXX)
set(CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET_NAME
    "sdizo")

set(SOURCES
src/IncidenceMatrix.cpp
src/DisjointSet.cpp
src/Sort.cpp)

set(TESTS
tests/tests.cpp)

find_package(Catch2 REQUIRED)

add_executable(test ${TESTS} ${SOURCES})
target_link_libraries(test PRIVATE Catch2::Catch2)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(${TARGET_NAME} src/main.cpp ${SOURCES})