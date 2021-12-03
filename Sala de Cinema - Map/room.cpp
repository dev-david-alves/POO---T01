#pragma once

#include "room.hpp"

int Room::findClient(std::string id) {
    int index = 0; 
    for (auto value: this->getSeats()) {
        if (value != nullptr && value->getId() == id) {
            return index;
        }

        index++;
    }

    return -1;
}

std::vector<std::shared_ptr<Client>> Room::getSeats() {
    return seats;
}

void Room::setSeat(int index, std::shared_ptr<Client> client) {
    this->seats[index] = client;
}

bool Room::reserve(std::string id, std::string fone, int index){
    if(index < 0 || index >= (int) this->getSeats().size()) {
        std::cout << "Cannot register on seat " << index << " cause this is an invalid seat.\n";
        return false;
    }

    if(findClient(id) != -1) {
        std::cout << "Cannot register " << id << " cause it's already registered.\n";
        return false;
    }

    if(this->getSeats()[index] != nullptr) {
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
    for(auto seat: this->getSeats()) {
        if(seat == nullptr) {
            std::cout << " - ";
        } else {
            std::cout << "[" << seat->getId() << " " << seat->getFone() << "] ";
        }
    }

    std::cout << "\n";
}