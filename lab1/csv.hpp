#pragma once

#include "pokemon.hpp"
#include "pokemons.hpp"
#include <string>
#include <fstream>

namespace csv {
    template<typename T>
    T read(std::string filename, unsigned line = 0);

    template<typename T>
    void write(std::string filename, T item, bool append = false);
}