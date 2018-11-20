#ifndef CONTROLADORAS_H_INCLUDED    
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "resultados.hpp"


#include <stdexcept>
#include <iostream>
#include <stdlib.h>


// Declaração de classe controladora de interação para o serviço de autenticação.


class CntrIUInicializacao: public IUInicializacao {

private:

	IUCadastro *cntrIUCadastro;
	IUAutenticacao *cntrIUAutenticacao;
	IUAcomodacao *cntrIUAcomodacao;

	const static char B_AUTENTICAR = '1';
	const static char B_CADASTRAR = '2';
	const static char B_ACOMODACAO = '3';
	const static char B_SAIR = '0';

public:

    CntrIUInicializacao();
    ~CntrIUInicializacao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrIUCadastro(IUCadastro*);
    void setCntrIUAutenticacao(IUAutenticacao*);
    void setCntrIUAcomodacao(IUAcomodacao*);

    void inicio();
    void apresentarOpcoes();
};




class CntrIUCadastro:public IUCadastro {

private:
    ILNCadastro *cntrILNCadastro;
    IULogado *cntrIULogado;
	// const static int LIMITE_TENTATIVAS = 4; 

public:
	CntrIUCadastro();
    ~CntrIUCadastro();
    void verifica_consistencia() throw (consistencia_error);
    void libera();
    
    void setCntrILNCadastro(ILNCadastro*);
    void setCntrIULogado(IULogado *);
};

class CntrIUAutenticacao:public IUAutenticacao {

private:
    ILNAutenticacao *cntrILNAutenticacao;
    IULogado *cntrIULogado;
public:
    CntrIUAutenticacao();
    ~CntrIUAutenticacao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();
    
    void setCntrILNAutenticacao(ILNAutenticacao*);
    void setCntrIULogado(IULogado *);

    void autenticar();
};

class CntrIULogado:public IULogado{
private:
    IUAcomodacao *cntrIUAcomodacao;
    IUReserva *cntrIUReserva;
    IUCadastroAcomodacao *cntrIUCadastroAcomodacao;
    IUDados *cntrIUDados;
public:
    CntrIULogado();
    ~CntrIULogado();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrIUAcomodacao(IUAcomodacao *);
    void setCntrIUReserva(IUReserva *);
    void setCntrIUCadastroAcomodacao(IUCadastroAcomodacao *);
    void setCntrIUDados(IUDados *);
};

class CntrIUAcomodacao:public IUAcomodacao {

private:
    ILNAcomodacao *cntrILNAcomodacao;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    CntrIUAcomodacao();
    ~CntrIUAcomodacao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNAcomodacao(ILNAcomodacao *);
    
};

class CntrIUReserva:public IUReserva {

private:
    ILNReserva *cntrILNReserva;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    CntrIUReserva();
    ~CntrIUReserva();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNReserva(ILNReserva *);    
};


class CntrIUCadastroAcomodacao:public IUCadastroAcomodacao {

private:
    ILNCadastroAcomodacao *cntrILNCadastroAcomodacao;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    CntrIUCadastroAcomodacao();
    ~CntrIUCadastroAcomodacao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNCadastroAcomodacao(ILNCadastroAcomodacao *);    
};


class CntrIUDados:public IUDados{
private:
    IUCartao *cntrIUCartao;
    IUContaCorrente *cntrIUContaCorrente;
    IUAlterarSenha *cntrIUAlterarSenha;
    IUAlterarNome *cntrIUAlterarNome;
    IUDeletarConta *cntrIUDeletarConta;
public:
    CntrIUDados();
    ~CntrIUDados();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrIUCartao(IUCartao *);
    void setCntrIUContaCorrente(IUContaCorrente *);
    void setCntrIUAlterarSenha(IUAlterarSenha *);
    void setCntrIUAlterarNome(IUAlterarNome *);
    void setCntrIUDeletarConta(IUDeletarConta *);
};


class CntrIUCartao:public IUCartao {

private:
    ILNCartao *cntrILNCartao;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    CntrIUCartao();
    ~CntrIUCartao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNCartao(ILNCartao *);    
};




class CntrIUContaCorrente:public IUContaCorrente {

private:
    ILNContaCorrente *cntrILNContaCorrente;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    CntrIUContaCorrente();
    ~CntrIUContaCorrente();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNContaCorrente(ILNContaCorrente *);    
};



class CntrIUAlterarSenha:public IUAlterarSenha {

private:
    ILNAlterarSenha *cntrILNAlterarSenha;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    CntrIUAlterarSenha();
    ~CntrIUAlterarSenha();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNAlterarSenha(ILNAlterarSenha *);    
};

class CntrIUAlterarNome:public IUAlterarNome {

private:
    ILNAlterarNome *cntrILNAlterarNome;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    CntrIUAlterarNome();
    ~CntrIUAlterarNome();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNAlterarNome(ILNAlterarNome *);    
};


class CntrIUDeletarConta:public IUDeletarConta {

private:
    ILNDeletarConta *cntrILNDeletarConta;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    CntrIUDeletarConta();
    ~CntrIUDeletarConta();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNDeletarConta(ILNDeletarConta *);    
};


#endif 