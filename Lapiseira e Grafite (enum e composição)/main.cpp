#include <iostream>
#include <algorithm>

struct Grafite {
    float calibre;
    std::string dureza;
    int tamanho;

    Grafite(float calibre = 0, std::string dureza = "", int tamanho = 0) : calibre(calibre), dureza(dureza), tamanho(tamanho) {
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
            std::cout << "Já tem grafite.\n";
            return false;
        }

        if(grafite->calibre != this->calibre) {
            std::cout << "Calibre imcompatível.\n";
            return false;
        }

        this->grafite = grafite;
        return true;
    }

    Grafite* removerGrafite() {
        if(this->grafite == nullptr) {
            std::cout << "Já está sem grafite.\n";
            return nullptr;
        }

        return std::exchange(this->grafite, nullptr);
    }
};




int main() {

    Grafite grafite(1.0, "HB", 10);
    Lapiseira lapiseira(0.1, &grafite);

    lapiseira.grafite->tamanho -= 5;

    std::cout << lapiseira.grafite->tamanho;

    return 0;
}