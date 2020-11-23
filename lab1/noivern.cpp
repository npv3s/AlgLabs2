#include "pokemons.hpp"
#include <sstream>

Noivern::Noivern(std::string name,
                 unsigned hp,
                 unsigned attack,
                 unsigned defense,
                 unsigned speed,
                 std::string special_attack,
                 std::string special_defense)
        : Pokemon(name, hp, attack, defense, speed) {
    noivernSpecialAttack = special_attack;
    noivernSpecialDefense = special_defense;
}

Noivern::Noivern(std::string line) : Pokemon(line) {
    unsigned columns[2];
    for (int i = line.length(), counter = 1; i >= 0; i--) {
        if (line[i] == ',') columns[counter--] = (i + 1);
    }
    noivernSpecialAttack = line.substr(columns[0], columns[1] - columns[0] - 1);
    noivernSpecialDefense = line.substr(columns[1], line.length() - columns[1]);
}

std::string Noivern::to_string() {
    std::stringstream addon;
    addon << ','
          << noivernSpecialAttack << ','
          << noivernSpecialDefense;
    std::string out = Pokemon::to_string();
    out.append(addon.str());
    return out;
}