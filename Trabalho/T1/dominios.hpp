#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <ctype.h>


class Agencia
{
private:
	std::string agencia;
	void validar(std::string) throw (std::invalid_argument);
	static const bool VERBOSE = false;
public:

	void set(std::string agencia) throw (std::invalid_argument); /**< Try to set the agencia number on the object */
	std::string get(); /**< Returns Agencia's string with 5 digits. */
	// Agencia(std::string);
	Agencia();
};


class Banco
{
private:
	std::string banco;
	void validar(std::string banco) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Try to set the banco number on the object. */
	std::string get(); /**< Returns Banco's string with 3 digits. */
	// Banco(std::string);
	Banco();
};


class CapacidadeAcomodacao
{
private:
	int valor;
	void validar(int valor) throw (std::invalid_argument);
public:
	void set(int) throw (std::invalid_argument); /**< Try to set the accommodation capacity number on the object. */
	int get(); /**< Returns the capacity value from CapacidadeAcomodacao's object. */
	CapacidadeAcomodacao();
};


class Diaria
{
private:
	double valor;
	void validar(double valor) throw (std::invalid_argument);
public:
	void set(double) throw (std::invalid_argument); /**< Try to set the price of Diaria on the object. */
	double get(); /**< Returns the price of a Diaria. */
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
	void set(int, std::string, int) throw (std::invalid_argument); /**< Try to set the date on the object */
	int getDia(); /**< Returns the day stored on Data's object. */
	std::string getMes(); /**< Returns the month stored on Data's object. */
	int getAno(); /**< Returns the year stored on Data's object. */
	// Data(int, std::string, int);
	Data();
};


class DataValidade
{
private:
	int mes, ano;
	void validar(int, int) throw (std::invalid_argument);
public:
	void set(int, int) throw (std::invalid_argument); /**< Try to set the validation date on the object */
	int getMes(); /**< Returns the month stored on DataValidade's object. */
	int getAno(); /**< Returns the year stored on DataValidade's object. */
	// DataValidade(int, int);
	DataValidade();
};


class Estado
{
private:
	std::string estado;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Try to set a state of Brazil on the object */
	std::string get(); /**< Returns the state of Brazil stored on Estado's object. */
	// Estado(std::string);
	Estado();
};


class Identificador
{
private:
	std::string identificador;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Try to set a identificator on the object */
	std::string get(); /**< Returns the identificator stored on Identificador's object. */
	// Identificador(std::string);
	Identificador();
};


class Nome
{
private:
	std::string nome;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Try to set a name on the object */
	std::string get(); /**< Returns the name stored on Nome's object. */
	// Nome(std::string);
	Nome();
};


class NumeroCartaoCredito
{
private:
	std::string numerocartaocredito;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Try to set a credit card number on the object */
	std::string get(); /**< Returns the credit card number stored on NumeroCartaoCredito's object. */
	// NumeroCartaoCredito(std::string);
	NumeroCartaoCredito();
};


class NumeroContaCorrente
{
private:
	std::string numerocontacorrente;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Try to set a account number on the object */
	std::string get(); /**< Returns the account number stored on NumeroContaCorrente's object. */
	// NumeroContaCorrente(std::string);
	NumeroContaCorrente();
};


class Senha
{
private:
	std::string senha;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Try to set a password on the object */
	std::string get(); /**< Returns the password stored on Senha's object. */
	// Senha(std::string);
	Senha();
};


class TipoAcomodacao
{
private:
	std::string tipoacomodacao;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument); /**< Try to set a accomodation type on the object */
	std::string get(); /**< Returns the accomodation type stored on TipoAcomodacao's object. */
	// TipoAcomodacao(std::string);
	TipoAcomodacao();
};

#endif
