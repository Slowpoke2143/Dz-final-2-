#ifndef LOCALMESSAGE_H
#define LOCALMESSAGE_H

#include <string>
#include <vector>
#include "User.h"

class Message {
public:
    std::string _name;
    std::string _login;
    std::string _message;
    Message(std::string name, std::string login, std::string message);
};

class LocalMessage {
private:
    User* _user1;
    User* _user2;
    std::vector<Message*> _message;

public:
    LocalMessage();
    LocalMessage(User* user1, User* user2);
    ~LocalMessage();

    void PrintAllMessage();
    void SendMessage(std::string login, std::string message);

    // ѕубличные методы дл€ получени€ пользователей
    User* getUser1() const { return _user1; }
    User* getUser2() const { return _user2; }
};

#endif // LOCALMESSAGE_H
