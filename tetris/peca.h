#ifndef PECA_H
#define PECA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include <constantes.h>

typedef struct peca PECA;

void copiar_peca(PECA* p2, int p1[4][4]);

PECA* criar_peca(int tipo);

PECA* salvar_estado_peca(PECA* po);
int retorna_indice_peca(int i, int j, int larg);
void rotacionar_90_peca(PECA* p);
  
void liberar_peca(PECA* p);
int retornar_x_peca(PECA* p);

int retornar_y_peca(PECA* p);

int retornar_conteudo_peca(PECA* p, int ind);
void congelar_peca(PECA* p);
void cair_peca(PECA* p);
#endif

