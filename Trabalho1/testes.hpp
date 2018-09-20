#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include "dominios.hpp"
#include "entidades.hpp"

class TU
{
protected:
    bool result;
public:
    void print_result(const std::string, const bool);
    const static bool VERBOSE = true;
    const static bool SUCESSO = true;
    const static bool FALHA   = false;
    TU();
    
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

};

#endif