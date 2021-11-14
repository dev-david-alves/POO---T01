#pragma once

#include "kid.hpp"

Kid::Kid(std::string name, int age) {
    this->name = name;
    this->age = age;
}

int Kid::getAge() {
    return age;
}

void Kid::setAge(int age) {
    this->age = age;
}

std::string Kid::getName() {
    return name;
}

void Kid::setName(std::string name) {
    this->name = name;
}