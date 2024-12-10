#include "LMStorage.h"
#include "LocalMessage.h"
#include <iostream>

LocalMessage* LMStorage::getLM(const std::string& login1, const std::string& login2) {
    for (auto lm : _localMessages) {
        if ((lm->getUser1()->get_login() == login1 && lm->getUser2()->get_login() == login2) ||
            (lm->getUser1()->get_login() == login2 && lm->getUser2()->get_login() == login1)) {
            return lm;
        }
    }
    return nullptr;
}

// Остальной код, если есть
