#include "controladoras.hpp"

#include "input_data.hpp"
// Definições de métodos da classe CntrIUAutenticacao.

std::string red(std::string message)
{
	return "\033[1;31m" + message + "\033[0m";
}
std::string green(std::string message)
{
    return "\033[1;32m" + message + "\033[0m";
}
void limpar_tela()
{
	system("clear");
}








CntrIUInicializacao::CntrIUInicializacao()
{
	cntrIUCadastro = NULL;
	cntrIUAutenticacao = NULL;
	cntrIUAcomodacao = NULL;
}
CntrIUInicializacao::~CntrIUInicializacao(){}
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
void CntrIUInicializacao::libera()
{
	if(cntrIUCadastro != NULL)
	{
		cntrIUCadastro->libera();
		delete cntrIUCadastro;
		cntrIUCadastro = NULL;
	}
	if(cntrIUAutenticacao != NULL)
	{
		cntrIUAutenticacao->libera();
		delete cntrIUAutenticacao;
		cntrIUAutenticacao = NULL;
	}
	if(cntrIUAcomodacao != NULL)
	{
		cntrIUAcomodacao->libera();
		delete cntrIUAcomodacao;
		cntrIUAcomodacao = NULL;
	}
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
void CntrIUInicializacao::inicio()
{
	char c;
	while(true)
	{
		apresentarOpcoes();
		c = getch();
		if(c == B_AUTENTICAR){
			cntrIUAutenticacao->autenticar();
		}
		else if(c == B_CADASTRAR){
			// cntrIUUsuario->menu();
		}
		else if(c == B_ACOMODACAO){
			//
		}
		else if(c == B_SAIR)
			break;
    }
}
void CntrIUInicializacao::apresentarOpcoes()
{
	limpar_tela();
	std::cout << std::endl << "Tela de apresentacao de sistema." << std::endl;

	std::cout << B_AUTENTICAR << ") Autenticar" << std::endl;
	std::cout << B_CADASTRAR  << ") Cadastrar" << std::endl;
	std::cout << B_ACOMODACAO << ") Acomodacao" << std::endl;
	std::cout << std::endl;
	std::cout << B_SAIR << ") Sair" << std::endl;
}





CntrIUCadastro::CntrIUCadastro()
{
	cntrILNCadastro = NULL;
	cntrIULogado = NULL;
}
CntrIUCadastro::~CntrIUCadastro(){}
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
void CntrIUCadastro::libera()
{
	if(cntrILNCadastro != NULL)
	{
		cntrILNCadastro->libera();
		delete cntrILNCadastro;
		cntrILNCadastro = NULL;
	}
	if(cntrIULogado != NULL)
	{
		// cntrIULogado->libera();
		delete cntrIULogado;
		cntrIULogado = NULL;
	}
}
void inline CntrIUCadastro::setCntrILNCadastro(ILNCadastro *cntrILNCadastro)
{
	this->cntrILNCadastro = cntrILNCadastro;
}
void inline CntrIUCadastro::setCntrIULogado(IULogado *cntrIULogado)
{
	this->cntrIULogado = cntrIULogado;
}








CntrIUAutenticacao::CntrIUAutenticacao() 
{
	cntrILNAutenticacao = NULL;
	cntrIULogado = NULL;
}
CntrIUAutenticacao::~CntrIUAutenticacao(){}
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
void CntrIUAutenticacao::libera()
{
	if(cntrILNAutenticacao != NULL)
	{
		cntrILNAutenticacao->libera();
		delete cntrILNAutenticacao;
		cntrILNAutenticacao = NULL;
	}
	if(cntrIULogado != NULL)
	{
		cntrIULogado->libera(); // O erro esta aqui, ainda existe o ponteiro, mas o objeto ja foi deletado e entao ele tenta acessar uma memória ja desalocada
		delete cntrIULogado;
		cntrIULogado = NULL;
	}
}
void inline CntrIUAutenticacao::setCntrILNAutenticacao(ILNAutenticacao *cntrILNAutenticacao)
{
	this->cntrILNAutenticacao = cntrILNAutenticacao;
}
void inline CntrIUAutenticacao::setCntrIULogado(IULogado *cntrIULogado)
{
	this->cntrIULogado = cntrIULogado;
}
void CntrIUAutenticacao::autenticar()
{
	std::cout << "Autenticou!!!" << std::endl;
	while(kbhit())
		getch();
	getch();
}





CntrIULogado::CntrIULogado() 
{
	cntrIUAcomodacao = NULL;
	cntrIUReserva = NULL;
	cntrIUCadastroAcomodacao = NULL;
	cntrIUDados = NULL;
}
CntrIULogado::~CntrIULogado(){}
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
void CntrIULogado::libera()
{
	if(cntrIUAcomodacao != NULL)
	{
		// cntrIUAcomodacao->libera();
		delete cntrIUAcomodacao;
		cntrIUAcomodacao = NULL;
	}
	if(cntrIUReserva != NULL)
	{
		cntrIUReserva->libera();
		delete cntrIUReserva;
		cntrIUReserva = NULL;
	}
	if(cntrIUCadastroAcomodacao != NULL)
	{
		cntrIUCadastroAcomodacao->libera();
		delete cntrIUCadastroAcomodacao;
		cntrIUCadastroAcomodacao = NULL;
	}
	if(cntrIUDados != NULL)
	{
		cntrIUDados->libera();
		delete cntrIUDados;
		cntrIUDados = NULL;
	}
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





CntrIUAcomodacao::CntrIUAcomodacao()
{
	cntrILNAcomodacao = NULL;	
}
CntrIUAcomodacao::~CntrIUAcomodacao(){}
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
void CntrIUAcomodacao::libera()
{
	if(cntrILNAcomodacao != NULL)
	{
		cntrILNAcomodacao->libera();	
		delete cntrILNAcomodacao;
		cntrILNAcomodacao = NULL;
	}
}
void inline CntrIUAcomodacao::setCntrILNAcomodacao(ILNAcomodacao *cntrILNAcomodacao)
{
	this->cntrILNAcomodacao = cntrILNAcomodacao;
}





CntrIUReserva::CntrIUReserva()
{
	cntrILNReserva = NULL;
}
CntrIUReserva::~CntrIUReserva(){}
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
void CntrIUReserva::libera()
{
	if(cntrILNReserva != NULL)
	{
		cntrILNReserva->libera();
		delete cntrILNReserva;
		cntrILNReserva = NULL;
	}
}
void inline CntrIUReserva::setCntrILNReserva(ILNReserva *cntrILNReserva)
{
	this->cntrILNReserva = cntrILNReserva;
}




CntrIUCadastroAcomodacao::CntrIUCadastroAcomodacao()
{
	cntrILNCadastroAcomodacao = NULL;	
}
CntrIUCadastroAcomodacao::~CntrIUCadastroAcomodacao(){}
void CntrIUCadastroAcomodacao::libera()
{
	if(cntrILNCadastroAcomodacao != NULL)
	{
		cntrILNCadastroAcomodacao->libera();
		delete cntrILNCadastroAcomodacao;
		cntrILNCadastroAcomodacao = NULL;
	}
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
CntrIUDados::~CntrIUDados(){}
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
void CntrIUDados::libera()
{
	if(cntrIUCartao != NULL)
	{
		cntrIUCartao->libera();
		delete cntrIUCartao; 
		cntrIUCartao = NULL;
	}
	if(cntrIUContaCorrente != NULL)
	{
		cntrIUContaCorrente->libera();
	    delete cntrIUContaCorrente;
	    cntrIUContaCorrente = NULL;
	}
	if(cntrIUAlterarSenha != NULL)
	{
	    cntrIUAlterarSenha->libera();
	    delete cntrIUAlterarSenha;
	    cntrIUAlterarSenha = NULL;
	}
	if(cntrIUAlterarNome != NULL)
	{
	    cntrIUAlterarNome->libera();
	    delete cntrIUAlterarNome;
	    cntrIUAlterarNome = NULL;
	}
	if(cntrIUDeletarConta != NULL)
	{
	    cntrIUDeletarConta->libera();
	    delete cntrIUDeletarConta;
	    cntrIUDeletarConta = NULL;
	}
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






CntrIUCartao::CntrIUCartao()
{
	cntrILNCartao = NULL;	
}
CntrIUCartao::~CntrIUCartao(){}
void CntrIUCartao::verifica_consistencia() throw (consistencia_error)
{
	if(cntrILNCartao == NULL)
		throw consistencia_error("IUCartao->ILNCartao");
	else
		cntrILNCartao->verifica_consistencia();
}
void CntrIUCartao::libera()
{
	if(cntrILNCartao != NULL)
	{
		cntrILNCartao->libera();	
		delete cntrILNCartao;
		cntrILNCartao = NULL;
	}
}
void inline CntrIUCartao::setCntrILNCartao(ILNCartao *cntrILNCartao)
{
	this->cntrILNCartao = cntrILNCartao;
}





CntrIUContaCorrente::CntrIUContaCorrente()
{
	cntrILNContaCorrente = NULL;	
}
CntrIUContaCorrente::~CntrIUContaCorrente(){}
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
void CntrIUContaCorrente::libera()
{
	if(cntrILNContaCorrente != NULL)
	{
		cntrILNContaCorrente->libera();	
		delete cntrILNContaCorrente;
		cntrILNContaCorrente = NULL;
	}
}
void inline CntrIUContaCorrente::setCntrILNContaCorrente(ILNContaCorrente *cntrILNContaCorrente)
{
	this->cntrILNContaCorrente = cntrILNContaCorrente;
}










CntrIUAlterarSenha::CntrIUAlterarSenha()
{
	cntrILNAlterarSenha = NULL;	
}
CntrIUAlterarSenha::~CntrIUAlterarSenha(){}
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
void CntrIUAlterarSenha::libera()
{
	if(cntrILNAlterarSenha != NULL)
	{
		cntrILNAlterarSenha->libera();
		delete cntrILNAlterarSenha;
		cntrILNAlterarSenha = NULL;
	}
}
void inline CntrIUAlterarSenha::setCntrILNAlterarSenha(ILNAlterarSenha *cntrILNAlterarSenha)
{
	this->cntrILNAlterarSenha = cntrILNAlterarSenha;
}






CntrIUAlterarNome::CntrIUAlterarNome()
{
	cntrILNAlterarNome = NULL;	
}
CntrIUAlterarNome::~CntrIUAlterarNome(){}
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
void CntrIUAlterarNome::libera()
{
	if(cntrILNAlterarNome != NULL)
	{
		cntrILNAlterarNome->libera();
		delete cntrILNAlterarNome;
		cntrILNAlterarNome = NULL;
	}
}
void inline CntrIUAlterarNome::setCntrILNAlterarNome(ILNAlterarNome *cntrILNAlterarNome)
{
	this->cntrILNAlterarNome = cntrILNAlterarNome;
}




CntrIUDeletarConta::CntrIUDeletarConta()
{
	cntrILNDeletarConta = NULL;	
}
CntrIUDeletarConta::~CntrIUDeletarConta(){}
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
void CntrIUDeletarConta::libera()
{
	if(cntrILNDeletarConta != NULL)
	{
		cntrILNDeletarConta->libera();
		delete cntrILNDeletarConta;
		cntrILNDeletarConta = NULL;	
	}
}
void inline CntrIUDeletarConta::setCntrILNDeletarConta(ILNDeletarConta *cntrILNDeletarConta)
{
	this->cntrILNDeletarConta = cntrILNDeletarConta;
}