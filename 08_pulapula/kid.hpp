#pragma once

#include <iostream>

class Kid {
    private:
        std::string name;
        int age;

    public:
        Kid(std::string name, int age);

        int getAge();

        void setAge(int age);

        std::string getName();

        void setName(std::string name);

        friend std::ostream& operator<<(std::ostream& os, const Kid& kid) {
            os << kid.name << " - " << kid.age;
            return os;
        }
};