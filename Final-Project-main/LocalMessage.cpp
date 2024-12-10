#include "LocalMessage.h"
#include <iostream>

Message::Message(std::string name, std::string login, std::string message)
    : _name(name), _login(login), _message(message) {}

LocalMessage::LocalMessage() : _user1(nullptr), _user2(nullptr) {}

LocalMessage::LocalMessage(User* user1, User* user2) : _user1(user1), _user2(user2) {}

LocalMessage::~LocalMessage() {
    for (auto msg : _message) {
        delete msg;
    }
}

void LocalMessage::PrintAllMessage() {
    if (_message.empty()) {
        std::cout << "Нет сообщений." << std::endl;
    }
    else {
        for (const auto& msg : _message) {
            std::cout << msg->_name << " (" << msg->_login << "): " << msg->_message << std::endl;
        }
    }
}

void LocalMessage::SendMessage(std::string login, std::string message) {
    // Добавляем новое сообщение в контейнер
    _message.push_back(new Message(_user1->get_name(), login, message));
}
