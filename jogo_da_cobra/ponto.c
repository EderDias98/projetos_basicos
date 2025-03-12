#include "ponto.h"

struct ponto{
    int x,y;
};

PONTO* criar_ponto(int x, int y){
    PONTO* p = (PONTO*) malloc(sizeof(PONTO));
    p->x = x;
    p->y = y;
    return p;
}

void atualizar_ponto(PONTO* p, int x, int y){
    p->x= x;
    p->y = y;
}

int retornar_ponto_x(PONTO* p){
    return p->x;
}
int retornar_ponto_y(PONTO* p){
    return p->y;
}

void liberar_ponto(PONTO* p){
    if(p){
        free(p);
    }
}

PONTO* copiar_ponto(PONTO* p){
    PONTO* c = criar_ponto(p->x, p->y);
    return c;
}
