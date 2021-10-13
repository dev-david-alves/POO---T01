#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ostream>
#include <algorithm>
#include <time.h>

#include "../testador.hpp"

// Funções de Filter

std::vector<int> sozinhos(const std::vector<int>& v) {
    std::vector<int> sozinhos;

    for(auto value: v) {
        if(std::count(v.begin(), v.end(), value) == 1) {
            if(std::count(v.begin(), v.end(), -value) <= 0) {
                sozinhos.push_back(abs(value));
            }
        }
    }

    return sozinhos;
}

void teste_sozinhos() {
    std::cout << "teste_sozinhos\n";
    testar(sozinhos({1, 3, 4, 3, -1, -3, -3}), {4});
    testar(sozinhos({6, 5, 3, 3, 5, 7, 88, 88, 99}), {6, 7, 99});
    testar(sozinhos({3, 1, 55, 66, 66}), {3, 1, 55});
}

int mais_ocorrencias(const std::vector<int>& v) {
    int mais_ocorrencias {0};

    for(auto value: v) {
        if(std::count(v.begin(), v.end(), value) + std::count(v.begin(), v.end(), -value) > mais_ocorrencias) {
            mais_ocorrencias = std::count(v.begin(), v.end(), value) + std::count(v.begin(), v.end(), -value);
        }
    }

    return mais_ocorrencias;
}

void teste_mais_ocorrencias() {
    std::cout << "teste_mais_ocorrencias\n";
    testar(mais_ocorrencias({1, 3, 4, 5, -1, -5, -5}), {3});
    testar(mais_ocorrencias({6, 5, 3, 3, 5, 7, 88, 88, 99}), {2});
    testar(mais_ocorrencias({3, 1, 55, 66, 66, 55, 99, 22, 55, 88, 55}), {4});
}

std::vector<int> mais_recorrentes(const std::vector<int>& v) {
    int mais_ocorrencias_contador {mais_ocorrencias(v)};
    std::vector<int> mais_recorrentes;

    for(auto value: v) {
        if(std::count(v.begin(), v.end(), value) + std::count(v.begin(), v.end(), -value) == mais_ocorrencias_contador) {
            if(std::find(mais_recorrentes.begin(), mais_recorrentes.end(), value) == mais_recorrentes.end() && std::find(mais_recorrentes.begin(), mais_recorrentes.end(), -value) == mais_recorrentes.end()) {
                mais_recorrentes.push_back(abs(value));
            }
        }
    }

    return mais_recorrentes;
}

void teste_mais_recorrentes() {
    std::cout << "teste_mais_recorrentes\n";
    testar(mais_recorrentes({1, 3, 4, 5, -1, -5, -5, 3, -3}), {3, 5});
    testar(mais_recorrentes({6, 5, 3, 3, 5, 7, 88, 88, 99}), {5, 3, 88});
    testar(mais_recorrentes({3, 1, 55, 66, 66, 55, 99, 22, 55, 88, 55}), {55});
}

int briga(const std::vector<int>& v) {
    int contador {0};

    for(int i = 1; i < (int) v.size() -1; i++) {
        if(abs(v[i]) > 50 && abs(v[i - 1]) > 30 && abs(v[i + 1]) > 30)
            contador++;
    }

    return contador;
}

void teste_briga() {
    std::cout << "teste_briga\n";
    testar(briga({33, 55, 40, 5, -60, 45, 77, 56, -3}), {2});
    testar(briga({6, 5, 51, 33, 5, 7, 88, 88, 99}), {1});
    testar(briga({3, 1, 55, 66, 66, 55, 99, 22, 55, 88, 55}), {4});
}

std::vector<int> apaziguado(const std::vector<int>& v) {
    std::vector<int> apaziguados;

    for(int i = 0; i < (int) v.size(); i++) {
        if(abs(v[i]) > 80) {
            if((i > 0 && abs(v[i - 1]) < 10) || (i < (int) v.size() - 1 && abs(v[i + 1]) < 10)) {
                apaziguados.push_back(i);
            }
        }
    }

    return apaziguados;
}

void teste_apaziguado() {
    std::cout << "teste_apaziguado\n";
    testar(apaziguado({33, 88, 9, 5, -90, 1, 77, 56, -3}), {1, 4});
    testar(apaziguado({6, 5, 51, 33, 5, 7, 88, 88, 99}), {6});
    testar(apaziguado({3, 1, 99, 66, 66, 55, 99, 2, 55, 88, 1}), {2, 6, 9});
}

int main() {
    // teste_sozinhos();
    // teste_mais_ocorrencias();
    // teste_mais_recorrentes();
    // teste_briga();
    teste_apaziguado();

    return 0;
}

