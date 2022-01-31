#include "trampoline.hpp"

// put on the waiting list
void Trampoline::arrive(std::shared_ptr<Kid> kid) {
    if(kid != nullptr) {
        waiting.push_back(kid);
        std::cout << kid->getName() << " put on waiting list.\n";
    } else {
        std::cout << "Nullptr cannot be put on the waiting list.\n";
    }
}

// remove from waiting list and place on playing list
void Trampoline::in() {
    if(waiting.size() > 0) {
        std::cout << waiting.front()->getName() << " put on playing list.\n";
        playing.push_back(waiting.front());
        waiting.pop_front();
    } else {
        std::cout << "There is no one on waiting list.\n";
    }
}

// remove from playing list and place on wainting list
void Trampoline::out() {
    if(playing.size() > 0) {
        std::cout << playing.front()->getName() << " put on waiting list.\n";
        waiting.push_back(playing.front());
        playing.pop_front();
    } else {
        std::cout << "There is no one on playing list.\n";
    }
}

// remove from the playground
std::shared_ptr<Kid> Trampoline::remove(std::string name) {
    std::shared_ptr<Kid> kid = remove_kid(name, playing);

    if(kid == nullptr) {
        kid = remove_kid(name, waiting);
    }

    if(kid != nullptr) {
        std::cout << kid->getName() << " removed from the playground.\n";
        return kid;
    }

    std::cout << "Kid not found on waiting list or playing list.\n";
    return nullptr;
}