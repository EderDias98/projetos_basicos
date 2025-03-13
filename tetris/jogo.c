#include "jogo.h"

struct jogo{
    int game_over;
    MAPA* mapa;
    PECA* peca_atual;
    int peca_congelada;
    char tecla_precionada;
};

int escolher_peca(){
    srand(time(NULL));
    return (rand()%7)+1;
}

JOGO* criar_jogo(){
    JOGO* j = (JOGO*) malloc(sizeof( JOGO));
    j->mapa = criar_mapa(LARG, ALTU);
    j->peca_atual = NULL;
    j->peca_congelada = 1;
    return j;
}

void jogar_jogo(JOGO* j){
    desativar_buffer();
    PECA* estado_anterior;
    while(1){
       
        limpar_tela();
        if(j->peca_congelada = 1){
            // liberar peca;
            j->peca_atual = criar_peca(escolher_peca());
        }
        estado_anterior = salvar_estado_peca(j->peca_atual);
        cair_peca(j->peca_atual);
        if(read(STDIN_FILENO,&j->tecla_precionada,1) > 0){
            switch (j->tecla_precionada)
            {
            case 'd':
                /* code */
                break;
            
            case 'a':
                /* code */
                break;
            
            case 'r':
                /* code */
                break;
            default:
                break;
            }
        }
        congelar_peca_mapa(j->mapa,j->peca_atual, &j->peca_congelada);
        if(j->peca_congelada){
            liberar_peca(j->peca_atual);
            j->peca_atual = estado_anterior;
            congelar_peca(j->peca_atual);
        }

        desenhar_peca_mapa(j->mapa, j->peca_atual);

    }
   
}   