#include "mapa.h"



struct mapa
{
    char* vet;
    int larg;
    int altu;
    PONTO* comida;
    int game_over;
};



void criar_comida_mapa(MAPA* mapa){

    srand(time(NULL));
    while(mapa->vet[retornar_ponto_y(mapa->comida)* mapa->larg + retornar_ponto_x(mapa->comida)] != ' '){
        atualizar_ponto(mapa->comida,rand()%(LARG -1),  rand()%(ALTU -1) );
    }
}


MAPA* criar_mapa(int larg, int altu){
    MAPA* mapa = (MAPA*) malloc(sizeof(MAPA));
    mapa->vet = (char*) malloc(sizeof(char)*larg*altu);
    mapa->comida = criar_ponto(0,0);
    mapa->altu = altu;
    mapa->larg = larg;
    return mapa;
}

void gerar_mapa(MAPA* mapa){
    for(int i=0; i< mapa->altu; i++){
        for(int j=0; j< mapa->larg; j++){
            int ind = i*mapa->larg +j;
            printf("%c", mapa->vet[ind]);
        }
        printf("\n");
    }
}



void atualizar_ponto_mapa(MAPA* mapa, PONTO*p, char chara){
    int ind = retornar_ponto_y(p)*mapa->larg + retornar_ponto_x(p);
    mapa->vet[ind] = chara;   
}



void liberar_mapa(MAPA* mapa){
    if(mapa){
        liberar_ponto(mapa->comida);
        free(mapa);
    }
}


 char retornar_char_mapa(MAPA* mapa, PONTO* p){
    int ind = retornar_ponto_y(p)*mapa->larg + retornar_ponto_x(p);
    return mapa->vet[ind];
 }
 
 int retornar_altu_mapa(MAPA* mapa){
    return mapa->altu;
 }
 int retornar_larg_mapa(MAPA* mapa){
    return mapa->larg;
 }
 PONTO* retornar_comida_mapa(MAPA* mapa){
    return mapa->comida;
 }