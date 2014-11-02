#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include "Data.h"
#include "Usuario.h"
using namespace std;

class Banco
{
	friend ostream &operator << (ostream &,const Banco &); //sobrecarga do operador "<<".
	
protected:
	int id;
	string nome;
	
	Usuario *userpadrao;
	int nusuarios;
	int ntotalcontas;
	
	const static Data dataAtual;
public:
	Banco(string nome = "",int id = 123456);
	Banco(const Banco &b);
	virtual ~Banco();
	
	Banco operator = (const Banco &); //sobrecarga do operador "=".
	
	//Funções get e set
	int getNContas();
	
	int getNUsuarios();
	
	void setUsuario(const Usuario &u);
	
	
	void registrarUsuario(const string &); //Registra um usuário novo no Caixa.
	int registrarConta(Usuario &); //Registra uma conta nova no usuário passado como parâmetro.
	const Conta * buscaConta(const int); //busca uma conta em todos os usuários.
	const Usuario * buscaCPF(const string &); //faz uma busca de um usuario através do seu CPF.
	void saque(const int); //faz um saque pelo caixa do banco.
	void pagamento(const int); //realiza uma operação de pagamento de uma conta para outra.
	void mostrarSaldo(const int) const; //imprime o saldo disponível na conta na tela.
	void incrementaNContas();
	static void mostrarData();//imprime a data na tela.
};

#endif // BANCO_H
