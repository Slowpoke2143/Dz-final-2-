#include "GlobalMessage.h"
#include <iostream>

GlobalMessage::GlobalMessage(UserStorage* userStorage) : _userStorage(userStorage) {}

void GlobalMessage::SendMessage(const std::string& login, const std::string& message)
{
    _message.push_back(new Message(_userStorage->get_user(login)->get_name(), login, message));
}

void GlobalMessage::PrintAll() const
{
    if (_message.empty())
    {
        std::cout << "Нет глобальных сообщений!" << std::endl;
        return;
    }

    for (const auto& msg : _message)
    {
        std::cout << msg->_name << ": " << msg->_message << std::endl;
    }
}
