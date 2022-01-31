#pragma once

#include <iostream>
#include <map>
#include <memory>

#include "client.hpp"

class Room {
    private:
        std::map<int, std::shared_ptr<Client>> seats;
        
    public:
        Room(int capacity = 0);

        void setSeat(int index, std::shared_ptr<Client> client);

        int findClient(std::string id);

        bool reserve(std::string id, std::string fone, int index);
        
        void cancel(std::string id);
        
        void toString();
};