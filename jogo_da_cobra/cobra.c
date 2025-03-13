#include "cobra.h"

struct cobra{
    PONTO** vet;
    int tam;
    int capac;
};

COBRA* criar_cobra(){
    COBRA* cobra = (COBRA*) malloc(sizeof(COBRA));
    cobra->vet = (PONTO**) malloc(sizeof(PONTO*)* TAM_INI);
    cobra->tam = 1;
    cobra->capac = 4;
    PONTO* cabeca = criar_ponto(1,1);
    cobra->vet[0] = cabeca; 
    return cobra;
}
void atualizar_cabeca_cobra(int tecla, PONTO* p){
    
    switch (tecla)
    {
    case 'd':
        atualizar_ponto(p, retornar_ponto_x(p)+1, retornar_ponto_y(p));
        break;
    case 'a':
        atualizar_ponto(p, retornar_ponto_x(p)-1, retornar_ponto_y(p));
        break;
    case 'w':
    atualizar_ponto(p, retornar_ponto_x(p), retornar_ponto_y(p)-1);
        break;
    case 's':
    atualizar_ponto(p, retornar_ponto_x(p), retornar_ponto_y(p)+1);
        break;
    default:
        atualizar_ponto(p, retornar_ponto_x(p)+1, retornar_ponto_y(p));
        break;
    }
}
void andar_cobra(COBRA* cobra,int tecla){
    PONTO* p = copiar_ponto(cobra->vet[0]);
    for(int i=cobra->tam -1; i>0; i--){
        cobra->vet[i] = cobra->vet[i-1];
    }

    atualizar_cabeca_cobra(tecla, p);
    cobra->vet[0] = p; 
}

void crescer_cobra(COBRA* cobra, PONTO* p){
    if(cobra->tam == cobra->capac){
        cobra->vet = realloc(cobra->vet, sizeof(PONTO*)*cobra->tam*2);
        cobra->capac = cobra->tam*2;
    }
    cobra->vet[cobra->tam] =p;
    cobra->tam++;
}


PONTO* retornar_ponto_cobra(COBRA* cobra, int ind){
    return cobra->vet[ind];
}
int retornar_tam_cobra(COBRA* cobra){
    return cobra->tam;
}
void liberar_cobra(COBRA* cobra){
    if(cobra){
        for( int i=0; i<cobra->tam; i++){
            liberar_ponto(cobra->vet[i]);
        }
        free(cobra->vet);
        free(cobra);
    }
}

