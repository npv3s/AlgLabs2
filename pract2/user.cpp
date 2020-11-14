#include "user.hpp"
#include <iostream>
#include <iomanip>

std::string separator(unsigned int length,
                      const int *columns,
                      int columns_length,
                      unsigned short type) {
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
    const std::string fields[5] = {"Имя    ", "Фамилия", "Логин  ", "E-Mail ", "Пароль "};
    const std::string values[5] = {userName,
                                   userSurname,
                                   userLogin,
                                   userEmail,
                                   userPassword};

    unsigned int size[5];
    for (int i = 0; i < 5; i++) {
        size[i] = values[i].size();
    }

    int max_size = 0;
    for (int i = 0; i < 5; i++) {
        if (max_size < size[i]) max_size = size[i];
    }

    int length = 10 + max_size;
    int first_column = 7;
    bool is_first = true;

    std::cout << separator(length, &first_column, 1, 1) << std::endl;
    for (int i = 0; i < 5; i++) {
        if (size[i] != 0) {
            if (!is_first) std::cout << separator(length, &first_column, 1) << std::endl;
            else is_first = false;
            std::cout << std::left << "|" << fields[i] << "|" <<
                      std::setw(max_size) << values[i] << "│" << std::endl;
        }
    }
    std::cout << separator(length, &first_column, 1, 2) << std::endl;
}