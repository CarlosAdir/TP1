#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "input_data.hpp"

// #include <stdexcept>
// #include <iostream>
// #include <typeinfo>


class StubILNCadastro:public ILNCadastro
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoCadastro cadastrar(const Usuario&) throw(std::runtime_error);
};
class StubILNAutenticacao:public ILNAutenticacao
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoAutenticacao autenticar(const Identificador&, const Senha&) throw(std::runtime_error);
};
class StubILNAcomodacao:public ILNAcomodacao
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	std::vector<Acomodacao> acomodacoes_cabiveis(Data &, Data &, CapacidadeAcomodacao &, Nome &, Estado &);
};
class StubILNReserva:public ILNReserva
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	bool existe_cartaocredito(Identificador &);
    ResultadoAdicionarReserva adicionar_reserva(Identificador &identificador, Identificador &acomod_identificador, Data &inicio, Data &termino);
    ResultadoRemoverReserva remover_reserva(Identificador &identificador, Identificador &acomod_identificador);
};
class StubILNCadastroAcomodacao:public ILNCadastroAcomodacao
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	bool existe_contacorrente(Identificador &);
    ResultadoAdicionarAcomodacao adicionar_acomodacao(Identificador &, Acomodacao &);
    ResultadoRemoverAcomodacao remover_acomodacao(Identificador &identificador, Identificador &acomod_identificador);
};
class StubILNCartao:public ILNCartao
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoCartaoCredito cartao_credito(Identificador &identificador, CartaoCredito &novo);
};
class StubILNContaCorrente:public ILNContaCorrente
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoContaCorrente conta_corrente(Identificador &identificador, ContaCorrente &nova);
};
class StubILNAlterarSenha:public ILNAlterarSenha
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoAlterarSenha alterar_senha(Identificador &identificador, Senha &velha, Senha &nova);
};
class StubILNAlterarNome:public ILNAlterarNome
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoAlterarNome alterar_nome(Identificador &identificador, Nome &novo, Senha &senha);
};
class StubILNDeletarConta:public ILNDeletarConta
{
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoDeletarConta deletar(Identificador &identificador, Senha &senha);
};

#endif // STUBS_H_INCLUDED
