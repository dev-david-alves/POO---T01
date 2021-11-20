#pragma once

#include "contact.hpp"

void Contact::addPhone(Phone phone) {
    if(Phone::validate(phone.getNumber())) {
        std::cout << "Phone added.\n";
        this->setPhone(phone);
    } else {
        std::cout << "Cannot add the phone, cause it's an invalid phone number." << "\n";
    }
}

void Contact::rmPhone(int index) {
    if(index < 0 || index >= (int) getPhones().size()) {
        std::cout << "Cannot remove the phone, cause it's an invalid index." << "\n";
    } else {
        std::cout << "Phone removed.\n";
        phones.erase(phones.begin() + index);
    }
}

//Getters and Setters

std::string Contact::getName() {
    return this->name;
}

void Contact::setName(std::string name) {
    this->name = name;
}

std::vector<Phone> Contact::getPhones() {
    return this->phones;
}

void Contact::setPhone(Phone phone) {
    this->phones.push_back(phone);
}

std::string Contact::toString() {
    std::string text = "";
    int index = 0;
    for(auto phone: this->getPhones()) {
        text += " [" + std::to_string(index) + ":" + phone.toString() + "]";
        index++;
    }

    return this->prefix +  " " + this->name + text; 
}