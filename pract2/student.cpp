#include "student.hpp"
#include <iostream>
#include <iomanip>

Student::Student(int group, bool status) : User() {
    studentGroup = group;
    studentStatus = status;
}

Student::Student(std::string name, int group, bool status) : User(name) {
    studentGroup = group;
    studentStatus = status;
}

Student::Student(std::string name, std::string surname, int group, bool status) : User(name, surname) {
    studentGroup = group;
    studentStatus = status;
}

Student::Student(std::string name, std::string surname, std::string login, int group, bool status) :
        User(name, surname, login) {
    studentGroup = group;
    studentStatus = status;
}

Student::Student(std::string name, std::string surname, std::string login, std::string email, int group, bool status) :
        User(name, surname, login, email) {
    studentGroup = group;
    studentStatus = status;
}

Student::Student(std::string name, std::string surname, std::string login, std::string email, std::string password,
                 int group, bool status) : User(name, surname, login, email, password) {
    studentGroup = group;
    studentStatus = status;
}

int Student::getGroup() {
    return studentGroup;
}

bool Student::getStatus() {
    return studentStatus;
}

void Student::setGroup(int group) {
    studentGroup = group;
}

void Student::setStatus(bool status) {
    studentStatus = status;
}

void Student::print() {
    const std::string fields[7] = {"Имя    ", "Фамилия", "Логин  ", "E-Mail ", "Пароль ", "Группа ", "Статус "};
    const std::string values[7] = {userName,
                                   userSurname,
                                   userLogin,
                                   userEmail,
                                   userPassword,
                                   std::to_string(studentGroup),
                                   studentStatus ? "Обучается" : "Отчислено"};

    unsigned int size[7];
    for (int i = 0; i < 7; i++) {
        size[i] = values[i].size();
    }

    int max_size = 0;
    for (int i = 0; i < 7; i++) {
        if (max_size < size[i]) max_size = size[i];
    }

    int length = 10 + max_size;
    int first_column = 7;
    bool is_first = true;

    std::cout << separator(length, &first_column, 1, 1) << std::endl;
    for (int i = 0; i < 7; i++) {
        if (size[i] != 0) {
            if (!is_first) std::cout << separator(length, &first_column, 1) << std::endl;
            else is_first = false;
            std::cout << std::left << "|" << fields[i] << "|" <<
                      std::setw(max_size) << values[i] << "│" << std::endl;
        }
    }
    std::cout << separator(length, &first_column, 1, 2) << std::endl;
}