#ifndef CONTROLADORAS_H_INCLUDED    
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "resultados.hpp"

#include <stdexcept>
#include <iostream>


// Declaração de classe controladora de interação para o serviço de autenticação.


class CntrIUInicializacao: public IUInicializacao {

private:

	IUCadastro *cntrIUCadastro;
    IUAutenticacao *cntrIUAutenticacao;
	IUAcomodacao *cntrIUAcomodacao;

public:

    CntrIUInicializacao();
    void verifica_consistencia() throw (consistencia_error);

    void setCntrIUCadastro(IUCadastro*);
    void setCntrIUAutenticacao(IUAutenticacao*);
    void setCntrIUAcomodacao(IUAcomodacao*);

    void apresentarOpcoes();
};




class CntrIUCadastro:public IUCadastro {

private:
    ILNCadastro *cntrILNCadastro;
    IULogado *cntrIULogado;
	// const static int LIMITE_TENTATIVAS = 4; 

public:
    void verifica_consistencia() throw (consistencia_error);
	CntrIUCadastro();
    void setCntrILNCadastro(ILNCadastro*);
    void setCntrIULogado(IULogado *);
};

class CntrIUAutenticacao:public IUAutenticacao {

private:
    ILNAutenticacao *cntrILNAutenticacao;
    IULogado *cntrIULogado;
public:
    void verifica_consistencia() throw (consistencia_error);
    CntrIUAutenticacao();
    void setCntrILNAutenticacao(ILNAutenticacao*);
    void setCntrIULogado(IULogado *);
};

class CntrIULogado:public IULogado{
private:
    IUAcomodacao *cntrIUAcomodacao;
    IUReserva *cntrIUReserva;
    IUCadastroAcomodacao *cntrIUCadastroAcomodacao;
    IUDados *cntrIUDados;
public:
    void verifica_consistencia() throw (consistencia_error);
    CntrIULogado();
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
    void verifica_consistencia() throw (consistencia_error);
    CntrIUAcomodacao();
    void setCntrILNAcomodacao(ILNAcomodacao *);
    
};

class CntrIUReserva:public IUReserva {

private:
    ILNReserva *cntrILNReserva;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    void verifica_consistencia() throw (consistencia_error);
    CntrIUReserva();
    void setCntrILNReserva(ILNReserva *);    
};


class CntrIUCadastroAcomodacao:public IUCadastroAcomodacao {

private:
    ILNCadastroAcomodacao *cntrILNCadastroAcomodacao;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    void verifica_consistencia() throw (consistencia_error);
    CntrIUCadastroAcomodacao();
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
    void verifica_consistencia() throw (consistencia_error);
    CntrIUDados();
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
    void verifica_consistencia() throw (consistencia_error);
    CntrIUCartao();
    void setCntrILNCartao(ILNCartao *);    
};




class CntrIUContaCorrente:public IUContaCorrente {

private:
    ILNContaCorrente *cntrILNContaCorrente;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    void verifica_consistencia() throw (consistencia_error);
    CntrIUContaCorrente();
    void setCntrILNContaCorrente(ILNContaCorrente *);    
};



class CntrIUAlterarSenha:public IUAlterarSenha {

private:
    ILNAlterarSenha *cntrILNAlterarSenha;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    void verifica_consistencia() throw (consistencia_error);
    CntrIUAlterarSenha();
    void setCntrILNAlterarSenha(ILNAlterarSenha *);    
};

class CntrIUAlterarNome:public IUAlterarNome {

private:
    ILNAlterarNome *cntrILNAlterarNome;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    void verifica_consistencia() throw (consistencia_error);
    CntrIUAlterarNome();
    void setCntrILNAlterarNome(ILNAlterarNome *);    
};


class CntrIUDeletarConta:public IUDeletarConta {

private:
    ILNDeletarConta *cntrILNDeletarConta;
    // const static int LIMITE_TENTATIVAS = 4; 

public:
    void verifica_consistencia() throw (consistencia_error);
    CntrIUDeletarConta();
    void setCntrILNDeletarConta(ILNDeletarConta *);    
};


#endif 