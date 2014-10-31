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
	Banco(Banco &b);
	virtual ~Banco();
	
	Banco operator = (const Banco &); //sobrecarga do operador "=".
	
	//Funções get e set
	int getNContas();
	
	int getNUsuarios();
	
	void setUsuario(Usuario u);
	Usuario* getUsuario();
	
	
	void info() const;
	
	void registrarUsuario(string &); //Registra um usuário novo no Caixa.
	int registrarConta(Usuario &); //Registra uma conta nova no usuário passado como parâmetro.
	int buscaCPF(string); //faz uma busca de um usuario através do seu CPF.
	void saque(int); //faz um saque pelo caixa do banco.
	void pagamento(int); //realiza uma operação de pagamento de uma conta para outra.
	void mostrarSaldo(int) const; //imprime o saldo disponível na conta na tela.
	void incrementaNContas();
	static void mostrarData();//imprime a data na tela.
};

#endif // BANCO_H
