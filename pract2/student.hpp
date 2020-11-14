#pragma once

#include "user.hpp"
#include <string>

class Student : public User {
    int studentGroup;
    bool studentStatus;
public:
    Student(int group, bool status);

    Student(std::string name, int group, bool status);

    Student(std::string name, std::string surname, int group, bool status);

    Student(std::string name, std::string surname, std::string login, int group, bool status);

    Student(std::string name, std::string surname, std::string login, std::string email, int group, bool status);

    Student(std::string name, std::string surname, std::string login, std::string email, std::string password,
            int group, bool status);

    int getGroup();

    bool getStatus();

    void setGroup(int group);

    void setStatus(bool status);

    void print();
};
