cmake_minimum_required(VERSION 3.19)
project(CppPkmGen)

set(CMAKE_CXX_STANDARD 14)

include_directories(CppPkmGen)

add_executable(CppPkmGen
        CppPkmGen/CppPkmGen.cpp
        CppPkmGen/NumberGenerator.cpp
        CppPkmGen/NumberGenerator.h
        CppPkmGen/Pokemon.cpp
        CppPkmGen/Pokemon.h
        CppPkmGen/Trainer.cpp
        CppPkmGen/Trainer.h)
