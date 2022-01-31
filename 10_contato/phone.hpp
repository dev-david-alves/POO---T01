#pragma once

#include <iostream>

class Phone {
    private:
        std::string id;
        std::string number;
    public:
        Phone(std::string id, std::string number) : id(id), number(number) {}

        //check if the number is a valid phone number

        static bool validate(std::string number) {
            for(auto c: number) {
                if((c < '0' || c > '9') && (c != '.') && (c != '(') && (c != ')')) return false;
            }

            return true;
        }

        //Getters and Setters

        std::string getId();

        void setId(std::string id);

        std::string getNumber();

        void setNumber(std::string number);

        std::string toString();
};