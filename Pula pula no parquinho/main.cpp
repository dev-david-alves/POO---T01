#include "trampoline.hpp"

int main() {
    std::shared_ptr<Kid> jose(new Kid("jose", 10));
    std::shared_ptr<Kid> maria(new Kid("maria", 11));
    std::shared_ptr<Kid> elias(new Kid("elias", 12));
    std::shared_ptr<Kid> david(new Kid("david", 13));

    Trampoline trampoline;

    trampoline.arrive(jose);
    trampoline.arrive(maria);
    trampoline.arrive(elias);
    trampoline.arrive(david);

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