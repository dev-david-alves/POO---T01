#include "client.hpp"

void Client::addAccount(std::shared_ptr<Account> account) {
    accounts.push_back(account);
}

// Getters and Setters
std::string Client::getClientId() {
    return clientId;
}

void Client::setClientId(std::string clientId) {
    this->clientId = clientId;
}

std::vector<std::shared_ptr<Account>> Client::getAccounts() {
    return accounts;
}

void Client::setAccounts(std::vector<std::shared_ptr<Account>> accounts) {
    this->accounts = accounts;
}