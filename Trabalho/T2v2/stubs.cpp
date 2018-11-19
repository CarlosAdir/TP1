#include "stubs.hpp"
#include "dominios.hpp"


void StubILNCadastro::verifica_consistencia() throw (consistencia_error)
{

}
void StubILNAutenticacao::verifica_consistencia() throw (consistencia_error)
{
    
}
void StubILNAcomodacao::verifica_consistencia() throw (consistencia_error)
{
    
}
void StubILNReserva::verifica_consistencia() throw (consistencia_error)
{
    
}
void StubILNCadastroAcomodacao::verifica_consistencia() throw (consistencia_error)
{
    
}
void StubILNCartao::verifica_consistencia() throw (consistencia_error)
{
    
}
void StubILNContaCorrente::verifica_consistencia() throw (consistencia_error)
{
    
}
void StubILNAlterarSenha::verifica_consistencia() throw (consistencia_error)
{
    
}
void StubILNAlterarNome::verifica_consistencia() throw (consistencia_error)
{
    
}
void StubILNDeletarConta::verifica_consistencia() throw (consistencia_error)
{
    
}



// //Definições de constantes.

// // const std::string StubLNAutenticacao::TRIGGER_FALHA;
// // const std::string StubLNAutenticacao::TRIGGER_ERRO_SISTEMA;

// // EXEMPLO
// // --------------------------------------------------------

// // Definições de método da classe stub do controlador da lógica de negócio de autenticação.

// ResultadoAutenticacao StubLNAutenticacao::autenticar(const Identificador &identificador, const Senha &senha) throw(consistencia_error)
// {

//     // Apresentar dados recebidos.

//     std::cout << std::endl << "StubLNAutenticacao::autenticar" << std::endl ;

//     std::cout << "Identificador = " << identificador.get() << std::endl ;
//     std::cout << "Senha         = " << senha.get()     << std::endl ;

//     ResultadoAutenticacao resultado;

    
//     resultado.setIdentificador(identificador);
//     resultado.setValor(ResultadoAutenticacao::SUCESSO);
    

//     return resultado;
// }



// int StubLNUsuario::cadastrar(const Usuario &user) throw(consistencia_error)
// {
// 	std::cout << "Dentro de cadastrar no stub: Sucesso!" << std::endl;
//     return 1;
// 	// std::cout << user.getNome();
// }
// // int StubLNUsuario::editar(const Identificador &id, const Usuario & user) throw(consistencia_error)
// // {

// // }
// int StubLNUsuario::deletar(const Identificador &id) throw(consistencia_error)
// {
//     return 1;
// }



// void StubLNAcomodacao::acomodar() throw(consistencia_error)
// {
// }



// void StubLNReserva::reservar() throw(consistencia_error)
// {
// }