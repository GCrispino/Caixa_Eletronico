/*
 * A classe Usuário foi criada para que as informações sobre um usuário de uma conta fossem mais completas do que antes.
 * Esta classe é formada basicamente por alguns atributos de identificação de uma pessoa, e de métodos que servem, em sua maioria,
 * para validar os atributos.
 * */

#ifndef USUARIO_H
#define USUARIO_H

#include "Conta.h"
#include "stringDigitos.h"
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
	Conta *contausuario; //ponteiro de inteiros que guarda o número das contas registradas do usuário;
	int ncontas; //inteiro que guarda o número de contas do usuário.
	const static int QTDMAX;//quantidade máxima de contas de um usuário permitida.

public:
	Usuario(string nome = "",int idade = 0,string cpf = "00000000000",string telefone = "11111111",string endereco = "",string rg = "00000000");
	Usuario(const Usuario &);
	~Usuario();

	Usuario operator = (const Usuario &); //Sobrecarga do operador "=".
	bool operator == (const Usuario &); //Sobrecarga do operador "==".

	//funções get e set
	void setNome(const string &);

	void setIdade(const int) ;

	void setTelefone(const string &);

	void setEndereco(const string &);

	void setRG(const string &);

	void setCPF(const string &);
	
	string getCPF();
	
	int setConta(Conta &);
	
	int getNContas();
	
	const int getQTDMAX();

	//funções de validação para cada atributo
	int validaIdade(const int);
	string validaNome(const string &);
	string validaTelefone(const string &);
	string validaEndereco(const string &);
	string validaRG(const string &);
	string validaCPF(const string &);
	
	
	const Conta * buscaConta(const int); //faz uma busca de um numero de uma conta em um usuário
	inline void incrementaNContas(); //incrementa o atributo "ncontas".
	void imprimeContas() const;//imprime as contas pertencentes a um determinado usuário.


};

#endif // USUARIO_H
