#pragma once

#include <iostream>
#include <list>
#include <memory>

#include "kid.hpp"

class Trampoline {
    private:
        std::list<std::shared_ptr<Kid>> waiting;
        std::list<std::shared_ptr<Kid>> playing;

        // remove and return the Kid with this name or nullptr if not found
        static std::shared_ptr<Kid> remove_kid(std::string name, std::list<std::shared_ptr<Kid>>& list) {
            int index = 0;
            for(auto value: list) {
                if(value->getName() == name) {
                    auto it = list.begin();
                    advance(it, index);
                    list.erase(it);
                    return value;
                }
                index++;
            }

            return nullptr;
        }

    public:
        Trampoline() {}

        // put on the waiting list
        void arrive(std::shared_ptr<Kid> kid);

        // remove from waiting list and place on playing list
        void in();

        // remove from playing list and place on wainting list
        void out();

        // remove from the playground
        std::shared_ptr<Kid> remove(std::string name);

        // Print the list of kids
        friend std::ostream& operator<<(std::ostream& os, const Trampoline& trampoline) {
            os << "\nWaiting: ";
            for(auto& kid : trampoline.waiting) {
                os << "[" << *kid << "] ";
            }

            os << "\n";

            os << "Playing: ";
            for(auto& kid : trampoline.playing) {
                os << "[" << *kid << "] ";
            }

            os << "\n";

            return os;
        }
};