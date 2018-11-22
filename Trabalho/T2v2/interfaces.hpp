#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.hpp"
#include "entidades.hpp"
#include "resultados.hpp"

#include <stdexcept>
#include <vector>


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
    virtual ~IU(){};
    virtual void verifica_consistencia() throw (consistencia_error) = 0;
    virtual void libera() = 0;
};
class ILN // Classe base para servicos - ILN = 
{
public:
    virtual ~ILN(){};
    virtual void verifica_consistencia() throw (consistencia_error) = 0;
    virtual void libera() = 0;
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
    virtual ResultadoCadastro cadastrar(const Usuario&) throw(std::runtime_error) = 0;
    // virtual ResultadoCadastro cadastrar(const Usuario&) throw(consistencia_error)= 0;
};
class ILNAutenticacao:public ILN{
public:
    virtual ResultadoAutenticacao autenticar(const Identificador&, const Senha&) throw(std::runtime_error)= 0;
};
class ILNAcomodacao:public ILN{
public:
    virtual std::vector<Acomodacao> acomodacoes_cabiveis(Data &, Data &, CapacidadeAcomodacao &, Nome &, Estado &) = 0;
};
class ILNReserva:public ILN{
public:
    virtual bool existe_cartaocredito(Identificador &) = 0;
    virtual ResultadoAdicionarReserva adicionar_reserva(Identificador &identificador, Identificador &acomod_identificador, Data &inicio, Data &termino) = 0;
    virtual ResultadoRemoverReserva remover_reserva(Identificador &identificador, Identificador &acomod_identificador) = 0;
};
class ILNCadastroAcomodacao:public ILN{
public:
    virtual bool existe_contacorrente(Identificador &) = 0;
    virtual ResultadoAdicionarAcomodacao adicionar_acomodacao(Identificador &identificador, Acomodacao &acomodacao) = 0;
    virtual ResultadoRemoverAcomodacao remover_acomodacao(Identificador &identificador, Identificador &acomod_identificador) = 0;
};
class ILNCartao:public ILN{
public:
    virtual ResultadoCartaoCredito cartao_credito(Identificador &, CartaoCredito &novo) = 0;
};
class ILNContaCorrente:public ILN{
public:
    virtual ResultadoContaCorrente conta_corrente(Identificador &, ContaCorrente &nova) = 0;
};
class ILNAlterarSenha:public ILN{
public:
    virtual ResultadoAlterarSenha alterar_senha(Identificador &, Senha &velha, Senha &nova) = 0;
};
class ILNAlterarNome:public ILN{
public:
    virtual ResultadoAlterarNome alterar_nome(Identificador &, Nome &novo, Senha &senha) = 0;
};
class ILNDeletarConta:public ILN{
public:
    virtual ResultadoDeletarConta deletar(Identificador &, Senha &) = 0;  
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
    virtual ~IUInicializacao(){};
    virtual void menu() = 0;
    virtual void setCntrIUCadastro(IUCadastro *) = 0;
    virtual void setCntrIUAutenticacao(IUAutenticacao *) = 0;
    virtual void setCntrIUAcomodacao(IUAcomodacao *) = 0;
};
class IUCadastro:public IU{
public:
    virtual ~IUCadastro(){};
    virtual void setCntrILNCadastro(ILNCadastro *) = 0;
    virtual void setCntrIULogado(IULogado *) = 0;

    virtual void cadastrar() = 0;
};
class IUAutenticacao:public IU{ // Onde realiza o login. No esquematico eh o terceiro bloco
public:    
    virtual ~IUAutenticacao(){};
    virtual void setCntrILNAutenticacao(ILNAutenticacao *) = 0;
    virtual void setCntrIULogado(IULogado *) = 0;

    virtual void autenticar() = 0;
};
class IULogado:public IU{
public:
    virtual ~IULogado(){};
    virtual void setCntrIUAcomodacao(IUAcomodacao *) = 0;
    virtual void setCntrIUReserva(IUReserva *) = 0;
    virtual void setCntrIUCadastroAcomodacao(IUCadastroAcomodacao *) = 0;
    virtual void setCntrIUDados(IUDados *) = 0;

    virtual void menu(Identificador &) = 0;
};
class IUAcomodacao:public IU{
public:
    virtual ~IUAcomodacao(){};
    virtual void setCntrILNAcomodacao(ILNAcomodacao *) = 0;
    virtual void acomodacao() = 0;
};
class IUReserva:public IU{
public:
    virtual ~IUReserva(){};
    virtual void setCntrILNReserva(ILNReserva *) = 0;

    virtual void menu(Identificador &) = 0;
};
class IUCadastroAcomodacao:public IU{
public:
    virtual ~IUCadastroAcomodacao(){};
    virtual void setCntrILNCadastroAcomodacao(ILNCadastroAcomodacao *) = 0;

    virtual void menu(Identificador &) = 0;
};
class IUDados:public IU{
public:
    virtual ~IUDados(){};
    virtual void setCntrIUCartao(IUCartao *) = 0;
    virtual void setCntrIUContaCorrente(IUContaCorrente *) = 0;
    virtual void setCntrIUAlterarSenha(IUAlterarSenha *) = 0;
    virtual void setCntrIUAlterarNome(IUAlterarNome *) = 0;
    virtual void setCntrIUDeletarConta(IUDeletarConta *) = 0;

    virtual void menu(Identificador &) = 0;
};
class IUCartao:public IU{
public:
    virtual ~IUCartao(){};
    virtual void setCntrILNCartao(ILNCartao *) = 0;

    virtual void setCartao(Identificador &) = 0;
};
class IUContaCorrente:public IU{
public:
    virtual ~IUContaCorrente(){};
    virtual void setCntrILNContaCorrente(ILNContaCorrente *) = 0;

    virtual void setConta(Identificador &) = 0;
};
class IUAlterarSenha:public IU{
public:
    virtual ~IUAlterarSenha(){};
    virtual void setCntrILNAlterarSenha(ILNAlterarSenha *) = 0;

    virtual void setSenha(Identificador &) = 0;
};
class IUAlterarNome:public IU{
public:
    virtual ~IUAlterarNome(){};
    virtual void setCntrILNAlterarNome(ILNAlterarNome *) = 0;

    virtual void setNome(Identificador &) = 0;
};
class IUDeletarConta:public IU{
public:
    virtual ~IUDeletarConta(){};
    virtual void setCntrILNDeletarConta(ILNDeletarConta *) = 0;

    virtual void deletar(Identificador &) = 0;
};


#endif