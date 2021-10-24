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
    Grafite* grafite;

    Lapiseira(float calibre, Grafite* grafite) : calibre(calibre), grafite(grafite) {
    }

    bool inserirGrafite(Grafite *grafite) {
        if(this->grafite != nullptr) {
            std::cout << "Ja tem grafite.\n";
            return false;
        }

        if(grafite->calibre != this->calibre) {
            std::cout << "Nao e posivel inserir, pois o calibre e imcompativel.\n";
            return false;
        }

        this->grafite = grafite;
        std::cout << "Grafite inserido.\n";
        return true;
    }

    Grafite* removerGrafite() {
        if(this->grafite == nullptr) {
            std::cout << "Nao e posivel remover, pois ja esta sem grafite.\n";
            return nullptr;
        }

        std::cout << "Grafite removido.\n";
        return std::exchange(this->grafite, nullptr);
    }

    bool escrever(int folhas) {
        int quantidade_inicial = folhas;
        if(this->grafite == nullptr) {
            std::cout << "Nao e possivel escrever, pois nao tem grafite.\n";
            return false;
        }

        while(this->grafite->tamanho > 0 && folhas > 0) {
            this->grafite->tamanho -= this->grafite->desgastePorFolha();
            folhas--;
        }

        if(folhas > 0) {
            std::cout << "O texto ficou incompleto pois o grafite acabou, foi possivel escrever em " << quantidade_inicial - folhas << " folhas.\n";
            return false;
        }

        std::cout << "Folhas escritas com sucesso.\n";
        return true;
    }
};




int main() {
    Lapiseira lapiseira(2.0, nullptr);
    Grafite grafite1(1.0, "HB", 10);
    Grafite grafite2(2.0, "2B", 10);
    Grafite grafite3(2.0, "6B", 70);

    lapiseira.inserirGrafite(&grafite1);
    lapiseira.escrever(13);
    lapiseira.removerGrafite();

    std::cout << "\n";

    lapiseira.inserirGrafite(&grafite2);
    lapiseira.escrever(15);
    lapiseira.removerGrafite();

    std::cout << "\n";

    lapiseira.inserirGrafite(&grafite3);
    lapiseira.escrever(8);
    lapiseira.removerGrafite();

    return 0;
}