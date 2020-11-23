#include "pokemon.hpp"

#include <string>
#include <sstream>

Pokemon::Pokemon(std::string name,
                 unsigned int hp,
                 unsigned int attack,
                 unsigned int defense,
                 unsigned int speed) {
    pokemonName = name;
    pokemonHP = hp;
    pokemonAttack = attack;
    pokemonDefense = defense;
    pokemonSpeed = speed;
}

Pokemon::Pokemon(std::string line) {
    unsigned columns[4];
    for (int i = 0, counter = 0; i < line.length(); i++) {
        if (line[i] == ',') columns[counter++] = (i + 1);
    }
    pokemonName = line.substr(0, columns[0] - 1);
    pokemonHP = std::stoi(line.substr(columns[0], columns[1] - columns[0]));
    pokemonAttack = std::stoi(line.substr(columns[1], columns[2] - columns[1]));
    pokemonDefense = std::stoi(line.substr(columns[2], columns[3] - columns[2]));
    pokemonSpeed = std::stoi(line.substr(columns[2], line.length() - columns[3]));
}

std::string Pokemon::to_string() {
    std::stringstream out;
    out << pokemonName << ','
        << pokemonHP << ','
        << pokemonAttack << ','
        << pokemonDefense << ','
        << pokemonSpeed << '\n';
    return out.str();
}

void Pokemon::setName(std::string name) {
    pokemonName = name;
}

void Pokemon::setHP(unsigned int hp) {
    pokemonHP = hp;
}

void Pokemon::setAttack(unsigned int attack) {
    pokemonAttack = attack;
}

void Pokemon::setDefense(unsigned int defense) {
    pokemonDefense = defense;
}

void Pokemon::setSpeed(unsigned int speed) {
    pokemonSpeed = speed;
}

std::string Pokemon::getName() {
    return pokemonName;
}

unsigned Pokemon::getHP() {
    return pokemonHP;
}

unsigned Pokemon::getAttack() {
    return pokemonAttack;
}

unsigned Pokemon::getDefense() {
    return pokemonDefense;
}

unsigned Pokemon::getSpeed() {
    return pokemonSpeed;
}

