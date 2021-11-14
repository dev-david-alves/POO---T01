#pragma once

#include <iostream>

class Client {
    private:
        std:: string id;
        std:: string fone;

    public:
        Client(std::string id = "-", std::string fone = "") : id(id), fone(fone) {}

        std::string getId();

        void setId(std::string id);

        std::string getFone();

        void setFone(std::string fone);

        friend std::ostream& operator<<(std::ostream& os, const Client& client) {
            os << client.id << " - " << client.fone;
            return os;
        }

};