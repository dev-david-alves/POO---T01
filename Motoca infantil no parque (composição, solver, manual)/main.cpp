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

    Pessoa* pessoa {nullptr};
    int potencia {1};
    int tempo {0};

    Moto(int potencia = 1) : potencia(potencia) {} 

    void comprarTempo(int tempo) {
        this->tempo += tempo;
        std::cout << "O tempo de " << this->tempo << " minutos foi adicionado ao total!\n";
    }

    bool subir(Pessoa *pessoa) {
        if(this->pessoa == nullptr) {
            this->pessoa = pessoa;

            std::cout << pessoa->nome << " subiu na moto!\n";
            return true;
        }

        std::cout << "Nao foi possivel subir na moto, pois ja tem uma pessoa nela!\n";

        return false;
    }

    Pessoa* descer() {
        if(this->pessoa != nullptr) {
            std::cout << this->pessoa->nome << " desceu da moto!\n";
            this->tempo = 0;
            return std::exchange(this->pessoa, nullptr);
        }

        std::cout << "Nao foi possivel descer da moto, pois ja nao tinha ninguem nela!\n";

        return nullptr;
    }

    void dirigir(int tempo) {
        if(this->pessoa != nullptr) {
            if(this->pessoa->idade <= 10 && this->tempo > 0) {
                if(tempo > this->tempo) {
                    std::cout << this->pessoa->nome << " pode dirigir a moto\n";
                    std::cout << "Dirigindo.........\n";
                    std::cout << "O tempo acabou, " << this->pessoa->nome << " dirigiu por " << this->tempo << " minutos!\n";
                    this->tempo = 0;
                    this->descer();
                } else {
                    std::cout << this->pessoa->nome << " ira dirigir a moto por " << tempo << " minutos!\n";
                    this->tempo -= tempo;
                }
            } else {
                if(this->pessoa->idade > 10) {
                    std::cout << this->pessoa->nome << " nao pode dirigir a moto por ser muito grande!\n";
                } else if(this->tempo <= 0) {
                    std::cout << this->pessoa->nome << " nao pode dirigir a moto, por falta de tempo!\n";
                }

                this->descer();
            }
        } else {
            std::cout << "Nao foi possivel dirigir, pois nao tinha ninguem na moto!\n";
        }
    }

    void buzinar() {
        if(this->pessoa != nullptr) {
            std::cout << "P" << std::string(this->potencia, 'e') << "m\n";
        } else {
            std::cout << "Nao foi possivel buzinar, pois nao tinha ninguem na moto!\n";
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Moto& moto) {
        os << "Moto -----------\n";
        os << "Potencia: " << moto.potencia << ", ";
        os << "Tempo: " << moto.tempo << ", ";
        if(moto.pessoa != nullptr) {
            os << "Pessoa: " << "[" << moto.pessoa->nome << ": " << moto.pessoa->idade << "]\n";
        } else {
            os << "Pessoa: null\n";
        }

        return os;
    }

    // float calibre;

    // static const int max_size = 10;
    // int num_pontas = 0;
    // Grafite* grafite[max_size];
    
    // Lapiseira(float calibre) {
    //     this->calibre = calibre;
    //     for(int i = 0; i < max_size; i++) {
    //         this->grafite[i] = nullptr;
    //     }
    // }

    // bool inserirGrafite(Grafite *grafite) {
    //     if(num_pontas >= max_size) {
    //         std::cout << "Ja tem grafites demais.\n";
    //         return false;
    //     }

    //     if(this->calibre != grafite->calibre) {
    //         std::cout << "Nao e posivel inserir, pois o calibre e imcompativel.\n";
    //         return false;
    //     }

    //     empurrarGrafite();
    //     this->grafite[0] = grafite;
    //     this->num_pontas++;

    //     std::cout << "Grafite inserido.\n";
    //     return true;
    // }

    // void empurrarGrafite() {
    //     for(int i = max_size - 1; i > 0; i--) {
    //         std::swap(this->grafite[i], this->grafite[i - 1]);
    //     }
    // }

    // bool removerGrafite() {
    //     if(this->grafite[0] == nullptr || this->num_pontas <= 0) {
    //         std::cout << "Nao e posivel remover mais, pois ja esta sem grafite.\n";
    //         return false;
    //     }

    //     this->grafite[0] = nullptr;
    //     puxarGrafite();
    //     this->num_pontas--;

    //     std::cout << "Grafite removido.\n";
    //     return true;
    // }

    // void puxarGrafite() {
    //     for(int i = 0; i < this->max_size - 1; i++) {
    //         std::swap(this->grafite[i], this->grafite[i + 1]);
    //     }
    // }

    // bool escrever(int folhas) {
    //     int quantidade_inicial = folhas;
    //     if(this->grafite[0] == nullptr || this->num_pontas <= 0) {
    //         std::cout << "Nao e possivel escrever, pois nao tem grafite.\n";
    //         return false;
    //     }

    //     while(folhas > 0) {
    //         if(this->grafite[0]->tamanho <= 10) {
    //             removerGrafite();
    //         }
            
    //         if(this->grafite[0] == nullptr) break;

    //         this->grafite[0]->tamanho -= this->grafite[0]->desgastePorFolha();

    //         folhas--;
    //     }

    //     if(this->grafite[0] != nullptr && this->grafite[0]->tamanho <= 10) {
    //         removerGrafite();
    //     }

    //     if(folhas > 0) {
    //         std::cout << "O texto ficou incompleto pois o grafite acabou, foi possivel escrever em " << quantidade_inicial - folhas << " folhas.\n";
    //         return false;
    //     }

    //     std::cout << "Folhas escritas com sucesso.\n";
    //     return true;
    // }

    // void print() {
    //     for(int i = 0; i < max_size; i++) {
    //         std::cout << this->grafite[i] << " ";
    //     }
    //     std::cout << "\n";
    // }
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

    moto.subir(&marisa);
    std::cout << moto << "\n";

    moto.comprarTempo(3);
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

    return 0;
}