#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <ctype.h>

class Agencia
{
//!
//! ... There is some text to put here to see what happens on the documentation ...
//!
private:
	std::string agencia; /*!< Detailed description after the member */
	void validar(std::string) throw (std::invalid_argument);
	static const bool VERBOSE = false; 
public:
	void set(std::string) throw (std::invalid_argument); /**< Set the number of the Agencia's object. */
	std::string get(); /**< Returns the string number of Agencia's object. */
	// Agencia(std::string);
	Agencia();
};

class Banco
{
private:
	std::string banco;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Set the number of the Banco's object. */
	std::string get(); /**< Returns the string number of Agencia's object. */
	// Banco(std::string);
	Banco();
};

class CapacidadeAcomodacao
{
private:
	int valor;
	void validar(int) throw (std::invalid_argument);
public:
	void set(int) throw (std::invalid_argument);
	int get();
	CapacidadeAcomodacao();
};

class Diaria
{
private:
	double valor;
	void validar(double) throw (std::invalid_argument);
public:
	void set(double) throw (std::invalid_argument);
	double get();
	// Diaria( double );
	Diaria();
};

class Data
{
private:
	int dia, ano;
	std::string mes;
	void validar(int, std::string, int) throw (std::invalid_argument);
public:
	void set(int, std::string, int) throw (std::invalid_argument);
	int getDia();
	std::string getMes();
	int getAno();
	// Data(int, std::string, int);
	Data();
};

class DataValidade
{
private:
	int mes, ano;
	void validar(int, int) throw (std::invalid_argument);
public:
	void set(int, int) throw (std::invalid_argument);
	int getMes();
	int getAno();
	// DataValidade(int, int);
	DataValidade();
};

class Estado
{
private:
	std::string estado;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	// Estado(std::string);
	Estado();
};

class Identificador
{
private:
	std::string identificador;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	// Identificador(std::string);
	Identificador();
};

class Nome
{
private:
	std::string nome;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	// Nome(std::string);
	Nome();
};

class NumeroCartaoCredito
{
private:
	std::string numerocartaocredito;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	// NumeroCartaoCredito(std::string);
	NumeroCartaoCredito();
};

class NumeroContaCorrente
{
private:
	std::string numerocontacorrente;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	// NumeroContaCorrente(std::string);
	NumeroContaCorrente();
};

class Senha
{
private:
	std::string senha;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	// Senha(std::string);
	Senha();
};

class TipoAcomodacao
{
private:
	std::string tipoacomodacao;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	// TipoAcomodacao(std::string);
	TipoAcomodacao();
};

#endif