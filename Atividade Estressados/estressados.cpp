#include <bits/stdc++.h>

using namespace std;

// Funções de Busca

string existe_valor_x() {
    return "nao";
}

string contar_x() {
    return "nao";
}

string procurar_valor_x() {
    return "nao";
}

string procurar_valor_x_apos() {
    return "nao";
}

void selecionar_item(char item) {
    switch (item) {
    case 'a':
        existe_valor_x();
        break;
    case 'b':
        contar_x();
        break;
    case 'c':
        procurar_valor_x();
        break;
    case 'd':
        procurar_valor_x_apos();
        break;
    default:
        break;
    }
}

int main() {

    char resposta;
    char item;

    vector<char> items{'a', 'b', 'c', 'd'};

    cout << "Deseja coletar informacoes sobre a fila? Digite a letra 's' ou 'S' para continuar." << "\n";
    cin >> resposta;

    while(resposta == 's' || resposta == 'S') {
        cout << "Selecione um item entre as perguntas ------------->" << "\n";
        while(true) { // Condição de existência virá aqui!
            cout << "Bloco ---------------->" << "\n";
            cout << "(a) Alguem com o valor X esta na fila?" << "\n";
            cout << "(b) Quantas vezes o valor X apareceu na fila?" << "\n";
            cout << "(c) Em que posicao da fila aparece X pela primeira vez?" << "\n";
            cout << "(d) Dada a posicao para iniciar a busca, qual a proxima posicao em que aparece X?" << "\n";

            cout << "Digite sua resposta: ";
            cin >> item;

            if(find(items.begin(), items.end(), item) != items.end()) {
                selecionar_item(item);
                break;
            } else {     
                cout << "Selecione um item existente na lista." << "\n";
            }
        }

        cout << "Deseja continuar coletando informacoes sobre a fila? Digite a letra 's' ou 'S' para continuar." << "\n";
        cin >> resposta;
    }

    cout << "Encerrando...";

    return 0;
}

// Digite s ou S para continuar
// Positivo = Homens
// Negativo = Mulheres