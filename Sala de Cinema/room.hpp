#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "client.hpp"

class Room {
    private:
        std::vector<std::shared_ptr<Client>> seats;
        
    public:
        Room(int capacity = 0);

        std::vector<std::shared_ptr<Client>> getSeats();

        void setSeat(int index, std::shared_ptr<Client> client);

        int findClient(std::string id);

        bool reserve(std::string id, std::string fone, int index);
        
        void cancel(std::string id);
        
        void toString();
};