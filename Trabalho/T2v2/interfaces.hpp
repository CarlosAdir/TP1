#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"
#include "resultados.hpp"

#include <stdexcept>


/* 

################################################
######## DEFINICAO DAS CLASSES INICIAIS ########
################################################

*/
class consistencia_error
{
private:
    std::string self_message;
    std::string red(std::string message){self_message = "\033[1;31m" + message + "\033[0m"; return self_message;}
    std::string green(std::string message){self_message = "\033[1;32m" + message + "\033[0m"; return self_message;}
public:
    consistencia_error(std::string message){std::cout << red(message) << std::endl;}
    std::string what(){return self_message;}
};
class IU  // Classe base para interface do usuario - IU = Interface User
{
public:
    virtual void verifica_consistencia() throw (consistencia_error) = 0;
    
};
class ILN // Classe base para servicos - ILN = 
{
public:
    virtual void verifica_consistencia() throw (consistencia_error) = 0;
};




















/*

###################################################
######## DEFINICAO DAS CLASSES DE SERVICOS ########
###################################################

*/

class ILNCadastro;
class ILNAutenticacao;
class ILNAcomodacao;
class ILNReserva;
class ILNCadastroAcomodacao;
class ILNCartao;
class ILNContaCorrente;

class ILNCadastro:public ILN{
public:
    // virtual ResultadoCadastro cadastrar(const Usuario&) throw(consistencia_error)= 0;
};
class ILNAutenticacao:public ILN{
public:
    // const static int DEU_CERTO = 1;
    // virtual int autenticar(const Usuario &) = 0;
};
class ILNAcomodacao:public ILN{
public:
};
class ILNReserva:public ILN{
public:
};
class ILNCadastroAcomodacao:public ILN{
public:
};
class ILNCartao:public ILN{
public:
};
class ILNContaCorrente:public ILN{
public:
};
class ILNAlterarSenha:public ILN{
public:
};
class ILNAlterarNome:public ILN{
public:
};
class ILNDeletarConta:public ILN{
public:
};
















/*

###############################################################
######## DEFINICAO DAS CLASSES DE INTERFACE DO USUARIO ########
##############################################################

*/

class IUInicializacao;
class IUCadastro;
class IUAutenticacao;
class IULogado;
class IUAcomodacao;
class IUReserva;
class IUCadastroAcomodacao; // Cadastrar e remover acomodacao
class IUDados; // Os dados do usuario, em que pode alterar nome, senha, deletar a conta, colocar cartao de credito e conta corrente
class IUCartao;
class IUContaCorrente;
class IUAlterarSenha;
class IUAlterarNome;
class IUDeletarConta;




class IUInicializacao:public IU{
public:
    virtual void setCntrIUCadastro(IUCadastro *) = 0;
    virtual void setCntrIUAutenticacao(IUAutenticacao *) = 0;
    virtual void setCntrIUAcomodacao(IUAcomodacao *) = 0;
};
class IUCadastro:public IU{
public:
    virtual void setCntrILNCadastro(ILNCadastro *) = 0;
    virtual void setCntrIULogado(IULogado *) = 0;
};
class IUAutenticacao:public IU{ // Onde realiza o login. No esquematico eh o terceiro bloco
public:    
    virtual void setCntrILNAutenticacao(ILNAutenticacao *) = 0;
    virtual void setCntrIULogado(IULogado *) = 0;
};
class IULogado:public IU{
public:
    virtual void setCntrIUAcomodacao(IUAcomodacao *) = 0;
    virtual void setCntrIUReserva(IUReserva *) = 0;
    virtual void setCntrIUCadastroAcomodacao(IUCadastroAcomodacao *) = 0;
    virtual void setCntrIUDados(IUDados *) = 0;
};
class IUAcomodacao:public IU{
public:
    virtual void setCntrILNAcomodacao(ILNAcomodacao *) = 0;
};
class IUReserva:public IU{
public:
    virtual void setCntrILNReserva(ILNReserva *) = 0;
};
class IUCadastroAcomodacao:public IU{
public:
    virtual void setCntrILNCadastroAcomodacao(ILNCadastroAcomodacao *) = 0;
};
class IUDados:public IU{
public:
    virtual void setCntrIUCartao(IUCartao *) = 0;
    virtual void setCntrIUContaCorrente(IUContaCorrente *) = 0;
    virtual void setCntrIUAlterarSenha(IUAlterarSenha *) = 0;
    virtual void setCntrIUAlterarNome(IUAlterarNome *) = 0;
    virtual void setCntrIUDeletarConta(IUDeletarConta *) = 0;
};
class IUCartao:public IU{
public:
    virtual void setCntrILNCartao(ILNCartao *) = 0;
};
class IUContaCorrente:public IU{
public:
    virtual void setCntrILNContaCorrente(ILNContaCorrente *) = 0;
};
class IUAlterarSenha:public IU{
public:
    virtual void setCntrILNAlterarSenha(ILNAlterarSenha *) = 0;
};
class IUAlterarNome:public IU{
public:
    virtual void setCntrILNAlterarNome(ILNAlterarNome *) = 0;
};
class IUDeletarConta:public IU{
public:
    virtual void setCntrILNDeletarConta(ILNDeletarConta *) = 0;
};

#endif