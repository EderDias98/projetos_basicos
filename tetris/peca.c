#include "peca.h"

int peca_1[4][4]={
    {1,1,1,1},
    {1,2,2,1},
    {1,2,2,1},
    {1,1,1,1}
};
int peca_2[4][4]={
    {2,2,2,2},
    {1,1,1,1},
    {1,1,1,1},
    {1,1,1,1}
};
int peca_3[4][4]={
    {2,2,1,1},
    {2,1,1,1},
    {2,1,1,1},
    {1,1,1,1}
};
int peca_4[4][4]={
    {1,2,1,1},
    {2,2,2,1},
    {1,1,1,1},
    {1,1,1,1}
};
int peca_5[4][4]={
    {1,2,1,1},
    {2,2,1,1},
    {2,1,1,1},
    {1,1,1,1}
};
int peca_6[4][4]={
    {1,2,2,1},
    {2,2,1,1},
    {1,1,1,1},
    {1,1,1,1}
};
int peca_7[4][4]={
    {1,1,1,1},
    {1,1,1,1},
    {1,1,2,1},
    {2,2,2,1}
};


struct peca{
    int vet[16];
    int tipo;
    int x,y; // ponto da peca no mapa
};
int retornar_x_peca(PECA* p){
    return p->x;
}
int retornar_y_peca(PECA* p){
    return p->y;
}

int retornar_conteudo_peca(PECA* p, int ind){
    return p->vet[ind];
}

int retorna_indice_peca(int i, int j){
    return i*4 +j;
}

void congelar_peca(PECA* p){
    for(int i =0; i< 4; i++){
        for(int j=0; j< 4; j++){
            int ind = retorna_indice_peca(i,j);
            if(p->vet[ind] == 2){
                p->vet[ind] = 3;
            }
     
        }
    }
}

PECA* salvar_estado_peca(PECA* po){
    PECA* pd = criar_peca(po->tipo);
    memcpy(pd, po, sizeof(PECA));
    return pd;
}
void copiar_peca(PECA* p2, int p1[4][4]){
    for(int i =0; i< 4; i++){
        for(int j=0; j< 4; j++){
            int ind = retorna_indice_peca(i,j);
            if(p1[i][j] == 1){
                p2->vet[ind] = 1;
            }else if(p1[i][j]==2){
                p2->vet[ind] = 2;
            }
        }
    }
}
PECA* criar_peca(int tipo){
    PECA* p = (PECA*) malloc(sizeof(PECA));
    p->tipo = tipo;
    p->x = LARG/2;
    p->y = 0;
    switch (tipo)
    {
    case 1:
        copiar_peca(p,peca_1);
        break;
    case 2:
        copiar_peca(p,peca_2);
        break;
    case 3:
        copiar_peca(p,peca_3);
        break;
    case 4:
        copiar_peca(p,peca_4);
        break;
    case 5:
        copiar_peca(p,peca_5);
        break;
    case 6:
        copiar_peca(p,peca_6);
        break;
    case 7:
        copiar_peca(p,peca_7);
        break;
    default:
        break;
    }

    return p;
}

void rotacionar_90_peca(PECA* p){
    for(int i =0; i< 4; i++){
        for(int j=0; j< 4; j++){
            int ind = retorna_indice_peca(i,j);
            if(p->vet[ind]==2){
                p->vet[ind] = 1;
                int ind_r = retorna_indice_peca(3-j,i);
                p->vet[ind_r] = 2;
            }
        }
    }
}

void liberar_peca(PECA* p){
    if(p){
        free(p);
    }
}
void cair_peca(PECA* p){
    p->y = p->y+1;
}