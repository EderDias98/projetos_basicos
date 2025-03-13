#ifndef MAPA_H
#define MAPA_H
#include <stdio.h>
#include <stdlib.h>
#include "peca.h"
typedef struct mapa MAPA;

MAPA* criar_mapa(int larg, int altu);

int retorna_indice_mapa(int i, int j, int larg);

int retorna_altura_mapa(MAPA* m);


void limpar_mapa(MAPA*m);
void desenhar_peca_mapa(MAPA*m,PECA* p);


int retorna_largura_mapa(MAPA* m);
void atualizar_mapa(MAPA* m, int ind, int num);

int congelar_peca_mapa(MAPA*m, PECA* p, int* p_c);
#endif