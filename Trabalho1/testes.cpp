#include "testes.hpp"

using namespace std;


// Classe base de teste de unidades

TU::TU()
{
    result = true;
}
void TU::print_result(const std::string texto, const bool result)
{
    std::cout << (result == false ? "\033[1;31m" : "\033[1;32m");
    std::cout << texto;
    std::cout << (result == false ? "\033[0m" : "\033[0m") << std::endl;
}









// Classe derivada de teste de unidade da Agencia

void TUAgencia::setUp()
{
    agencia = new Agencia();
    if(VERBOSE)
    {
        cout << "[1/4] - ";
        print_result("TUAgencia::setUp", result);
    }
}
void TUAgencia::testarCenarioSucesso(){
    try
    {
        agencia->set(AGENCIA_VALIDA());
        if (agencia->get() != AGENCIA_VALIDA())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
    {
        cout << "[2/4] - ";
        print_result("TUAgencia::testarCenarioSucesso", result);
    }
}
void TUAgencia::testarCenarioFalha(){
    try
    {
        agencia->set(AGENCIA_INVALIDA());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
    {
        cout << "[3/4] - ";
        print_result("TUAgencia::testarCenarioFalha", result);
    }
}

void TUAgencia::tearDown()
{
    delete agencia;
    if(VERBOSE)
    {
        cout << "[4/4] - ";
        print_result("TUAgencia::tearDown", result);
    }
}


bool TUAgencia::run()
{
	std::cout << "***** Teste da Agencia *****" << std::endl;
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}
















// Classe derivada de teste de unidade do Banco

void TUBanco::setUp()
{
    banco = new Banco();
    if(VERBOSE)
    {
        cout << "[1/4] - ";
        print_result("TUBanco::setUp", result);
    }
}
void TUBanco::testarCenarioSucesso(){
    try
    {
        banco->set(BANCO_VALIDO());
        if (banco->get() != BANCO_VALIDO())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
    {
        cout << "[2/4] - ";
        print_result("TUBanco::testarCenarioSucesso", result);
    }
}
void TUBanco::testarCenarioFalha(){
    try
    {
        banco->set(BANCO_INVALIDO());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
    {
        cout << "[3/4] - ";
        print_result("TUBanco::testarCenarioFalha", result);
    }
}

void TUBanco::tearDown()
{
    delete banco;
    if(VERBOSE)
    {
        cout << "[4/4] - ";
        print_result("TUBanco::tearDown", result);
    }
}


bool TUBanco::run()
{
	std::cout << "***** Teste do Banco *****" << std::endl;
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}









// Classe derivada de teste de unidade do Banco

void TUCapacidadeAcomodacao::setUp()
{
    capacidadeacomodacao = new CapacidadeAcomodacao();
    if(VERBOSE)
    {
        cout << "[1/4] - ";
        print_result("TUCapacidadeAcomodacao::setUp", result);
    }
}
void TUCapacidadeAcomodacao::testarCenarioSucesso(){
    try
    {
        capacidadeacomodacao->set(CAPACIDADE_VALIDA());
        if (capacidadeacomodacao->get() != CAPACIDADE_VALIDA())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
    {
        cout << "[2/4] - ";
        print_result("TUCapacidadeAcomodacao::testarCenarioSucesso", result);
    }
}
void TUCapacidadeAcomodacao::testarCenarioFalha(){
    try
    {
        capacidadeacomodacao->set(CAPACIDADE_INVALIDA());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
    {
        cout << "[3/4] - ";
        print_result("TUCapacidadeAcomodacao::testarCenarioFalha", result);
    }
}

void TUCapacidadeAcomodacao::tearDown()
{
    delete capacidadeacomodacao;
    if(VERBOSE)
    {
        cout << "[4/4] - ";
        print_result("TUCapacidadeAcomodacao::tearDown", result);
    }
}


bool TUCapacidadeAcomodacao::run()
{
	std::cout << "***** Teste da Capacidade de Acomodacao *****" << std::endl;
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}