cmake_minimum_required(VERSION 3.15)
project(AdventureGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Adventure-Game")

# all source files in the Adventure-Game directory
file(GLOB SOURCES "Adventure-Game/*.cpp")

add_executable(adventure_game ${SOURCES})