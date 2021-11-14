#pragma once

#include "room.hpp"

std::vector<Client> Room::getSeats() {
    return seats;
}

bool Room::reserve(std::string id, std::string fone, int index){
    if(index < 0 || index >= (int) seats.size()) {
        std::cout << index << " is an invalid seat.\n";
        return false;
    }

    for(int i = 0; i < (int) seats.size(); i++) {
        if(seats[i].getId() == id) {
            std::cout << "Cannot register " << id << " cause it's already registered.\n";
            return false;
        }
    }

    if(seats[index].getId() != "-") {
        std::cout << "Cannot register cause this seat is already taken.\n";
        return false;
    }

    std::cout << "Reserving seat " << index << " for " << id << ".\n";

    Client client(id, fone);
    seats[index] = client;

    this->toString();

    return true;
}

void Room::cancel(std::string id) {
    bool exists = false;

    for(int i = 0; i < (int) seats.size(); i++) {
        if(seats[i].getId() == id) {
            exists = true;
            break;
        }
    }

    if(!exists) {
        std::cout << "Cannot cancel " << id << " cause it's not registered.\n";
    } else {
        for(int i = 0; i < (int) seats.size(); i++) {
            if(seats[i].getId() == id) {
                seats[i].setId("-");
                seats[i].setFone("");
                break;
            }
        }

        std::cout << "Reservation Canceled for " << id << ".\n";
    }

    this->toString();
}

void Room::toString() {
    std::cout << "\n";
    for(auto c: this->getSeats()) {
        if(c.getId() == "-") {
            std::cout << " - ";
        } else {
            std::cout << "[" << c.getId() << " " << c.getFone() << "] ";
        }
    }

    std::cout << "\n";
}