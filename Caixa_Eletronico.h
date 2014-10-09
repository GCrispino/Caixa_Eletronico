#ifndef CAIXA_ELETRONICO_H
#define CAIXA_ELETRONICO_H

using namespace std;

#include<iostream>
#include<vector>

#include "Data.h"

class Caixa_Eletronico
{

friend bool operator == (const Caixa_Eletronico &c1, const Caixa_Eletronico &c2); //Sobrecarga do operador "==".
friend ostream &operator << (ostream &,const Caixa_Eletronico &);

private:
	float dinheiro; //Dinheiro disponível no caixa eletrônico.
	string modelo; //Modelo do caixa eletrônico.
	
	vector<int> conta; //Vector de strings que armazena as contas dos usuários.
	vector<float> saldo; //Vector de float que armazena na posição i o saldo do usuário localizado
						 //na posição i do vector 'conta'.]
	
	static int nclientes; //Número de clientes do banco.
	static Data data; //Data armazenada no caixa.
	
	const static int IDBANCO; //ID universal do banco ao qual todos os caixas pertencem.
	const static string NOMEBANCO;//Nome do banco cuja ID é representada pela variável 'IDBANCO'.
	
public:
	Caixa_Eletronico(float dinheiro = 0, string modelo = ""); //Construtor default que inicializa as variaveis dinheiro e modelo.
	Caixa_Eletronico(float dinheiro,string &modelo, int nclientes, Data data); //Construtor customizado para a modificação dos
	Caixa_Eletronico(Caixa_Eletronico &); //Construtor de cópia				  //atributos static nclientes e data.
	~Caixa_Eletronico();
	
	int setConta(int conta); //retorna -1 se o valor de entrada da conta ja existir ou for invalido.
	void setSaldo(int conta, float saldo);
	
	vector<int> getConta();
	
	void saque(int conta); //realiza uma operação de saque no caixa eletrônico.
	void pagamento(int conta); //realiza uma operação de pagamento no caixa eletrônico.
	inline void mostrarSaldo(int conta) const; //imprime o saldo disponível na conta na tela.
	void info() const; //imprime as informações do caixa na tela.
	static void mostrarData();//imprime a data na tela.
};

#endif // CAIXA_ELETRONICO_H
