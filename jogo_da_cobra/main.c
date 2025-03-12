#include <stdio.h>
#include "jogo.h"
#define LARG 20 
#define ALTU 10



int main(){


    JOGO* j = criar_jogo();
    iniciar_jogo(j);
    loop_jogo(j);
    liberar_jogo(j);
    return 0;
}