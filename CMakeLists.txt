cmake_minimum_required(VERSION 3.4)
project(GPMF VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

execute_process(COMMAND git submodule update --init --recursive
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(extern/MP4)

add_executable(joinGoPro joinGoPro.cpp)
target_link_libraries(joinGoPro PRIVATE MP4)
