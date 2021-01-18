cmake_minimum_required(VERSION 3.5)

project(nirs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(frontend)

add_executable(nirs main.cpp)

target_link_libraries(nirs main_window)
