#ifndef SERVICOS_H_INCLUDED
#define SERVICOS_H_INCLUDED

#include "interfaces.hpp"
#include "dominios.hpp"
#include "entidades.hpp"
#include "input_data.hpp"
#include "resultados.hpp"

#include <fstream>
// #include <stdexcept>
// #include <iostream>
// #include <typeinfo>



class CntrILNCadastro:public ILNCadastro
{
private:
	const static char *ARCH_USUARIO;

	Usuario line_to_user(const std::string line);
	std::vector<Usuario> getUsuarios(const char *file_name);
	bool existe_usuario(const Usuario &user, std::vector<Usuario> usuarios);
	ResultadoCadastro gravar_usuario(const Usuario &user, const char *file_name);
public:
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoCadastro cadastrar(const Usuario&) throw(std::runtime_error);
};
class CntrILNAutenticacao:public ILNAutenticacao
{
private:
	const static char *ARCH_USUARIO;


	Usuario line_to_user(const std::string line);
	std::vector<Usuario> getUsuarios(const char *file_name);
	ResultadoAutenticacao possivel_autenticar(Identificador identificador, Senha senha, std::vector<Usuario> usuarios);

public:
	void verifica_consistencia() throw (consistencia_error);
	void libera();

	ResultadoAutenticacao autenticar(const Identificador&, const Senha&) throw(std::runtime_error);
};


#endif // STUBS_H_INCLUDED
