#include "account.hpp"

// Withdraw
void Account::withdraw(float value) {
    if (value > this->balance) {
        std::cout << "Impossivel sacar, saldo insuficiente.\n";
    } else {
        this->balance -= value;
    }
}

// Deposit
void Account::deposit(float value) {
    this->balance += value;
}

// Transfer to another account
void Account::transfer(std::shared_ptr<Account> other, float value) {
    if (value > this->balance) {
        std::cout << "Impossivel trasferir, saldo insuficiente.\n";
    } else {
        this->balance -= value;
        other->deposit(value);
    }
}

// Getters and Setters
int Account::getId() {
    return this->id;
}

float Account::getBalance() {
    return this->balance;
}

std::string Account::getClientId() {
    return this->clientId;
}

std::string Account::getType() {
    return this->type;
}

void Account::setId(int id) {
    this->id = id;
}

void Account::setBalance(float balance) {
    this->balance = balance;
}

void Account::setClientId(std::string clientId) {
    this->clientId = clientId;
}

void Account::setType(std::string type) {
    this->type = type;
}