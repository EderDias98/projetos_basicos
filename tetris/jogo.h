#ifndef JOGO_H
#define JOGO_H
#include "mapa.h"
#include "peca.h"
#include "terminal.h"
#include "time.h"

typedef struct jogo JOGO;
int escolher_peca();


JOGO* criar_jogo();


void jogar_jogo(JOGO* j);

#endif