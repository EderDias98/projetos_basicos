#include "jogo.h"
#include <unistd.h>
#include <termios.h>

struct jogo{
    MAPA* mapa;
    COBRA* cobra;
    int tecla_atual;
    int game_over;
};

JOGO* criar_jogo(){
    JOGO* jogo = (JOGO*) malloc(sizeof(JOGO));
    jogo->game_over = 0;
    jogo->tecla_atual = 'd';
    return jogo;
}

int retornar_game_over_jogo(JOGO* jogo){
    return jogo->game_over;
}


int eh_encontrei_comida_jogo(JOGO* jogo){
    PONTO* p = retornar_ponto_cobra(jogo->cobra, 0);
    if(retornar_char_mapa(jogo->mapa, p) == '$'){
        return 1;
    }else return 0;
}

void iniciar_jogo(JOGO* jogo){
    jogo->mapa = criar_mapa(LARG, ALTU);
    jogo->cobra = criar_cobra();
    iniciar_mapa_jogo(jogo);
   

}

MAPA* retornar_mapa_jogo(JOGO* jogo){
    return jogo->mapa;
}

void atualizar_jogo(JOGO* jogo){
    
    char tecla;
    
    if (read(STDIN_FILENO, &tecla, 1) > 0){
        jogo->tecla_atual = tecla;
    }

    PONTO* ultimo = retornar_ponto_cobra(jogo->cobra, retornar_tam_cobra(jogo->cobra)-1);
    
    atualizar_ponto_mapa(jogo->mapa, ultimo, ' ');
    andar_cobra(jogo->cobra, jogo->tecla_atual);
    
    if(eh_encontrei_comida_jogo(jogo)){
        criar_comida_mapa(jogo->mapa);
        atualizar_ponto_mapa(jogo->mapa, retornar_comida_mapa(jogo->mapa), '$');
        crescer_cobra(jogo->cobra, ultimo);
    }else {
        liberar_ponto(ultimo);
    }

    eh_game_over_jogo(jogo);
    desenhar_cobra_jogo(jogo);
   

}



char retornar_direcao_cabeca(JOGO* jogo){
    char dir = 'T';
    if(jogo->tecla_atual == 'd'){
        dir = '>';
    }else if(jogo->tecla_atual == 'a'){
        dir = '<';
    }else if(jogo->tecla_atual == 'w'){
        dir = '^';
    }else if(jogo->tecla_atual){
        dir = 'V';
    }
    return dir;
}

void desenhar_cobra_jogo(JOGO* jogo){
    PONTO* p;
    for(int i=0; i< retornar_tam_cobra(jogo->cobra); i++){
        p = retornar_ponto_cobra(jogo->cobra,i);
        if(jogo->game_over){
            atualizar_ponto_mapa(jogo->mapa, p, 'X');
            continue;
        }
        if(i !=0){
            atualizar_ponto_mapa(jogo->mapa,p, 'o');
        }else atualizar_ponto_mapa(jogo->mapa,p, retornar_direcao_cabeca(jogo));

    }
    
}
void iniciar_mapa_jogo(JOGO* jogo){
    //posicao cobra



    //desenhar as paredes
    int larg = retornar_larg_mapa(jogo->mapa);
    int altu = retornar_altu_mapa(jogo->mapa);
    PONTO* p = criar_ponto(0,0);
    for(int i=0; i< altu ; i++){
        for(int j=0; j< larg; j++){
            atualizar_ponto(p,j,i);
            if(i==0 || i == altu -1 || j==0 || j == larg -1){
                atualizar_ponto_mapa(jogo->mapa,p,'#');
            }else{
                atualizar_ponto_mapa(jogo->mapa,p, ' ');
            };
        }
    }
    criar_comida_mapa(jogo->mapa);
    atualizar_ponto_mapa(jogo->mapa, retornar_comida_mapa(jogo->mapa), '$');
    liberar_ponto(p);
    desenhar_cobra_jogo(jogo);
}
void eh_game_over_jogo(JOGO* jogo){
    // se encontar na parede 
    PONTO* cabeca = retornar_ponto_cobra(jogo->cobra, 0);
  
    if(retornar_char_mapa(jogo->mapa, cabeca) == '#' || retornar_char_mapa(jogo->mapa, cabeca) == 'o'){
        jogo->game_over=1;
    }else jogo->game_over = 0;
    // se esconstar na propia calda
}

void liberar_jogo(JOGO* jogo){
    if(jogo){
        liberar_mapa(jogo->mapa);
        liberar_cobra(jogo->cobra);
        free(jogo);
    }
}