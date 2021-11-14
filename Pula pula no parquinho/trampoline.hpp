#pragma once

#include <iostream>
#include <list>

class Trampoline {
    private:
        std::list<Kid> waiting;
        std::list<Kid> playing;

        // remove and return the Kid with this name or nullptr if not found
        static Kid* remove_kid(std::string name, std::list<Kid>& list) {
            for(auto it = list.begin(); it != list.end(); it++) {
                if(it->getName() == name) {
                    auto kid = &*it;
                    list.erase(it);
                    return kid;
                }
            }

            return nullptr;
        }

    public:
        Trampoline() {}

        // put on the waiting list
        void arrive(Kid* kid);

        // remove from waiting list and place on playing list
        void in();

        // remove from playing list and place on wainting list
        void out();

        // remove from the playground
        Kid* remove(std::string name);

        // Print the list of kids
        friend std::ostream& operator<<(std::ostream& os, const Trampoline& trampoline) {
            os << "\nWaiting: ";
            for(auto& kid : trampoline.waiting) {
                os << "[" << kid << "] ";
            }

            os << "\n";

            os << "Playing: ";
            for(auto& kid : trampoline.playing) {
                os << "[" << kid << "] ";
            }

            os << "\n";

            return os;
        }
};