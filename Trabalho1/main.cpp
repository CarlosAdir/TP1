#include <iostream>
#include "testes.hpp"

int main()
{
	TUAgencia tuagencia = TUAgencia();
	TUBanco tubanco = TUBanco();
	TUCapacidadeAcomodacao tucapacidadeacomodacao = TUCapacidadeAcomodacao();

	tuagencia.run();
	tubanco.run();
	tucapacidadeacomodacao.run();

	return 0;
}