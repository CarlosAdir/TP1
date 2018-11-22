#include "controladoras.hpp"

// Definições de métodos da classe CntrIUAutenticacao.










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
void CntrIUInicializacao::menu()
{
	char c;
	while(true)
	{
		apresentarOpcoes();
		c = getch();
		if(c == B_AUTENTICAR)
			cntrIUAutenticacao->autenticar();
		else if(c == B_CADASTRAR)
			cntrIUCadastro->cadastrar();
		else if(c == B_ACOMODACAO)
			cntrIUAcomodacao->acomodacao();
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
bool CntrIUCadastro::getData(Usuario *usuario)
{
	Identificador identificador;
	Senha senha;
	Nome nome;
	std::string entrada;
	char mensagem[100];
	int contador, i;

	for(i = 0; i < 3; i++)
	{
		sprintf(mensagem, "\n");
		contador = 0;
		while(true) {

			limpar_tela();
			std::cout << std::endl << "Cadastro de usuario." << std::endl << std::endl;
			std::cout << std::endl << mensagem << std::endl << std::endl;
			try
			{
				if(i > -1)
				{
					std::cout << "Nome          : ";
					if(i == 0)
						std::cin >> nome;
					else
						std::cout << nome << std::endl;
				}
				if(i > 0)
				{
					std::cout << "Identificador : ";
					if(i == 1)
						std::cin >> identificador;
					else
						std::cout << identificador << std::endl; 
				}
				if(i > 1)
				{
					std::cout << "Senha         : ";
					if(i == 2)
						std::cin >> senha;
				}

				limpar_buffer();
				break;
			}
			catch (const std::invalid_argument &exp)
			{
				limpar_buffer();
				contador += 1;
				if(contador == LIMITE_TENTATIVAS)
					return false;
				sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
			}
			
		}
	}
	usuario->setNome(nome);
	usuario->setIdentificador(identificador);
	usuario->setSenha(senha);
	return true;
}
void CntrIUCadastro::cadastrar()
{
	Usuario usuario;
	Identificador identificador;
	ResultadoCadastro result;
	bool cons; // conseguiu pegar os dados
	
	cons = getData(&usuario);
	if(cons == false)
		return;
	identificador = usuario.getIdentificador();

	result = cntrILNCadastro->cadastrar(usuario); // Aqui vem a parte do servico

	if(result.getValor() == ResultadoAutenticacao::SUCESSO)
		cntrIULogado->menu(identificador);
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
bool CntrIUAutenticacao::getData(Identificador *identificador, Senha *senha)
{
	// Essa funcao apenas pergunta ao usuario o identificador e a senha para se fazer a autenticacao
	std::string entrada;
	char mensagem[100];
	int contador, i;

	for(i = 0; i < 2; i++)
	{
		sprintf(mensagem, "\n");
		contador = 0;
		while(true) {

			limpar_tela();
			std::cout << std::endl << "Autenticacao de usuario." << std::endl << std::endl;
			std::cout << std::endl << mensagem << std::endl << std::endl;
			try
			{
				std::cout << "Identificador : ";
				if(i == 0)
					std::cin >> *identificador;
				else
					std::cout << *identificador << std::endl; 
					

				if(i > 0)
				{
					std::cout << "Senha         : ";
					if(i == 1)
						std::cin >> *senha;
				}
				limpar_buffer();
				break;
			}
			catch (const std::invalid_argument &exp)
			{
				limpar_buffer();
				contador += 1;
				if(contador == LIMITE_TENTATIVAS)
					return false;
				sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
			}
		}
	}
	return true;
}

void CntrIUAutenticacao::autenticar()
{
	ResultadoAutenticacao result;
	Identificador identificador;
	Senha senha;
	bool cons;

	// Solicitar matricula e senha.

	cons = getData(&identificador, &senha);
	if(cons == false)
	{
		return;
	}
	else
	{
		result = cntrILNAutenticacao->autenticar(identificador, senha);
		if(result.getValor() == ResultadoAutenticacao::SUCESSO)
			cntrIULogado->menu(identificador);
	}
	// identificador.set("abcde");
	// cntrIULogado->menu(identificador);
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


void CntrIULogado::menu(Identificador &identificador)
{
	char c;
	while(true)
	{
		apresentarOpcoes(identificador);
		c = getch();
		if(c == B_ACOMODACAO)
			cntrIUAcomodacao->acomodacao();
		else if(c == B_CADASTRAR_ACOMODACAO)
			cntrIUCadastroAcomodacao->menu(identificador);
		else if(c == B_RESERVA)
			cntrIUReserva->menu(identificador);
		else if(c == B_DADOS)
			cntrIUDados->menu(identificador);
		else if(c == B_LOGOUT)
			break;
    }
}
void CntrIULogado::apresentarOpcoes(Identificador &identificador)
{
	limpar_tela();
	std::cout << std::endl << "Tela de logado." << std::endl;
	std::cout << "Identificador: " << identificador << std::endl << std::endl;

	std::cout << B_ACOMODACAO << ") Acomodacao" << std::endl;
	std::cout << B_CADASTRAR_ACOMODACAO  << ") Cadastrar Acomodacao" << std::endl;
	std::cout << B_RESERVA << ") Reserva" << std::endl;
	std::cout << B_DADOS << ") Dados" << std::endl;
	std::cout << std::endl;
	std::cout << B_LOGOUT << ") Logout" << std::endl;
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

bool CntrIUAcomodacao::getData(Data *inicio, Data *termino, CapacidadeAcomodacao *cap, Nome *cidade, Estado *estado)
{
	char mensagem[100];
	int contador, i;

	for(i = 0; i < 5; i++) // Temos 5 entradas do usuario: data de inicio, termino, capacidade, cidade e estado
	{
		if(i < 2)
			sprintf(mensagem, "Exemplo de data: 12 jan 2003\n");
		else
			sprintf(mensagem, "\n");
		contador = 0;
		while(true) {
			limpar_tela();
			std::cout << std::endl << "Pesquisar uma acomodacao." << std::endl << std::endl;
			std::cout << std::endl << mensagem << std::endl << std::endl;
			try
			{
				std::cout << "Data de Inicio : ";
				if(i == 0)
					std::cin >> *inicio;
				else
					std::cout << *inicio << std::endl; 
				

				if(i > 0)
				{
					std::cout << "Data de Termino: ";
					if(i == 1)
					{
						std::cin >> *termino;
						if(*termino < *inicio)
							throw std::invalid_argument("Data de termino menor que data de inicio");
					}
					else
						std::cout << *termino << std::endl;
				}

				if(i > 1)
				{
					std::cout << "Capacidade     : ";
					if(i == 2)
						std::cin >> *cap;
					else
						std::cout << *cap << std::endl;
				}

				if(i > 2)
				{
					std::cout << "Cidade         : ";
					if(i == 3)
					{
						std::cin >> *cidade;
					}
					else
						std::cout << *cidade << std::endl;
				}

				if(i > 3)
				{
					std::cout << "Estado         : ";
					std::cin >> *estado;
				}
				limpar_buffer();
				break;
			}
			catch (const std::invalid_argument &exp)
			{
				limpar_buffer();
				contador += 1;
				if(contador == LIMITE_TENTATIVAS)
					return false;
				sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
			}
			// catch (...)
			// {
			// 	limpar_buffer();
			// 	std::cout << "what" << std::endl;
			// 	contador += 1;
			// 	if(contador == LIMITE_TENTATIVAS)
			// 		return;
			// }
		}
	}
	return true;
}

void CntrIUAcomodacao::acomodacao()
{
	Data inicio, termino; // Data de inicio e termino da acomodacao
	CapacidadeAcomodacao cap;
	Nome cidade;
	Estado estado;
	bool cons;

	std::vector<Acomodacao> acomodacoes;


	// Solicitar matricula e senha.
	cons = getData(&inicio, &termino, &cap, &cidade, &estado);
	if(cons == false)
	{
		// std::cout << "Nao consegui pegar os dados corretamente, o usuario quebrou o limite de tentativas" << std::endl;
		// travar_tela();
		return;
	}
	limpar_tela();

	std::cout << "Dados informados pelo usuario" << std::endl;
	std::cout << inicio << std::endl;
	std::cout << termino << std::endl;
	std::cout << cap.get() << std::endl;
	std::cout << cidade.get() << std::endl;
	std::cout << estado.get() << std::endl;
	std::cout << "Aqui entao deveria mostrar a lista de acomodacoes que satisfacam os requisitos" << std::endl;
	std::cout << "Mas a de servico ainda nao foi totalmente implementada" << std::endl;
	travar_tela();
	
	acomodacoes = cntrILNAcomodacao->acomodacoes_cabiveis(inicio, termino, cap, cidade, estado);

	imprime_acomodacoes(acomodacoes);


}

void CntrIUAcomodacao::imprime_acomodacoes(std::vector<Acomodacao> &acomodacoes)
{

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
void CntrIUReserva::menu(Identificador &identificador)
{
	char c;
	if(verifica_cartaocredito(identificador) == false)
		return;
	while(true)
	{
		apresentarOpcoes();
		c = getch();
		if(c == B_ADICIONAR)
			adicionar_reserva(identificador);
		else if(c == B_REMOVER)
			remover_reserva(identificador);
		else if(c == B_VOLTAR)
			break;
    }
}
void CntrIUReserva::apresentarOpcoes()
{
	limpar_tela();
	std::cout << std::endl << "Tela de adicionar/remover reserva." << std::endl;

	std::cout << B_ADICIONAR << ") Adicionar" << std::endl;
	std::cout << B_REMOVER  << ") Remover" << std::endl;
	std::cout << std::endl;
	std::cout << B_VOLTAR << ") Voltar" << std::endl;
}
bool CntrIUReserva::verifica_cartaocredito(Identificador &identificador)
{
	bool r = cntrILNReserva->existe_cartaocredito(identificador); 
	if(r == true)
		return true;
	std::cout << "Nao foi possivel entrar na Reserva pois voce nao possui Cartao de Credito" << std::endl;
	travar_tela();
	return false;
}
bool CntrIUReserva::getDataAdicionar(Identificador *acomod_identificador, Data *inicio, Data *termino)
{
	int i, contador;
	char mensagem[100];
	for(i = 0; i < 3; i++)
	{
		sprintf(mensagem, "\n");
		contador = 0;
		while(true) {
			limpar_tela();
			std::cout << std::endl << "Tela de Adicionar Reserva" << std::endl << std::endl;
			std::cout << std::endl << mensagem << std::endl << std::endl;
			try
			{
				std::cout << "Identificador da Acomodacao : ";
				if(i == 0)
					std::cin >> *acomod_identificador;
				else
					std::cout << *acomod_identificador << std::endl; 
				

				if(i > 0)
				{
					std::cout << "Data de Inicio                  : ";
					if(i == 1)
						std::cin >> *inicio;
					else
						std::cout << *inicio << std::endl;
				}

				if(i > 1)
				{
					std::cout << "Data de Termino                 : ";
					std::cin >> *termino;
				}
				break;
			}
			catch (const std::invalid_argument &exp)
			{
				limpar_buffer();
				contador += 1;
				if(contador == LIMITE_TENTATIVAS)
					return false;
				sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
			}
		}

	}
	return true;
}
bool CntrIUReserva::getDataRemover(Identificador *acomod_identificador)
{
	int contador;
	char mensagem[100];
	sprintf(mensagem, "\n");
	contador = 0;
	while(true) {
		limpar_tela();
		std::cout << std::endl << "Tela de Remover Reserva" << std::endl << std::endl;
		std::cout << std::endl << mensagem << std::endl << std::endl;
		try
		{
			std::cout << "Identificador da Acomodacao : ";
			std::cin >> *acomod_identificador;
			break;
		}
		catch (const std::invalid_argument &exp)
		{
			limpar_buffer();
			contador += 1;
			if(contador == LIMITE_TENTATIVAS)
				return false;
			sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
		}
	}
	return true;
}
void CntrIUReserva::adicionar_reserva(Identificador &identificador)
{
	Identificador acomod_identificador;
	Data inicio, termino;
	ResultadoAdicionarReserva result;
	bool cons;

	cons = getDataAdicionar(&acomod_identificador, &inicio, &termino);
	if(cons == false)
		return;
	
	result = cntrILNReserva->adicionar_reserva(identificador, acomod_identificador, inicio, termino);
	// fazer alguma coisa aqui com o result
}
void CntrIUReserva::remover_reserva(Identificador &identificador)
{
	Identificador acomod_identificador;
	ResultadoRemoverReserva result;
	bool cons;

	cons = getDataRemover(&acomod_identificador);
	if(cons == false)
		return;
	
	result = cntrILNReserva->remover_reserva(identificador, acomod_identificador);
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
void CntrIUCadastroAcomodacao::menu(Identificador &identificador)
{
	char c;
	if(verifica_contacorrente(identificador) == false)
		return;
	while(true)
	{
		apresentarOpcoes();
		c = getch();
		if(c == B_ADICIONAR)
			adicionar_acomodacao(identificador);
		else if(c == B_REMOVER)
			remover_acomodacao(identificador);
		else if(c == B_VOLTAR)
			break;
    }
}
bool CntrIUCadastroAcomodacao::verifica_contacorrente(Identificador &identificador)
{
	bool r = cntrILNCadastroAcomodacao->existe_contacorrente(identificador);
	if(r == true)
		return true;
	std::cout << "Nao foi possivel entrar no Cadastro de Acomodacao pois voce nao possui Conta Corrente" << std::endl;
	travar_tela();
	return false;
}
void CntrIUCadastroAcomodacao::apresentarOpcoes()
{
	limpar_tela();
	std::cout << std::endl << "Tela de adicionar/remover acomodacao." << std::endl;

	std::cout << B_ADICIONAR << ") Adicionar" << std::endl;
	std::cout << B_REMOVER  << ") Remover" << std::endl;
	std::cout << std::endl;
	std::cout << B_VOLTAR << ") Voltar" << std::endl;
}
bool CntrIUCadastroAcomodacao::getDataAdicionar(Acomodacao *acomodacao)
{
	Identificador acomod_identificador;
	TipoAcomodacao tipo;
	CapacidadeAcomodacao cap;
	Diaria diaria;
	Nome cidade;
	Estado estado;
	Data inicio, termino; // Para estipular o tempo em que a acomodacao esta aberta.
	int i, contador;
	char mensagem[100];

	for(i = 0; i < 8; i++)
	{
		sprintf(mensagem, "\n");
		contador = 0;
		while(true) {
			limpar_tela();
			std::cout << std::endl << "Tela de Adicionar Acomodacao" << std::endl << std::endl;
			std::cout << std::endl << mensagem << std::endl << std::endl;
			try
			{
				std::cout << "Identificador da Acomodacao : ";
				if(i == 0)
					std::cin >> acomod_identificador;
				else
					std::cout << acomod_identificador << std::endl; 
				
				if(i > 0)
				{
					std::cout << "Tipo da Acomodacao          : ";
					if(i == 1)
						std::cin >> acomod_identificador;
					else
						std::cout << acomod_identificador << std::endl;
				}

				if(i > 1)
				{
					std::cout << "Capacidade de Acomodacao    : ";
					if(i == 2)
						std::cin >> cap;
					else
						std::cout << cap << std::endl;
				}

				if(i > 2)
				{
					std::cout << "Diaria                      : ";
					if(i == 3)
						std::cin >> diaria;
					else
						std::cout << diaria << std::endl;
				}

				if(i > 3)
				{
					std::cout << "Cidade                      : ";
					if(i == 4)
						std::cin >> cidade;
					else
						std::cout << cidade << std::endl;
				}

				if(i > 4)
				{
					std::cout << "Estado                      : ";
					if(i == 5)
						std::cin >> estado;
					else
						std::cout << estado << std::endl;
				}



				if(i > 5)
				{
					std::cout << "Data de Inicio                  : ";
					if(i == 6)
						std::cin >> inicio;
					else
						std::cout << inicio << std::endl;
				}

				if(i > 6)
				{
					std::cout << "Data de Termino                 : ";
					std::cin >> termino;
				}
				break;
			}
			catch (const std::invalid_argument &exp)
			{
				limpar_buffer();
				contador += 1;
				if(contador == LIMITE_TENTATIVAS)
					return false;
				sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
			}
		}
	}
	acomodacao->setIdentificador(acomod_identificador);
	acomodacao->setTipoAcomodacao(tipo);
	acomodacao->setCapacidadeAcomodacao(cap);
	acomodacao->setDiaria(diaria);
	acomodacao->setCidade(cidade);
	acomodacao->setEstado(estado);
	acomodacao->setDatas(inicio, termino);
	return true;
}
void CntrIUCadastroAcomodacao::adicionar_acomodacao(Identificador &identificador)
{
	Acomodacao acomodacao;
	ResultadoAdicionarAcomodacao result;
	bool cons;

	cons = getDataAdicionar(&acomodacao);
	if(cons == false)
		return;
	
	result = cntrILNCadastroAcomodacao->adicionar_acomodacao(identificador, acomodacao);
	// fazer alguma coisa aqui com o result

}
bool CntrIUCadastroAcomodacao::getDataRemover(Identificador *acomod_identificador)
{
	int contador;
	char mensagem[100];
	sprintf(mensagem, "\n");
	contador = 0;
	while(true) {
		limpar_tela();
		std::cout << std::endl << "Tela de Remover Reserva" << std::endl << std::endl;
		std::cout << std::endl << mensagem << std::endl << std::endl;
		try
		{
			std::cout << "Identificador da Acomodacao : ";
			std::cin >> *acomod_identificador;
			break;
		}
		catch (const std::invalid_argument &exp)
		{
			limpar_buffer();
			contador += 1;
			if(contador == LIMITE_TENTATIVAS)
				return false;
			sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
		}
	}
	return true;
}
void CntrIUCadastroAcomodacao::remover_acomodacao(Identificador &identificador)
{
	ResultadoRemoverAcomodacao result;
	Identificador acomod_identificador;
	bool cons;

	cons = getDataRemover(&acomod_identificador);
	if(cons == false)
		return;
	
	result = cntrILNCadastroAcomodacao->remover_acomodacao(identificador, acomod_identificador);
	// fazer alguma coisa aqui com o result
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
void CntrIUDados::menu(Identificador &identificador)
{
	char c;
	while(true)
	{
		apresentarOpcoes();
		c = getch();
		if(c == B_CARTAO)
			cntrIUCartao->setCartao(identificador);
		else if(c == B_CONTA)
			cntrIUContaCorrente->setConta(identificador);
		else if(c == B_SENHA)
			cntrIUAlterarSenha->setSenha(identificador);
		else if(c == B_NOME)
			cntrIUAlterarNome->setNome(identificador);
		else if(c == B_DELETAR)
			cntrIUDeletarConta->deletar(identificador);
		else if(c == B_VOLTAR)
			break;
    }
}
void CntrIUDados::apresentarOpcoes()
{
	limpar_tela();
	std::cout << std::endl << "Tela de Perfil do Usuario." << std::endl;

	std::cout << B_CARTAO << ") Adicionar/Alterar cartao de credito" << std::endl;
	std::cout << B_CONTA  << ") Adicionar/Alterar conta corrente" << std::endl;
	std::cout << B_SENHA  << ") Alterar senha" << std::endl;
	std::cout << B_NOME  << ") Alterar nome" << std::endl;
	std::cout << B_DELETAR  << ") Deletar conta" << std::endl;
	std::cout << std::endl;
	std::cout << B_VOLTAR << ") Voltar" << std::endl;
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
bool CntrIUCartao::getData(CartaoCredito *cartao)
{
	NumeroCartaoCredito numero;
	DataValidade data_validade;
	char mensagem[100];
	int contador, i;

	for(i = 0; i < 2; i++) // Temos 2 entradas do usuario: NumeroCartaoCredito, Data Validade
	{
		sprintf(mensagem, "\n");
		contador = 0;
		while(true) {
			limpar_tela();
			std::cout << std::endl << "Tela de Cartao de Credito" << std::endl << std::endl;
			std::cout << std::endl << "Digite seu novo cartao: ";
			std::cout << std::endl << mensagem << std::endl << std::endl;
			try
			{
				std::cout << "Cartao de Credito : ";
				if(i == 0)
					std::cin >> numero;
				else
					std::cout << numero << std::endl; 
				

				if(i > 0)
				{
					std::cout << "Data de Validade  : ";
					std::cin >> data_validade;
				}
				break;
			}
			catch (const std::invalid_argument &exp)
			{
				limpar_buffer();
				contador += 1;
				if(contador == LIMITE_TENTATIVAS)
					return false;
				sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
			}
		}
	}
	cartao->setNumero(numero);
	cartao->setValidade(data_validade);
	return true;

}
void CntrIUCartao::setCartao(Identificador &identificador)
{
	CartaoCredito cartao;
	ResultadoCartaoCredito result;
	bool cons;

	cons = getData(&cartao);
	if(cons == false)
		return;

	result = cntrILNCartao->cartao_credito(identificador, cartao);
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
bool CntrIUContaCorrente::getData(ContaCorrente *conta)
{
	NumeroContaCorrente numero;
	Agencia agencia;
	Banco banco;
	char mensagem[100];
	int contador, i;

	for(i = 0; i < 3; i++) // Temos 3 entradas do usuario: NumeroContaCorrente, Agencia, Banco
	{
		sprintf(mensagem, "\n");
		contador = 0;
		while(true) {
			limpar_tela();
			std::cout << std::endl << "Tela de Conta Corrente" << std::endl << std::endl;
			std::cout << std::endl << "Digite sua nova conta corrente: ";
			std::cout << std::endl << mensagem << std::endl << std::endl;
			try
			{
				std::cout << "Conta Corrente : ";
				if(i == 0)
					std::cin >> numero;
				else
					std::cout << numero << std::endl; 
				

				if(i > 0)
				{
					std::cout << "Agencia        : ";
					if(i == 1)
						std::cin >> agencia;
					else
						std::cout << agencia << std::endl;
				}

				if(i > 1)
				{
					std::cout << "Banco          : ";
					std::cin >> banco;
				}
				break;
			}
			catch (const std::invalid_argument &exp)
			{
				limpar_buffer();
				contador += 1;
				if(contador == LIMITE_TENTATIVAS)
					return false;
				sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
			}
		}
	}
	conta->setContaCorrente(numero);
	conta->setAgencia(agencia);
	conta->setBanco(banco);
	return true;
}
void CntrIUContaCorrente::setConta(Identificador &identificador)
{
	ContaCorrente conta;
	ResultadoContaCorrente result;
	bool cons;
	
	cons = getData(&conta);
	if(cons == false) // indicando que o usuario errou demais em informar os dados
	{
		// std::cout << "CntrIUContaCorrente::setConta - Errou demais!" << std::endl;
		// travar_tela(); 
		return;
	}
	
	result = cntrILNContaCorrente->conta_corrente(identificador, conta);

	// Fazer alguma coisa com o result
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
bool CntrIUAlterarSenha::getData(Senha *velha, Senha *nova)
{
	int i, contador;
	char mensagem[100];
	for(i = 0; i < 2; i++)
	{
		contador = 0;
		sprintf(mensagem, "\n");
		while(true)
		{
			limpar_tela();
			std::cout << std::endl << "Tela de Alteracao de senha." << std::endl;
			std::cout << mensagem << std::endl << std::endl;
			try
			{
				std::cout << "Digite a antiga senha: ";
				if(i == 0)
					std::cin >> *velha;
				else
					std::cout << *velha << std::endl;

				if(i == 1)
				{
					std::cout << "Digite a nova senha  : ";
					std::cin >> *nova;
				}
				break;
			}
			catch (const std::invalid_argument &exp)
			{
				limpar_buffer();
				contador += 1;
				if(contador == LIMITE_TENTATIVAS)
					return false;
				sprintf(mensagem, "%s\nRestam %d tentativas.", exp.what(), (LIMITE_TENTATIVAS - contador));
			}
		}
	}
	return true;
}
void CntrIUAlterarSenha::setSenha(Identificador &identificador)
{
	Senha velha, nova;
	ResultadoAlterarSenha result;
	bool cons;

	cons = getData(&velha, &nova);
	if(cons == false)
		return;
	

	result = cntrILNAlterarSenha->alterar_senha(identificador, velha, nova);
	
	// Fazer alguma coisa com esse result aqui
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
bool CntrIUAlterarNome::getData(Nome *nome, Senha *senha)
{
	limpar_tela();
	std::cout << std::endl << "Tela de Alterar Nome" << std::endl << std::endl;
	try
	{
		std::cout << std::endl << "Digite seu novo nome: ";
		std::cin >> *nome;
		std::cout << "Digite sua senha    : ";
		std::cin >> *senha;
	}
	catch(const std::invalid_argument &exp)
	{
		std::cout << exp.what() << std::endl;
		return false;
	}
	return true;
}
void CntrIUAlterarNome::setNome(Identificador &identificador)
{
	Nome nome;
	Senha senha;
	ResultadoAlterarNome result;
	bool cons;

	cons = getData(&nome, &senha);
	if(cons == false)
		return;

	result = cntrILNAlterarNome->alterar_nome(identificador, nome, senha);


	// Fazer alguma coisa com o result
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
bool CntrIUDeletarConta::getData(Senha *senha)
{
	std::string entrada;
	limpar_tela();
	std::cout << std::endl << "Tela de Deletar Conta." << std::endl << std::endl;
	std::cout << "Voce tem certeza que quer deletar sua conta? Caso sim, digite \"Sim\"" << std::endl << std::endl;
	std::cout << "Resposta: ";
	std::getline(std::cin, entrada);
	if(entrada != "Sim")
	{
		std::cout << "Exclusao abortada pois nao digitou \"Sim\"" << std::endl;
		return false;
	}
	try
	{
		std::cout << std::endl << "Digite sua senha: ";
		std::cin >> *senha;
	}
	catch (const std::invalid_argument &exp)
	{
		std::cout << exp.what() << std::endl;
		travar_tela();
		return false;
	}
	return true;
}
void CntrIUDeletarConta::deletar(Identificador &identificador)
{
	Senha senha;
	ResultadoDeletarConta result;
	bool cons;
	cons = getData(&senha);
	if(cons == false)
		return;
	result = cntrILNDeletarConta->deletar(identificador, senha);

	// Fazer alguma coisa com result, informando se foi possivel excluir a conta ou nao
}