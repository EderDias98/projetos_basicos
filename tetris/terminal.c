#include "terminal.h"


// Desativa o buffer de entrada para capturar teclas sem precisar pressionar ENTER
void desativar_buffer() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

// Restaura as configurações originais do terminal
void restaurar_buffer() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// Função para limpar a tela sem "piscar"
void limpar_tela() {
    printf("\033[H\033[J");
}