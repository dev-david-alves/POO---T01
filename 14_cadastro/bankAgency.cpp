#include "bankAgency.hpp"
#include "savingsAccount.hpp"
#include "checkingAccount.hpp"

// If the client does not exist, it will be created.
// Create a savings account and a checking account for the client.
// Add those accounts to the vector of accounts and to the vector of clients.
// Add the client to the map of clients.
void BankAgency::addClient(std::string clientId) {
    if (clients.find(clientId) == clients.end()) {
        std::shared_ptr<Client> client = std::make_shared<Client>(clientId);
        client->addAccount(std::make_shared<CheckingAccount>(nextAccountId, clientId));
        client->addAccount(std::make_shared<SavingsAccount>((nextAccountId + 1), clientId));
        clients[clientId] = client;
        accounts[nextAccountId] = client->getAccounts()[0];
        accounts[nextAccountId + 1] = client->getAccounts()[1];
        nextAccountId += 2;
    }
}

// Get the client and call the actions
void BankAgency::withdraw(int accountId, float value) {
    auto account = this->getAccount(accountId);

    if(account != nullptr) {
        account->withdraw(value);
    }
}

void BankAgency::deposit(int accountId, float value) {
    auto account = this->getAccount(accountId);

    if(account != nullptr) {
        account->deposit(value);
    }
}

void BankAgency::transfer(int accountFrom, int accountTo, float value) {
    auto accountFromPtr = this->getAccount(accountFrom);
    auto accountToPtr = this->getAccount(accountTo);

    if(accountFromPtr != nullptr && accountToPtr != nullptr) {
        accountFromPtr->transfer(accountToPtr, value);
    }
}

void BankAgency::monthlyUpdate() {
    for (auto account: this->accounts) {
        account.second->monthlyUpdate();
    }
}