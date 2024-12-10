#pragma once
#include <vector>
#include <string>
#include "UserStorage.h"
#include "LocalMessage.h"

class GlobalMessage
{
private:
    std::vector<Message*> _message;  // Используем std::vector для хранения сообщений
    UserStorage* _userStorage;

public:
    GlobalMessage(UserStorage* userStorage);

    // Отправить сообщение
    void SendMessage(const std::string& login, const std::string& message);

    // Вывести все сообщения
    void PrintAll() const;
};
