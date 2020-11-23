cmake_minimum_required(VERSION 3.16)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab1 main.cpp pokemon.hpp pokemon.cpp pokemons.hpp bulbasaur.cpp vullaby.cpp noivern.cpp csv.hpp csv.cpp)