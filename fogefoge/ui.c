#include <stdio.h>
#include "ui.h"

char desenhoFantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoParede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoHeroi[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhoPilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhoVazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprimeParte(char desenho[4][7], int parte) {
    printf("%s", desenho[parte]);
}

void imprimeMapa(MAPA* m) {
    // "transforms" mapa.txt to a new output map converted
    for (int i = 0; i < m->linhas; i++) {
        /* os novos desenhos são feitos em 4 linhas, varre a mesma linha 4 vezes e imprime a 
            parte do desenho de acordo com a variavel 'parte' */
        for (int parte = 0; parte < 4; parte++) {
            for (int j = 0; j < m->colunas; j++) {
                /* cada vez que ele entrar neste switch, sera impresso a parte do desenho de acordo com a ordem do mapa original
                   varre a linha 1 4 vzs x 10 colunas, cada vez ira imprimir um fragmento do desenho */
                switch(m->matriz[i][j]) {
                    case FANTASMA:
                        imprimeParte(desenhoFantasma, parte);
                        break;
                    case HEROI:
                        imprimeParte(desenhoHeroi, parte);
                        break;
                    case PILULA:
                        imprimeParte(desenhoPilula, parte);
                        break;
                    case PAREDE_VERTICAL:
                    case PAREDE_HORIZONTAL:
                        imprimeParte(desenhoParede, parte);
                        break;
                    case VAZIO:
                        imprimeParte(desenhoVazio, parte);
                        break;
                }
            }
            printf("\n");
        }
    }
}