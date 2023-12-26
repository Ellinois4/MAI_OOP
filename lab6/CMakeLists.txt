cmake_minimum_required(VERSION 3.14)

project(lab6)

add_subdirectory(test)

# Project lib
add_library(${PROJECT_NAME}_lib
        src/factory.cpp
        src/bear.cpp
        src/werewolf.cpp
        src/npc.cpp
        src/observer.cpp
        src/robber.cpp)


target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_options(${PROJECT_NAME}_lib PUBLIC "-g" "-Wall" "-fsanitize=undefined" "-fsanitize=address")
target_link_options(${PROJECT_NAME}_lib PUBLIC "-fsanitize=undefined" "-fsanitize=address")

set_target_properties(${PROJECT_NAME}_lib PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)

# Executable
add_executable(${PROJECT_NAME}_exe ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME}_lib)