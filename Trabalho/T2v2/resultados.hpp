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

// class ResultadoAutenticar:public Resultado
// {


// };

// class ResultadoAcomodacao:public Resultado
// {


// };

// class ResultadoReserva:public Resultado
// {


// };

#endif
