/*
 * A classe Usuário foi criada para que as informações sobre um usuário de uma conta fossem mais completas do que antes.
 * Esta classe é formada basicamente por alguns atributos de identificação de uma pessoa, e de métodos que servem, em sua maioria,
 * para validar os atributos.
 * */

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

using namespace std;

class Usuario
{
	friend ostream &operator <<(ostream &, const Usuario &u);
private:
	string nome;
	int idade;
	string telefone;
	string endereco;
	string rg;
	string cpf;
	string *contas; //ponteiro de strings que guarda o número das contas registradas do usuário;
	int ncontas; //inteiro que guarda o número de contas do usuário.
	const static int QTDMAX;//quantidade máxima de contas de um usuário permitida.
	
public:
	Usuario(string nome = "",int idade = 0,string cpf = "00000000000",string telefone = "11111111",string endereco = "",string rg = "00000000", string contas = 0);
	Usuario(const Usuario &);
	~Usuario();
	
	Usuario operator = (const Usuario &); //Sobrecarga do operador "=".
	bool operator == (const Usuario &); //Sobrecarga do operador "==".
	
	//funções get e set
	void setNome(string nome){
		this->nome = Usuario::validaNome(nome);
	}
	
	void setIdade(int idade){
		this->idade = Usuario::validaIdade(idade);
	}
	
	void setTelefone(string telefone){
		this->telefone = Usuario::validaTelefone(telefone);
	}
	
	void setEndereco(string endereco){
		this->endereco = Usuario::validaEndereco(endereco);
	}
	
	void setRG(string rg){
		this->rg = Usuario::validaRG(rg);
	}
	
	void setCPF(string cpf){
		this->cpf = Usuario::validaCPF(cpf);
	}
	string getCPF(){
		return this->cpf;
	}
	
	//funções de validação para cada atributo
	int validaIdade(int);
	string validaNome(string &);
	string validaTelefone(string &);
	string validaEndereco(string &);
	string validaRG(string &);
	string validaCPF(string &);
	
	void info();
	void imprimeUsuario(); //imprime o nome e cpf do usuario usando a sobrecarga do operador "<<".
	
	//Função auxiliar utilizada para verifica se uma string dada é formada por números, para validar alguns atributos.
	bool stringDigitos(const string &);

	
};

#endif // USUARIO_H
