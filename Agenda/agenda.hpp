#pragma once

#include <iostream>
#include <vector>

#include "../Contato/contact.hpp"

class Agenda {
    private:
        std::vector<Contact> contacts;

        // returns the position of the contact with that name in the vector or -1 if it does not exist.
        int findPosByName(std::string name);

        // merge the phones

        void mergePhones(int pos, Contact contact);

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
        std::vector<Contact> search(std::string pattern);

        // Only used to print the search results        
        void printSearch(std::vector<Contact> result);

        // get the list of contacts
        std::vector<Contact> getContacts();

        std::string toString();
};