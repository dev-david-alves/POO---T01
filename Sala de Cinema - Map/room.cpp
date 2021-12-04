#include "room.hpp"

Room::Room (int capacity) {
    std::shared_ptr<Client> client;
    for(int i = 0; i < capacity; i++) {
        this->seats.insert(std::pair<int, std::shared_ptr<Client>>(i, client));
    }

    std::cout << "Room created with " << capacity << " seats.\n";
    this->toString();
}

int Room::findClient(std::string id) {
    for(auto itr = this->seats.begin(); itr != this->seats.end(); itr++) {
        if(itr->second != nullptr && itr->second->getId() == id) {
            return itr->first;
        }
    }

    return -1;
}

void Room::setSeat(int index, std::shared_ptr<Client> client) {
    auto itr = this->seats.find(index);
    if(itr != this->seats.end()) {
        itr->second = client;
    }
}

bool Room::reserve(std::string id, std::string fone, int index){
    auto itr = this->seats.find(index);

    if(itr == this->seats.end()) {
        std::cout << "Cannot register on seat " << index << " cause this is an invalid seat.\n";
        return false;
    }

    if(findClient(id) != -1) {
        std::cout << "Cannot register " << id << " cause it's already registered.\n";
        return false;
    }

    if(itr->second != nullptr) {
        std::cout << "Cannot register on seat " << index << " cause this seat is already taken.\n";
        return false;
    }

    std::cout << "Reserving seat " << index << " for " << id << ".\n";

    std::shared_ptr<Client> client(new Client(id, fone));

    this->setSeat(index, client);
    this->toString();

    return true;
}

void Room::cancel(std::string id) {
    int clientIndex = findClient(id);

    if(clientIndex == -1) {
        std::cout << "Cannot cancel " << id << " cause it's not registered.\n";
    } else {
        this->setSeat(clientIndex, nullptr);
        std::cout << "Reservation Canceled for " << id << ".\n";
    }

    this->toString();
}

void Room::toString() {
    for(auto itr = this->seats.begin(); itr != this->seats.end(); itr++) {
        if(itr->second == nullptr) {
            std::cout << " - ";
        } else {
            std::cout << "[" << itr->second->getId() << " " << itr->second->getFone() << "] ";
        }
    }

    std::cout << "\n";
}