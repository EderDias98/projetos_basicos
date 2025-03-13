#include "mapa.h"


struct mapa
{
    int* vet;
    int larg;
    int altu;
};


MAPA* criar_mapa(int larg, int altu){
    MAPA* m = (MAPA*) malloc(sizeof(MAPA));
    m->vet = (int*) malloc(sizeof(int)*larg*altu);
    m->altu = altu;
    m->larg =larg;
}


int retorna_indice_mapa(int i, int j, int larg){
    return i*larg +j;
}

void gerar_mapa(MAPA* m){
    for(int i=0; i< m->altu ; i++){
        for(int j=0; j< m->larg; j++){
            int ind = retorna_indice_mapa(i,j,m->larg);
            int num = m->vet[ind];
            if(num == 1){
                printf(" ");
            }else if(num == 2 || num ==3){
                printf("#");
            };
        }
        printf("\n");
    }
}

void desenhar_parede_mapa(MAPA* m){
    for(int i=0; i< m->altu ; i++){
        for(int j=0; j< m->larg; j++){
            int ind = retorna_indice_mapa(i,j,m->larg);
            if(i==0 || i == m->altu -1 || j==0 || j == m->larg -1){
                m->vet[ind] = 3;
            }else{
                m->vet[ind] = 1;
            };
        }
    }
}

void limpar_mapa(MAPA*m){
    for(int i=0; i< m->altu ; i++){
        for(int j=0; j< m->larg; j++){
            int ind = retorna_indice_mapa(i,j,m->larg);
            if(m->vet[ind] == 2){
                m->vet[ind] = 1;
            }
        }
    }
}

void desenhar_peca_mapa(MAPA*m,PECA* p){
    int i = retornar_y_peca(p);
    int j = retornar_x_peca(p);
    for (int k = 0; k < 4; k++)
    {
        for (int l = 0; l < 4; l++)
        {
            int ind_p = retorna_indice_peca(k, l, 4);
            int num = retornar_conteudo_peca(p, ind_p);
            int ind_m = retorna_indice_mapa(i + l, j + k, m->larg);
            m->vet[ind_m] = num;
        }
    }
} 
int retorna_altura_mapa(MAPA* m){
    return m->altu;
}

int retorna_largura_mapa(MAPA* m){
    return m->larg;
}
void atualizar_mapa(MAPA* m, int ind, int num){
    m->vet[ind] = num; 
}

int congelar_peca_mapa(MAPA*m, PECA* p, int* p_c){
    //logica das bordas
    // logica colisao de pecas
    int i = retornar_y_peca(p);
    int j = retornar_x_peca(p);

    for (int k = 0; k < 4; k++)
    {
        for (int l = 0; l < 4; l++)
        {
            int ind_p = retorna_indice_peca(k, l, 4);
            int num_p = retornar_conteudo_peca(p, ind_p);
            int ind_m = retorna_indice_mapa(i + l, j + k, m->larg);
            int num_m = m->vet[ind_m];
            if (num_p == 2 && num_m == 3)
            {
                *p_c = 1;
                congelar_peca(p);
            }
        }
    }

}