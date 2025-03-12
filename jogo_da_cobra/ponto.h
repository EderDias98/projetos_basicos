#ifndef PONTO_H
#define PONTO_H

#include <stdlib.h>
#include <stdio.h>



#define TAM_INI 4

typedef struct ponto PONTO;

PONTO* criar_ponto(int x, int y);
void atualizar_ponto(PONTO* p, int x, int y);
int retornar_ponto_x(PONTO* p);
int retornar_ponto_y(PONTO* p);

void liberar_ponto(PONTO* p);

PONTO* copiar_ponto(PONTO* p);



#endif