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
        if(std::count(v.begin(), v.end(), value) == 1 && std::count(v.begin(), v.end(), -value) <= 0) {
                sozinhos.push_back(abs(value));
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
            if(std::find(mais_recorrentes.begin(), mais_recorrentes.end(), abs(value)) == mais_recorrentes.end()) {
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
    std::vector<int> fila = v; // Para que o jeito que eu faço os testes continue dando certo, o compilador só aceita se o parâmentro for constante, mas para essa questão preciso que ele seja variável
    fila.push_back(0);
    int quantos_times_contador {0};
    int time_m {0};
    int time_h {0};

    for(int i = 0; i < (int) fila.size(); i++) {
        if(fila[i] < 0) {
            if(time_h > 1) quantos_times_contador++;

            time_m++;
            time_h = 0;
        } else if(fila[i] > 0) {
            if(time_m > 1) quantos_times_contador++;

            time_m = 0;
            time_h++;
        } else if(fila[i] == 0) {
            if(time_m > 1 || time_h > 1) quantos_times_contador++;
        }
    }

    return quantos_times_contador;
}

void teste_quantos_times() {
    std::cout << "teste_quantos_times\n";
    testar(quantos_times({1, 3, 4, 5, -1, -5, -5, 3, -3, -80}), {3});
    testar(quantos_times({6, 5, 3, -3, -5, 7, 88, 88, -1, -10}), {4});
    testar(quantos_times({3, 1, 55, -66, -66, 55, 99, -22, -55, 88, 55}), {5});
}

int maior_time(const std::vector<int>& v) {
    std::vector<int> fila = v; // Para que o jeito que eu faço os testes continue dando certo, o compilador só aceita se o parâmentro for constante, mas para essa questão preciso que ele seja variável
    fila.push_back(0);
    int maior_time_contador {-99999};
    int time_m {0};
    int time_h {0};

    for(int i = 0; i < (int) v.size(); i++) {
        if(fila[i] < 0) {
            if(time_h > 1 && time_h > maior_time_contador) maior_time_contador = time_h;

            time_m++;
            time_h = 0;
        } else if(fila[i] > 0) {
            if(time_m > 1 && time_m > maior_time_contador) maior_time_contador = time_m;

            time_m = 0;
            time_h++;
        } else if(fila[i] == 0) {
            if(time_m > 1 && time_m > maior_time_contador) maior_time_contador = time_m;
            if(time_h > 1 && time_h > maior_time_contador) maior_time_contador = time_h;
        }
    }

    return maior_time_contador;
}

void teste_maior_time() {
    std::cout << "teste_maior_time\n";
    testar(maior_time({1, 3, 4, 5, -1, -5, -5, 3, -3, -4}), {4});
    testar(maior_time({6, 5, 3, -3, -5, 7, 88, 88, -1, -1}), {3});
    testar(maior_time({3, 1, 55, -66, -66, 55, 99, -22, -55, 88, 55, -11, -12}), {3});
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

// Funções de Grupos

int casais(const std::vector<int>& v) {
    int casais_contador {0};
    std::vector<int> lista_de_espera = v;

    for(int i = 0; i < (int) lista_de_espera.size() - 1; i++) {
        for(int j = i + 1; j < (int) lista_de_espera.size(); j++) {
            if(abs(lista_de_espera[i]) == abs(lista_de_espera[j]) && lista_de_espera[i] != lista_de_espera[j] && lista_de_espera[i] != 0) {
                lista_de_espera[i] = 0;
                lista_de_espera[j] = 0;
                casais_contador++;
                break;
            }
        }
    }

    return casais_contador;
}

void teste_casais() {
    std::cout << "teste_casais\n";
    testar(casais({1, 3, 4, 5, -1, -5, -5, 3, -3}), {3});
    testar(casais({6, 5, 3, -3, -5, 7, 88, 88, -1}), {2});
    testar(casais({3, -1, 55, -66, -66, -55, 99, -22, -55, 88, 55, -11}), {2});
}

int trios(const std::vector<int>& v) {
    int trios_contador {0};
    std::vector<int> lista_de_espera = v;

    for(int i = 0; i < (int) lista_de_espera.size() - 2; i++) {
        for(int j = i + 1; j < (int) lista_de_espera.size() - 1; j++) {
            if(abs(lista_de_espera[i]) == abs(lista_de_espera[j]) && lista_de_espera[i] != 0) {
                for(int k = j + 1; k < (int) lista_de_espera.size(); k++) {
                    if(abs(lista_de_espera[j]) == abs(lista_de_espera[k])) {
                        lista_de_espera[i] = 0;
                        lista_de_espera[j] = 0;
                        lista_de_espera[k] = 0;
                        trios_contador++;
                        break;
                    }
                }
            }
        }
    }

    return trios_contador;
}

void teste_trios() {
    std::cout << "teste_trios\n";
    testar(trios({1, 3, 4, 5, -1, -5, -5, 3, -3}), {2});
    testar(trios({6, -88, 5, 3, -3, -5, 7, 88, 88, -1}), {1});
    testar(trios({3, -11, 55, -66, -66, -55, 11, -22, -55, 66, 88, 55, -11}), {3});
}

// Funções de Alteração

void remove(std::vector<int>& v, int pessoa) {
    for(int i = 0; i < (int) v.size(); i++) {
        if(v[i] == pessoa) {
            v.erase(v.begin() + i, v.begin() + i + 1);
        }
    }
}

void teste_remove() {
    std::cout << "teste_remove\n";

    // Está dando erro passar o vetor normalmente pelo método testar porque o parâmetro da função não é constante, por isso resolvi testar criando os vetores separados, executando a função, e só depois chamar o testar.

    std::vector<int> v1 {1, 3, 4, 5, -1, -5, -5, 3, -3};
    std::vector<int> v2 {6, -88, 5, 3, -3, -5, 7, 88, 88, -1};
    std::vector<int> v3 {3, -11, 55, -66, -66, -55, 11, -22, -55, 66, 88, 55, -11};

    remove(v1, 3);
    remove(v2, 5);
    remove(v3, 11);

    testar(v1, {1, 4, 5, -1, -5, -5, -3});
    testar(v2, {6, -88, 3, -3, -5, 7, 88, 88, -1});
    testar(v3, {3, -11, 55, -66, -66, -55, -22, -55, 66, 88, 55, -11});
}

void insert(std::vector<int>& v, int pessoa, int pos) {
    v.insert(v.begin() + pos, pessoa);
}

void teste_insert() {
    std::cout << "teste_insert\n";

    // Está dando erro passar o vetor normalmente pelo método testar porque o parâmetro da função não é constante, por isso resolvi testar criando os vetores separados, executando a função, e só depois chamar o testar.

    std::vector<int> v1 {1, 3, 4, 5, -1, -5, -5, 3, -3};
    std::vector<int> v2 {6, -88, 5, 3, -3, -5, 7, 88, 88, -1};
    std::vector<int> v3 {3, -11, 55, -66, -66, -55, 11, -22, -55, 66, 88, 55, -11};

    insert(v1, 33, 2);
    insert(v2, -5, 7);
    insert(v3, -99, 5);

    testar(v1, {1, 3, 33, 4, 5, -1, -5, -5, 3, -3});
    testar(v2, {6, -88, 5, 3, -3, -5, 7, -5, 88, 88, -1});
    testar(v3, {3, -11, 55, -66, -66, -99, -55, 11, -22, -55, 66, 88, 55, -11});
}

std::vector<int> dance(const std::vector<int>& v) {
    std::vector<int> lista_de_espera = v;

    for(int i = 0; i < (int) lista_de_espera.size() - 1; i++) {
        if(abs(lista_de_espera[i]) == abs(lista_de_espera[i + 1])) {
            lista_de_espera.erase(lista_de_espera.begin() + i, lista_de_espera.begin() + i + 2);
            i = -1;
        }
    }

    return lista_de_espera;
}

void teste_dance() {
    std::cout << "teste_dance\n";
    testar(dance({-3, 3, 4, 5, -1, -5, -5, 3, -3}), {4, 5, -1});
    testar(dance({6, 5, 3, -3, -5, 7, 88, 88, -1}), {6, 7, -1});
    testar(dance({3, -1, 55, -66, -66, -55, 99, -22, -55, 88, 55, -11}), {3, -1, 99, -22, -55, 88, 55, -11});
}

// Função Principal

int main() {

    teste_sozinhos();
    teste_mais_ocorrencias();
    teste_mais_recorrentes();

    teste_briga();
    teste_apaziguado();

    teste_quantos_times();
    teste_maior_time();
    teste_sozinhos_sem_time();

    teste_casais();
    teste_trios();
    
    teste_remove();
    teste_insert();
    teste_dance();

    return 0;
}

