#pragma once

#include "phone.hpp"

std::string Phone::getId() {
    return this->id;
}

void Phone::setId(std::string id) {
    this->id = id;
}

std::string Phone::getNumber() {
    return this->number;
}

void Phone::setNumber(std::string number) {
    this->number = number;
}

std::string Phone::toString() {
    return this->getId() + ":" + this->getNumber();
}