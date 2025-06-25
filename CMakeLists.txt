cmake_minimum_required(VERSION 3.16)
project(TaskManager LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
add_executable(task_manager
    Modern_CLI/main.cpp        # ← make sure this path exists
)

# Headers go in include/
target_include_directories(task_manager PRIVATE include)
