#include <iostream>
#include <algorithm>

struct Pessoa {
    std::string nome;
    int idade;

    Pessoa(std::string nome, int idade) : nome(nome), idade(idade) {}

    friend std::ostream& operator<<(std::ostream& os, const Pessoa& pessoa) {
        os << "Pessoa -----------\n";
        os << "Nome: " << pessoa.nome << ", ";
        os << "Idade: " << pessoa.idade << "\n";

        return os;
    }
};

struct Moto {

    static const int capacidade {3};
    int qtdPessoas {0};
    Pessoa* pessoa[capacidade] {nullptr};
    int potencia {1};
    int tempo {0};

    Moto(int potencia = 1) : potencia(potencia) {} 

    void comprarTempo(int tempo) {
        this->tempo += tempo;
        std::cout << "O tempo de " << this->tempo << " minutos foi adicionado ao total!\n";
    }

    bool subir(Pessoa *pessoa) {
        if(this->qtdPessoas < capacidade) {
            this->pessoa[qtdPessoas] = pessoa;
            this->qtdPessoas++;
            std::cout << pessoa->nome << " subiu na moto!\n";
            return true;
        }

        std::cout << "Nao foi possivel subir na moto, pois ja atingiu a capacidade maxima!\n";

        return false;
    }

    Pessoa* descer(int pos = 0) {
        if(this->qtdPessoas > 0) {
            Pessoa* pessoa = std::exchange(this->pessoa[pos], nullptr);
            this->qtdPessoas--;
            std::cout << pessoa->nome << " desceu da moto!\n";

            Pessoa* temp[capacidade] {nullptr};
            int cont {0};
            for(int i = 0; i < this->capacidade; i++) {
                if(this->pessoa[i] != nullptr) {
                    temp[cont] = this->pessoa[i];
                    cont++;
                }
            }

            for(int i = 0; i < this->capacidade; i++) {
                this->pessoa[i] = temp[i];
            }
            
            return pessoa;
        }

        std::cout << "Nao foi possivel descer da moto, pois ja nao tinha ninguem nela!\n";

        return nullptr;
    }

    void dirigir(int tempo) {
        if(this->pessoa[0] != nullptr) {
            if(this->pessoa[0]->idade <= 10 && this->tempo > 0) {
                if(tempo > this->tempo) {
                    std::cout << this->pessoa[0]->nome << " pode dirigir a moto\n";
                    std::cout << "Dirigindo.........\n";
                    std::cout << "O tempo acabou, " << this->pessoa[0]->nome << " dirigiu por " << this->tempo << " minutos!\n";
                    this->tempo = 0;
                    this->descer();
                } else {
                    std::cout << this->pessoa[0]->nome << " ira dirigir a moto por " << tempo << " minutos!\n";
                    this->tempo -= tempo;
                }
            } else {
                if(this->pessoa[0]->idade > 10) {
                    std::cout << this->pessoa[0]->nome << " nao pode dirigir a moto por ser muito grande!\n";
                } else if(this->tempo <= 0) {
                    std::cout << this->pessoa[0]->nome << " nao pode dirigir a moto, por falta de tempo!\n";
                }

                this->descer();
            }
        } else {
            std::cout << "Nao foi possivel dirigir, pois nao tinha ninguem na moto!\n";
        }
    }

    void buzinar() {
        if(this->qtdPessoas > 0) {
            std::cout << "P" << std::string(this->potencia, 'e') << "m\n";
        } else {
            std::cout << "Nao foi possivel buzinar, pois nao tinha ninguem na moto!\n";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Moto& moto) {
        os << "\nMoto -----------\n";
        os << "Potencia: " << moto.potencia << ", ";
        os << "Tempo: " << moto.tempo << ", ";

        os << "Pessoas: [  ";
        for(auto pessoa: moto.pessoa) {
            if(pessoa != nullptr) {
                os << pessoa->nome << ": " << pessoa->idade << "  ";
            } else {
                os << "null  ";
            }
        }

        os << "]\n";

        return os;
    }
};

int main() {
    Moto moto(5);
    std::cout << moto << "\n";
    moto.buzinar();

    Pessoa marcos("Marcos", 4);

    moto.subir(&marcos);
    std::cout << moto << "\n";

    moto.buzinar();

    Pessoa marisa("Marisa", 2);
    Pessoa josefina("Josefina", 10);
    Pessoa breno("Breno", 9);
    Pessoa david("David", 8);

    moto.subir(&marisa);
    std::cout << moto << "\n";

    moto.subir(&josefina);
    std::cout << moto << "\n";

    moto.subir(&breno);
    std::cout << moto << "\n";

    moto.subir(&david);
    std::cout << moto << "\n";

    moto.comprarTempo(30);
    std::cout << moto << "\n";

    moto.dirigir(5);
    std::cout << moto << "\n";

    moto.subir(&marisa);
    moto.comprarTempo(10);
    std::cout << moto << "\n";

    moto.dirigir(5);
    moto.descer();

    std::cout << moto << "\n";

    Pessoa jose("Jose", 23);
    moto.subir(&jose);
    std::cout << moto << "\n";

    moto.buzinar();
    moto.dirigir(15);
    std::cout << moto << "\n";

    moto.descer(1);
    std::cout << moto << "\n";

    moto.dirigir(15);
    std::cout << moto << "\n";

    moto.comprarTempo(5);
    std::cout << moto << "\n";

    moto.dirigir(10);
    std::cout << moto << "\n";

    moto.comprarTempo(5);
    std::cout << moto << "\n";

    moto.dirigir(10);
    std::cout << moto << "\n";

    return 0;
}