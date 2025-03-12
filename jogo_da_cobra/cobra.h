#ifndef COBRA_H
#define COBRA_H

#include "ponto.h"
typedef struct cobra COBRA;


COBRA* criar_cobra();
 
void crescer_cobra(COBRA* cobra, PONTO* p);
void andar_cobra(COBRA* cobra,int tecla);

PONTO* retornar_ponto_cobra(COBRA* cobra, int ind);
int retornar_tam_cobra(COBRA* cobra);

void liberar_cobra(COBRA* cobra);
#endif