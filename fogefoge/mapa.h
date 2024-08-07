#ifndef _MAPA_H_
#define _MAPA_H_
#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'
#define PILULA 'P'
#define BOMBA 'b'

struct mapa {
    char** matriz;
    int linhas, colunas;
};

typedef struct mapa MAPA;

struct posicao {
    int x, y;
};

typedef struct posicao POSICAO;

void liberaMapa(MAPA* m);
void alocaMapa(MAPA* m);
void leMapa(MAPA* m);
void copiaMapa(MAPA* destino, MAPA* origem);
void andaNoMapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
int encontraNoMapa(MAPA* m, POSICAO* p, char c);
int ehDirecaoValida(MAPA* m, int x, int y);
int ehParede(MAPA*, int x, int y);
int ehPersonagem(MAPA* m, char personagem, int x, int y);
int podeAndar(MAPA* m, char personagem, int x, int y);

#endif