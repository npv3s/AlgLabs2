#include "user.hpp"
#include <iostream>
#include <iomanip>

std::string separator(unsigned int length,
                      const int *columns = nullptr,
                      int columns_length = 0,
                      unsigned short type = 0) {
    // type
    // 0 - в середине
    // 1 - в начале
    // 2 - в конце
    std::string line;
    int counter = 1;
    switch (type) {
        case 1:
            line.append("┌");
            break;
        case 2:
            line.append("└");
            break;
        default:
            line.append("├");
            break;
    }
    for (int cols_index = 0; cols_index < columns_length; cols_index++) {
        for (int i = 0; i < (columns[cols_index] + cols_index); i++, counter++)
            line.append("─");
        counter++;
        switch (type) {
            case 1:
                line.append("┬");
                break;
            case 2:
                line.append("┴");
                break;
            default:
                line.append("┼");
                break;
        }
    }
    for (int i = counter; i < (length - 1); i++)
        line.append("─");
    switch (type) {
        case 1:
            line.append("┐");
            break;
        case 2:
            line.append("┘");
            break;
        default:
            line.append("┤");
            break;
    }
    return line;
}

User::User() = default;

User::User(std::string name) {
    userName = name;
}

User::User(std::string name, std::string surname) {
    userName = name;
    userSurname = surname;
}

User::User(std::string name, std::string surname, std::string login) {
    userName = name;
    userSurname = surname;
    userLogin = login;
}

User::User(std::string name, std::string surname, std::string login, std::string email) {
    userName = name;
    userSurname = surname;
    userLogin = login;
    userEmail = email;
}

User::User(std::string name, std::string surname, std::string login, std::string email, std::string password) {
    userName = name;
    userSurname = surname;
    userLogin = login;
    userEmail = email;
    userPassword = password;
}

std::string User::getName() {
    return userName;
}

std::string User::getSurname() {
    return userSurname;
}

std::string User::getLogin() {
    return userLogin;
}

std::string User::getEmail() {
    return userEmail;
}

std::string User::getPassword() {
    return userPassword;
}

void User::setName(std::string name) {
    userName = name;
}

void User::setSurname(std::string surname) {
    userSurname = surname;
}

void User::setLogin(std::string login) {
    userLogin = login;
}

void User::setEmail(std::string email) {
    userEmail = email;
}

void User::setPassword(std::string password) {
    userPassword = password;
}

void User::print() {
    unsigned int size[5];
    size[0] = userName.size();
    size[1] = userSurname.size();
    size[2] = userLogin.size();
    size[3] = userEmail.size();
    size[4] = userPassword.size();

    int max_size = 0;
    for (int i = 0; i < 5; i++) {
        if (max_size < size[i]) max_size = size[i];
    }

    int length = 10 + max_size;
    int first_column = 7;
    bool is_first = true;

    std::cout << separator(length, &first_column, 1, 1) << std::endl;
    if (size[0] != 0) {
        is_first = false;
        std::cout << "│Имя    │" << std::left << std::setw(max_size) << userName << "│" << std::endl;
    }
    if (size[1] != 0) {
        if (!is_first) std::cout << separator(length, &first_column, 1) << std::endl;
        else is_first = false;
        std::cout << "│Фамилия│" << std::left << std::setw(max_size) << userSurname << "│" << std::endl;
    }
    if (size[2] != 0) {
        if (!is_first) std::cout << separator(length, &first_column, 1) << std::endl;
        else is_first = false;
        std::cout << "│Логин  │" << std::left << std::setw(max_size) << userLogin << "│" << std::endl;
    }
    if (size[3] != 0) {
        if (!is_first) std::cout << separator(length, &first_column, 1) << std::endl;
        else is_first = false;
        std::cout << "│E-Mail │" << std::left << std::setw(max_size) << userEmail << "│" << std::endl;
    }
    if (size[4] != 0) {
        if (!is_first) std::cout << separator(length, &first_column, 1) << std::endl;
        std::cout << "│Пароль │" << std::left << std::setw(max_size) << userPassword << "│" << std::endl;
    }
    std::cout << separator(length, &first_column, 1, 2) << std::endl;
}