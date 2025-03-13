#ifndef TERMINAL_H
#define TERMINAL_H

#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>

void desativar_buffer();


// Restaura as configurações originais do terminal
void restaurar_buffer();


// Função para limpar a tela sem "piscar"
void limpar_tela();


#endif