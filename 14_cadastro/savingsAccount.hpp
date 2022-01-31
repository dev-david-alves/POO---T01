#pragma once

#include <iostream>

class SavingsAccount: public Account {
    public:
        SavingsAccount(int id, std::string clientId) : Account(id, clientId) {
            this->setType("CP");
        }
                
        // increasy the balance of the account by 1%
        void monthlyUpdate() {
            double new_amount = this->getBalance() * 0.01;
            this->setBalance(this->getBalance() + new_amount);
        }
};