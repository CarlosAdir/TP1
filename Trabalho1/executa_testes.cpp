#include <iostream>
#include "testes.hpp"
#define VERBOSE true

int main()
{
	const int TESTES_DOMINIO = 13;
	const int TESTES_ENTIDADE = 4;
	int i;
	bool result = true;

	// TESTES DOMINIO
	TUAgencia tuagencia = TUAgencia();
	TUBanco tubanco = TUBanco();
	TUCapacidadeAcomodacao tucapacidadeacomodacao = TUCapacidadeAcomodacao();
	TUDiaria tudiaria = TUDiaria();
	TUData tudata = TUData();
	TUDataValidade tudatavalidade = TUDataValidade();
	TUEstado tuestado = TUEstado();
	TUIdentificador tuidentificador = TUIdentificador();
	TUNome tunome = TUNome();
	TUNumeroCartaoCredito tunumerocartaocredito = TUNumeroCartaoCredito();
	TUNumeroContaCorrente tunumerocontacorrente = TUNumeroContaCorrente();
	TUSenha tusenha = TUSenha();
	TUTipoAcomodacao tutipoacomodacao = TUTipoAcomodacao();
	
	// TESTES ENTIDADE
	TUUsuario tuusuario = TUUsuario();
	TUAcomodacao tuacomodacao = TUAcomodacao();
	TUCartaoCredito tucartaocredito = TUCartaoCredito();
	TUContaCorrente tucontacorrente = TUContaCorrente();

	// PARA FAZER OS TESTES DE DOMINIO
	if(result == false)
		return 1;
	else
	{
		for(i = 0; i < TESTES_DOMINIO && result == true; i++)
			switch(i)
			{
			case 0:
				std::cout << "***** Teste da Agencia *****" << std::endl;
				result = tuagencia.run();
				break;
			case 1:
				std::cout << "***** Teste do Banco *****" << std::endl;
				result = tubanco.run();
				break;
			case 2:
				std::cout << "***** Teste da Capacidade de Acomodacao *****" << std::endl;
				result = tucapacidadeacomodacao.run();
				break;
			case 3:
				std::cout << "***** Teste de Diaria *****" << std::endl;
				result = tudiaria.run();
				break;
			case 4:
				std::cout << "***** Teste de Data *****" << std::endl;
				result = tudata.run();
				break;
			case 5:
				std::cout << "***** Teste de Data de Validade *****" << std::endl;
				result = tudatavalidade.run();
				break;
			case 6:
				std::cout << "***** Teste de Estado *****" << std::endl;
				result = tuestado.run();
				break;
			case 7:
				std::cout << "***** Teste de Identificador *****" << std::endl;
				result = tuidentificador.run();
				break;
			case 8:
				std::cout << "***** Teste de Nome *****" << std::endl;
				result = tunome.run();
				break;
			case 9:
				std::cout << "***** Teste de Numero Cartao de Credito *****" << std::endl;
				result = tunumerocartaocredito.run();
				break;
			case 10:
				std::cout << "***** Teste de Numero Conta Corrente *****" << std::endl;
				result = tunumerocontacorrente.run();
				break;
			case 11:
				std::cout << "***** Teste de Senha *****" << std::endl;
				result = tusenha.run();
				break;
			case 12:
				std::cout << "***** Teste de Tipo de Acomodacao *****" << std::endl;
				result = tutipoacomodacao.run();
				break;
			}
	}
	// PARA FAZER OS TESTES DE ENTIDADE
	if(result == false)
		std::cout << "Parado no teste " << i << std::endl;
	else
	{
		for(i = 0; i < TESTES_ENTIDADE && result; i++)
			switch(i)
			{
			case 0:
				std::cout << "***** Teste de Usuário *****" << std::endl;
				result = tuusuario.run();
				break;
			case 1:
				std::cout << "***** Teste de Usuário *****" << std::endl;
				result = tuacomodacao.run();
				break;
			case 2:
				std::cout << "***** Teste de Usuário *****" << std::endl;
				result = tucartaocredito.run();
				break;
			case 3:
				std::cout << "***** Teste de Usuário *****" << std::endl;
				result = tucontacorrente.run();
				break;
			}
	}
	return 0;
}