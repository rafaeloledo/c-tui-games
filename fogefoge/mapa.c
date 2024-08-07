#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void copiaMapa(MAPA* destino, MAPA* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocaMapa(destino);

    for (int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

void andaNoMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino) {
    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;
}

int podeAndar(MAPA* m, char personagem, int x, int y) {
    return 
        ehDirecaoValida(m, x, y) && 
        !ehParede(m, x, y) &&
        !ehPersonagem(m, personagem, x, y);
}

int ehPersonagem(MAPA* m, char personagem, int x, int y) {
    return m->matriz[x][y] == personagem;
}

int ehDirecaoValida(MAPA* m, int x, int y) {
    if (x >= m->linhas)
        return 0;
    if (y >= m->colunas)
        return 0;
    return 1;
}

int encontraNoMapa(MAPA* m, POSICAO* p, char c) {

    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            if(m->matriz[i][j] == c) {
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }

    return 0;
}

int ehParede(MAPA* m, int x, int y) {
    return 
        m->matriz[x][y] == PAREDE_HORIZONTAL ||
        m->matriz[x][y] == PAREDE_VERTICAL;
}

void liberaMapa(MAPA* m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        free(m->matriz[i]);
    }
    
    free(m->matriz);
}

void alocaMapa(MAPA* m)
{
    m->matriz = malloc(sizeof(char*) * m->linhas);
    for (int i = 0; i < m->linhas; i++)
    {
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void leMapa(MAPA* m)
{
    FILE* f = fopen("mapa.txt", "r");

    if (f == NULL)
    {
        printf("Erro ao abrir o mapa");
        exit(1);
    }

    fscanf(f, "%d%d", &m->linhas, &m->colunas);

    alocaMapa(m);
    
    for (int i = 0; i < 5; i++)
    {
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose(f);
}
