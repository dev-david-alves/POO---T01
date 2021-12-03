#include "phone.hpp"
#include "contact.hpp"

int main() {
    Contact contact("David");
    std::cout << contact.toString() << "\n";

    contact.addPhone(Phone("oi", "88"));
    contact.addPhone(Phone("tim", "99"));
    contact.addPhone(Phone("tim", "98"));
    contact.addPhone(Phone("vivo", "83"));
    std::cout << contact.toString() << "\n";

    contact.rmPhone(2);
    std::cout << contact.toString() << "\n";

    contact.rmPhone(0);
    std::cout << contact.toString() << "\n";

    contact.addPhone(Phone("tim", "9a9"));
    contact.addPhone(Phone("tim", "(85)99.99"));
    std::cout << contact.toString() << "\n";

    contact.rmPhone(5);
    std::cout << contact.toString() << "\n";

    return 0;
}