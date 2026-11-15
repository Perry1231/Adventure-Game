cmake_minimum_required(VERSION 3.15)
project(AdventureGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(AdventureGame
    src/Main.cpp
    src/Addition.cpp
    src/Additional_Functions.cpp
    src/AdditionalGames.cpp
    src/Armory.cpp
    src/Artifact.cpp
    src/Character.cpp
    src/Chest.cpp
    src/Deleter.cpp
    src/Enemy.cpp
    src/ErrorCatcher.cpp
    src/Events.cpp
    src/Inventory.cpp
    src/Loader.cpp
    src/Weapon.cpp         
    src/Objects.cpp      
    src/Potion.cpp   
    src/OtherRandomizer.cpp
    src/ Task_Generatotor_For_Character.cpp
)

if(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
endif()