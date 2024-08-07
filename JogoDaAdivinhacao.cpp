#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
    cout << "************************************" << endl;
    cout << "* Bem-vindo ao jogo da adivinhação *" << endl;
    cout << "************************************" << endl;

    cout << "Escolha o nível de dificuldade: " << endl;
    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

    char dificuldade;
    cin >> dificuldade; 

    int numero_de_tentativas;

    if(dificuldade == 'F') {
        numero_de_tentativas = 15;
    }
    else if (dificuldade == 'M') {
        numero_de_tentativas = 10;
    }
    else {
        numero_de_tentativas = 5;
    }

    srand(time(0));
    const int NUMERO_SECRETO = rand() % 100;

    bool nao_acertou = true;
    int tentativas = 0;
 
    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas ++) {
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / (double) 2;
        pontos -= pontos_perdidos;

        cout << "O valor do seu chute é: " << chute << endl;

        bool acertou = chute == NUMERO_SECRETO;
        bool errou = chute > NUMERO_SECRETO;
        
        if (acertou) {
            cout << "Acertou!" << endl;
            nao_acertou = false;
            break;
        }
        else if (errou) {
            cout << "Chute > Número Secreto" << endl;
        }
        else {
            cout << "Chute < Número Secreto" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    if (nao_acertou) {
        cout << "Você perdeu" << endl;
    }
    else {
        cout << "Conseguiu em: " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Pontos: " << pontos << endl;
    }
}
