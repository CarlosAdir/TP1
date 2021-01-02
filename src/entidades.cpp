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

Nome Usuario::getNome() const
{
	return this->nome;
}

Identificador Usuario::getIdentificador() const
{
	return this->id;
}

Senha Usuario::getSenha() const
{
	return this->senha;
}




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
void Acomodacao::validar(Data inicio, Data termino) throw (std::invalid_argument)
{
	if(termino < inicio)
		throw std::invalid_argument("Datas invalidas! O termino é antes do comeco!");
}
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
void Acomodacao::setDatas(const Data &inicio, const Data &termino)
{
	validar(inicio, termino);
	this->data_inicio = inicio;
	this->data_termino = termino;
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
Identificador  Acomodacao::getIdentificador() const
{
	return this->id;
}
TipoAcomodacao  Acomodacao::getTipoAcomodacao() const
{
	return this->tipo;
}
CapacidadeAcomodacao  Acomodacao::getCapacidadeAcomodacao() const
{
	return this->capacidade;
}
Data  Acomodacao::getDataInicio() const
{
	return this->data_termino;
}
Data  Acomodacao::getDataTermino() const
{
	return this->data_termino;
}
Nome  Acomodacao::getCidade() const
{
	return this->cidade;
}
Estado  Acomodacao::getEstado() const
{
	return this->estado;
}
Diaria  Acomodacao::getDiaria() const
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
NumeroCartaoCredito  CartaoCredito::getNumero() const
{
	return this->numero;
}
DataValidade  CartaoCredito::getValidade() const
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
NumeroContaCorrente  ContaCorrente::getContaCorrente() const
{
	return this->numero;
}
Agencia  ContaCorrente::getAgencia() const
{
	return this->agencia;
}
Banco  ContaCorrente::getBanco() const
{
	return this->banco;
}