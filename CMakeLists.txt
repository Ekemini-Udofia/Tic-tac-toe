cmake_minimum_required(VERSION 3.16)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

# Add all source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Find SDL3
find_package(SDL3 REQUIRED CONFIG)

# Include directories
include_directories(src)

# Executable
add_executable(tictactoe ${SOURCES})

# Link SDL3
target_link_libraries(tictactoe SDL3::SDL3)
