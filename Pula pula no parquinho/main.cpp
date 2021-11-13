#include "kid.cpp"
#include "trampoline.hpp"

int main() {
    Kid jose("jose", 10);
    Kid maria("maria", 11);
    Kid elias("elias", 12);
    Kid david("david", 13);

    Trampoline trampoline;

    trampoline.arrive(&jose);
    trampoline.arrive(&maria);
    trampoline.arrive(&elias);
    trampoline.arrive(&david);

    std::cout << trampoline << "\n";

    trampoline.in();
    trampoline.in();

    std::cout << trampoline << "\n";
}