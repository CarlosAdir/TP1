#ifndef RESULTADOS_H_INCLUDED
#define RESULTADOS_H_INCLUDED

class Resultado
{

protected:
    int valor;

public:

    // Declarações de possíveis resultados.

    const static int SUCESSO = 0;
    const static int FALHA   = 1;

    void setValor(int valor){
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }
};


class ResultadoCadastro:public Resultado
{

};

class ResultadoAutenticacao:public Resultado
{

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
