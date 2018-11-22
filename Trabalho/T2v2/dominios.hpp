#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <ctype.h>


class Agencia
{
private:
	std::string agencia;
	void validar(std::string agencia) throw (std::invalid_argument);
public:

	void set(std::string agencia) throw (std::invalid_argument); /**< Try to set the agencia number on the object */
	std::string get(); /**< Returns Agencia's string with 5 digits. */
	// Agencia(std::string);
	Agencia();
	friend std::ostream& operator<<(std::ostream& os, Agencia&);
    friend std::istream& operator>>(std::istream& os, Agencia&);
};


class Banco
{
private:
	std::string banco;
	void validar(std::string banco) throw (std::invalid_argument);
public:
	void set(std::string banco) throw (std::invalid_argument); /**< Try to set the banco number on the object. */
	std::string get(); /**< Returns Banco's string with 3 digits. */
	// Banco(std::string);
	Banco();
	friend std::ostream& operator<<(std::ostream& os, Banco&);
    friend std::istream& operator>>(std::istream& os, Banco&);
};


class CapacidadeAcomodacao
{
private:
	int valor;
	void validar(int valor) throw (std::invalid_argument);
public:
	void set(int valor) throw (std::invalid_argument); /**< Try to set the accommodation capacity number on the object. */
	int get(); /**< Returns the capacity value from CapacidadeAcomodacao's object. */
	CapacidadeAcomodacao();
	friend std::ostream& operator<<(std::ostream& os, CapacidadeAcomodacao&);
    friend std::istream& operator>>(std::istream& os, CapacidadeAcomodacao&);
};


class Diaria
{
private:
	double valor;
	void validar(double valor) throw (std::invalid_argument);
public:
	void set(double valor) throw (std::invalid_argument); /**< Try to set the price of Diaria on the object. */
	double get(); /**< Returns the price of a Diaria. */
	// Diaria( double );
	Diaria();
	friend std::ostream& operator<<(std::ostream& os, Diaria&);
    friend std::istream& operator>>(std::istream& os, Diaria&);
};


class Data
{
private:
	int dia, ano;
	std::string mes;
	void validar(int dia, std::string mes, int ano) throw (std::invalid_argument);
	int mes_number(const std::string &) throw (std::invalid_argument);
public:
	void set(int dia, std::string mes, int ano) throw (std::invalid_argument); /**< Try to set the date on the object */
	int getDia(); /**< Returns the day stored on Data's object. */
	std::string getMes(); /**< Returns the month stored on Data's object. */
	int getAno(); /**< Returns the year stored on Data's object. */
	// Data(int, std::string, int);
	Data();
	bool operator<(Data &d1);
	friend std::ostream& operator<<(std::ostream& os, Data&);
    friend std::istream& operator>>(std::istream& os, Data&);
};


class DataValidade
{
private:
	int mes, ano;
	void validar(int mes, int ano) throw (std::invalid_argument);
public:
	void set(int mes, int ano) throw (std::invalid_argument); /**< Try to set the validation date on the object */
	int getMes(); /**< Returns the month stored on DataValidade's object. */
	int getAno(); /**< Returns the year stored on DataValidade's object. */
	// DataValidade(int, int);
	DataValidade();
	friend std::ostream& operator<<(std::ostream& os, DataValidade&);
    friend std::istream& operator>>(std::istream& os, DataValidade&);
};


class Estado
{
private:
	std::string estado;
	void validar(std::string estado) throw (std::invalid_argument);
public:
	void set(std::string estado) throw (std::invalid_argument); /**< Try to set a state of Brazil on the object */
	std::string get(); /**< Returns the state of Brazil stored on Estado's object. */
	// Estado(std::string);
	Estado();
	friend std::ostream& operator<<(std::ostream& os, Estado&);
    friend std::istream& operator>>(std::istream& os, Estado&);
};


class Identificador
{
private:
	std::string identificador;
	void validar(std::string id) throw (std::invalid_argument);
public:
	void set(std::string id) throw (std::invalid_argument); /**< Try to set a identificator on the object */
	std::string get() const; /**< Returns the identificator stored on Identificador's object. */
	// Identificador(std::string);
	Identificador();
	friend std::ostream& operator<<(std::ostream& os, Identificador&);
    friend std::istream& operator>>(std::istream& os, Identificador&);
};


class Nome
{
private:
	std::string nome;
	void validar(std::string nome) throw (std::invalid_argument);
public:
	void set(std::string nome) throw (std::invalid_argument); /**< Try to set a name on the object */
	std::string get(); /**< Returns the name stored on Nome's object. */
	// Nome(std::string);
	Nome();
	friend std::ostream& operator<<(std::ostream& os, Nome&);
    friend std::istream& operator>>(std::istream& os, Nome&);
};


class NumeroCartaoCredito
{
private:
	std::string numerocartaocredito;
	void validar(std::string numerocartaocredito) throw (std::invalid_argument);
public:
	void set(std::string numerocartaocredito) throw (std::invalid_argument); /**< Try to set a credit card number on the object */
	std::string get(); /**< Returns the credit card number stored on NumeroCartaoCredito's object. */
	// NumeroCartaoCredito(std::string);
	NumeroCartaoCredito();
	friend std::ostream& operator<<(std::ostream& os, NumeroCartaoCredito&);
    friend std::istream& operator>>(std::istream& os, NumeroCartaoCredito&);
};


class NumeroContaCorrente
{
private:
	std::string numerocontacorrente;
	void validar(std::string numerocontacorrente) throw (std::invalid_argument);
public:
	void set(std::string numerocontacorrente) throw (std::invalid_argument); /**< Try to set a account number on the object */
	std::string get(); /**< Returns the account number stored on NumeroContaCorrente's object. */
	// NumeroContaCorrente(std::string);
	NumeroContaCorrente();
	friend std::ostream& operator<<(std::ostream& os, NumeroContaCorrente&);
    friend std::istream& operator>>(std::istream& os, NumeroContaCorrente&);
};


class Senha
{
private:
	std::string senha;
	void validar(std::string senha) throw (std::invalid_argument);
public:
	void set(std::string senha) throw (std::invalid_argument); /**< Try to set a password on the object */
	std::string get() const; /**< Returns the password stored on Senha's object. */
	// Senha(std::string);
	Senha();
	friend std::ostream& operator<<(std::ostream& os, Senha&);
    friend std::istream& operator>>(std::istream& os, Senha&);
};


class TipoAcomodacao
{
private:
	std::string tipoacomodacao;
	void validar(std::string tipo) throw (std::invalid_argument);
public:
	void set(std::string tipo) throw (std::invalid_argument); /**< Try to set a accomodation type on the object */
	std::string get(); /**< Returns the accomodation type stored on TipoAcomodacao's object. */
	// TipoAcomodacao(std::string);
	TipoAcomodacao();
	friend std::ostream& operator<<(std::ostream& os, TipoAcomodacao&);
    friend std::istream& operator>>(std::istream& os, TipoAcomodacao&);
};

#endif
