cmake_minimum_required(VERSION 3.10)
project(algorithm-visualizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(algorithm-visualizer 
    src/main.cpp
    src/quicksort.cpp
)

target_include_directories(algorithm-visualizer PRIVATE include)

target_link_libraries(algorithm-visualizer sfml-graphics sfml-window sfml-system)
