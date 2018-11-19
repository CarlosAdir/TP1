#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.hpp"

// #include <stdexcept>
// #include <iostream>
// #include <typeinfo>


class StubILNCadastro:public ILNCadastro
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNAutenticacao:public ILNAutenticacao
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNAcomodacao:public ILNAcomodacao
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNReserva:public ILNReserva
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNCadastroAcomodacao:public ILNCadastroAcomodacao
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNCartao:public ILNCartao
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNContaCorrente:public ILNContaCorrente
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNAlterarSenha:public ILNAlterarSenha
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNAlterarNome:public ILNAlterarNome
{
	void verifica_consistencia() throw (consistencia_error);
};
class StubILNDeletarConta:public ILNDeletarConta
{
	void verifica_consistencia() throw (consistencia_error);
};
// // Declaração de classe stub da interface ILNAutenticacao.

// class StubLNAutenticacao:public ILNAutenticacao{

// public:

//     // Definições de valores a serem usados como gatilhos para notificações de erros.

//     // const std::string TRIGGER_FALHA        = "PTkMe";
//     // const static std::string TRIGGER_ERRO_SISTEMA = 78901;

//     // Declaração de método previsto na interface.

//     ResultadoAutenticacao autenticar(const Identificador&, const Senha&) throw(consistencia_error);
// };


// class StubLNUsuario:public ILNUsuario{

// public:

// 	int cadastrar(const Usuario &) throw(consistencia_error);	
//     // int editar(const Identificador&, const Usuario &) throw(consistencia_error); 
//     int deletar(const Identificador&) throw(consistencia_error); 
    
// };


// class StubLNAcomodacao:public ILNAcomodacao{

// public:

// 	void acomodar() throw(consistencia_error);
//     // Definições de valores a serem usados como gatilhos para notificações de erros.

//     // const std::string TRIGGER_FALHA        = "PTkMe";
//     // const static std::string TRIGGER_ERRO_SISTEMA = 78901;

//     // Declaração de método previsto na interface.

//     // ResultadoAutenticacao autenticar(const Identificador&, const Senha&) throw(consistencia_error);
// };


// class StubLNReserva:public ILNReserva{

// public:

// 	void reservar() throw(consistencia_error);
//     // Definições de valores a serem usados como gatilhos para notificações de erros.

//     // const std::string TRIGGER_FALHA        = "PTkMe";
//     // const static std::string TRIGGER_ERRO_SISTEMA = 78901;

//     // Declaração de método previsto na interface.

//     // ResultadoAutenticacao autenticar(const Identificador&, const Senha&) throw(consistencia_error);
// };

#endif // STUBS_H_INCLUDED
