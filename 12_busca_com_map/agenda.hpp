#pragma once

#include <iostream>
#include <map>

#include "../Contato/contact.hpp"

class Agenda {
    private:
        std::map<std::string, Contact> contacts;

        // merge the phones

        void mergePhones(Contact contact);

    public:
        Agenda() {}

        // returns the contact object with that name or null if it does not exist
        Contact findContact(std::string name);

        // if no contact exists with that name, add it
        // if it already exists, merge it by adding the phones
        // if you've added a new contact, sort the list to alphabetical order
        void addContact(Contact contact);

        // if the phone exists, remove it
        void rmPhone(std::string name, int id);

        // if the contact exists, remove it
        void rmContact(std::string name);

        // build a helper list by looking in each contact's .toString()
        std::map<std::string, Contact> search(std::string pattern);

        // Only used to print the search results        
        void printSearch(std::map<std::string, Contact> result);

        std::string toString();
};