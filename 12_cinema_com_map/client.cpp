#include "client.hpp"

std::string Client::getId() {
    return id;
}

void Client::setId(std::string id) {
    this->id = id;
}

std::string Client::getFone() {
    return fone;
}

void Client::setFone(std::string fone) {
    this->fone = fone;
}