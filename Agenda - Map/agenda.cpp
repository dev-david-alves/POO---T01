#include <algorithm>

#include "agenda.hpp"

void Agenda::mergePhones(Contact contact) {
    auto itr = this->contacts.find(contact.getName());
    
    for(auto phone: contact.getPhones()) {
        itr->second.setPhone(phone);
    }
}

// if no contact exists with that name, add it
// if it already exists, merge it by adding the phones
// if you've added a new contact, sort the list to alphabetical order
void Agenda::addContact(Contact contact) {
    auto itr = this->contacts.find(contact.getName());

    if (itr == this->contacts.end()) {
        this->contacts.insert(std::pair<std::string, Contact>(contact.getName(), contact));
        std::cout << "New contact added.\n";
    } else {
        this->mergePhones(contact);
        std::cout << "This contact already exists, so it was merged.\n";
    }
}

// if the phone exists, remove it
void Agenda::rmPhone(std::string name, int id) {
    auto itr = this->contacts.find(name);

    if (itr != this->contacts.end()) {
        itr->second.rmPhone(id);
    }
}

// if the contact exists, remove it
void Agenda::rmContact(std::string name) {
    auto itr = this->contacts.find(name);

    if (itr != this->contacts.end()) {
        this->contacts.erase(itr);
        std::cout << "Contact removed.\n";
    }
}

// build a helper list by looking in each contact's .toString()
std::map<std::string, Contact> Agenda::search(std::string pattern) {
    std::map<std::string, Contact> result;

    for (auto itr = this->contacts.begin(); itr != this->contacts.end(); ++itr) {
        if (itr->second.toString().find(pattern) != std::string::npos) {
            result.insert(std::pair<std::string, Contact>(itr->first, itr->second));
        }
    }

    return result;
}

void Agenda::printSearch(std::map<std::string, Contact> result) {
    std::cout << "Search results:\n";
    
    for (auto itr = result.begin(); itr != result.end(); ++itr) {
        std::cout << itr->second.toString() << "\n";
    }
}

std::string Agenda::toString() {
    for (auto itr = this->contacts.begin(); itr != this->contacts.end(); ++itr) {
        std::cout << itr->second.toString() << "\n";
    }

    return "";
}