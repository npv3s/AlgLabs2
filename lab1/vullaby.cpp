#include "pokemons.hpp"
#include <sstream>

Vullaby::Vullaby(std::string name,
                 unsigned hp,
                 unsigned attack,
                 unsigned defense,
                 unsigned speed,
                 std::string special_attack,
                 std::string special_defense)
        : Pokemon(name, hp, attack, defense, speed) {
    vullabySpecialAttack = special_attack;
    vullabySpecialDefense = special_defense;
}

Vullaby::Vullaby(std::string line) : Pokemon(line) {
    unsigned columns[2];
    for (int i = line.length(), counter = 1; i >= 0; i--) {
        if (line[i] == ',') columns[counter--] = (i + 1);
    }
    vullabySpecialAttack = line.substr(columns[0], columns[1] - columns[0] - 1);
    vullabySpecialDefense = line.substr(columns[1], line.length() - columns[1]);
}

std::string Vullaby::to_string() {
    std::stringstream addon;
    addon << ','
          << vullabySpecialAttack << ','
          << vullabySpecialDefense << '\n';
    std::string out = Pokemon::to_string();
    out.pop_back();
    out.append(addon.str());
    return out;
}