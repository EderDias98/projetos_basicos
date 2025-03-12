#ifndef MAPA_H
#define MAPA_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ponto.h"
#define LARG 20 
#define ALTU 10

typedef struct mapa MAPA;

MAPA* criar_mapa(int larg, int altu);
void gerar_mapa(MAPA* mapa);
void criar_comida_mapa(MAPA* mapa);

int retornar_altu_mapa(MAPA* mapa);
int retornar_larg_mapa(MAPA* mapa);
PONTO* retornar_comida_mapa(MAPA* mapa);

void liberar_mapa(MAPA* mapa);
void atualizar_ponto_mapa(MAPA* mapa, PONTO*p, char chara);
void liberar_mapa(MAPA* mapa);
char retornar_char_mapa(MAPA* mapa, PONTO* p);
#endif