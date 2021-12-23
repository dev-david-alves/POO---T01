#include "bankAgency.hpp"

int main() {
    try {
        BankAgency bankAgency;
        bankAgency.addClient("Almir");
        bankAgency.addClient("Julia");
        bankAgency.addClient("Maria");

        std::cout << bankAgency << "\n";

        bankAgency.deposit(0, 100);
        bankAgency.deposit(1, 200);
        bankAgency.deposit(2, 50);
        bankAgency.deposit(3, 300);

        bankAgency.withdraw(3, 50);
        bankAgency.withdraw(0, 70);
        bankAgency.withdraw(1, 300);

        std::cout << bankAgency << "\n";

        bankAgency.transfer(3, 5, 200);
        bankAgency.transfer(0, 4, 25);

        std::cout << bankAgency << "\n";

        bankAgency.monthlyUpdate();

        std::cout << bankAgency << "\n";

        bankAgency.transfer(9, 1, 30);
        bankAgency.transfer(2, 8, 10);

        std::cout << bankAgency << "\n";

    } catch (std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}