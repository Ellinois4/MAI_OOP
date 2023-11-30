cmake_minimum_required(VERSION 3.14)

project(lab5)

add_subdirectory(test)

# main executable target
add_executable(${PROJECT_NAME}_exe ${PROJECT_SOURCE_DIR}/main.cpp)
set_target_properties(${PROJECT_NAME}_exe PROPERTIES
                    CXX_STANDARD 20
                    CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME}_exe PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_compile_options(${PROJECT_NAME}_exe PUBLIC "-Wall" "-g" "-fsanitize=undefined" "-fsanitize=address")
target_link_options(${PROJECT_NAME}_exe PUBLIC "-fsanitize=undefined" "-fsanitize=address")