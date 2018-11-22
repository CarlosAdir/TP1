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
	// Sets
	void setNome(const Nome&);
	void setIdentificador(const Identificador&);
	void setSenha(const Senha&);
	// Gets
	Nome getNome() const;
	Identificador getIdentificador() const;
	Senha getSenha() const;
	// Construct
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
	void validar(Data inicio, Data termino) throw (std::invalid_argument);
public:
	// Sets
	void setIdentificador(const Identificador&);
	void setTipoAcomodacao(const TipoAcomodacao&);
	void setCapacidadeAcomodacao(const CapacidadeAcomodacao&);
	void setDatas(const Data &inicio, const Data &termino);
	void setCidade(const Nome&);
	void setEstado(const Estado&);
	void setDiaria(const Diaria&);
	// Gets
	Identificador getIdentificador() const;
	TipoAcomodacao getTipoAcomodacao() const;
	CapacidadeAcomodacao getCapacidadeAcomodacao() const;
	Data getDataInicio() const;
	Data getDataTermino() const;
	Nome getCidade() const;
	Estado getEstado() const;
	Diaria getDiaria() const;
	// Construct
	Acomodacao();
	~Acomodacao();
};


class CartaoCredito
{
private:
	NumeroCartaoCredito numero;
	DataValidade data_validade;
public:
	// Sets
	void setNumero(const NumeroCartaoCredito&);
	void setValidade(const DataValidade&);
	// Gets
	NumeroCartaoCredito getNumero() const;
	DataValidade getValidade() const;
	// Construct
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
	// Sets
	void setContaCorrente(const NumeroContaCorrente &);
	void setAgencia(const Agencia&);
	void setBanco(const Banco&);
	// Gets
	NumeroContaCorrente getContaCorrente() const;
	Agencia getAgencia() const;
	Banco getBanco() const;
	// Construct
	ContaCorrente();
	~ContaCorrente();
};






#endif
