#pragma once
#include <vector>
#include <string>
#include "UserStorage.h"
#include "LocalMessage.h"

class GlobalMessage
{
private:
    std::vector<Message*> _message;  // ���������� std::vector ��� �������� ���������
    UserStorage* _userStorage;

public:
    GlobalMessage(UserStorage* userStorage);

    // ��������� ���������
    void SendMessage(const std::string& login, const std::string& message);

    // ������� ��� ���������
    void PrintAll() const;
};
