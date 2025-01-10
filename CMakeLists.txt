cmake_minimum_required(VERSION 3.30)
project(CAGEv2)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan 1.3.296 REQUIRED)
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

add_executable(CAGEv2 src/main.cpp
        src/Renderer.cpp
        src/Renderer.h
        src/external/volk.c
        src/external/volk.h)

include_directories(${Vulkan_INCLUDE_DIRS})
target_link_libraries(CAGEv2 SDL3::SDL3)