#include "stubs.hpp"
#include "entidades.hpp"


void StubILNCadastro::verifica_consistencia() throw (consistencia_error){}
void StubILNCadastro::libera(){}
void StubILNAutenticacao::verifica_consistencia() throw (consistencia_error){}
void StubILNAutenticacao::libera(){}
void StubILNAcomodacao::verifica_consistencia() throw (consistencia_error){}
void StubILNAcomodacao::libera(){}
void StubILNReserva::verifica_consistencia() throw (consistencia_error){}
void StubILNReserva::libera(){}
void StubILNCadastroAcomodacao::verifica_consistencia() throw (consistencia_error){}
void StubILNCadastroAcomodacao::libera(){}
void StubILNCartao::verifica_consistencia() throw (consistencia_error){}
void StubILNCartao::libera(){}
void StubILNContaCorrente::verifica_consistencia() throw (consistencia_error){}
void StubILNContaCorrente::libera(){}
void StubILNAlterarSenha::verifica_consistencia() throw (consistencia_error){}
void StubILNAlterarSenha::libera(){}
void StubILNAlterarNome::verifica_consistencia() throw (consistencia_error){}
void StubILNAlterarNome::libera(){}
void StubILNDeletarConta::verifica_consistencia() throw (consistencia_error){}
void StubILNDeletarConta::libera(){}


ResultadoCadastro StubILNCadastro::cadastrar(const Usuario &user) throw(std::runtime_error)
{
    ResultadoCadastro resultado;
    const static char SUCESSO = 's';
    const static char FALHA = 'f';
    char c;

    Nome name;
    Senha pass;
    Identificador id;

    name = user.getNome();
    pass = user.getSenha();
    id = user.getIdentificador();

    limpar_tela();
    std::cout << "Aqui estamos dentro da classe de servico para Cadastro, da StubILNCadastro" << std::endl;
    std::cout << "Os valores passados atraves da interface foram:" << std::endl;
    std::cout << "Nome   = " << name.get() << std::endl ;
    std::cout << "Senha  = " << pass.get()     << std::endl ;
    std::cout << "   ID  = " << id.get()     << std::endl ;   

    std::cout << "\n" << std::endl;
    std::cout << "Por enquanto ainda nao foi implementada as funcoes que relacionam o banco de dados" << std::endl;
    std::cout << "Contudo, a funcao deve retornar se o cadastro foi realizado com sucesso ou nao" << std::endl << std::endl;
    std::cout << "Ai vem a sua escolha:" << std::endl;
    std::cout << "s) Retornar SUCESSO, indicando que o usuario foi cadastrado" << std::endl;
    std::cout << "f) Retornar FALHA, indicando que o identificador ja existe" << std::endl;
    do
    {
        c = getch();
    }while(c != SUCESSO && c != FALHA);
    
    if(c == SUCESSO)
    {
        resultado.setValor(ResultadoCadastro::SUCESSO);
        std::cout << "Cadastro realizado com sucesso!" << std::endl;
    }
    else
    {
        resultado.setValor(ResultadoCadastro::FALHA);
        std::cout << "O usuario ja existe!" << std::endl;
    }
    travar_tela();
    return resultado;
}



ResultadoAutenticacao StubILNAutenticacao::autenticar(const Identificador &identificador, const Senha &senha) throw(std::runtime_error)
{
	// Apresentar dados recebidos.
 
    ResultadoAutenticacao resultado;
    const static char SUCESSO = 's';
    const static char FALHA = 'f';
    char c;

    limpar_tela();
    std::cout << "Aqui estamos dentro da classe de servico para Autenticacao, da StubILNAutenticacao" << std::endl;
    std::cout << "Os valores passados atraves da interface foram:" << std::endl;
    std::cout << "Identificador = " << identificador.get() << std::endl ;
    std::cout << "Senha         = " << senha.get()     << std::endl ;
    
    std::cout << "\n" << std::endl;
    std::cout << "Por enquanto ainda nao foi implementada as funcoes que relacionam o banco de dados" << std::endl;
    std::cout << "Contudo, a funcao deve retornar se o cadastro foi realizado com sucesso ou nao" << std::endl << std::endl;
    std::cout << "Ai vem a sua escolha:" << std::endl;
    std::cout << "s) Retornar SUCESSO, indicando que o usuario foi autenticado" << std::endl;
    std::cout << "f) Retornar FALHA, indicando que nao foi possivel realizar a autenticacao" << std::endl;

    do
    {
    	c = getch();
    }while(c != SUCESSO && c != FALHA);
    if(c == SUCESSO)
    {
	    resultado.setValor(ResultadoAutenticacao::SUCESSO);
	    std::cout << "Autenticacao realizada com sucesso!" << std::endl;
    }
	else
	{
		resultado.setValor(ResultadoAutenticacao::FALHA);
		std::cout << "Nao foi possivel realizar a autenticacao!" << std::endl;
	}
    travar_tela();
    return resultado;
}


std::vector<Acomodacao> StubILNAcomodacao::acomodacoes_cabiveis(Data &inicio, Data &termino, CapacidadeAcomodacao &cap, Nome &cidade, Estado &estado)
{
    std::vector<Acomodacao> acomodacoes;
    // Aqui eh o codigo de pegar as acomodacoes no banco de dados e retornar apenas os que fazem sentido
    std::cout << "\n\n\n" << std::endl;
    std::cout << "Dentro de StubILNAcomodacao::acomodacoes_cabiveis" << std::endl;
    travar_tela();
    return acomodacoes;
}


bool StubILNReserva::existe_cartaocredito(Identificador &identificador)
{
    return true;
}
ResultadoAdicionarReserva StubILNReserva::adicionar_reserva(Identificador &identificador, Identificador &acomod_identificador, Data &inicio, Data &termino)
{
    ResultadoAdicionarReserva result;

    return result;
}
ResultadoRemoverReserva StubILNReserva::remover_reserva(Identificador &identificador, Identificador &acomod_identificador)
{
    ResultadoRemoverReserva result;

    return result;
}

bool StubILNCadastroAcomodacao::existe_contacorrente(Identificador &identificador)
{
    return true;
}
ResultadoAdicionarAcomodacao StubILNCadastroAcomodacao::adicionar_acomodacao(Identificador &identificador, Acomodacao &acomodacao)
{
    ResultadoAdicionarAcomodacao result;

    return result;
}
ResultadoRemoverAcomodacao StubILNCadastroAcomodacao::remover_acomodacao(Identificador &identificador, Identificador &acomod_identificador)
{
    ResultadoRemoverAcomodacao result;

    return result;
}






ResultadoCartaoCredito StubILNCartao::cartao_credito(Identificador &identificador, CartaoCredito &novo)
{
    ResultadoCartaoCredito result;

    std::cout << "\n\n\n" << std::endl;
    std::cout << "Dentro de StubILNCartao::cartao_credito" << std::endl;
    travar_tela();

    return result;

}

ResultadoContaCorrente StubILNContaCorrente::conta_corrente(Identificador &identificador, ContaCorrente &nova)
{
    ResultadoContaCorrente result;

    std::cout << "\n\n\n" << std::endl;
    std::cout << "Dentro de StubILNContaCorrente::conta_corrente" << std::endl;
    travar_tela();

    return result;
}



ResultadoAlterarSenha StubILNAlterarSenha::alterar_senha(Identificador &identificador, Senha &velha, Senha &nova)
{
    ResultadoAlterarSenha result;

    std::cout << "\n\n\n" << std::endl;
    std::cout << "Dentro de StubILNAlterarSenha::alterar_senha" << std::endl;
    travar_tela();

    return result;
}

ResultadoAlterarNome StubILNAlterarNome::alterar_nome(Identificador &identificador, Nome &novo, Senha &senha)
{
    ResultadoAlterarNome result;

    std::cout << "\n\n\n" << std::endl;
    std::cout << "Dentro de StubILNAlterarSenha::alterar_senha" << std::endl;
    travar_tela();

    return result;

}

ResultadoDeletarConta StubILNDeletarConta::deletar(Identificador &identificador, Senha &senha)
{
    ResultadoDeletarConta result;

    std::cout << "\n\n\n" << std::endl;
    std::cout << "Dentro de StubILNDeletarConta::deletar" << std::endl;
    travar_tela();

    return result;
}