#include "controladoras.hpp"

// Definições de métodos da classe CntrIUAutenticacao.

std::string red(std::string message)
{
	return "\033[1;31m" + message + "\033[0m";
}
std::string green(std::string message)
{
    return "\033[1;32m" + message + "\033[0m";
}


CntrIUInicializacao::CntrIUInicializacao()
{
	cntrIUCadastro = NULL;
	cntrIUAutenticacao = NULL;
	cntrIUAcomodacao = NULL;
}
void inline CntrIUInicializacao::setCntrIUCadastro(IUCadastro *cntrIUCadastro)
{
	this->cntrIUCadastro = cntrIUCadastro;
}
void inline CntrIUInicializacao::setCntrIUAutenticacao(IUAutenticacao *cntrIUAutenticacao)
{
	this->cntrIUAutenticacao = cntrIUAutenticacao;
}
void inline CntrIUInicializacao::setCntrIUAcomodacao(IUAcomodacao *cntrIUAcomodacao)
{
	this->cntrIUAcomodacao = cntrIUAcomodacao;
}
void CntrIUInicializacao::verifica_consistencia() throw (consistencia_error)
{
	if(cntrIUCadastro == NULL)
		throw consistencia_error("IUInicializacao->IUCadastro");
	else
	{
		std::cout << green("IUInicializacao->IUCadastro") << std::endl;
		cntrIUCadastro->verifica_consistencia();
	}
	if(cntrIUAutenticacao == NULL)
		throw consistencia_error("a IUInicializacao->IUAutenticacao");
	else
	{
		std::cout << green("IUInicializacao->IUAutenticacao") << std::endl;
		cntrIUAutenticacao->verifica_consistencia();
	}
	if(cntrIUAcomodacao == NULL)
		throw consistencia_error("a IUInicializacao->IUAcomodacao");
	else
	{
		std::cout << green("IUInicializacao->IUAcomodacao") << std::endl;
		cntrIUAcomodacao->verifica_consistencia();
	}
}
void CntrIUInicializacao::apresentarOpcoes()
{
	int choose;
	bool loop = true;
	while(loop)
	{
		try
		{
			std::cout << std::endl << "Tela de apresentacao de sistema." << std::endl;

			std::cout << "1) Autenticar" << std::endl;
			std::cout << "2) Cadastros" << std::endl;
			std::cout << "3) Acomodacao" << std::endl;
			std::cout << "4) Reserva" << std::endl;
			std::cout << std::endl;
			std::cout << "0) Sair" << std::endl;

			std::cin >> choose;

			switch(choose)
			{
				case 1:
					// cntrIUAutenticacao->autenticar();
					break;
				case 2:
					// cntrIUUsuario->menu();
					break;
				case 3:
					// cntrIUAcomodacao->acomodar();
					break;
				case 4:
					// cntrIUReserva->reservar();
					break;
				case 0:
					// std::cout << "Escolha Sair" << std::endl;
					loop = false;
					break;
				default:
					throw std::invalid_argument("Opcao Invalida");

			}
		}
		catch(std::invalid_argument &e)
		{
			std::cout << e.what() << std::endl;
		}
    }
}





CntrIUCadastro::CntrIUCadastro()
{
	cntrILNCadastro = NULL;
	cntrIULogado = NULL;
}
void inline CntrIUCadastro::setCntrILNCadastro(ILNCadastro *cntrILNCadastro)
{
	this->cntrILNCadastro = cntrILNCadastro;
}
void inline CntrIUCadastro::setCntrIULogado(IULogado *cntrIULogado)
{
	this->cntrIULogado = cntrIULogado;
}
void CntrIUCadastro::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNCadastro == NULL)
		throw consistencia_error("IUCadastro->ILNCadastro");
	else
	{
		std::cout << green("IUCadastro->ILNCadastro") << std::endl;
		cntrILNCadastro->verifica_consistencia();
	}
	if(cntrIULogado == NULL)
		throw consistencia_error("IUCadastro->IULogado");
	else
	{
		std::cout << green("IUCadastro->IULogado") << std::endl;
		cntrIULogado->verifica_consistencia();
	}
}








CntrIUAutenticacao::CntrIUAutenticacao() 
{
	cntrILNAutenticacao = NULL;
	cntrIULogado = NULL;
}
void inline CntrIUAutenticacao::setCntrILNAutenticacao(ILNAutenticacao *cntrILNAutenticacao)
{
	this->cntrILNAutenticacao = cntrILNAutenticacao;
}
void inline CntrIUAutenticacao::setCntrIULogado(IULogado *cntrIULogado)
{
	this->cntrIULogado = cntrIULogado;
}
void CntrIUAutenticacao::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNAutenticacao == NULL)
		throw consistencia_error("IUAutenticacao->ILNAutenticacao");
	else
	{
		std::cout << green("IUAutenticacao->ILNAutenticacao") << std::endl;
		cntrILNAutenticacao->verifica_consistencia();
	}
	if(cntrIULogado == NULL)
		throw consistencia_error("IUAutenticacao->IULogado");
	else
	{
		std::cout << green("IUAutenticacao->IULogado") << std::endl;
		cntrIULogado->verifica_consistencia();
	}
}


CntrIULogado::CntrIULogado() 
{
	cntrIUAcomodacao = NULL;
	cntrIUReserva = NULL;
	cntrIUCadastroAcomodacao = NULL;
	cntrIUDados = NULL;
}
void inline CntrIULogado::setCntrIUAcomodacao(IUAcomodacao *cntrIUAcomodacao)
{
	this->cntrIUAcomodacao = cntrIUAcomodacao;
}
void inline CntrIULogado::setCntrIUReserva(IUReserva *cntrIUReserva)
{
	this->cntrIUReserva = cntrIUReserva;
}
void inline CntrIULogado::setCntrIUCadastroAcomodacao(IUCadastroAcomodacao *cntrIUCadastroAcomodacao)
{
	this->cntrIUCadastroAcomodacao = cntrIUCadastroAcomodacao;
}
void inline CntrIULogado::setCntrIUDados(IUDados *cntrIUDados)
{
	this->cntrIUDados = cntrIUDados;
}
void CntrIULogado::verifica_consistencia() throw (consistencia_error)
{
	if(cntrIUAcomodacao == NULL)
		throw consistencia_error("IULogado->IUAcomodacao");
	else
	{
		std::cout << green("IULogado->IUAcomodacao") << std::endl;
		cntrIUAcomodacao->verifica_consistencia();
	}
	if(cntrIUReserva == NULL)
		throw consistencia_error("IULogado->IUReserva");
	else
	{
		std::cout << green("IULogado->IUReserva") << std::endl;
		cntrIUReserva->verifica_consistencia();
	}
	if(cntrIUCadastroAcomodacao == NULL)
		throw consistencia_error("IULogado->IUCadastroAcomodacao");
	else
	{
		std::cout << green("IULogado->IUCadastroAcomodacao") << std::endl;
		cntrIUCadastroAcomodacao->verifica_consistencia();
	}
	if(cntrIUDados == NULL)
		throw consistencia_error("IULogado->IUDados");
	else
	{
		std::cout << green("IULogado->IUDados") << std::endl;
		cntrIUDados->verifica_consistencia();
	}
}





CntrIUAcomodacao::CntrIUAcomodacao()
{
	cntrILNAcomodacao = NULL;	
}
void inline CntrIUAcomodacao::setCntrILNAcomodacao(ILNAcomodacao *cntrILNAcomodacao)
{
	this->cntrILNAcomodacao = cntrILNAcomodacao;
}
void CntrIUAcomodacao::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNAcomodacao == NULL)
		throw consistencia_error("IUAcomodacao->ILNAcomodacao");
	else
	{
		std::cout << green("IUAcomodacao->ILNAcomodacao") << std::endl;
		cntrILNAcomodacao->verifica_consistencia();
	}
}





CntrIUReserva::CntrIUReserva()
{
	cntrILNReserva = NULL;	
}
void inline CntrIUReserva::setCntrILNReserva(ILNReserva *cntrILNReserva)
{
	this->cntrILNReserva = cntrILNReserva;
}
void CntrIUReserva::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNReserva == NULL)
		throw consistencia_error("IUReserva->ILNReserva");
	else
	{
		std::cout << green("IUReserva->ILNReserva") << std::endl;
		cntrILNReserva->verifica_consistencia();
	}
}




CntrIUCadastroAcomodacao::CntrIUCadastroAcomodacao()
{
	cntrILNCadastroAcomodacao = NULL;	
}
void inline CntrIUCadastroAcomodacao::setCntrILNCadastroAcomodacao(ILNCadastroAcomodacao *cntrILNCadastroAcomodacao)
{
	this->cntrILNCadastroAcomodacao = cntrILNCadastroAcomodacao;
}
void CntrIUCadastroAcomodacao::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNCadastroAcomodacao == NULL)
		throw consistencia_error("IUCadastroAcomodacao->ILNCadastroAcomodacao");
	else
	{
		std::cout << green("IUCadastroAcomodacao->ILNCadastroAcomodacao") << std::endl;
		cntrILNCadastroAcomodacao->verifica_consistencia();
	}
}


CntrIUDados::CntrIUDados()
{
	cntrIUCartao = NULL;
    cntrIUContaCorrente = NULL;
    cntrIUAlterarSenha = NULL;
    cntrIUAlterarNome = NULL;
    cntrIUDeletarConta = NULL;
}
void inline CntrIUDados::setCntrIUCartao(IUCartao *cntrIUCartao)
{
	this->cntrIUCartao = cntrIUCartao;
}
void inline CntrIUDados::setCntrIUContaCorrente(IUContaCorrente *cntrIUContaCorrente)
{
	this->cntrIUContaCorrente = cntrIUContaCorrente;
}
void inline CntrIUDados::setCntrIUAlterarSenha(IUAlterarSenha *cntrIUAlterarSenha)
{
	this->cntrIUAlterarSenha = cntrIUAlterarSenha;
}
void inline CntrIUDados::setCntrIUAlterarNome(IUAlterarNome *cntrIUAlterarNome)
{
	this->cntrIUAlterarNome = cntrIUAlterarNome;
}
void inline CntrIUDados::setCntrIUDeletarConta(IUDeletarConta *cntrIUDeletarConta)
{
	this->cntrIUDeletarConta = cntrIUDeletarConta;
}
void CntrIUDados::verifica_consistencia() throw (consistencia_error)
{
	if(cntrIUCartao == NULL)
		throw consistencia_error("IUDados->IUCartao");
	else
	{
		std::cout << green("IUDados->IUCartao") << std::endl;
		cntrIUCartao->verifica_consistencia();
	}
	if(cntrIUContaCorrente == NULL)
		throw consistencia_error("IUDados->IUContaCorrente");
	else
	{
		std::cout << green("IUDados->IUContaCorrente") << std::endl;
		cntrIUContaCorrente->verifica_consistencia();
	}
	if(cntrIUAlterarSenha == NULL)
		throw consistencia_error("IUDados->IUAlterarSenha");
	else
	{
		std::cout << green("IUDados->IUAlterarSenha") << std::endl;
		cntrIUAlterarSenha->verifica_consistencia();
	}
	if(cntrIUAlterarNome == NULL)
		throw consistencia_error("IUDados->IUAlterarNome");
	else
	{
		std::cout << green("IUDados->IUAlterarNome") << std::endl;
		cntrIUAlterarNome->verifica_consistencia();
	}
	if(cntrIUDeletarConta == NULL)
		throw consistencia_error("IUDados->IUDeletarConta");
	else
	{
		std::cout << green("IUDados->DeletarConta") << std::endl;
		cntrIUDeletarConta->verifica_consistencia();
	}
}






CntrIUCartao::CntrIUCartao()
{
	cntrILNCartao = NULL;	
}
void inline CntrIUCartao::setCntrILNCartao(ILNCartao *cntrILNCartao)
{
	this->cntrILNCartao = cntrILNCartao;
}
void CntrIUCartao::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNCartao == NULL)
		throw consistencia_error("IUCartao->ILNCartao");
	else
		cntrILNCartao->verifica_consistencia();
}

CntrIUContaCorrente::CntrIUContaCorrente()
{
	cntrILNContaCorrente = NULL;	
}
void inline CntrIUContaCorrente::setCntrILNContaCorrente(ILNContaCorrente *cntrILNContaCorrente)
{
	this->cntrILNContaCorrente = cntrILNContaCorrente;
}
void CntrIUContaCorrente::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNContaCorrente == NULL)
		throw consistencia_error("IUContaCorrente->ILNContaCorrente");
	else
	{
		std::cout << green("IUContaCorrente->ILNContaCorrente") << std::endl;
		cntrILNContaCorrente->verifica_consistencia();
	}
}










CntrIUAlterarSenha::CntrIUAlterarSenha()
{
	cntrILNAlterarSenha = NULL;	
}
void inline CntrIUAlterarSenha::setCntrILNAlterarSenha(ILNAlterarSenha *cntrILNAlterarSenha)
{
	this->cntrILNAlterarSenha = cntrILNAlterarSenha;
}
void CntrIUAlterarSenha::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNAlterarSenha == NULL)
		throw consistencia_error("IUAlterarSenha->ILNAlterarSenha");
	else
	{
		std::cout << green("IUAlterarSenha->ILNAlterarSenha") << std::endl;
		cntrILNAlterarSenha->verifica_consistencia();
	}
}






CntrIUAlterarNome::CntrIUAlterarNome()
{
	cntrILNAlterarNome = NULL;	
}
void inline CntrIUAlterarNome::setCntrILNAlterarNome(ILNAlterarNome *cntrILNAlterarNome)
{
	this->cntrILNAlterarNome = cntrILNAlterarNome;
}
void CntrIUAlterarNome::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNAlterarNome == NULL)
		throw consistencia_error("IUAlterarNome->ILNAlterarNome");
	else
	{
		std::cout << green("IUAlterarNome->ILNAlterarNome") << std::endl;
		cntrILNAlterarNome->verifica_consistencia();
	}
}




CntrIUDeletarConta::CntrIUDeletarConta()
{
	cntrILNDeletarConta = NULL;	
}
void inline CntrIUDeletarConta::setCntrILNDeletarConta(ILNDeletarConta *cntrILNDeletarConta)
{
	this->cntrILNDeletarConta = cntrILNDeletarConta;
}
void CntrIUDeletarConta::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNDeletarConta == NULL)
		throw consistencia_error("IUDeletarConta->ILNDeletarConta");
	else
	{
		std::cout << green("IUAlterarNome->ILNAlterarNome") << std::endl;
		cntrILNDeletarConta->verifica_consistencia();
	}
}