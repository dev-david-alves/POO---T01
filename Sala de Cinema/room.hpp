#pragma once

#include <iostream>
#include <vector>

class Room {
    private:
        std::vector<Client> seats;
        
        std::vector<Client> getSeats();

    public:
        Room (int capacity = 0) {
            Client client;
            for(int i = 0; i < capacity; i++) {
                seats.push_back(client);
            }

            std::cout << "Room created with " << capacity << " seats.\n";
            this->toString();
        }

        bool reserve(std::string id, std::string fone, int index);
        
        void cancel(std::string id);
        
        void toString();
};