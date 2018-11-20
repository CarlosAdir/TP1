#include <iostream>


#include "dominios.hpp"
#include "entidades.hpp"
#include "interfaces.hpp"
#include "controladoras.hpp"
#include "stubs.hpp"

#include "testes.hpp"


/*! \mainpage Trabalho 1 - Técnicas de Programação 1 - Trabalho 1
 *
 * \section intro_sec Introduction
 *
 * This is the introduction.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
 */

bool TU::VERBOSE = true;
const static int TESTES_DOMINIO = 13;
const static int TESTES_ENTIDADE = 4;

bool teste_dominio()
{
	
	bool result = TU::SUCESSO;
	int i;

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

	// PARA FAZER OS TESTES DE DOMINIO
	for(i = 0; i < TESTES_DOMINIO && result == TU::SUCESSO; i++)
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
	return result;
}

bool teste_entidade()
{
	bool result = TU::SUCESSO;
	int i;
	
	// TESTES ENTIDADE
	TUUsuario tuusuario = TUUsuario();
	TUAcomodacao tuacomodacao = TUAcomodacao();
	TUCartaoCredito tucartaocredito = TUCartaoCredito();
	TUContaCorrente tucontacorrente = TUContaCorrente();

	for(i = 0; i < TESTES_ENTIDADE && result == TU::SUCESSO; i++)
		switch(i)
		{
		case 0:
			std::cout << "***** Teste de Usuário *****" << std::endl;
			result = tuusuario.run();
			break;
		case 1:
			std::cout << "***** Teste de Acomodacao *****" << std::endl;
			result = tuacomodacao.run();
			break;
		case 2:
			std::cout << "***** Teste de Cartao de Credito *****" << std::endl;
			result = tucartaocredito.run();
			break;
		case 3:
			std::cout << "***** Teste de Conta Corrente *****" << std::endl;
			result = tucontacorrente.run();
			break;
		}
	return result;
}

IUInicializacao *initial_setting()
{
	IUInicializacao *cntrIUInicio = new CntrIUInicializacao();
	IUCadastro *cntrIUCadastro = new CntrIUCadastro();
	IUAutenticacao *cntrIUAutenticacao = new CntrIUAutenticacao();
	IUAcomodacao *cntrIUAcomodacao = new CntrIUAcomodacao();
	IULogado *cntrIULogado = new CntrIULogado();
	IUReserva *cntrIUReserva = new CntrIUReserva();
	IUCadastroAcomodacao *cntrIUCadastroAcomodacao = new CntrIUCadastroAcomodacao();
	IUDados *cntrIUDados = new CntrIUDados();
	IUAlterarSenha *cntrIUAlterarSenha = new CntrIUAlterarSenha();
	IUAlterarNome *cntrIUAlterarNome = new CntrIUAlterarNome();
	IUDeletarConta *cntrIUDeletarConta = new CntrIUDeletarConta();
	IUCartao *cntrIUCartao = new CntrIUCartao();
	IUContaCorrente *cntrIUContaCorrente = new CntrIUContaCorrente();

	ILNCadastro *cntrILNCadastro = new StubILNCadastro();
	ILNAutenticacao *cntrILNAutenticacao = new StubILNAutenticacao();
	ILNAcomodacao *cntrILNAcomodacao = new StubILNAcomodacao();
	ILNReserva *cntrILNReserva = new StubILNReserva();
	ILNCadastroAcomodacao *cntrILNCadastroAcomodacao = new StubILNCadastroAcomodacao();
	ILNAlterarSenha *cntrILNAlterarSenha = new StubILNAlterarSenha();
	ILNAlterarNome *cntrILNAlterarNome = new StubILNAlterarNome();
	ILNDeletarConta *cntrILNDeletarConta = new StubILNDeletarConta();
	ILNCartao *cntrILNCartao = new StubILNCartao();
	ILNContaCorrente *cntrILNContaCorrente = new StubILNContaCorrente();

	// Aqui coloca os serviços

	cntrIUCadastro->setCntrILNCadastro(cntrILNCadastro);
	cntrIUAutenticacao->setCntrILNAutenticacao(cntrILNAutenticacao);
	cntrIUAcomodacao->setCntrILNAcomodacao(cntrILNAcomodacao);
	cntrIUReserva->setCntrILNReserva(cntrILNReserva);
	cntrIUCadastroAcomodacao->setCntrILNCadastroAcomodacao(cntrILNCadastroAcomodacao);
	cntrIUAlterarSenha->setCntrILNAlterarSenha(cntrILNAlterarSenha);
	cntrIUAlterarNome->setCntrILNAlterarNome(cntrILNAlterarNome);
	cntrIUDeletarConta->setCntrILNDeletarConta(cntrILNDeletarConta);
	cntrIUCartao->setCntrILNCartao(cntrILNCartao);
	cntrIUContaCorrente->setCntrILNContaCorrente(cntrILNContaCorrente);
	

	cntrIUInicio->setCntrIUCadastro(cntrIUCadastro);
	cntrIUInicio->setCntrIUAutenticacao(cntrIUAutenticacao);
	cntrIUInicio->setCntrIUAcomodacao(cntrIUAcomodacao);
	cntrIUCadastro->setCntrIULogado(cntrIULogado);
	cntrIUAutenticacao->setCntrIULogado(cntrIULogado);
	cntrIULogado->setCntrIUAcomodacao(cntrIUAcomodacao);
	cntrIULogado->setCntrIUReserva(cntrIUReserva);
	cntrIULogado->setCntrIUCadastroAcomodacao(cntrIUCadastroAcomodacao);
	cntrIULogado->setCntrIUDados(cntrIUDados);
	cntrIUDados->setCntrIUAlterarSenha(cntrIUAlterarSenha);
	cntrIUDados->setCntrIUAlterarNome(cntrIUAlterarNome);
	cntrIUDados->setCntrIUDeletarConta(cntrIUDeletarConta);
	cntrIUDados->setCntrIUCartao(cntrIUCartao);
	cntrIUDados->setCntrIUContaCorrente(cntrIUContaCorrente);

	return cntrIUInicio;	
}

int main()
{
	IUInicializacao *cntrIUInicio;
	// teste_dominio();
	// teste_entidade();
	cntrIUInicio = initial_setting();
	// cntrIUInicio->verifica_consistencia();
	
	cntrIUInicio->inicio();

	// cntrIUInicio->libera();

	return 0;
}
