#include <bits/stdc++.h>

using namespace std;

// Funções de Busca

bool existe_valor_x(vector<int> stress) {
    int valor = 0;

    cout << "Digite o valor que deseja procurar na fila: ";

    cin >> valor;

    if(valor >= -99 && valor <= 99) {
        if(find(stress.begin(), stress.end(), valor) != stress.end()) {
            cout << "Existe esse valor na fila." << "\n";
        } else {
            cout << "Nao existe esse valor na fila." << "\n";
        }

        return true;
    } else {
        cout << "Digite um valor entre -99 e 99." << "\n";
    }

    return false;
}

bool contar_x() {
    return false;
}

bool procurar_valor_x() {
    return false;
}

bool procurar_valor_x_apos() {
    return false;
}

bool selecionar_item(char item, vector<int> stress) {
    switch (item) {
    case 'a':
        return existe_valor_x(stress);
        break;
    case 'b':
        return contar_x();
        break;
    case 'c':
        return procurar_valor_x();
        break;
    case 'd':
        return procurar_valor_x_apos();
        break;
    default:
        break;
    }

    return false;
}

int main() {

    char resposta;
    char item;

    vector<char> items{'a', 'b', 'c', 'd'};
    vector<int> stress{-11, 1, 99, 2};

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

            cout << "Item: ";
            cin >> item;

            if(find(items.begin(), items.end(), item) != items.end()) {
                if(selecionar_item(item, stress)) break;
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