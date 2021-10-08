#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ostream>
#include <algorithm>
#include <time.h>

#include "../testador.hpp"

// Sempre coloco um dos testes errados para testar --->

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
            homens.push_back(i); // Pega a posição dos homens

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
            calmos.push_back(i); // Pega a posição dos calmos

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
            mulheres_calmas.push_back(i); // Pega a posição das mulheres calmas

    return mulheres_calmas;
}

void teste_pegar_mulheres_calmas() {
    std::cout << "teste_pegar_mulheres_calmas\n";
    testar(pegar_mulheres_calmas({-1, -22, 30}), {0});
    testar(pegar_mulheres_calmas({66, -2, -32, 4, 5}), {1});
    testar(pegar_mulheres_calmas({3, -52, -8, 12}), {1, 2});
}

// Funções de Acesso

std::vector<int> inverter_com_copia(const std::vector<int>& v) {
    std::vector<int> invertido;

    for(int i = (int) v.size() -1; i >= 0; i--)
        invertido.push_back(v[i]);

    return invertido;
}

void teste_inverter_com_copia() {
    std::cout << "teste_inverter_com_copia\n";
    testar(inverter_com_copia({-1, -22, 30}), {30, -22, -1});
    testar(inverter_com_copia({66, -2, -32, 4, 5}), {5, 4, -32, -2, 66});
    testar(inverter_com_copia({3, -52, -8, 12}), {3, -52, 12, -8});
}

void inverter_inplace(std::vector<int>& v) {
    for(int i = 0; i < (int) v.size() / 2; i++)
        std::swap(v[i], v[((int) v.size()) - i - 1]);
}

void teste_inverter_inplace() {
    std::cout << "teste_inverter_inplace\n";

    std::vector<int> v1 {-1, -22, 30};
    std::vector<int> v2 {66, -2, -32, 4, 5};
    std::vector<int> v3 {3, -52, -8, 12};

    inverter_inplace(v1);
    inverter_inplace(v2);
    inverter_inplace(v3);

    testar(v1, {30, -22, -1});
    testar(v2, {5, 4, -32, -2, 66});
    testar(v3, {3, -52, 12, -8});
}

int sortear(const std::vector<int>& v) {
    srand(time(NULL));
    int size { (int) v.size() };
    int indice { rand() % size};
    return v[indice];
}

void teste_sortear() {
    std::cout << "teste_sortear\n";

    std::cout << sortear({-1, -34, 2, -4, 55}) << "\n";
    std::cout << sortear({44, -34, 22, 32, 5}) << "\n";
    std::cout << sortear({31, -34, 42, 44, 89}) << "\n";
}

void embaralhar(std::vector<int>& v) {
    srand(time(NULL));
    int size { (int) v.size() };
    int i_1 {};
    int i_2 {};

    for(int i = 0; i < (int) v.size(); i++) {
        i_1 = rand() % size;
        i_2 = rand() % size;

        std::swap(v[i_1], v[i_2]);
    }
}

void teste_embaralhar() {
    std::cout << "teste_embaralhar\n";

    std::vector<int> v1 {-1, -22, 30};
    std::vector<int> v2 {66, -2, -32, 4, 5};
    std::vector<int> v3 {3, -52, -8, 12};

    std::cout << v1 << " -> ";
    embaralhar(v1);
    std::cout << v1 << "\n";

    std::cout << v2 << " -> ";
    embaralhar(v2);
    std::cout << v2 << "\n";

    std::cout << v3 << " -> ";
    embaralhar(v3);
    std::cout << v3 << "\n";
}

void ordenar(std::vector<int>& v) {
    std::sort(v.begin(), v.end());
}

void teste_ordenar() {
    std::cout << "teste_ordenar\n";

    std::vector<int> v1 {-1, -22, 30};
    std::vector<int> v2 {66, -2, -32, 4, 5};
    std::vector<int> v3 {3, -52, -8, 12};

    std::cout << v1 << " -> ";
    ordenar(v1);
    std::cout << v1 << "\n";

    std::cout << v2 << " -> ";
    ordenar(v2);
    std::cout << v2 << "\n";

    std::cout << v3 << " -> ";
    ordenar(v3);
    std::cout << v3 << "\n";
}

// Funções de Conjuntos

std::vector<int> exclusivos(const std::vector<int>& v) {
    std::vector<int> novo_vetor;

    for(int i = 0; i < (int) v.size(); i++) {
        if(find(novo_vetor.begin(), novo_vetor.end(), v[i]) == novo_vetor.end()) // Se não encontrar no novo_vetor
            novo_vetor.push_back(v[i]);
    }

    return novo_vetor;
}

void teste_exclusivos() {
    std::cout << "teste_exclusivos\n";
    testar(exclusivos({1, 3, 4, 3, -1, -2, -2}), {1, 3, 4, -1, -2});
    testar(exclusivos({6, -2, -2, -3, 4, 5, 3, 4}), {6, -2, -3, 4, 5, 3});
    testar(exclusivos({3, 2, 1, 1, 2}), {2, 1});
}

std::vector<int> diferentes(const std::vector<int>& v) {
    std::vector<int> novo_vetor;

    for(int i = 0; i < (int) v.size(); i++) {
        if(find(novo_vetor.begin(), novo_vetor.end(), abs(v[i])) == novo_vetor.end()) // Se não encontrar no novo_vetor
            novo_vetor.push_back(abs(v[i]));
    }

    return novo_vetor;
}

void teste_diferentes() {
    std::cout << "teste_diferentes\n";
    testar(diferentes({1, 3, 4, 3, -1, -2, -2}), {1, 3, 4, 2});
    testar(diferentes({6, -2, -2, -3, 4, 5, 3, 4}), {6, 2, 3, 4, 5});
    testar(diferentes({3, 2, 1, 1, 2}), {2, 1});
}

std::vector<int> abandonados(const std::vector<int>& v) {
    std::vector<int> removidos;
    std::vector<int> novo_vetor = v;
    int c { 0 }; // Ele é necessário para não passar do tamanho do novo_vetor
    for(int i = 0; i < (int) v.size(); i++) {
        if(find(removidos.begin(), removidos.end(), v[i]) == removidos.end()) { // Se não encontrar em removidos
            removidos.push_back(v[i]);
            novo_vetor.erase(novo_vetor.begin() + i - c++);
        }
    }

    return novo_vetor;
}

void teste_abandonados() {
    std::cout << "teste_abandonados\n";
    testar(abandonados({1, 3, 4, 3, -1, -2, -2}), {3, -2});
    testar(abandonados({6, -2, -2, -3, 4, 5, 3, 4}), {-2, 4});
    testar(abandonados({3, 2, 1, 1, 2}), {2, 1});
}

int main() {
    // teste_clone();
    // teste_pegar_homens();
    // teste_pegar_calmos();
    // teste_pegar_mulheres_calmas();

    // teste_inverter_com_copia();
    // teste_inverter_inplace();
    // teste_sortear();
    // teste_embaralhar();
    // teste_ordenar();
    
    teste_exclusivos();
    teste_diferentes();
    teste_abandonados();

    return 0;
}

