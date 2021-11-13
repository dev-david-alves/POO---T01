// #include "trampoline.hpp"
// #include <iterator>

// //remove and return the Kid with this name or null
// Kid* Trampoline::remove_kid(std::string name, std::list<Kid> list) {

//     for(int i = 0; i < (int) list.size(); i++) {
//         // std::advance(it, i);
//         // if(it.getName() == name) {
//         //     auto kid = it;
//         //     list.erase(list.begin() + i);
//         //     return it;
//         // }
//         std::next(list.begin(), i);
//     }

//     std::cout << name << " is not playing" << "\n";

//     return nullptr;
// }

// //put on the waiting list
// void Trampoline::arrive(Kid* kid) {
//     this->waiting.push_back(kid);
//     std::cout << "Kid " << this->waiting.back().getName() << " is waiting" << "\n";
// }

// // remove from waiting list and place on playing list
// void Trampoline::in() {
//     if(this->waiting.size() > 0) {
//         this->playing.push_back(this->waiting.front());
//         this->waiting.pop_front();
//         std::cout << "Kid " << this->playing.back().getName() << " is playing" << "\n";
//     } else {
//         std::cout << "There is no one waiting to play" << "\n";
//     }
// }

// //remove from playing to wainting
// void Trampoline::out() {
//     if(this->playing.size() > 0) {
//         this->waiting.push_back(this->playing.front());
//         this->playing.pop_front();
//         std::cout << "Kid " << this->waiting.back().getName() << " is waiting" << "\n";
//     } else {
//         std::cout << "There is no one playing" << "\n";
//     }
// }

// // remove from the playground
// Kid* Trampoline::remove(std::string name) {
//     // if(this->playing.size() > 0) {
//     //     for(int i = 0; i < (int) this->playing.size(); i++) {
//     //         if(this->playing.at(i).getName() == name) {
//     //             auto kid = this->playing.at(i);
//     //             this->playing.erase(this->playing.begin() + i);
//     //             return kid;
//     //         }
//     //     }
//     // }

//     // if(this->wainting.size() > 0) {
//     //     for(int i = 0; i < (int) this->wainting.size(); i++) {
//     //         if(this->wainting.at(i).getName() == name) {
//     //             auto kid = this->wainting.at(i);
//     //             this->wainting.erase(this->wainting.begin() + i);
//     //             return kid;
//     //         }
//     //     }
//     // }

//     std::cout << name << " is not playing" << "\n";
    

//     return nullptr;
// }