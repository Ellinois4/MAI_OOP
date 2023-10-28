cmake_minimum_required (VERSION 3.10)

project(lab3)

add_compile_options(-Wall -g)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)
file(GLOB_RECURSE INCLUDES LIST_DIRECTORIES false ${INCLUDE_DIR}/*.hpp)

#
# library with common functions for tests and exe
#
add_library(${PROJECT_NAME}_lib
            ${SOURCES}
            ${INCLUDES})            

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

#
# project itself
#
add_executable(${PROJECT_NAME}_exe
                ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

set_target_properties(${PROJECT_NAME}_exe PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)

add_dependencies(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_exe ${PROJECT_NAME}_lib)

#
# unit tests
#

# download googletest
configure_file(config/CMakeLists.txt.gtest.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# add googletest to build. This defines the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# test Diamond target                 
add_executable(${PROJECT_NAME}_test_diamond
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Diamond_test.cpp)

set_target_properties(${PROJECT_NAME}_test_diamond PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_diamond PRIVATE
                           "${PROJECT_SOURCE_DIR}/src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                           "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_diamond ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_diamond ${PROJECT_NAME}_lib gtest_main)

# test Vector target
add_executable(${PROJECT_NAME}_test_vector
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Vector_test.cpp)


set_target_properties(${PROJECT_NAME}_test_vector PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_vector PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_vector ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_vector ${PROJECT_NAME}_lib gtest_main)

# test Hexagon target
add_executable(${PROJECT_NAME}_test_hexagon
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Hexagon_test.cpp)


set_target_properties(${PROJECT_NAME}_test_hexagon PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_hexagon PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_hexagon ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_hexagon ${PROJECT_NAME}_lib gtest_main)

# test Pentagon target
add_executable(${PROJECT_NAME}_test_pentagon
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Pentagon_test.cpp)


set_target_properties(${PROJECT_NAME}_test_pentagon PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_pentagon PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_pentagon ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_pentagon ${PROJECT_NAME}_lib gtest_main)


# test Point target
add_executable(${PROJECT_NAME}_test_point
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Point_test.cpp)


set_target_properties(${PROJECT_NAME}_test_point PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_include_directories(${PROJECT_NAME}_test_point PRIVATE
                    "${PROJECT_SOURCE_DIR}/src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                    "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

add_dependencies(${PROJECT_NAME}_test_point ${PROJECT_NAME}_lib)
target_link_libraries(${PROJECT_NAME}_test_point ${PROJECT_NAME}_lib gtest_main)