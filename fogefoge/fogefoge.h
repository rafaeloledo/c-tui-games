#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int ehDirecao(char direcao);
void move(char comando);
int acabou();
void fantasmas();
int praOndeOFantasmaVai(int xatual, int yatual, int* xdestino, int* ydestino);
void explodePilula();
void explodePilula2(int x, int y, int somax, int somay, int qtd);

#endif