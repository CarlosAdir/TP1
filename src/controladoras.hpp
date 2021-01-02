#ifndef CONTROLADORAS_H_INCLUDED    
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "resultados.hpp"
#include "input_data.hpp"

#include <stdexcept>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>


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

    void apresentarOpcoes();
public:

    CntrIUInicializacao();
    ~CntrIUInicializacao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrIUCadastro(IUCadastro*);
    void setCntrIUAutenticacao(IUAutenticacao*);
    void setCntrIUAcomodacao(IUAcomodacao*);

    void menu();
};




class CntrIUCadastro:public IUCadastro {

private:
    ILNCadastro *cntrILNCadastro;
    IULogado *cntrIULogado;

	const static int LIMITE_TENTATIVAS = 4; 

    bool getData(Usuario *);
public:
	CntrIUCadastro();
    ~CntrIUCadastro();
    void verifica_consistencia() throw (consistencia_error);
    void libera();
    
    void setCntrILNCadastro(ILNCadastro*);
    void setCntrIULogado(IULogado *);

    void cadastrar();
};

class CntrIUAutenticacao:public IUAutenticacao {

private:
    ILNAutenticacao *cntrILNAutenticacao;
    IULogado *cntrIULogado;

    const static int LIMITE_TENTATIVAS = 3;

    bool getData(Identificador *, Senha *);
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

    const static char B_ACOMODACAO = '1';
    const static char B_CADASTRAR_ACOMODACAO = '2';
    const static char B_RESERVA = '3';
    const static char B_DADOS = '4';
    const static char B_LOGOUT = '0';

    void apresentarOpcoes(Identificador &);
public:
    CntrIULogado();
    ~CntrIULogado();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrIUAcomodacao(IUAcomodacao *);
    void setCntrIUReserva(IUReserva *);
    void setCntrIUCadastroAcomodacao(IUCadastroAcomodacao *);
    void setCntrIUDados(IUDados *);

    void menu(Identificador &);
};

class CntrIUAcomodacao:public IUAcomodacao {

private:
    ILNAcomodacao *cntrILNAcomodacao;
    const static int LIMITE_TENTATIVAS = 4; 

    bool getData(Data *inicio, Data *termino, CapacidadeAcomodacao *cap, Nome *cidade, Estado *estado);
    void imprime_acomodacoes(std::vector<Acomodacao> &);

public:
    CntrIUAcomodacao();
    ~CntrIUAcomodacao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNAcomodacao(ILNAcomodacao *);

    void acomodacao();
    
};

class CntrIUReserva:public IUReserva {

private:
    ILNReserva *cntrILNReserva;
    const static int LIMITE_TENTATIVAS = 4; 

    const static char B_ADICIONAR = '1';
    const static char B_REMOVER = '2';
    const static char B_VOLTAR = '0';

    void apresentarOpcoes(Identificador &);

    void adicionar_reserva(Identificador &);
    void remover_reserva(Identificador &);
    bool verifica_cartaocredito(Identificador &);
    bool getDataAdicionar(Identificador *acomod_identificador, Data *inicio, Data *termino);
    bool getDataRemover(Identificador *acomod_identificador);
public:
    CntrIUReserva();
    ~CntrIUReserva();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNReserva(ILNReserva *);

    void menu(Identificador &);
};


class CntrIUCadastroAcomodacao:public IUCadastroAcomodacao {

private:
    ILNCadastroAcomodacao *cntrILNCadastroAcomodacao;
    const static int LIMITE_TENTATIVAS = 4;
     

    const static char B_ADICIONAR = '1';
    const static char B_REMOVER = '2';
    const static char B_VOLTAR = '0';

    void apresentarOpcoes(Identificador &);

    void adicionar_acomodacao(Identificador &);
    void remover_acomodacao(Identificador &);
    bool verifica_contacorrente(Identificador &);
    bool getDataRemover(Identificador *acomod_identificador);
    bool getDataAdicionar(Acomodacao *acomodacao);
public:
    CntrIUCadastroAcomodacao();
    ~CntrIUCadastroAcomodacao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNCadastroAcomodacao(ILNCadastroAcomodacao *);    

    void menu(Identificador &);
};









class CntrIUDados:public IUDados{
private:
    IUCartao *cntrIUCartao;
    IUContaCorrente *cntrIUContaCorrente;
    IUAlterarSenha *cntrIUAlterarSenha;
    IUAlterarNome *cntrIUAlterarNome;
    IUDeletarConta *cntrIUDeletarConta;

    const static char B_CARTAO = '1';
    const static char B_CONTA = '2';
    const static char B_SENHA = '3';
    const static char B_NOME = '4';
    const static char B_DELETAR = '5';
    const static char B_VOLTAR = '0';
    
    void apresentarOpcoes(Identificador &);
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

    void menu(Identificador &);
};


class CntrIUCartao:public IUCartao {

private:
    ILNCartao *cntrILNCartao;
    const static int LIMITE_TENTATIVAS = 4; 
    bool getData(CartaoCredito *cartao);
public:
    CntrIUCartao();
    ~CntrIUCartao();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNCartao(ILNCartao *); 

    void setCartao(Identificador &);
};




class CntrIUContaCorrente:public IUContaCorrente {

private:
    ILNContaCorrente *cntrILNContaCorrente;
    const static int LIMITE_TENTATIVAS = 4; 

    bool getData(ContaCorrente *);

public:
    CntrIUContaCorrente();
    ~CntrIUContaCorrente();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNContaCorrente(ILNContaCorrente *);

    void setConta(Identificador &);  
};



class CntrIUAlterarSenha:public IUAlterarSenha {

private:
    ILNAlterarSenha *cntrILNAlterarSenha;
    const static int LIMITE_TENTATIVAS = 4; 

    bool getData(Senha *velha, Senha *nova);
public:
    CntrIUAlterarSenha();
    ~CntrIUAlterarSenha();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNAlterarSenha(ILNAlterarSenha *);    

    void setSenha(Identificador &);
};

class CntrIUAlterarNome:public IUAlterarNome {

private:
    ILNAlterarNome *cntrILNAlterarNome;
    const static int LIMITE_TENTATIVAS = 4; 

    bool getData(Nome *nome, Senha *senha);
public:
    CntrIUAlterarNome();
    ~CntrIUAlterarNome();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNAlterarNome(ILNAlterarNome *);

    void setNome(Identificador &);
};


class CntrIUDeletarConta:public IUDeletarConta {

private:
    ILNDeletarConta *cntrILNDeletarConta;
    
    bool getData(Senha *);
public:
    CntrIUDeletarConta();
    ~CntrIUDeletarConta();
    void verifica_consistencia() throw (consistencia_error);
    void libera();

    void setCntrILNDeletarConta(ILNDeletarConta *);  

    void deletar(Identificador &);  
};


#endif 