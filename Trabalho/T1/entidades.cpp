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
