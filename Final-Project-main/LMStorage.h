#ifndef LMSTORAGE_H
#define LMSTORAGE_H

#include "LocalMessage.h"
#include <vector>
#include <string>

class LMStorage {
private:
    std::vector<LocalMessage*> _localMessages; // Хранение сообщений

public:
    LocalMessage* getLM(const std::string& login1, const std::string& login2);
    void addLM(User* user1, User* user2) {
        _localMessages.push_back(new LocalMessage(user1, user2));
    }

    // Остальные методы, если есть
};

#endif // LMSTORAGE_H
