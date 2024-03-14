cmake_minimum_required(VERSION 3.27)
project(RPG)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPG main.cpp
        Player/Player.cpp
        Player/Player.h
        Utils.h
        Enemy/Enemy.cpp
        Enemy/Enemy.h
        Combat/Action.cpp
        Combat/Action.h
        Combat/Combat.cpp
        Combat/Combat.h
        Character/Character.cpp
        Character/Character.h
)
