#include "pokemons.hpp"
#include <sstream>

Bulbasaur::Bulbasaur(std::string name,
                     unsigned hp,
                     unsigned attack,
                     unsigned defense,
                     unsigned speed,
                     std::string special_attack,
                     std::string special_defense)
        : Pokemon(name, hp, attack, defense, speed) {
    bulbasaurSpecialAttack = special_attack;
    bulbasaurSpecialDefense = special_defense;
}

Bulbasaur::Bulbasaur(std::string line) : Pokemon(line) {
    unsigned columns[2];
    for (int i = line.length(), counter = 1; (i >= 0) and (counter >= 0); i--) {
        if (line[i] == ',') columns[counter--] = (i + 1);
    }
    bulbasaurSpecialAttack = line.substr(columns[0], columns[1] - columns[0] - 1);
    bulbasaurSpecialDefense = line.substr(columns[1], line.length() - columns[1]);
}

std::string Bulbasaur::to_string() {
    std::stringstream addon;
    addon << ','
          << bulbasaurSpecialAttack << ','
          << bulbasaurSpecialDefense << '\n';
    std::string out = Pokemon::to_string();
    out.pop_back();
    out.append(addon.str());
    return out;
}