cmake_minimum_required(VERSION 3.15)
project(ProjectTest1)

include_directories( ./src )
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        main.cpp
        src/GameManager.cpp
        src/Board.cpp
        src/Pawn.cpp
        )

add_executable(my_exec ${SOURCE_FILES})