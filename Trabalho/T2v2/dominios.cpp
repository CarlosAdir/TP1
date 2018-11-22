#include "dominios.hpp"

/**
* \class Agencia
*
*  A base class to store a bank branch number.
*
*  The class is only to store the bank branch number and this class verifies if the number set is possible.
*/
// Agencia::Agencia(std::string agencia)
// {set(agencia);}
Agencia::Agencia()
{}
void Agencia::validar(std::string agencia) throw (std::invalid_argument)
{
	int i, n = agencia.size();
	if(n != 5)
		throw std::invalid_argument("Agencia invalida - Nao ha 5 algarismos");
	for(i = 0; i < n; i++)
		if(!isdigit(agencia[i]))
			throw std::invalid_argument("Agencia invalida - Deve-se ter apenas algarismos");
}
void Agencia::set(std::string agencia) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT | WRONG  |
	* |---------|--------|
	* | 12345   | asd1a  |
	* | 91532   | 123456 |
	* | 02314   | 2314   |
	*
	* \param[in] agencia is the string to set on the object and must have 5 digits(characteres from 0 to 9).
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(agencia);
	this->agencia = agencia;
}
std::string Agencia::get()
{
	/**
	* Returns the string number from the object.
	* This string is composed for exactly for 5 digits.
	* It is possible the frist character be 0.
	*/
	return agencia;
}
std::ostream& operator<<(std::ostream& os, Agencia& a)  
{  
    os << a.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, Agencia& a)  
{  
	std::string valor_agencia;
	is >> valor_agencia;
	a.set(valor_agencia);
    return is;  
}





/**
* \class Banco
*
*  A base class to store a bank number.
*
*  The class is only to store the bank number and this class verifies if the number set is possible.
*/
// Banco::Banco(std::string banco)
// {set(banco);}
Banco::Banco()
{}
void Banco::validar(std::string banco) throw (std::invalid_argument)
{
	int i, n = banco.size();
	if(n != 3)
		throw std::invalid_argument("Banco invalido - Nao ha 3 algarismos");
	for(i = 0; i < n; i++)
		if(!isdigit(banco[i]))
			throw std::invalid_argument("Banco invalido - Deve-se ter apenas algarismos");
}
void Banco::set(std::string banco) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT | WRONG  |
	* |---------|--------|
	* | 123     | d1a    |
	* | 915     | 1234   |
	* | 023     | 23     |
	*
	* \param[in] banco is the string to set on the object and must have 3 digits(characteres from 0 to 9).
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(banco);
	this->banco = banco;
}
std::string Banco::get()
{
	/**
	* Returns the string number from the object.
	* This string is composed for exactly for 3 digits.
	* It is possible the frist character be 0.
	*/
	return banco;
}
std::ostream& operator<<(std::ostream& os, Banco& b)  
{  
    os << b.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, Banco& b)  
{  
	std::string valor_banco;
	is >> valor_banco;
	b.set(valor_banco);
    return is;  
}


/**
* \class CapacidadeAcomodacao
*
*  A base class to store a accomodation capacity number.
*
*  The class is only to store the accommodation capacity number and this class verifies if the number set is possible, if the number is between 1 and 9.
*/
// CapacidadeAcomodacao::CapacidadeAcomodacao(int valor)
// {set(valor)}
CapacidadeAcomodacao::CapacidadeAcomodacao()
{}
void CapacidadeAcomodacao::validar(int valor) throw (std::invalid_argument)
{
	if(valor > 9 || valor < 1)
		throw std::invalid_argument("Capacidade invalida - Nao esta entre 1 e 9");
}
void CapacidadeAcomodacao::set(int valor) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT | WRONG  |
	* |---------|--------|
	* | 1       | 0      |
	* | 9       | 10     |
	* | 5       | -3     |
	*
	* \param[in] valor is the int to set on the object and must be between 1 and 9.
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(valor);
	this->valor = valor;
}
int CapacidadeAcomodacao::get()
{
	/**
	* Returns the accomodation capacity number from the object.
	* This integer is on the interval [1, 9].
	*/
	return valor;
}
std::ostream& operator<<(std::ostream& os, CapacidadeAcomodacao& c)  
{  
    os << c.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, CapacidadeAcomodacao& c)  
{  
	int valor_capacidade;
	is >> valor_capacidade;
	c.set(valor_capacidade);
    return is;  
}








/**
* \class Diaria
*
*  A base class to store a diaria price.
*
*  The class is only to store the Diaria's price and this class verifies if the value set is possible.
*/
Diaria::Diaria()
{}
void Diaria::validar(double valor) throw (std::invalid_argument)
{
	if(valor < 1 || valor > 1e+4)
		throw std::invalid_argument("Diaria invalida - Deve-se ter valor entre 1 e 1000");
}
void Diaria::set(double valor) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT | WRONG   |
	* |---------|---------|
	* | 1.0     | 0.99    |
	* | 10000.0 | 10000.1 |
	* | 100.0   | -10.0   |
	*
	* \param[in] valor is the double to set on the object, the price for each day, and must be on the interval [1.0, 10000.0].
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(valor);
	this->valor = valor;
}
double Diaria::get()
{
	/**
	* Returns the price per day.
	* This number is on the interval [1.0, 10000.0].
	*/
	return valor;
}
std::ostream& operator<<(std::ostream& os, Diaria& d)  
{  
    os << d.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, Diaria& d)  
{  
	double valor;
	is >> valor;
	d.set(valor);
    return is;  
}





/**
* \class Data
*
*  A base class to store a date.
*
*  The class is only to store the date with day, month and year. This class verifies if the date set is a possible, inclusive if it is a leap year.
*/
Data::Data()
{}
void Data::validar(int dia, std::string mes, int ano) throw (std::invalid_argument)
{
	if(dia < 1 || dia > 31)
		throw std::invalid_argument("Dia invalido - Deve estar entre 1 e 31");
	if(ano < 2000 || ano >= 2100)
		throw std::invalid_argument("Ano invalido - Deve estar entre 2000 e 2100");
	if(mes == "jan")
	{
		// Mes ja tem 31 dias no maximo
	}
	else if(mes == "fev")
	{
		if(ano%4 == 0)
		{
			if(dia > 29)
				throw std::invalid_argument("Dia invalido - Fevereiro tem apenas 29 dias nesse ano");
		}
		else
		{
			if(dia > 28)
				throw std::invalid_argument("Dia invalido - Fevereiro tem apenas 28 dias nesse ano");
		}
	}
	else if(mes == "mar")
	{
		// Mes ja tem 31 dias no maximo
	}
	else if(mes == "abr")
	{
		if(dia > 30)
			throw std::invalid_argument("Dia invalido - Abril so tem 30 dias");
	}
	else if(mes == "mai")
	{
		// Mes ja tem 31 dias no maximo
	}
	else if(mes == "jun")
	{
		if(dia > 30)
			throw std::invalid_argument("Dia invalido - Junho so tem 30 dias");
	}
	else if(mes == "jul")
	{
		// Mes ja tem 31 dias no maximo
	}
	else if(mes == "ago")
	{
		// Mes ja tem 31 dias no maximo
	}
	else if(mes == "set")
	{
		if(dia > 30)
			throw std::invalid_argument("Dia invalido - Setembro so tem 30 dias");
	}
	else if(mes == "out")
	{
		// Mes ja tem 31 dias no maximo
	}
	else if(mes == "nov")
	{
		if(dia > 30)
			throw std::invalid_argument("Dia invalido - Novembro so tem 30 dias");
	}
	else if(mes == "dez")
	{
		// Mes ja tem 31 dias no maximo
	}
	else
		throw std::invalid_argument("Mes invalido");
}
void Data::set(int dia, std::string mes, int ano) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT     | WRONG       |
	* |-------------|-------------|
	* | 01 jan 2000 | 29 fev 2001 |
	* | 29 fev 2000 | 31 abr 2004 |
	* | 31 jul 2053 | 01 jul 1999 |
	*
	* \param[in] dia is the day and must be on the interval [1, 31] depending on the month and year.
	* \param[in] mes is the month and must be one of them: jan, fev, mar, abr, mai, jun, jul, ago, set, out, nov, dez.
	* \param[in] ano is the year and must be be on the interval [2000, 2099].
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(dia, mes, ano);
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}
int Data::getDia()
{
	/**
	* Returns the day.
	* This number is on the interval [1, 31], depending on the month and the year.
	*/
	return dia;
}
std::string Data::getMes()
{
	/**
	* Returns the month.
	* This number is one of: jan, fev, mar, abr, mai, jun, jul, ago, set, out, nov, dez.
	*/
	return mes;
}
int Data::getAno()
{
	/**
	* Returns the year.
	* This number is on the interval [2000, 2099].
	*/
	return ano;
}
int Data::mes_number(const std::string &o_mes) throw (std::invalid_argument)
{
	if(o_mes == "jan")
		return 1;
	if(o_mes == "fev")
		return 2;
	if(o_mes == "mar")
		return 3;
	if(o_mes == "abr")
		return 4;
	if(o_mes == "mai")
		return 5;
	if(o_mes == "jun")
		return 6;
	if(o_mes == "jul")
		return 7;
	if(o_mes == "ago")
		return 8;
	if(o_mes == "set")
		return 9;
	if(o_mes == "out")
		return 10;
	if(o_mes == "nov")
		return 11;
	if(o_mes == "dez")
		return 12;
	throw std::invalid_argument("O mes passado nao esta dentre os possiveis");
	return 0;
}
bool Data::operator<(Data &dt)
{
	int dia1, dia2;
	int mes1, mes2;
	int ano1, ano2;
	dia1 = dt.getDia();
	dia2 = this->dia;
	mes1 = mes_number(dt.getMes());
	mes2 = mes_number(this->mes);
	ano1 = dt.getAno();
	ano2 = this->getAno();
	if(ano1 < ano2)
		return false;
	if(mes1 < mes2)
		return false;
	if(dia1 < dia2)
		return false;
	return true;
}
std::ostream& operator<<(std::ostream& os, Data& t)  
{  
    os << t.getDia() << " " << t.getMes() << " " << t.getAno();
    return os;  
}  
std::istream& operator>>(std::istream& is, Data& t)  
{  
	int dia, ano;
	std::string mes;
	is >> dia >> mes >> ano;
	t.set(dia, mes, ano);
    return is;  
}




/**
* \class DataValidade
*
*  A base class to store a validation date.
*
*  The class is only to store the date with month and year, both as number. This class verifies if the date set is a possible.
*/
DataValidade::DataValidade()
{}
void DataValidade::validar(int mes, int ano) throw (std::invalid_argument)
{
	if(mes < 1 || mes > 12)
		throw std::invalid_argument("Mes invalido.");
	if(ano < 0 || ano > 99)
		throw std::invalid_argument("Ano invalido.");

}
void DataValidade::set(int mes, int ano) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT | WRONG |
	* |---------|-------|
	* | 01 00   | 00 01 |
	* | 12 99   | 13 99 |
	* | 4 54    | -1 03 |
	*
	* \param[in] mes is the month and must be on the interval [1, 12].
	* \param[in] ano is the year and must be on the interval [0, 99].
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(mes, ano);
	this->mes = mes;
	this->ano = ano;
}
int DataValidade::getMes()
{
	/**
	* Returns the month.
	* This number is on the interval [1, 12].
	*/
	return mes;
}
int DataValidade::getAno()
{
	/**
	* Returns the year.
	* This number is on the interval [0, 99].
	*/
	return ano;
}
std::ostream& operator<<(std::ostream& os, DataValidade& d)  
{  
    os << d.getMes() << "/" << d.getAno();
    return os;  
}  
std::istream& operator>>(std::istream& is, DataValidade& d)  
{  
	int mes, ano;
	is >> mes >> ano;
	d.set(mes, ano);
    return is;  
}





/**
* \class Estado
*
*  A base class to store a state of Brazil.
*
*  The class is only to store the state of Brazil. This class verifies if the state set is a possible state of Brazil.
*/
Estado::Estado()
{}
void Estado::validar(std::string estado) throw (std::invalid_argument)
{
	if(estado == "AC" || estado == "AL" || estado == "AP" || estado == "AM"){}
	else if(estado == "BA" || estado == "CE" || estado == "DF" || estado == "ES"){}
	else if(estado == "GO" || estado == "MA" || estado == "MT" || estado == "MS" || estado == "MG"){}
	else if(estado == "PA" || estado == "PB" || estado == "PR" || estado == "PE" || estado == "PI"){}
	else if(estado == "RJ" || estado == "RN" || estado == "RS" || estado == "RO" || estado == "RR"){}
	else if(estado == "SC" || estado == "SP" || estado == "SE" || estado == "TO"){}
	else
		throw std::invalid_argument("Estado invalido.");
}
void Estado::set(std::string estado) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT | WRONG |
	* |---------|-------|
	* | AC      | PT    |
	* | RN      | SR    |
	* | SP      | BT    |
	*
	* \param[in] estado is the region inside a country, and must be one of them: AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO.
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(estado);
	this->estado = estado;
}
std::string Estado::get()
{
	/**
	* Returns the state.
	* This string must be one of them: AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO.
	*/
	return estado;
}
std::ostream& operator<<(std::ostream& os, Estado& e)  
{  
    os << e.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, Estado& e)  
{  
	std::string estado;
	is >> estado;
	e.set(estado);
    return is;  
}







/**
* \class Identificador
*
*  A base class to store a identificator.
*
*  The class is only to store the identificator. This class verifies if the identificator set is a possible identificator with 5 lower case letters.
*/
Identificador::Identificador()
{}
void Identificador::validar(std::string identificador) throw (std::invalid_argument)
{
	int i, n = identificador.size();
	if(n != 5)
		throw std::invalid_argument("Identificador invalido - Nao possui 5 caracteres.");
	for(i = 0; i < n; i++)
		if(!islower(identificador[i]))
			throw std::invalid_argument("Identificador invalido - Nao esta composto apenas de letras minusculas.");
}
void Identificador::set(std::string identificador) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT | WRONG  |
	* |---------|--------|
	* | abcde   | abcdE  |
	* | zefri   | abcd   |
	* | papag   | abcdef |
	*
	* \param[in] identificador is the string to set on the object and must have 5 small letters(characteres from \a a to \a z).
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(identificador);
	this->identificador = identificador;
}
std::string Identificador::get() const
{
	/**
	* Returns the identificator.
	* This string has 5 small letters from \a a to \a z.
	*/
	return identificador;
}
std::ostream& operator<<(std::ostream& os, Identificador& id)  
{  
    os << id.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, Identificador& id)  
{  
	std::string iden;
	is >> iden;
	id.set(iden);
    return is;  
}






/**
* \class Nome
*
*  A base class to store a name.
*
*  The class is only to store a name. This class verifies if the name set is a possible name.
*/
Nome::Nome()
{}
void Nome::validar(std::string nome) throw (std::invalid_argument)
{
	int i, n = nome.size();
	for(i = 0; i < n-1; i++)
	{
		if(nome[i] == nome[i+1] && nome[i] == ' ')
			throw std::invalid_argument("Nome invalido.");
		if(nome[i+1] == '.' && !isalpha(nome[i]))
			throw std::invalid_argument("Nome invalido.");
		if(!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '.')
			throw std::invalid_argument("Nome invalido.");
	}
	if(!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '.')
		throw std::invalid_argument("Nome invalido.");
}
void Nome::set(std::string nome) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* |        CORRECT      |         WRONG       |
	* |---------------------|---------------------|
	* | Joao de Albuquerque | Joao & Albuquerque  |
	* | Matheus S. Leite    | Joao.. Paulo        |
	* | Lucas Schiavini S.  | Cleiton . Santos    |
	*
	* \param[in] identificador is the string to set on the object and must have at least one letter, each point is after a letter, there is no two spaces side by side and must be composed only by letters, points and spaces.
	* 							There is no limit to the name size.
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(nome);
	this->nome = nome;
}
std::string Nome::get()
{
	/**
	* Returns the name.
	* This string is a valid name, only with letters, points and spaces.
	*/
	return nome;
}
std::ostream& operator<<(std::ostream& os, Nome& nome)  
{  
    os << nome.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, Nome& nome)  
{  
	std::string entrada;
	std::getline(is, entrada);
	nome.set(entrada);
    return is;  
}






/**
* \class NumeroCartaoCredito
*
*  A base class to store a credit card number.
*
*  The class is only to store a credit card number. This class verifies if the number set is a possible 16 digit credit card number according the Luhn algorithm.
*/
NumeroCartaoCredito::NumeroCartaoCredito()
{}
void NumeroCartaoCredito::validar(std::string numerocartaocredito) throw (std::invalid_argument)
{
	int i, n = numerocartaocredito.size();
	if(n != 16)
		throw std::invalid_argument("Numero de cartao invalido - Nao ha 16 digitos.");
	for(i = 0; i < n; i++)
		if(!isdigit(numerocartaocredito[i]))
			throw std::invalid_argument("Numero de cartao invalido - Deve-se ter apenas digitos");

	int nSum       = 0;
    int nParity    = (n-1) % 2;
    int nDigit;
    for (i = n; i > 0 ; i--)
    {
      nDigit = numerocartaocredito[i-1] - '0'; // Transform to int
      if (nParity == i % 2)
        nDigit = nDigit * 2;
      nSum += (nDigit/10 + nDigit%10);
    }
    if(nSum % 10 != 0)
    	throw std::invalid_argument("Numero de cartao invalido - Provavelmente falha de digitacao.");
}
void NumeroCartaoCredito::set(std::string numerocartaocredito) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* |      CORRECT     |       WRONG      |
	* |------------------|------------------|
	* | 7992739871312342 | 8851168461321878 |
	* | 9153212345600214 | 4846813a44849123 |
	* | 2548931455678624 | 2314231423142314 |
	*
	* \param[in] agencia is the string to set on the object and must have 16 digits(characteres from 0 to 9) and checked by the Luhn algorithm.
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(numerocartaocredito);
	this->numerocartaocredito = numerocartaocredito;
}
std::string NumeroCartaoCredito::get()
{
	/**
	* Returns the credit card number.
	* This string is a credit card number, with 16 digits and checked by Luhn algorithm.
	*/
	return numerocartaocredito;
}
std::ostream& operator<<(std::ostream& os, NumeroCartaoCredito& numero)  
{  
    os << numero.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, NumeroCartaoCredito& numero)  
{  
	std::string entrada;
	std::getline(is, entrada);
	numero.set(entrada);
    return is;  
}








/**
* \class NumeroContaCorrente

  A base class to store a account number.

  The class is only to store a account number. This class verifies if the number set is a possible 6 digit account number.
*/
NumeroContaCorrente::NumeroContaCorrente()
{}
void NumeroContaCorrente::validar(std::string numerocontacorrente) throw (std::invalid_argument)
{
	int i, n = numerocontacorrente.size();
	if(n != 6)
		throw std::invalid_argument("Numero de Conta Corrente invalido - Nao possui 6 digitos");
	for(i = 0; i < n; i++)
		if(!isdigit(numerocontacorrente[i]))
			throw std::invalid_argument("Numero de Conta Corrente invalido - Deve-se ter apenas digitos");
}
void NumeroContaCorrente::set(std::string numerocontacorrente) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT |  WRONG  |
	* |---------|---------|
	* | 123456  | 22d1a3  |
	* | 915321  | 1234567 |
	* | 023141  | 23142   |
	*
	* \param[in] numerocontacorrente is the string to set on the object and must have 6 digits(characteres from 0 to 9).
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(numerocontacorrente);
	this->numerocontacorrente = numerocontacorrente;
}
std::string NumeroContaCorrente::get()
{
	/**
	* Returns the string number from the object.
	* This string is composed for exactly for 6 digits.
	* It is possible the frist character be 0.
	*/
	return numerocontacorrente;
}
std::ostream& operator<<(std::ostream& os, NumeroContaCorrente& numero)  
{  
    os << numero.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, NumeroContaCorrente& numero)  
{  
	std::string entrada;
	std::getline(is, entrada);
	numero.set(entrada);
    return is;  
}





/**
* \class Senha

  A base class to store a password.

  The class is only to store a password. This class verifies if the password set is a possible with 8 characters.
*/
Senha::Senha()
{}
void Senha::validar(std::string senha) throw (std::invalid_argument)
{
	bool upper = false, lower = false, digit = false, simbol = false;
	int i, j, n = senha.size();
	if(n != 8)
		throw std::invalid_argument("Senha invalida - Deve-se ter 8 caracteres");
	for(i = 0; i < n; i++)
	{
		if(isupper(senha[i]))
			upper = true;
		else if(islower(senha[i]))
			lower = true;
		else if(isdigit(senha[i]))
			digit = true;
		else if(senha[i] == '!' || senha[i] == '#' || senha[i] == '$' || senha[i] == '%' || senha[i] == '&')
			simbol = true;
	}
	if(!upper)
		throw std::invalid_argument("Senha invalida - Nao ha nenhuma letra maiuscula");
	if(!lower)
		throw std::invalid_argument("Senha invalida - Nao ha nenhuma letra minuscula");
	if(!digit)
		throw std::invalid_argument("Senha invalida - Nao ha nenhum numero");
	if(!simbol)
		throw std::invalid_argument("Senha invalida - Nao ha nenhum simbolo");
	for(i = 0; i < n-1; i++)
		for(j = i+1; j < n; j++)
			if(senha[i] == senha[j])
				throw std::invalid_argument("Senha invalida - Existe caracter repetido");
}
void Senha::set(std::string senha) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* | CORRECT  |  WRONG   |
	* |----------|----------|
	* | !aS9kmKM | 22d1a3#m |
	* | kw32!Am9 | 123456a! |
	* | KmkMQz#1 | #12Am*3) |
	*
	* \param[in] senha is the string to set on the object and must have 8 characteres,
						at least a symbol(! # $ % &), a lower case letter(a-z), a upper case letter(A-Z) and a digit(0-9).
						Must not have repeated character.
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(senha);
	this->senha = senha;
}
std::string Senha::get() const
{
	/**
	* Returns the correct password.
	* This string is composed for exactly for 8 characteres.
	* There is at least one symbol, a lower case letter, a upper case letter and a digit. Each character is differente to another.
	*/
	return senha;
}
std::ostream& operator<<(std::ostream& os, Senha& password)  
{  
    os << password.get();
    return os;  
}  
std::istream& operator>>(std::istream& is, Senha& password)  
{  
	std::string sen;
	is >> sen;
	password.set(sen);
    return is;  
}








/**
* \class TipoAcomodacao

  A base class to store a accomodation type.

  The class is only to store a accomodation type. This class verifies if the accomodation type set is valid.
*/
TipoAcomodacao::TipoAcomodacao()
{}
void TipoAcomodacao::validar(std::string tipoacomodacao) throw (std::invalid_argument)
{
	if(tipoacomodacao != "Casa" && tipoacomodacao != "Apartamento" && tipoacomodacao != "Flat")
		throw std::invalid_argument("Tipo de Acomodacao Invalido");
}
void TipoAcomodacao::set(std::string tipoacomodacao) throw (std::invalid_argument)
{
	/**
	* If is not possible to set, it is only because the given data is not valid.
	* In that case, the system will throw an exception called <b>std::invalid_argument</b>.
	* Some possible examples are shown on the table below.
	*
	* |   CORRECT   |  WRONG   |
	* |-------------|----------|
	* | Casa 	    | Chacara  |
	* | Apartamento | Barraco  |
	* | Flat 		| Hostel   |
	*
	* \param[in] tipoacomodacao is the string to set on the object and must be one of them: Apartamento, Casa or Flat.
	*
    * \throw std::invalid_argument Exception thrown when the parameters are not valid data.
    *								Some valid data are shown on the table above.
	*/
	validar(tipoacomodacao);
	this->tipoacomodacao = tipoacomodacao;
}
std::string TipoAcomodacao::get()
{
	/**
	* Returns the type of accomodation.
	* It is one of them: Apartamento, Casa or Flat
	*/
	return tipoacomodacao;
}
