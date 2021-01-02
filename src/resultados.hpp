#ifndef RESULTADOS_H_INCLUDED
#define RESULTADOS_H_INCLUDED

class Resultado
{

protected:
    int valor;

public:
    void setValor(int valor){
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }
};


class ResultadoCadastro:public Resultado
{
public:
    const static int EXISTE = 0;
    const static int ERRO_INESPERADO = 1;
    const static int CADASTRADO = 2;

};

class ResultadoAutenticacao:public Resultado
{
private:
    int valor;
public:
    const static int SENHA_VALIDA = 1;
    const static int SENHA_INVALIDA = 2;
    const static int NAO_CADASTRADO = 3;
};

class ResultadoAcomodacao:public Resultado
{


};

class ResultadoLogado:public Resultado
{


};


class ResultadoAdicionarAcomodacao:public Resultado{};
class ResultadoRemoverAcomodacao:public Resultado{};
class ResultadoAdicionarReserva:public Resultado{};
class ResultadoRemoverReserva:public Resultado{};

class ResultadoContaCorrente:public Resultado
{


};

class ResultadoCartaoCredito:public Resultado
{


};

class ResultadoAlterarSenha:public Resultado
{


};

class ResultadoAlterarNome:public Resultado
{


};

class ResultadoDeletarConta:public Resultado
{


};

#endif
