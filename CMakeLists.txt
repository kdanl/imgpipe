cmake_minimum_required(VERSION 3.20)

project(imgpipe
        VERSION 1.0.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(PROJECT_VERSION="${PROJECT_VERSION}")

add_executable(imgpipe
        scr/main.cpp
        scr/cli/ArgumentParser.cpp
)

target_include_directories(imgpipe PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/scr
)
