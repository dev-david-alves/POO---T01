#pragma once

#include <algorithm>

#include "agenda.hpp"
#include "../Contato/contact.cpp"
#include "../Contato/phone.cpp"

// returns the position of the contact with that name in the vector or -1 if it does not exist.
int Agenda::findPosByName(std::string name) {
    for (int i = 0; i < (int) this->contacts.size(); i++) {
        if (contacts[i].getName() == name) {
            return i;
        }
    }

    return -1;
}

void Agenda::mergePhones(int pos, Contact contact) {
    for(auto phone: contact.getPhones()) {
        this->contacts[pos].setPhone(phone);
    }
}

// returns the contact object with that name or null if it does not exist
Contact Agenda::findContact(std::string name) {
    int pos = findPosByName(name);

    if (pos == -1) {
        return this->contacts[pos];
    }

    return this->contacts[pos];
}

// if no contact exists with that name, add it
// if it already exists, merge it by adding the phones
// if you've added a new contact, sort the list to alphabetical order
void Agenda::addContact(Contact contact) {
    int pos = findPosByName(contact.getName());

    if (pos == -1) {
        this->contacts.push_back(contact);
        std::cout << "New contact added.\n";
    } else {
        this->mergePhones(pos, contact);
        std::cout << "This contact already exists, so it was merged.\n";
    }

    std::sort(this->contacts.begin(), this->contacts.end(), [](Contact a, Contact b) {
        return a.getName() < b.getName();
    });
}

// if the phone exists, remove it
void Agenda::rmPhone(std::string name, int id) {
    int pos = findPosByName(name);

    if (pos != -1) {
        this->contacts[pos].rmPhone(id);
    }
}

// if the contact exists, remove it
void Agenda::rmContact(std::string name) {
    int pos = findPosByName(name);

    if (pos != -1) {
        this->contacts.erase(this->contacts.begin() + pos);
        std::cout << "Contact removed.\n";
    }
}

// build a helper list by looking in each contact's .toString()
std::vector<Contact> Agenda::search(std::string pattern) {
    std::vector<Contact> result;
    
    for(auto contact: this->contacts) {
        if(contact.toString().find(pattern) != std::string::npos) {
            result.push_back(contact);
        }
    }

    return result;
}

void Agenda::printSearch(std::vector<Contact> result) {
    std::cout << "Search results:\n";
    for(auto contact: result) {
        std::cout << contact.toString() << "\n";
    }
}

// get the list of contacts
std::vector<Contact> Agenda::getContacts() {
    return this->contacts;
}

std::string Agenda::toString() {
    for(auto contact: this->contacts) {
        std::cout << contact.toString() << "\n";
    }

    return "";
}