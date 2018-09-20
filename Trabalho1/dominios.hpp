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
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	Agencia();
};



class Banco
{
private:
	std::string banco;
	void validar(std::string) throw (std::invalid_argument);
public:
	void set(std::string) throw (std::invalid_argument);
	std::string get();
	Banco();
};


class CapacidadeAcomodacao
{
private:
	int valor;
	void validar(int valor) throw (std::invalid_argument);
public:
	void set(int valor) throw (std::invalid_argument);
	int get();
	CapacidadeAcomodacao();
};

#endif