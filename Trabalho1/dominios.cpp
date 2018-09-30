#include "dominios.hpp"

// Agencia::Agencia(std::string agencia)
// {set(agencia);}
Agencia::Agencia()
{}
void Agencia::validar(std::string agencia) throw (std::invalid_argument)
{
	int i, n = agencia.size();
	for(i = 0; i < n; i++)
		if(!isdigit(agencia[i]))
			throw std::invalid_argument("Argumento invalido.");
}
void Agencia::set(std::string agencia) throw (std::invalid_argument)
{
	validar(agencia);
	this->agencia = agencia;
}
std::string Agencia::get()
{
	return agencia;
}






// Banco::Banco(std::string banco)
// {set(banco);}
Banco::Banco()
{}
void Banco::validar(std::string banco) throw (std::invalid_argument)
{
	int i, n = banco.size();
	for(i = 0; i < n; i++)
		if(!isdigit(banco[i]))
			throw std::invalid_argument("Argumento invalido.");
}
void Banco::set(std::string banco) throw (std::invalid_argument)
{
	validar(banco);
	this->banco = banco;
}
std::string Banco::get()
{
	return banco;
}




// CapacidadeAcomodacao::CapacidadeAcomodacao(int valor)
// {set(valor)}
CapacidadeAcomodacao::CapacidadeAcomodacao()
{}
void CapacidadeAcomodacao::validar(int valor) throw (std::invalid_argument)
{
	if(valor > 9 || valor < 1)
		throw std::invalid_argument("Argumento invalido.");
}
void CapacidadeAcomodacao::set(int valor) throw (std::invalid_argument)
{
	validar(valor);
	this->valor = valor;
}
int CapacidadeAcomodacao::get()
{
	return valor;
}









Diaria::Diaria()
{}
void Diaria::validar(double valor) throw (std::invalid_argument)
{
	if(valor < 1 || valor > 1e+4)
		throw std::invalid_argument("Argumento invalido.");
}
void Diaria::set(double valor) throw (std::invalid_argument)
{
	validar(valor);
	this->valor = valor;
}
double Diaria::get()
{
	return valor;
}





Data::Data()
{}
void Data::validar(int dia, std::string mes, int ano) throw (std::invalid_argument)
{
	if(dia < 1 || dia > 31)
		throw std::invalid_argument("Argumento invalido.");
	if(ano < 2000 || ano >= 2100)
		throw std::invalid_argument("Argumento invalido.");
	if(mes == "jan")
	{
		// Mes ja tem 31 dias no maximo
	}	
	else if(mes == "fev")
	{
		if(ano%4 == 0)
		{
			if(dia > 29)
				throw std::invalid_argument("Argumento invalido.");
		}
		else
		{
			if(dia > 28)
				throw std::invalid_argument("Argumento invalido.");
		}
	}
	else if(mes == "mar")
	{
		// Mes ja tem 31 dias no maximo
	}	
	else if(mes == "abr")
	{
		if(dia > 30)
			throw std::invalid_argument("Argumento invalido.");
	}
	else if(mes == "mai")
	{
		// Mes ja tem 31 dias no maximo
	}	
	else if(mes == "jun")
	{
		if(dia > 30)
			throw std::invalid_argument("Argumento invalido.");
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
			throw std::invalid_argument("Argumento invalido.");
	}	
	else if(mes == "out")
	{
		// Mes ja tem 31 dias no maximo	
	}
	else if(mes == "nov")
	{
		if(dia > 30)
			throw std::invalid_argument("Argumento invalido.");
	}	
	else if(mes == "dez")
	{
		// Mes ja tem 31 dias no maximo
	}
	else
		throw std::invalid_argument("Argumento invalido.");
}
void Data::set(int dia, std::string mes, int ano) throw (std::invalid_argument)
{
	validar(dia, mes, ano);
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}
int Data::getDia()
{
	return dia;
}
std::string Data::getMes()
{
	return mes;
}
int Data::getAno()
{
	return ano;
}







DataValidade::DataValidade()
{}
void DataValidade::validar(int mes, int ano) throw (std::invalid_argument)
{
	if(mes < 1 || mes > 12)
		throw std::invalid_argument("Argumento invalido.");
	if(ano < 0 || ano > 99)
		throw std::invalid_argument("Argumento invalido.");

}
void DataValidade::set(int mes, int ano) throw (std::invalid_argument)
{
	validar(mes, ano);
	this->mes = mes;
	this->ano = ano;
}
int DataValidade::getMes()
{
	return mes;
}
int DataValidade::getAno()
{
	return ano;
}





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
		throw std::invalid_argument("Argumento invalido.");
}
void Estado::set(std::string estado) throw (std::invalid_argument)
{
	validar(estado);
	this->estado = estado;
}
std::string Estado::get()
{
	return estado;
}








Identificador::Identificador()
{}
void Identificador::validar(std::string identificador) throw (std::invalid_argument)
{
	int i, n = identificador.size();
	for(i = 0; i < n; i++)
		if(!islower(identificador[i]))
			throw std::invalid_argument("Argumento invalido.");
}
void Identificador::set(std::string identificador) throw (std::invalid_argument)
{
	validar(identificador);
	this->identificador = identificador;
}
std::string Identificador::get()
{
	return identificador;
}








Nome::Nome()
{}
void Nome::validar(std::string nome) throw (std::invalid_argument)
{
	int i, n = nome.size();
	for(i = 0; i < n-1; i++)
	{
		if(nome[i] == nome[i+1] && nome[i] == ' ')
			throw std::invalid_argument("Argumento invalido.");
		if(nome[i+1] == '.' && !isalpha(nome[i]))
			throw std::invalid_argument("Argumento invalido.");
		if(!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '.')
			throw std::invalid_argument("Argumento invalido.");
	}
	if(!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '.')
		throw std::invalid_argument("Argumento invalido.");
}
void Nome::set(std::string nome) throw (std::invalid_argument)
{
	validar(nome);
	this->nome = nome;
}
std::string Nome::get()
{
	return nome;
}







NumeroCartaoCredito::NumeroCartaoCredito()
{}
void NumeroCartaoCredito::validar(std::string numerocartaocredito) throw (std::invalid_argument)
{
	int i, n = numerocartaocredito.size();
	for(i = 0; i < n; i++)
		if(!isdigit(numerocartaocredito[i]))
			throw std::invalid_argument("Argumento invalido.");	
}
void NumeroCartaoCredito::set(std::string numerocartaocredito) throw (std::invalid_argument)
{
	validar(numerocartaocredito);
	this->numerocartaocredito = numerocartaocredito;
}
std::string NumeroCartaoCredito::get()
{
	return numerocartaocredito;
}







NumeroContaCorrente::NumeroContaCorrente()
{}
void NumeroContaCorrente::validar(std::string numerocontacorrente) throw (std::invalid_argument)
{
	int i, n = numerocontacorrente.size();
	for(i = 0; i < n; i++)
		if(!isdigit(numerocontacorrente[i]))
			throw std::invalid_argument("Argumento invalido.");	
}
void NumeroContaCorrente::set(std::string numerocontacorrente) throw (std::invalid_argument)
{
	validar(numerocontacorrente);
	this->numerocontacorrente = numerocontacorrente;
}
std::string NumeroContaCorrente::get()
{
	return numerocontacorrente;
}






Senha::Senha()
{}
void Senha::validar(std::string senha) throw (std::invalid_argument)
{
	bool upper = false, lower = false, digit = false, simbol = false;
	int i, j, n = senha.size();
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
	if(!(upper && lower && digit && simbol))
		throw std::invalid_argument("Argumento invalido.");
	for(i = 0; i < n-1; i++)
		for(j = i+1; j < n; j++)
			if(senha[i] == senha[j])
				throw std::invalid_argument("Argumento invalido.");
}
void Senha::set(std::string senha) throw (std::invalid_argument)
{
	validar(senha);
	this->senha = senha;
}
std::string Senha::get()
{
	return senha;
}










TipoAcomodacao::TipoAcomodacao()
{}
void TipoAcomodacao::validar(std::string tipoacomodacao) throw (std::invalid_argument)
{
	if(tipoacomodacao != "Casa" && tipoacomodacao != "Apartamento" && tipoacomodacao != "Flat")
		throw std::invalid_argument("Argumento invalido.");
}
void TipoAcomodacao::set(std::string tipoacomodacao) throw (std::invalid_argument)
{
	validar(tipoacomodacao);
	this->tipoacomodacao = tipoacomodacao;
}
std::string TipoAcomodacao::get()
{
	return tipoacomodacao;
}





