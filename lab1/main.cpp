#include "pokemon.hpp"
#include "pokemons.hpp"
#include "csv.hpp"
#include <iostream>

int main() {
    auto pokemon = Pokemon("pokemon", 1, 2, 3, 4);
    auto bulbasaur = Bulbasaur("bulbasaur", 1, 2, 3, 4, "b_a", "b_d");
    auto vollaby = Vullaby("vollaby", 1, 2, 3, 4, "v_a", "v_d");
    auto noivern = Noivern("bulbasaur", 1, 2, 3, 4, "n_a", "n_d");

    csv::write("../pokemons.txt", pokemon);
    csv::write("../pokemons.txt", bulbasaur, true);
    csv::write("../pokemons.txt", vollaby, true);
    csv::write("../pokemons.txt", noivern, true);

    auto pokemon2 = csv::read<Pokemon>("../pokemons.txt", 0);
    auto bulbasaur2 = csv::read<Bulbasaur>("../pokemons.txt", 1);
    auto vollaby2 = csv::read<Vullaby>("../pokemons.txt", 2);
    auto noivern2 = csv::read<Noivern>("../pokemons.txt", 3);

    std::cout << pokemon2.getName() << ' '
              << pokemon2.getHP() << ' '
              << pokemon2.getAttack() << ' '
              << pokemon2.getDefense() << ' '
              << pokemon2.getSpeed() << std::endl;

    std::cout << bulbasaur2.getName() << ' '
              << bulbasaur2.getHP() << ' '
              << bulbasaur2.getAttack() << ' '
              << bulbasaur2.getDefense() << ' '
              << bulbasaur2.getSpeed() << ' '
              << bulbasaur2.getSpecialAttack() << ' '
              << bulbasaur2.getSpecialDefense() << std::endl;

    std::cout << vollaby2.getName() << ' '
              << vollaby2.getHP() << ' '
              << vollaby2.getAttack() << ' '
              << vollaby2.getDefense() << ' '
              << vollaby2.getSpeed() << ' '
              << vollaby2.getSpecialAttack() << ' '
              << vollaby2.getSpecialDefense() << std::endl;

    std::cout << noivern2.getName() << ' '
              << noivern2.getHP() << ' '
              << noivern2.getAttack() << ' '
              << noivern2.getDefense() << ' '
              << noivern2.getSpeed() << ' '
              << vollaby2.getSpecialAttack() << ' '
              << vollaby2.getSpecialDefense() << std::endl;

    return 0;
}
