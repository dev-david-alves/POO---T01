#pragma once

#include <iostream>

class CheckingAccount: public Account {
    public:
        CheckingAccount(int id, std::string clientId): Account(id, clientId) {
            this->setType("CC");
        }

        // decrease balance by 20
        void monthlyUpdate() {
            this->setBalance(this->getBalance() - 20);
        }
};