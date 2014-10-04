#ifndef CAIXA_ELETRONICO_H
#define CAIXA_ELETRONICO_H

using namespace std;

#include<iostream>
#include<vector>

#include "Data.h"

class Caixa_Eletronico
{
private:
	int nclientes; //Número de clientes do banco.
	float dinheiro; //Dinheiro disponível no caixa eletrônico.
	string modelo; //Modelo do caixa eletrônico.
	
	vector<string> conta; //Vector de strings que armazena as contas dos usuários.
	vector<float> saldo; //Vector de float que armazena na posição i o saldo do usuário localizado
						 //na posição i do vector 'conta'.]
	
	static Data data; //Data armazenada no caixa.
	
	const static int IDBANCO; //ID universal do banco ao qual todos os caixas pertencem.
	const static string NOMEBANCO;//Nome do banco cuja ID é representada pela variável 'IDBANCO'.
	
public:
	Caixa_Eletronico();
	Caixa_Eletronico(int nclientes,float dinheiro, string &modelo, vector<string> &conta, vector<float> &saldo, Data data);
	Caixa_Eletronico(Caixa_Eletronico &);
	~Caixa_Eletronico();
	
	void saque(string &conta); //realiza uma operação de saque no caixa eletrônico.
	void pagamento(string &conta); //realiza uma operação de pagamento no caixa eletrônico.
	inline void mostrarSaldo(string &conta) const; //imprime o saldo disponível na conta na tela.
	void info() const; //imprime as informações do caixa na tela.
	static void mostrarData();//imprime a data na tela.
};

#endif // CAIXA_ELETRONICO_H
