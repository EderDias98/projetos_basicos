#ifndef JOGO_H
#define JOGO_H
#include "mapa.h"
#include "cobra.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#define LARG 20 
#define ALTU 10

typedef struct jogo JOGO;
JOGO* criar_jogo();


int retornar_game_over_jogo(JOGO* jogo);


int eh_encontrei_comida_jogo(JOGO* jogo);
 

void iniciar_jogo(JOGO* jogo);

void atualizar_jogo(JOGO* jogo);


char retornar_direcao_cabeca(JOGO* jogo);
 

void desenhar_cobra_jogo(JOGO* jogo);
   
void iniciar_mapa_jogo(JOGO* jogo);

void eh_game_over_jogo(JOGO* jogo);

void liberar_jogo(JOGO* jogo);
void loop_jogo(JOGO* jogo);

#endif