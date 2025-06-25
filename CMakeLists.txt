set(CMAKE_TOOLCHAIN_FILE "C:/Users/jfire/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
cmake_minimum_required(VERSION 3.16)
project(TaskManager LANGUAGES CXX)
 find_package(nlohmann_json CONFIG REQUIRED)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
 
add_executable(task_manager
    src/main.cpp        )
    
target_link_libraries(task_manager PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(task_manager PRIVATE include)
