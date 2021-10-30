#include <iostream>
#include <algorithm>

struct Grafite {
    float calibre;
    std::string dureza;
    int tamanho;

    Grafite(float calibre = 0, std::string dureza = "", int tamanho = 0) : calibre(calibre), dureza(dureza), tamanho(tamanho) {
    }

    int desgastePorFolha() {
        if(this->dureza == "HB") {
            return 1;
        } else if(this->dureza == "2B") {
            return 2;
        } else if(this->dureza == "4B") {
            return 4;
        } else if(this->dureza == "6B") {
            return 6;
        }

        return 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Grafite& grafite) {
        os << "Calibre: " << grafite.calibre << " mm, ";
        os << "Dureza: " << grafite.dureza << ", ";
        os << "Tamanho: " << grafite.tamanho << " mm\n";

        return os;
    }
};

struct Lapiseira {
    float calibre;

    static const int max_size = 10;
    int num_pontas = 0;
    Grafite* grafite[max_size];
    
    Lapiseira(float calibre) {
        this->calibre = calibre;
        for(int i = 0; i < max_size; i++) {
            this->grafite[i] = nullptr;
        }
    }

    bool inserirGrafite(Grafite *grafite) {
        if(num_pontas >= max_size) {
            std::cout << "Ja tem grafites demais.\n";
            return false;
        }

        if(this->calibre != grafite->calibre) {
            std::cout << "Nao e posivel inserir, pois o calibre e imcompativel.\n";
            return false;
        }

        empurrarGrafite();
        this->grafite[0] = grafite;
        this->num_pontas++;

        std::cout << "Grafite inserido.\n";
        return true;
    }

    void empurrarGrafite() {
        for(int i = max_size - 1; i > 0; i--) {
            std::swap(this->grafite[i], this->grafite[i - 1]);
        }
    }

    bool removerGrafite() {
        if(this->grafite[0] == nullptr || this->num_pontas <= 0) {
            std::cout << "Nao e posivel remover mais, pois ja esta sem grafite.\n";
            return false;
        }

        this->grafite[0] = nullptr;
        puxarGrafite();
        this->num_pontas--;

        std::cout << "Grafite removido.\n";
        return true;
    }

    void puxarGrafite() {
        for(int i = 0; i < this->max_size - 1; i++) {
            std::swap(this->grafite[i], this->grafite[i + 1]);
        }
    }

    bool escrever(int folhas) {
        int quantidade_inicial = folhas;
        if(this->grafite[0] == nullptr || this->num_pontas <= 0) {
            std::cout << "Nao e possivel escrever, pois nao tem grafite.\n";
            return false;
        }

        while(folhas > 0) {
            if(this->grafite[0]->tamanho <= 10) {
                removerGrafite();
            }
            
            if(this->grafite[0] == nullptr) break;

            this->grafite[0]->tamanho -= this->grafite[0]->desgastePorFolha();

            folhas--;
        }

        if(this->grafite[0] != nullptr && this->grafite[0]->tamanho <= 10) {
            removerGrafite();
        }

        if(folhas > 0) {
            std::cout << "O texto ficou incompleto pois o grafite acabou, foi possivel escrever em " << quantidade_inicial - folhas << " folhas.\n";
            return false;
        }

        std::cout << "Folhas escritas com sucesso.\n";
        return true;
    }

    void print() {
        for(int i = 0; i < max_size; i++) {
            std::cout << this->grafite[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Lapiseira lapiseira(2.0);
    Grafite grafite1(1.0, "HB", 10);
    Grafite grafite2(2.0, "6B", 70);

    Grafite grafite3(2.0, "2B", 16);
    Grafite grafite4(2.0, "2B", 16);
    Grafite grafite5(2.0, "2B", 16);
    Grafite grafite6(2.0, "2B", 16);
    Grafite grafite7(2.0, "2B", 16);
    Grafite grafite8(2.0, "2B", 16);

    lapiseira.inserirGrafite(&grafite1);
    lapiseira.escrever(13);
    lapiseira.removerGrafite();

    std::cout << "\n";

    lapiseira.inserirGrafite(&grafite2);
    lapiseira.inserirGrafite(&grafite4);
    lapiseira.inserirGrafite(&grafite5);
    lapiseira.inserirGrafite(&grafite6);
    lapiseira.inserirGrafite(&grafite7);
    lapiseira.inserirGrafite(&grafite8);
    
    lapiseira.escrever(15);
    lapiseira.removerGrafite();

    std::cout << "\n";

    lapiseira.inserirGrafite(&grafite3);
    lapiseira.escrever(8);
    lapiseira.removerGrafite();

    std::cout << grafite1 << "\n";

    return 0;
}