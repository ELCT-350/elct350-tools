cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_CXX_STANDARD 20)

project(Elct350Tools)

find_package(sciplot CONFIG REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_subdirectory(Main)
add_subdirectory(HtmlPlotter)