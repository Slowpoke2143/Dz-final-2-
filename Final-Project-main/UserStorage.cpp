#include "UserStorage.h"
#include <vector>
#include <algorithm> // Для std::find

UserStorage::UserStorage() {}

UserStorage::~UserStorage()
{
    for (auto user : users)
    {
        delete user;
    }
}

bool UserStorage::registerUser(const std::string& login, const std::string& password, const std::string& name)
{
    // Проверяем, не существует ли уже пользователь с таким логином
    auto it = std::find_if(users.begin(), users.end(),
        [&login](User* user) { return user->get_login() == login; });

    if (it != users.end())
    {
        return false; // Логин уже занят
    }

    // Регистрируем нового пользователя
    users.push_back(new User(login, password, name));
    return true;
}

int UserStorage::get_length() const
{
    return users.size();
}

User* UserStorage::get_user(const std::string& login)
{
    auto it = std::find_if(users.begin(), users.end(),
        [&login](User* user) { return user->get_login() == login; });

    return it != users.end() ? *it : nullptr;
}

User* UserStorage::get_user(const std::string&& login)
{
    auto it = std::find_if(users.begin(), users.end(),
        [&login](User* user) { return user->get_login() == login; });

    return it != users.end() ? *it : nullptr;
}

User* UserStorage::login(const std::string& login, const std::string& password)
{
    auto it = std::find_if(users.begin(), users.end(),
        [&login, &password](User* user) { return user->get_login() == login && user->get_password() == password; });

    if (it != users.end())
    {
        std::cout << "Welcome, " << (*it)->get_name() << "!" << std::endl;
        return *it;
    }

    throw std::runtime_error("Invalid login or password");
}

User* UserStorage::operator[](int i)
{
    if (i < users.size())
        return users[i];

    return nullptr;
}
