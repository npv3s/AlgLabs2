#include "csv.hpp"
#include <string>
#include <iostream>

using namespace csv;

template<typename T>
T csv::read(std::string filename, unsigned line) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int counter = 0;
        std::string buff;
        getline(file, buff);
        while (counter != line && getline(file, buff)) {
            ++counter;
        }

        if (counter == line) {
            file.close();
            return T(buff);
        } else {
            std::cout << "Строка " << line << " не найдена!" << std::endl;
            exit(0);
        }
    }
    std::cout << "Не удалось открыть/считать " << filename << std::endl;
    exit(0);
}

template Pokemon csv::read<Pokemon>(std::string filename, unsigned int line);

template Bulbasaur csv::read<Bulbasaur>(std::string filename, unsigned int line);

template Vullaby csv::read<Vullaby>(std::string filename, unsigned int line);

template Noivern csv::read<Noivern>(std::string filename, unsigned int line);

template<typename T>
void csv::write(std::string filename, T item, bool append) {
    // append
    // false - перезаписать существующие значения
    // true - добавить к существующим
    std::ofstream table;
    table.open(filename, append ? std::ios::app : std::ios::trunc);
    table << item.to_string() << std::endl;
    table.close();
}

template void csv::write(std::string filename, Pokemon item, bool append);

template void csv::write(std::string filename, Bulbasaur item, bool append);

template void csv::write(std::string filename, Vullaby item, bool append);

template void csv::write(std::string filename, Noivern item, bool append);