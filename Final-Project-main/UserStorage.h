#pragma once
#include "User.h"
#include <string>
#include <vector>
#include <iostream>

class UserStorage {
private:
    std::vector<User*> users; // »спользуем вектор дл€ хранени€ пользователей
    int _userValue = 0;

public:
    UserStorage();
    ~UserStorage();

    bool registerUser(const std::string& login, const std::string& password, const std::string& name);

    User* login(const std::string& login, const std::string& password);

    int get_length() const;
    User* get_user(const std::string& login);
    User* get_user(const std::string&& login);

    void setUserValue(int userValue) { _userValue = userValue; }

    User* operator[](int i); // ќператор дл€ доступа к пользовател€м по индексу
};
