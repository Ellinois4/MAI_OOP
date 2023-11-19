cmake_minimum_required (VERSION 3.10)

project(lab4)

#
# project itself
#
add_executable(${PROJECT_NAME}_exe
                ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_compile_options(${PROJECT_NAME}_exe PRIVATE "-Wall" "-Werror")

set_target_properties(${PROJECT_NAME}_exe PROPERTIES
                      CXX_STANDARD 20
                      CXX_STANDARD_REQUIRED YES
                      CXX_EXTENSIONS NO)
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

target_link_libraries(${PROJECT_NAME}_test_diamond gtest_main)

# test Vector target
add_executable(${PROJECT_NAME}_test_vector
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Vector_test.cpp)


set_target_properties(${PROJECT_NAME}_test_vector PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_link_libraries(${PROJECT_NAME}_test_vector gtest_main)

# test Hexagon target
add_executable(${PROJECT_NAME}_test_hexagon
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Hexagon_test.cpp)


set_target_properties(${PROJECT_NAME}_test_hexagon PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_link_libraries(${PROJECT_NAME}_test_hexagon gtest_main)

# test Pentagon target
add_executable(${PROJECT_NAME}_test_pentagon
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Pentagon_test.cpp)


set_target_properties(${PROJECT_NAME}_test_pentagon PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_link_libraries(${PROJECT_NAME}_test_pentagon gtest_main)


# test Point target
add_executable(${PROJECT_NAME}_test_point
               ${CMAKE_CURRENT_SOURCE_DIR}/test/Point_test.cpp)


set_target_properties(${PROJECT_NAME}_test_point PROPERTIES
               CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES)

target_link_libraries(${PROJECT_NAME}_test_point gtest_main)

