#pragma once

#include <string>

class User {
private:
    std::string userName;
    std::string userSurname;
    std::string userLogin;
    std::string userEmail;
    std::string userPassword;
public:
    User();

    User(std::string name);

    User(std::string name, std::string surname);

    User(std::string name, std::string surname, std::string login);

    User(std::string name, std::string surname, std::string login, std::string email);

    User(std::string name, std::string surname, std::string login, std::string email, std::string password);

    std::string getName();

    std::string getSurname();

    std::string getLogin();

    std::string getEmail();

    std::string getPassword();

    void setName(std::string name);

    void setSurname(std::string surname);

    void setLogin(std::string login);

    void setEmail(std::string email);

    void setPassword(std::string password);

    void print();
};

