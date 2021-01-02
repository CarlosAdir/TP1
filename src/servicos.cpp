#include "servicos.hpp"

const char *CntrILNCadastro::ARCH_USUARIO = "data/usuarios.txt";
const char *CntrILNAutenticacao::ARCH_USUARIO = "data/usuarios.txt";

void CntrILNCadastro::verifica_consistencia() throw (consistencia_error){}
void CntrILNCadastro::libera(){}
void CntrILNAutenticacao::verifica_consistencia() throw (consistencia_error){}
void CntrILNAutenticacao::libera(){}
// void CntrILNAcomodacao::verifica_consistencia() throw (consistencia_error){}
// void CntrILNAcomodacao::libera(){}
// void CntrILNReserva::verifica_consistencia() throw (consistencia_error){}
// void CntrILNReserva::libera(){}
// void CntrILNCadastroAcomodacao::verifica_consistencia() throw (consistencia_error){}
// void CntrILNCadastroAcomodacao::libera(){}
// void CntrILNCartao::verifica_consistencia() throw (consistencia_error){}
// void CntrILNCartao::libera(){}
// void CntrILNContaCorrente::verifica_consistencia() throw (consistencia_error){}
// void CntrILNContaCorrente::libera(){}
// void CntrILNAlterarSenha::verifica_consistencia() throw (consistencia_error){}
// void CntrILNAlterarSenha::libera(){}
// void CntrILNAlterarNome::verifica_consistencia() throw (consistencia_error){}
// void CntrILNAlterarNome::libera(){}
// void CntrILNDeletarConta::verifica_consistencia() throw (consistencia_error){}
// void CntrILNDeletarConta::libera(){}





Usuario CntrILNCadastro::line_to_user(const std::string line)
{
    Usuario usuario;
    std::vector<std::string> input;
    input = split(line, ';');
    usuario.setIdentificador(Identificador(input[0]));
    usuario.setNome(Nome(input[1]));
    usuario.setSenha(Senha(input[2]));
    return usuario;
}

std::vector<Usuario> CntrILNCadastro::getUsuarios(const char *file_name)
{
    std::vector<Usuario> usuarios;
    Usuario usuario;
    std::ifstream entrada;
    
    std::string line;
    entrada.open(file_name);
    while(entrada.good())
    {
        std::getline(entrada, line);
        usuario = line_to_user(line);
        usuarios.insert(usuarios.begin(), usuario);
    }
    entrada.close();

    return usuarios;
}

bool CntrILNCadastro::existe_usuario(const Usuario &usuario, std::vector<Usuario> usuarios)
{
    std::vector<Usuario>::iterator it;
    for(it = usuarios.begin(); it != usuarios.end(); it++)
        if(usuario.getIdentificador() == it->getIdentificador())
            return true;
    return false;
}
ResultadoCadastro CntrILNCadastro::gravar_usuario(const Usuario &usuario, const char *file_name)
{
    ResultadoCadastro result;
    std::ofstream saida;
    saida.open(file_name, std::ios_base::app);
    if(! saida.is_open())
        result.setValor(ResultadoCadastro::ERRO_INESPERADO);
    else
    {
        saida << std::endl << usuario.getIdentificador() << ";" << usuario.getNome() << ";" << usuario.getSenha();
        saida.close();
        result.setValor(ResultadoCadastro::CADASTRADO);
    }
    return result;
}

ResultadoCadastro CntrILNCadastro::cadastrar(const Usuario &usuario) throw(std::runtime_error)
{
    ResultadoCadastro result;
    std::vector<Usuario> usuarios;
    usuarios = getUsuarios(ARCH_USUARIO);

    if(existe_usuario(usuario, usuarios))
    {
        result.setValor(ResultadoCadastro::EXISTE);
        std::cout << "O usuario ja existe!\n" << std::endl;
    }
    else
    {
        result = gravar_usuario(usuario, ARCH_USUARIO);
        std::cout << "Usuario cadastrado com sucesso!" << std::endl;
    }

    
    return result;
}










Usuario CntrILNAutenticacao::line_to_user(const std::string line)
{
    Usuario usuario;
    std::vector<std::string> input;
    input = split(line, ';');
    usuario.setIdentificador(Identificador(input[0]));
    usuario.setNome(Nome(input[1]));
    usuario.setSenha(Senha(input[2]));
    return usuario;
}

std::vector<Usuario> CntrILNAutenticacao::getUsuarios(const char *file_name)
{
    std::vector<Usuario> usuarios;
    Usuario usuario;
    std::ifstream entrada;
    
    std::string line;
    entrada.open(file_name);
    while(entrada.good())
    {
        std::getline(entrada, line);
        usuario = line_to_user(line);
        usuarios.insert(usuarios.begin(), usuario);
    }
    entrada.close();

    return usuarios;
}

ResultadoAutenticacao CntrILNAutenticacao::possivel_autenticar(Identificador identificador, Senha senha, std::vector<Usuario> usuarios)
{
    ResultadoAutenticacao result;
    std::vector<Usuario>::iterator it;
    for(it = usuarios.begin(); it != usuarios.end(); it++)
        if(identificador == it->getIdentificador())
        {
            if(senha == it->getSenha())
                result.setValor(ResultadoAutenticacao::SENHA_VALIDA);
            else
                result.setValor(ResultadoAutenticacao::SENHA_INVALIDA);
            return result;
        }
    result.setValor(ResultadoAutenticacao::NAO_CADASTRADO);
    return result;
}

ResultadoAutenticacao CntrILNAutenticacao::autenticar(const Identificador &identificador, const Senha &senha) throw(std::runtime_error)
{
    ResultadoAutenticacao result;
    std::vector<Usuario> usuarios;
    result.setValor(ResultadoCadastro::CADASTRADO);
    usuarios = getUsuarios(ARCH_USUARIO);
    result = possivel_autenticar(identificador, senha, usuarios);
    return result;
}