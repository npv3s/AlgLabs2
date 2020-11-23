#pragma once

#include <string>

class Pokemon {
protected:
    std::string pokemonName;
    unsigned int pokemonHP;
    unsigned int pokemonAttack;
    unsigned int pokemonDefense;
    unsigned int pokemonSpeed;
public:
    Pokemon(std::string line);

    Pokemon(std::string name,
            unsigned int hp,
            unsigned int attack,
            unsigned int defense,
            unsigned int speed);

    void setName(std::string name);

    void setHP(unsigned int hp);

    void setAttack(unsigned int attack);

    void setDefense(unsigned int defense);

    void setSpeed(unsigned int speed);

    std::string getName();

    unsigned getHP();

    unsigned getAttack();

    unsigned getDefense();

    unsigned getSpeed();

    std::string to_string();
};
