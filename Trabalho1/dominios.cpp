#include "dominios.hpp"

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





CapacidadeAcomodacao::CapacidadeAcomodacao()
{}
void CapacidadeAcomodacao::validar(int valor) throw (std::invalid_argument)
{

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