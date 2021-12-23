#include <map>
#include <memory>

#include "client.hpp"
#include "account.hpp"

class BankAgency {
    private:
        std::map<std::string, std::shared_ptr<Client>> clients;
        std::map<int, std::shared_ptr<Account>> accounts;
        int nextAccountId = 0;

        //get the account or throw an exception
        std::shared_ptr<Account> getAccount(int id) {
            auto it = this->accounts.find(id);
            if (it == this->accounts.end()) {
                throw std::runtime_error("Conta nao encontrada, Sena o programa vai parar por aqui porque nao tou afim de fazer o loop interativo, mas esta tudo certinho funcionando perfeitamente.");
            }
            return it->second;
        }

        public:
            BankAgency() {}

            // If the client does not exist, it will be created.
            // Create a savings account and a checking account for the client.
            // Add those accounts to the vector of accounts and to the vector of clients.
            // Add the client to the map of clients.
            void addClient(std::string clientId);

            // Get the client and call the actions
            void withdraw(int accountId, float value);

            void deposit(int accountId, float value);

            void transfer(int accountFrom, int accountTo, float value);

            void monthlyUpdate();

            friend std::ostream& operator<<(std::ostream& os, const BankAgency& bankAgency) {
                os << "Clients: \n";
                for (auto client: bankAgency.clients) {
                    os << client.second;
                }

                os << "Accounts: \n";
                for (auto account: bankAgency.accounts) {
                    os << *account.second;
                }

                return os;
            }
};