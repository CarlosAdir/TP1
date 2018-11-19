#include "entidades.hpp"

/**
* \class Usuario
*
*  A class that controls the informations and actions of the User.
*
*  This is a second order class that uses the basic classes as atributes and do not worry about treat the input data because the methods in base classes already do that.
*  The User, as the name means, has atributes and methods that the user uses: name, password, book a accomodation, cancel the reservation, etc;
*/
Usuario::Usuario()
{}
Usuario::~Usuario()
{}
void Usuario::setNome(const Nome &nome)
{
	this->nome = nome;
}

void Usuario::setIdentificador(const Identificador &id)
{
	this->id = id;
}

void Usuario::setSenha(const Senha &senha)
{
	this->senha = senha;
}

Nome inline Usuario::getNome() const
{
	return this->nome;
}

Identificador inline Usuario::getIdentificador() const
{
	return this->id;
}

Senha inline Usuario::getSenha() const
{
	return this->senha;
}

// void Usuario::validar(std::string agencia) throw (std::invalid_argument)
// {

// }
// void Usuario::set() throw (std::invalid_argument)
// {

// }


/**
* \class Acomodacao
*
*  A class that controls informations about Accomodation.
*
*  This is a second order class that uses the basic classes as atributes and do not worry about treat the input data because the methods in base classes already do that.
*  The Accomodation, as the name means, has atributes and methods that the accomodation uses: price, duration, booking it, cancel reservation, etc.
*/
Acomodacao::Acomodacao()
{}
Acomodacao::~Acomodacao()
{}
void Acomodacao::setIdentificador(const Identificador &id)
{
	this->id = id;
}
void Acomodacao::setTipoAcomodacao(const TipoAcomodacao &tipo)
{
	this->tipo = tipo;
}
void Acomodacao::setCapacidadeAcomodacao(const CapacidadeAcomodacao &capacidade)
{
	this->capacidade = capacidade;
}
void Acomodacao::setDataInicio(const Data &data_inicio)
{
	this->data_inicio = data_inicio;
}
void Acomodacao::setDataTermino(const Data &data_termino)
{
	this->data_termino = data_termino;
}
void Acomodacao::setCidade(const Nome &cidade)
{
	this->cidade = cidade;
}
void Acomodacao::setEstado(const Estado &estado)
{
	this->estado = estado;
}
void Acomodacao::setDiaria(const Diaria &diaria)
{
	this->diaria = diaria;
}
Identificador inline Acomodacao::getIdentificador() const
{
	return this->id;
}
TipoAcomodacao inline Acomodacao::getTipoAcomodacao() const
{
	return this->tipo;
}
CapacidadeAcomodacao inline Acomodacao::getCapacidadeAcomodacao() const
{
	return this->capacidade;
}
Data inline Acomodacao::getDataInicio() const
{
	return this->data_termino;
}
Data inline Acomodacao::getDataTermino() const
{
	return this->data_termino;
}
Nome inline Acomodacao::getCidade() const
{
	return this->cidade;
}
Estado inline Acomodacao::getEstado() const
{
	return this->estado;
}
Diaria inline Acomodacao::getDiaria() const
{
	return this->diaria;
}



/**
* \class CartaoCredito
*
*  A class that controls informations about Credit Card.
*
*  This is a second order class that uses the basic classes as atributes and do not worry about treat the input data because the methods in base classes already do that.
*  The Credit Card, as the name means, has atributes and methods that the credit card uses: the number card, buy something, etc.
*/
CartaoCredito::CartaoCredito()
{}
CartaoCredito::~CartaoCredito()
{}
void CartaoCredito::setNumero(const NumeroCartaoCredito &numero)
{
	this->numero = numero;
}
void CartaoCredito::setValidade(const DataValidade &data_validade)
{
	this->data_validade = data_validade;
}
NumeroCartaoCredito inline CartaoCredito::getNumero() const
{
	return this->numero;
}
DataValidade inline CartaoCredito::getValidade() const
{
	return this->data_validade;
}


/**
* \class ContaCorrente
*
*  A class that controls informations about Account.
*
*  This is a second order class that uses the basic classes as atributes and do not worry about treat the input data because the methods in base classes already do that.
*  The Account, as the name means, has atributes and methods that the account uses: account number, bank, bank branch, etc.
*/
ContaCorrente::ContaCorrente()
{}
ContaCorrente::~ContaCorrente()
{}
void ContaCorrente::setContaCorrente(const NumeroContaCorrente &numero)
{
	this->numero = numero;
}
void ContaCorrente::setAgencia(const Agencia &agencia)
{
	this->agencia = agencia;
}
void ContaCorrente::setBanco(const Banco &banco)
{
	this->banco = banco;
}
NumeroContaCorrente inline ContaCorrente::getContaCorrente() const
{
	return this->numero;
}
Agencia inline ContaCorrente::getAgencia() const
{
	return this->agencia;
}
Banco inline ContaCorrente::getBanco() const
{
	return this->banco;
}