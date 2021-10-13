#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ostream>
#include <algorithm>
#include <time.h>

#include "../testador.hpp"

// Funções de Map

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

// Funções de Proximidade

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

// Funções de Sequências

int quantos_times(const std::vector<int>& v) {
    int quantos_times_contador {0};
    int time_m {0};
    int time_h {0};

    for(int i = 0; i < (int) v.size(); i++) {
        if(v[i] < 0) {
            if(time_h > 1) quantos_times_contador++;

            time_m++;
            time_h = 0;
        } else if(v[i] > 0) {
            if(time_m > 1) quantos_times_contador++;

            time_m = 0;
            time_h++;
        }
    }

    return quantos_times_contador;
}

void teste_quantos_times() {
    std::cout << "teste_quantos_times\n";
    testar(quantos_times({1, 3, 4, 5, -1, -5, -5, 3, -3}), {2});
    testar(quantos_times({6, 5, 3, -3, -5, 7, 88, 88, -1}), {3});
    testar(quantos_times({3, 1, 55, -66, -66, 55, 99, -22, -55, 88, 55, -11}), {5});
}

int maior_time(const std::vector<int>& v) {
    int maior_time_contador {-99999};
    int time_m {0};
    int time_h {0};

    for(int i = 0; i < (int) v.size(); i++) {
        if(v[i] < 0) {
            if(time_h > 1 && time_h > maior_time_contador) maior_time_contador = time_h;

            time_m++;
            time_h = 0;
        } else if(v[i] > 0) {
            if(time_m > 1 && time_m > maior_time_contador) maior_time_contador = time_m;

            time_m = 0;
            time_h++;
        }
    }

    return maior_time_contador;
}

void teste_maior_time() {
    std::cout << "teste_maior_time\n";
    testar(maior_time({1, 3, 4, 5, -1, -5, -5, 3, -3}), {4});
    testar(maior_time({6, 5, 3, -3, -5, 7, 88, 88, -1}), {3});
    testar(maior_time({3, 1, 55, -66, -66, 55, 99, -22, -55, 88, 55, -11}), {3});
}

int sozinhos_sem_time(const std::vector<int>& v) {
    int sozinhos_sem_time_contador {0};

    for(int i = 1; i < (int) v.size() - 1; i++) {
        if(v[i] > 0 && v[i - 1] < 0 && v[i + 1] < 0) {
            sozinhos_sem_time_contador++;
        }

        if(v[i] < 0 && v[i - 1] > 0 && v[i + 1] > 0) {
            sozinhos_sem_time_contador++;
        }
    }

    if(v[0] > 0 && v[1] < 0) sozinhos_sem_time_contador++;
    if(v[v.size() - 1] > 0 && v[v.size() - 2] < 0) sozinhos_sem_time_contador++;

    if(v[0] < 0 && v[1] > 0) sozinhos_sem_time_contador++;
    if(v[v.size() - 1] < 0 && v[v.size() - 2] > 0) sozinhos_sem_time_contador++;

    return sozinhos_sem_time_contador;
}

void teste_sozinhos_sem_time() {
    std::cout << "teste_sozinhos_sem_time\n";
    testar(sozinhos_sem_time({1, 3, 4, 5, -1, -5, -5, 3, -3}), {2});
    testar(sozinhos_sem_time({6, 5, 3, -3, -5, 7, 88, 88, -1}), {1});
    testar(sozinhos_sem_time({3, -1, 55, -66, -66, 55, 99, -22, -55, 88, 55, -11}), {4});
}


int main() {
    // teste_sozinhos();
    // teste_mais_ocorrencias();
    // teste_mais_recorrentes();
    // teste_briga();
    // teste_apaziguado();
    // teste_quantos_times();
    // teste_maior_time();
    teste_sozinhos_sem_time();

    return 0;
}

