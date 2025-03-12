#include <stdio.h>
#include "jogo.h"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#define LARG 20 
#define ALTU 10


// Desativa o buffer de entrada para capturar teclas sem precisar pressionar ENTER
void desativarBuffer() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Restaura as configurações originais do terminal
void restaurarBuffer() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Função para limpar a tela sem "piscar"
void limparTela() {
    printf("\033[H\033[J");
}

int main(){
    struct termios old_tio, new_tio;

    // Salvar as configurações atuais do terminal
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    // Configurar entrada não bloqueante
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    JOGO* j = criar_jogo();
    iniciar_jogo(j);
    desativarBuffer();
    while(1){
        limparTela();
        usleep(100000);
        gerar_mapa(retornar_mapa_jogo(j));
        if(retornar_game_over_jogo(j) == 1){
            break;
        }
        atualizar_jogo(j);


    }
     // Restaurar as configurações originais do terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    liberar_jogo(j);



    return 0;
}