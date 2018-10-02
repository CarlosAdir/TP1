#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.hpp"

class Usuario
{
private:
	Nome nome;
	Identificador id;
	Senha senha;
public:
	Usuario();
	~Usuario();
};


class Acomodacao
{
private:
	Identificador id;
	TipoAcomodacao tipo;
	CapacidadeAcomodacao capacidade;
	Data data_inicio;
	Data data_termino;
	Nome cidade;
	Estado estado;
	Diaria diaria;
public:
	Acomodacao();
	~Acomodacao();
};


class CartaoCredito
{
private:
	NumeroCartaoCredito numero;
	DataValidade data_validade;
public:
	CartaoCredito();
	~CartaoCredito();
};


class ContaCorrente
{
private:
	NumeroContaCorrente numero;
	Agencia agencia;
	Banco banco;
public:
	ContaCorrente();
	~ContaCorrente();
};

#endif
