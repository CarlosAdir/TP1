#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include "entidades.hpp"

class TU
{
private:
    int numerador;
    int denominador;
protected:
    bool result;
    void print_result(const std::string, const bool);
    void print_final_result(const bool);
    void set_denominador(int);
public:
    static bool VERBOSE;
    const static bool SUCESSO = true;
    const static bool FALHA   = false;
    TU();
	// void setUp();
	// void testarCenarioSucesso();
	// void testarCenarioFalha();
	// void tearDown();
	// bool run();  
};


class TUAgencia:public TU
{
private:
    Agencia *agencia;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string AGENCIA_VALIDA(){return "01234";}
    const static std::string AGENCIA_INVALIDA(){return "asd1a";}
public:
    bool run();
    TUAgencia();
};


class TUBanco:public TU
{
private:
    Banco *banco;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string BANCO_VALIDO(){return "012";}
    const static std::string BANCO_INVALIDO(){return "a1d";}
public:
    bool run();
    TUBanco();
};


class TUCapacidadeAcomodacao:public TU
{
private:
    CapacidadeAcomodacao *capacidadeacomodacao;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static int CAPACIDADE_VALIDA(){return 3;}
    const static int CAPACIDADE_INVALIDA(){return 120;}
public:
    bool run();
    TUCapacidadeAcomodacao();
};


class TUDiaria:public TU
{
private:
    Diaria *diaria;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static double DIARIA_VALIDA(){return 10.1;}
    const static double DIARIA_INVALIDA(){return 0.1;}
public:
    bool run();
    TUDiaria();
};


class TUData:public TU
{
private:
    Data *data;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static int DIA_VALIDO(){return 2;}
    const static int DIA_INVALIDO(){return 32;}
    const static std::string MES_VALIDO(){return "ago";}
    const static std::string MES_INVALIDO(){return "deu";}
    const static int ANO_VALIDO(){return 2001;}
    const static int ANO_INVALIDO(){return 1999;}
public:
    bool run();
    TUData();
};


class TUDataValidade:public TU
{
private:
    DataValidade *datavalidade;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static int MES_VALIDO(){return 1;}
    const static int MES_INVALIDO(){return 0;}
    const static int ANO_VALIDO(){return 95;}
    const static int ANO_INVALIDO(){return 100;}
public:
    bool run();
    TUDataValidade();
};


class TUEstado:public TU
{
private:
    Estado *estado;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string ESTADO_VALIDO(){return "TO";}
    const static std::string ESTADO_INVALIDO(){return "PT";}
public:
    bool run();
    TUEstado();
};


class TUIdentificador:public TU
{
private:
    Identificador *identificador;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string IDENTIFICADOR_VALIDO(){return "asdop";}
    const static std::string IDENTIFICADOR_INVALIDO(){return "PTkMe";}
public:
    bool run();
    TUIdentificador();
};


class TUNome:public TU
{
private:
    Nome *nome;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string NOME_VALIDO(){return "Joao";}
    const static std::string NOME_INVALIDO(){return "..123.";}
public:
    bool run();
    TUNome();
};


class TUNumeroCartaoCredito:public TU
{
private:
    NumeroCartaoCredito *numerocartaocredito;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string NUMEROCARTAOCREDITO_VALIDO(){return "7992739871312342";}
    const static std::string NUMEROCARTAOCREDITO_INVALIDO(){return "1234567890123451";}
public:
    bool run();
    TUNumeroCartaoCredito();
};


class TUNumeroContaCorrente:public TU
{
private:
    NumeroContaCorrente *numerocontacorrente;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string NUMEROCONTACORRENTE_VALIDO(){return "123456";}
    const static std::string NUMEROCONTACORRENTE_INVALIDO(){return "12345A";}
public:
    bool run();
    TUNumeroContaCorrente();
};


class TUSenha:public TU
{
private:
    Senha *senha;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string SENHA_VALIDA(){return "asDHk12#";}
    const static std::string SENHA_INVALIDA(){return "asDDk12#";}
public:
    bool run();
    TUSenha();
};


class TUTipoAcomodacao:public TU
{
private:
    TipoAcomodacao *tipoacomodacao;
    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

    const static std::string TIPOACOMODACAO_VALIDA(){return "Casa";}
    const static std::string TIPOACOMODACAO_INVALIDA(){return "Que";}
public:
    bool run();
    TUTipoAcomodacao();
};









class TUUsuario:public TU
{
private:
    Usuario *usuario;
    void setUp();
    void tearDown();
public:
    TUUsuario();
    bool run();
};


class TUAcomodacao:public TU
{
private:
    Acomodacao *acomodacao;
    void setUp();
    void tearDown();
public:
    TUAcomodacao();
    bool run();
};


class TUCartaoCredito:public TU
{
private:
    CartaoCredito *cartaocredito;
    void setUp();
    void tearDown();
public:
    TUCartaoCredito();
    bool run();
};


class TUContaCorrente:public TU
{
private:
    ContaCorrente *contacorrente;
    void setUp();
    void tearDown();
public:
    TUContaCorrente();
    bool run();
};


#endif