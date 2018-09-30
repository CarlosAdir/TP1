#include "testes.hpp"

using namespace std;


// Classe base de teste de unidades

TU::TU()
{
    result = true;
    numerador = 1;
    denominador = 4;
}
void TU::print_result(const std::string texto, const bool result)
{
    if(numerador <= denominador)
        std::cout << "[" << numerador << "/" << denominador << "] - ";
    std::cout << (result == false ? "\033[1;31m" : "\033[1;32m");
    std::cout << texto;
    std::cout << (result == false ? "\033[0m" : "\033[0m") << std::endl;
    numerador += 1;
}

void TU::setUp()
{}
void TU::testarCenarioSucesso()
{}
void TU::testarCenarioFalha()
{}
void TU::tearDown()
{}
bool TU::run()
{
	if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}





















// Classe derivada de teste de unidade da Agencia

void TUAgencia::setUp()
{
    agencia = new Agencia();
    if(VERBOSE)
        print_result("TUAgencia::setUp", result);
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
        print_result("TUAgencia::testarCenarioSucesso", result);
}
void TUAgencia::testarCenarioFalha(){
    try
    {
        agencia->set(AGENCIA_INVALIDA());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUAgencia::testarCenarioFalha", result);
}

void TUAgencia::tearDown()
{
    delete agencia;
    if(VERBOSE)
        print_result("TUAgencia::tearDown", result);
}
bool TUAgencia::run()
{
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
        print_result("TUBanco::setUp", result);
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
        print_result("TUBanco::testarCenarioSucesso", result);
}
void TUBanco::testarCenarioFalha(){
    try
    {
        banco->set(BANCO_INVALIDO());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUBanco::testarCenarioFalha", result);
}

void TUBanco::tearDown()
{
    delete banco;
    if(VERBOSE)
        print_result("TUBanco::tearDown", result);
}


bool TUBanco::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}

















// Classe derivada de teste de unidade do Capacidade de Acomodacao

void TUCapacidadeAcomodacao::setUp()
{
    capacidadeacomodacao = new CapacidadeAcomodacao();
    if(VERBOSE)
        print_result("TUCapacidadeAcomodacao::setUp", result);
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
        print_result("TUCapacidadeAcomodacao::testarCenarioSucesso", result);
}
void TUCapacidadeAcomodacao::testarCenarioFalha(){
    try
    {
        capacidadeacomodacao->set(CAPACIDADE_INVALIDA());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUCapacidadeAcomodacao::testarCenarioFalha", result);
}

void TUCapacidadeAcomodacao::tearDown()
{
    delete capacidadeacomodacao;
    if(VERBOSE)
        print_result("TUCapacidadeAcomodacao::tearDown", result);
}


bool TUCapacidadeAcomodacao::run()
{
	if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}




















// Classe derivada de teste de unidade do Diaria

void TUDiaria::setUp()
{
    diaria = new Diaria();
    if(VERBOSE)
        print_result("TUDiaria::setUp", result);
}
void TUDiaria::testarCenarioSucesso(){
    try
    {
        diaria->set(DIARIA_VALIDA());
        if (diaria->get() != DIARIA_VALIDA())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUDiaria::testarCenarioSucesso", result);
}
void TUDiaria::testarCenarioFalha(){
    try
    {
        diaria->set(DIARIA_INVALIDA());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUDiaria::testarCenarioFalha", result);
}

void TUDiaria::tearDown()
{
    delete diaria;
    if(VERBOSE)
        print_result("TUDiaria::tearDown", result);
}


bool TUDiaria::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}








// Classe derivada de teste de unidade do Data

void TUData::setUp()
{
    data = new Data();
    if(VERBOSE)
        print_result("TUData::setUp", result);
}
void TUData::testarCenarioSucesso(){
    const int dia = 13, ano = 2001;
    const std::string mes = "ago"; 

    try
    {
        data->set(dia, mes, ano);
        if (data->getDia() != dia || data->getMes() != mes || data->getAno() != ano)
        {
            result = FALHA;
        }
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUData::testarCenarioSucesso", result);
}
void TUData::testarCenarioFalha(){
    const int dia = 13, ano = 1999;
    const std::string mes = "DBZ";
    try
    {
        data->set(dia, mes, ano);
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUData::testarCenarioFalha", result);
}

void TUData::tearDown()
{
    delete data;
    if(VERBOSE)
        print_result("TUData::tearDown", result);
}


bool TUData::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}















// Classe derivada de teste de unidade do Data Validade

void TUDataValidade::setUp()
{
    datavalidade = new DataValidade();
    if(VERBOSE)
        print_result("TUDataValidade::setUp", result);
}
void TUDataValidade::testarCenarioSucesso(){
    const int mes = 4, ano = 00;
    try
    {
        datavalidade->set(mes, ano);
        if (datavalidade->getMes() != mes || datavalidade->getAno() != ano)
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUDataValidade::testarCenarioSucesso", result);
}
void TUDataValidade::testarCenarioFalha(){
    const int mes = 13, ano = 2000;
    try
    {
        datavalidade->set(mes, ano);
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUDataValidade::testarCenarioFalha", result);
}

void TUDataValidade::tearDown()
{
    delete datavalidade;
    if(VERBOSE)
        print_result("TUDataValidade::tearDown", result);
}


bool TUDataValidade::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}















// Classe derivada de teste de unidade do Estado

void TUEstado::setUp()
{
    estado = new Estado();
    if(VERBOSE)
        print_result("TUEstado::setUp", result);
}
void TUEstado::testarCenarioSucesso(){
    try
    {
        estado->set(ESTADO_VALIDO());
        if (estado->get() != ESTADO_VALIDO())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUEstado::testarCenarioSucesso", result);
}
void TUEstado::testarCenarioFalha(){
    try
    {
        estado->set(ESTADO_INVALIDO());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUEstado::testarCenarioFalha", result);
}

void TUEstado::tearDown()
{
    delete estado;
    if(VERBOSE)
        print_result("TUEstado::tearDown", result);
}


bool TUEstado::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}



























// Classe derivada de teste de unidade de Identificador

void TUIdentificador::setUp()
{
    identificador = new Identificador();
    if(VERBOSE)
        print_result("TUIdentificador::setUp", result);
}
void TUIdentificador::testarCenarioSucesso(){
    try
    {
        identificador->set(IDENTIFICADOR_VALIDO());
        if (identificador->get() != IDENTIFICADOR_VALIDO())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUIdentificador::testarCenarioSucesso", result);
}
void TUIdentificador::testarCenarioFalha(){
    try
    {
        identificador->set(IDENTIFICADOR_INVALIDO());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUIdentificador::testarCenarioFalha", result);
}

void TUIdentificador::tearDown()
{
    delete identificador;
    if(VERBOSE)
        print_result("TUIdentificador::tearDown", result);
}


bool TUIdentificador::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}
































// Classe derivada de teste de unidade do Identificador

void TUNome::setUp()
{
    nome = new Nome();
    if(VERBOSE)
        print_result("TUNome::setUp", result);
}
void TUNome::testarCenarioSucesso(){
    try
    {
        nome->set(NOME_VALIDO());
        if (nome->get() != NOME_VALIDO())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUNome::testarCenarioSucesso", result);
}
void TUNome::testarCenarioFalha(){
    try
    {
        nome->set(NOME_INVALIDO());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUNome::testarCenarioFalha", result);
}

void TUNome::tearDown()
{
    delete nome;
    if(VERBOSE)
        print_result("TUNome::tearDown", result);
}


bool TUNome::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}













// Classe derivada de teste de unidade de Identificador

void TUNumeroCartaoCredito::setUp()
{
    numerocartaocredito = new NumeroCartaoCredito();
    if(VERBOSE)
        print_result("TUNumeroCartaoCredito::setUp", result);
}
void TUNumeroCartaoCredito::testarCenarioSucesso(){
    try
    {
        numerocartaocredito->set(NUMEROCARTAOCREDITO_VALIDO());
        if (numerocartaocredito->get() != NUMEROCARTAOCREDITO_VALIDO())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUNumeroCartaoCredito::testarCenarioSucesso", result);
}
void TUNumeroCartaoCredito::testarCenarioFalha(){
    try
    {
        numerocartaocredito->set(NUMEROCARTAOCREDITO_INVALIDO());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUNumeroCartaoCredito::testarCenarioFalha", result);
}

void TUNumeroCartaoCredito::tearDown()
{
    delete numerocartaocredito;
    if(VERBOSE)
        print_result("TUNumeroCartaoCredito::tearDown", result);
}


bool TUNumeroCartaoCredito::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}
















// Classe derivada de teste de unidade de Identificador

void TUNumeroContaCorrente::setUp()
{
    numerocontacorrente = new NumeroContaCorrente();
    if(VERBOSE)
        print_result("TUNumeroContaCorrente::setUp", result);
}
void TUNumeroContaCorrente::testarCenarioSucesso(){
    try
    {
        numerocontacorrente->set(NUMEROCONTACORRENTE_VALIDO());
        if (numerocontacorrente->get() != NUMEROCONTACORRENTE_VALIDO())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUNumeroContaCorrente::testarCenarioSucesso", result);
}
void TUNumeroContaCorrente::testarCenarioFalha(){
    try
    {
        numerocontacorrente->set(NUMEROCONTACORRENTE_INVALIDO());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUNumeroCartaoCredito::testarCenarioFalha", result);
}

void TUNumeroContaCorrente::tearDown()
{
    delete numerocontacorrente;
    if(VERBOSE)
        print_result("TUNumeroContaCorrente::tearDown", result);
}


bool TUNumeroContaCorrente::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}










// Classe derivada de teste de unidade de Identificador

void TUSenha::setUp()
{
    senha = new Senha();
    if(VERBOSE)
        print_result("TUSenha::setUp", result);
}
void TUSenha::testarCenarioSucesso(){
    try
    {
        senha->set(SENHA_VALIDA());
        if (senha->get() != SENHA_VALIDA())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUSenha::testarCenarioSucesso", result);
}
void TUSenha::testarCenarioFalha(){
    try
    {
        senha->set(SENHA_INVALIDA());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUNumeroCartaoCredito::testarCenarioFalha", result);
}

void TUSenha::tearDown()
{
    delete senha;
    if(VERBOSE)
        print_result("TUSenha::tearDown", result);
}


bool TUSenha::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}















// Classe derivada de teste de unidade de Identificador

void TUTipoAcomodacao::setUp()
{
    tipoacomodacao = new TipoAcomodacao();
    if(VERBOSE)
        print_result("TUTipoAcomodacao::setUp", result);
}
void TUTipoAcomodacao::testarCenarioSucesso(){
    try
    {
        tipoacomodacao->set(TIPOACOMODACAO_VALIDA());
        if (tipoacomodacao->get() != TIPOACOMODACAO_VALIDA())
            result = FALHA;
    }
    catch(std::invalid_argument excecao)
    {
        result = FALHA;
    }
    if(VERBOSE)
        print_result("TUTipoAcomodacao::testarCenarioSucesso", result);
}
void TUTipoAcomodacao::testarCenarioFalha(){
    try
    {
        tipoacomodacao->set(TIPOACOMODACAO_INVALIDA());
        result = FALHA;
    }
    catch(std::invalid_argument excecao){}
    if(VERBOSE)
        print_result("TUNumeroCartaoCredito::testarCenarioFalha", result);
}

void TUTipoAcomodacao::tearDown()
{
    delete tipoacomodacao;
    if(VERBOSE)
        print_result("TUTipoAcomodacao::tearDown", result);
}


bool TUTipoAcomodacao::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}

















































// Classe derivada de teste de unidade de Identificador
TUUsuario::TUUsuario()
{
    denominador = 2;
}
void TUUsuario::setUp()
{
    usuario = new Usuario();
    if(VERBOSE)
        print_result("TUUsuario::setUp", result);
}
void TUUsuario::tearDown()
{
    delete usuario;
    if(VERBOSE)
        print_result("TUUsuario::tearDown", result);
}
bool TUUsuario::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}


// Classe derivada de teste de unidade de Identificador

TUAcomodacao::TUAcomodacao()
{
    denominador = 2;
}
void TUAcomodacao::setUp()
{
    acomodacao = new Acomodacao();
    if(VERBOSE)
        print_result("TUAcomodacao::setUp", result);
}
void TUAcomodacao::tearDown()
{
    delete acomodacao;
    if(VERBOSE)
        print_result("TUAcomodacao::tearDown", result);
}
bool TUAcomodacao::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}



// Classe derivada de teste de unidade de Identificador

TUCartaoCredito::TUCartaoCredito()
{
    denominador = 2;
}
void TUCartaoCredito::setUp()
{
    cartaocredito = new CartaoCredito();
    if(VERBOSE)
        print_result("TUCartaoCredito::setUp", result);
}
void TUCartaoCredito::tearDown()
{
    delete cartaocredito;
    if(VERBOSE)
        print_result("TUCartaoCredito::tearDown", result);
}
bool TUCartaoCredito::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}




// Classe derivada de teste de unidade de Identificador

TUContaCorrente::TUContaCorrente()
{
    denominador = 2;
}
void TUContaCorrente::setUp()
{
    contacorrente = new ContaCorrente();
    if(VERBOSE)
        print_result("TUContaCorrente::setUp", result);
}
void TUContaCorrente::tearDown()
{
    delete contacorrente;
    if(VERBOSE)
        print_result("TUContaCorrente::tearDown", result);
}
bool TUContaCorrente::run()
{
    if(result == SUCESSO) setUp();
    if(result == SUCESSO) testarCenarioSucesso();
    if(result == SUCESSO) testarCenarioFalha();
    if(result == SUCESSO) tearDown();
    print_result(result == SUCESSO ? "\nSUCESSO\n" : "\nFALHA\n" , result);
    std::cout << std::endl;
    return result;
}