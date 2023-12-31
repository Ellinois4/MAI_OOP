cmake_minimum_required(VERSION 3.10)

# download googletest
configure_file(${PROJECT_SOURCE_DIR}/cmake/CMakeLists.txt.gtest.in googletest-download/CMakeLists.txt)
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


# Test Queue Target
add_executable(${PROJECT_NAME}_test_queue test_queue.cpp)

set_target_properties(${PROJECT_NAME}_test_queue PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED ON)

#target_compile_options(${PROJECT_NAME}_test_queue PUBLIC "-Wall" "-g" "-fsanitize=undefined" "-fsanitize=address")
#target_link_options(${PROJECT_NAME}_test_queue PUBLIC "-fsanitize=undefined" "-fsanitize=address")

target_include_directories(${PROJECT_NAME}_test_queue PRIVATE
                "${PROJECT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

target_link_libraries(${PROJECT_NAME}_test_queue gtest_main)

# Test Allocator Target
add_executable(${PROJECT_NAME}_test_allocator test_allocator.cpp)

set_target_properties(${PROJECT_NAME}_test_allocator PROPERTIES
                CXX_STANDARD 20
                CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME}_test_allocator PRIVATE
                "${PROJECT_SOURCE_DIR}/include"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
                "${CMAKE_CURRENT_BINARY_DIR}/googletest-src/include")

target_link_libraries(${PROJECT_NAME}_test_allocator gtest_main)