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
	void setNome(string nome) {
		this->nome = Usuario::validaNome(nome);
	}

	void setIdade(int idade) {
		this->idade = Usuario::validaIdade(idade);
	}

	void setTelefone(string telefone) {
		this->telefone = Usuario::validaTelefone(telefone);
	}

	void setEndereco(string endereco) {
		this->endereco = Usuario::validaEndereco(endereco);
	}

	void setRG(string rg) {
		this->rg = Usuario::validaRG(rg);
	}

	void setCPF(string cpf) {
		this->cpf = Usuario::validaCPF(cpf);
	}
	string getCPF() {
		return this->cpf;
	}
	int setConta(Conta);
	void setContas(Conta);
	Conta * getContas() {
		return this->contausuario;
	}
	int getNContas() {
		return this->ncontas;
	}
	const int getQTDMAX() {
		return this->QTDMAX;
	}

	//funções de validação para cada atributo
	int validaIdade(int);
	string validaNome(string &);
	string validaTelefone(string &);
	string validaEndereco(string &);
	string validaRG(string &);
	string validaCPF(string &);

	int buscaConta(int); //faz uma busca de um numero de uma conta em um usuário
	void info(); //Mostra as informações gerais de um usuário.
	void incrementaNContas(); //incrementa o atributo "ncontas".
	void imprimeContas();//imprime as contas pertencentes a um determinado usuário.


};

#endif // USUARIO_H
