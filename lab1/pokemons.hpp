#pragma once

#include "pokemon.hpp"

class Bulbasaur : public Pokemon {
protected:
    std::string bulbasaurSpecialAttack;
    std::string bulbasaurSpecialDefense;
public:
    Bulbasaur(std::string name,
              unsigned hp,
              unsigned attack,
              unsigned defense,
              unsigned speed,
              std::string special_attack,
              std::string special_defense);

    Bulbasaur(std::string line);

    std::string to_string();

    void setSpecialAttack(std::string special_attack) {
        bulbasaurSpecialAttack = special_attack;
    }

    void setSpecialDefense(std::string special_defense) {
        bulbasaurSpecialDefense = special_defense;
    }

    std::string getSpecialAttack() {
        return bulbasaurSpecialAttack;
    }

    std::string getSpecialDefense() {
        return bulbasaurSpecialDefense;
    }
};

class Vullaby : public Pokemon {
protected:
    std::string vullabySpecialAttack;
    std::string vullabySpecialDefense;
public:
    Vullaby(std::string name,
            unsigned hp,
            unsigned attack,
            unsigned defense,
            unsigned speed,
            std::string special_attack,
            std::string special_defense);

    Vullaby(std::string line);

    std::string to_string();

    void setSpecialAttack(std::string special_attack) {
        vullabySpecialAttack = special_attack;
    }

    void setSpecialDefense(std::string special_defense) {
        vullabySpecialDefense = special_defense;
    }

    std::string getSpecialAttack() {
        return vullabySpecialAttack;
    }

    std::string getSpecialDefense() {
        return vullabySpecialDefense;
    }
};

class Noivern : public Pokemon {
protected:
    std::string noivernSpecialAttack;
    std::string noivernSpecialDefense;
public:
    Noivern(std::string name,
            unsigned hp,
            unsigned attack,
            unsigned defense,
            unsigned speed,
            std::string special_attack,
            std::string special_defense);

    Noivern(std::string line);

    std::string to_string();

    void setSpecialAttack(std::string special_attack) {
        noivernSpecialAttack = special_attack;
    }

    void setSpecialDefense(std::string special_defense) {
        noivernSpecialDefense = special_defense;
    }

    std::string getSpecialAttack() {
        return noivernSpecialAttack;
    }

    std::string getSpecialDefense() {
        return noivernSpecialDefense;
    }
};
