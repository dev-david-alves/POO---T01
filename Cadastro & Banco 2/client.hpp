#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "account.hpp"

class Client {
    private:
        std::string clientId;
        std::vector<std::shared_ptr<Account>> accounts;

    public:
        Client(std::string clientId): clientId(clientId) {}

        void addAccount(std::shared_ptr<Account> account);

        // Getters and Setters
        std::string getClientId();

        void setClientId(std::string clientId);

        std::vector<std::shared_ptr<Account>> getAccounts();

        void setAccounts(std::vector<std::shared_ptr<Account>> accounts);

        friend std::ostream& operator<<(std::ostream& os, Client* client) {
            std::vector<std::shared_ptr<Account>> account = client->getAccounts();

            os << "- " << client->clientId << " [";

            for (int i = 0; i < (int) account.size() - 1; i++) {
                os << account[i]->getId() << ", ";
            }

            os << account[account.size() - 1]->getId() << "]\n";
            
            return os;
        }
};