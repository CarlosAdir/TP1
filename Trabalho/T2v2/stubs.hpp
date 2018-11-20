#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.hpp"

// #include <stdexcept>
// #include <iostream>
// #include <typeinfo>


class StubILNCadastro:public ILNCadastro
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNAutenticacao:public ILNAutenticacao
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNAcomodacao:public ILNAcomodacao
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNReserva:public ILNReserva
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNCadastroAcomodacao:public ILNCadastroAcomodacao
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNCartao:public ILNCartao
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNContaCorrente:public ILNContaCorrente
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNAlterarSenha:public ILNAlterarSenha
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNAlterarNome:public ILNAlterarNome
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};
class StubILNDeletarConta:public ILNDeletarConta
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();
};

#endif // STUBS_H_INCLUDED
