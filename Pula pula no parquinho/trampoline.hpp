#include <iostream>
#include <list>
#include <memory>

class Trampoline {
    private:
        std::list<Kid> waiting;
        std::list<Kid> playing;

    public:
        Trampoline() {}

        Kid* remove_kid(std::string name, std::list<Kid> list) {

            for(auto it = list.begin(); it != list.end(); it++) {
                if(it->getName() == name) {
                    list.erase(it);
                    return &*it;
                }                
            }

            return nullptr;
        }

        //put on the waiting list
        void arrive(Kid* kid) {
            waiting.push_back(*kid);

            // std::cout << "Arriving " << kid->getName() << "\n";
        }

        // remove from waiting list and place on playing list
        void in() {
            if(waiting.size() > 0) {
                playing.push_back(waiting.front());
                waiting.pop_front();
            }
        }

        void out() {

        }

        Kid* remove(std::string name) {
            std::cout << "Removing " << name << "\n";
            return nullptr;
        }

        friend std::ostream& operator<<(std::ostream& os, const Trampoline& trampoline) {
            os << "Waiting: ";
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