#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("***********************************\n");
    printf("*Bem vindo ao jogo da adivinhação *\n");
    printf("***********************************\n");

    int numeroSecreto = 42;
    int chute = 0;
    int tentativas = 0;

    while(1){
        printf("Tentativa %d \n", tentativas + 1);
        printf("Chute um número: ");

        scanf("%d", &chute);
        printf("Seu chute: %d \n", chute);

        if(chute < 0){
            printf("Chute < 0 - Não permitido");
            continue;
        }

        int acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if(acertou){
            printf("Correto! \n");
            break;
        }
        else if(maior){
            printf("Chute > Número Secreto \n");
        }
        else{
            printf("Chute < Número Secreto \n");
        }
        tentativas++;
    }
    printf("Fim do jogo\n");
    printf("Acertou em %d tentativas\n", tentativas);
}
