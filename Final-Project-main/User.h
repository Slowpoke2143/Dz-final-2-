#pragma once
#include <iostream>
#include <string>
#include <vector>

class User {
protected:
    std::string _login;
    std::string _password;
    std::string _name;

public:
    User() {}
    User(const std::string& login, const std::string& password, const std::string& name)
        : _login(login), _password(password), _name(name) {}

    ~User() = default;

    const std::string& get_login() const { return _login; }
    const std::string& get_password() const { return _password; }
    const std::string& get_name() const { return _name; }

    void set_login(const std::string& login) { _login = login; }
    void set_password(const std::string& password) { _password = password; }
    void set_name(const std::string& name) { _name = name; }

    bool operator==(const std::string& login) const {
        return _login == login;
    }
};
