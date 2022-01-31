#pragma once

#include "phone.hpp"

#include <iostream>
#include <vector>

class Contact {
    private:
        std::string name;
        std::vector<Phone> phones;
        std::string prefix = "-"; //utilizado no toString
        
    public:
        Contact(std::string name = "", std::vector<Phone> phones = {}) : name(name), phones(phones) {};

        void addPhone(Phone phone);

        void rmPhone(int index);

        //Getters and Setters

        std::string getName();

        void setName(std::string name);

        std::vector<Phone> getPhones();

        void setPhone(Phone phone);

        std::string getPrefix();

        std::string toString();
};