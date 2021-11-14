#include "kid.cpp"
#include "trampoline.cpp"

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
    trampoline.in();
    trampoline.in();
    trampoline.in();

    std::cout << trampoline << "\n";

    trampoline.out();
    trampoline.out();

    std::cout << trampoline << "\n";

    trampoline.remove("david");
    trampoline.remove("maria");

    std::cout << trampoline << "\n";

    trampoline.remove("francisco");
    trampoline.remove("jose");

    std::cout << trampoline << "\n";
}