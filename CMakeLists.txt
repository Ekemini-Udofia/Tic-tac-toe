cmake_minimum_required(VERSION 3.20)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

# Find SDL3 and SDL3_image
set(CMAKE_PREFIX_PATH "C:/SDL3")  # Adjust path if needed
find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)

# Add source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Create executable
add_executable(tictactoe ${SOURCES})

# Include headers
target_include_directories(tictactoe PRIVATE src)

# Link libraries
target_link_libraries(tictactoe
    PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    ws2_32  # For Winsock
)
