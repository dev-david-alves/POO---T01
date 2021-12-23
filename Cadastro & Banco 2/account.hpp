#pragma once

#include <iostream>
#include <memory>
#include <iomanip>

class Account {
    protected:
        int id;
        float balance {0.00};
        std::string type {""};
        std::string clientId;

    public:
        Account(int id, std::string clientId): id(id), clientId(clientId) {}

        // Withdraw
        void withdraw(float value);

        // Deposit
        void deposit(float value);

        // Transfer to another account
        void transfer(std::shared_ptr<Account> other, float value);

        virtual void monthlyUpdate() = 0;

        // Getters and Setters
        int getId();

        float getBalance();

        std::string getClientId();

        std::string getType();

        void setId(int id);

        void setBalance(float balance);

        void setClientId(std::string clientId);

        void setType(std::string type);

        // Print
        friend std::ostream& operator<<(std::ostream& os, const Account& account) {
            os << account.id << ":" << account.clientId << ":" << std::fixed << std::setprecision(2) << account.balance << ":" << account.type << "\n";
            return os;
        }
};