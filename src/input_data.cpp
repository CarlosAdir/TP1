#include "input_data.hpp"

 
char getch()/*le um caracter da entrada padrão sem o bloqueio de entrada(nao necessita apertar enter) */
{
    int ch;
    struct termios oldt;
    struct termios newt;
    tcgetattr(STDIN_FILENO,&oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

void limpar_buffer()
{
  while(kbhit())
  {
    getch();
  }
  std::cin.clear();
}
void travar_tela()
{
  limpar_buffer();
  std::cout << "Pressione uma tecla...";
  getch();
}


std::string red(std::string message)
{
  return "\033[1;31m" + message + "\033[0m";
}
std::string green(std::string message)
{
    return "\033[1;32m" + message + "\033[0m";
}
void limpar_tela()
{
  system("clear || cls");
  // std::cout << "\n\n\n" << std::endl;
}


std::vector<std::string> split(std::string str, char delimiter = ' ')
{
    std::vector<std::string> ret;
    if(str.empty()) 
    {
        ret.push_back(std::string(""));
        return ret;
    }

    unsigned i = 0;
    std::string strstack;
    while(!(str.empty()) && (str[0] == delimiter)) {str.erase(0,1);}
    std::reverse(str.begin(), str.end());
    while(!(str.empty()) && (str[0] == delimiter)) {str.erase(0,1);}
    std::reverse(str.begin(), str.end());
    while(!str.empty())
    {
        ret.push_back(str.substr(i, str.find(delimiter)));
        str.erase(0,str.find(delimiter));
        while(!(str.empty()) && (str[0] == delimiter)) {str.erase(0,1);}
    }

    return ret;
}