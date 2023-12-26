cmake_minimum_required(VERSION 3.14)

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


add_executable(${PROJECT_NAME}_npc_test ${PROJECT_SOURCE_DIR}/test/npc_test.cpp)
target_link_libraries(${PROJECT_NAME}_npc_test ${PROJECT_NAME}_lib gtest_main)

add_executable(${PROJECT_NAME}_factory_test ${PROJECT_SOURCE_DIR}/test/factory_test.cpp)
target_link_libraries(${PROJECT_NAME}_factory_test ${PROJECT_NAME}_lib gtest_main)

add_executable(${PROJECT_NAME}_bear_test ${PROJECT_SOURCE_DIR}/test/bear_test.cpp)
target_link_libraries(${PROJECT_NAME}_bear_test ${PROJECT_NAME}_lib gtest_main)

add_executable(${PROJECT_NAME}_werewolf_test ${PROJECT_SOURCE_DIR}/test/werewolf_test.cpp)
target_link_libraries(${PROJECT_NAME}_werewolf_test ${PROJECT_NAME}_lib gtest_main)

add_executable(${PROJECT_NAME}_robber_test ${PROJECT_SOURCE_DIR}/test/robber_test.cpp)
target_link_libraries(${PROJECT_NAME}_robber_test ${PROJECT_NAME}_lib gtest_main)