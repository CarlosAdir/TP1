#ifndef INPUT_DATA_H_INCLUDED    
#define INPUT_DATA_H_INCLUDED

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

 
char getch();
int kbhit(void);
void limpar_buffer();
void travar_tela();
std::string red(std::string);
std::string green(std::string);
void limpar_tela();

#endif 