#include <iostream>
#include <vector>
#include <ostream>
#include <algorithm>

#include "../testador.hpp"

// Funções de Filter

std::vector<int> clone(const std::vector<int>& v) {
    std::vector<int> clonado = v;
    return clonado;
}

void teste_clone() {
    std::cout << "teste_clone\n";
    testar(clone({1, 2, 3}), {1, 2, 3});
    testar(clone({6, 5, 3}), {1, 4, 3});
    testar(clone({3, 2, 1}), {3, 2, 1});
}

std::vector<int> pegar_homens(const std::vector<int>& v) {
    std::vector<int> homens;
    for(int i = 0; i < (int) v.size(); i++)
        if(v[i] > 0)
            homens.push_back(i);

    return homens;
}

void teste_pegar_homens() {
    std::cout << "teste_pegar_homens\n";
    testar(pegar_homens({-1, -2, 3}), {2});
    testar(pegar_homens({6, -2, -3, 4, 5}), {0, 3, 4});
    testar(pegar_homens({3, 2, 1}), {0, 3, 5});
}

std::vector<int> pegar_calmos(const std::vector<int>& v) {
    std::vector<int> calmos;
    for(int i = 0; i < (int) v.size(); i++)
        if(abs(v[i]) <  10)
            calmos.push_back(i);

    return calmos;
}

void teste_pegar_calmos() {
    std::cout << "teste_pegar_calmos\n";
    testar(pegar_calmos({-1, -22, 30}), {0});
    testar(pegar_calmos({66, -2, -32, 4, 5}), {1, 2});
    testar(pegar_calmos({3, 52, 8, 12}), {0, 2});
}

std::vector<int> pegar_mulheres_calmas(const std::vector<int>& v) {
    std::vector<int> mulheres_calmas;
    for(int i = 0; i < (int) v.size(); i++)
        if(v[i] < 0 && abs(v[i]) < 10)
            mulheres_calmas.push_back(i);

    return mulheres_calmas;
}

void teste_pegar_mulheres_calmas() {
    std::cout << "pegar_mulheres_calmas\n";
    testar(pegar_mulheres_calmas({-1, -22, 30}), {0});
    testar(pegar_mulheres_calmas({66, -2, -32, 4, 5}), {1});
    testar(pegar_mulheres_calmas({3, -52, -8, 12}), {1, 2});
}


int main() {
    teste_clone();
    teste_pegar_homens();
    teste_pegar_calmos();
    teste_pegar_mulheres_calmas();


    return 0;
}

