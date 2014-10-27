#ifndef CAIXA_ELETRONICO_H
#define CAIXA_ELETRONICO_H

using namespace std;

#include<iostream>

#include "Banco.h"

class Caixa_Eletronico: public Banco
{
friend ostream &operator << (ostream &,const Caixa_Eletronico &); //sobrecarga do operador "<<".

private:
	float dinheiro; //Dinheiro disponível no caixa eletrônico.
	string modelo; //Modelo do caixa eletrônico.
	
	//static Usuario *u; //Ponteiro que representa o array de contas dos usuários.
	//static int ncontas;
	//static int nusuarios;
	//static int ntotalcontas;
	//static vector<float> saldo; //Vector de float que armazena na posição i o saldo do usuário localizado
						 //na posição i do vector 'conta'.]
//static int nclientes; //Número de clientes do banco.
	//static Data d; //Data armazenada no caixa.
	
	//const static int IDBANCO; //ID universal do banco ao qual todos os caixas pertencem.
	//const static string NOMEBANCO;//Nome do banco cuja ID é representada pela variável 'IDBANCO'.
	
public:
	Caixa_Eletronico(float dinheiro = 0, string modelo = ""); //Construtor default que inicializa as variaveis dinheiro e modelo.
	Caixa_Eletronico(float dinheiro,string *modelo, Data data); //Construtor customizado para a modificação dos
	Caixa_Eletronico(Caixa_Eletronico &); //Construtor de cópia				  //atributos static nclientes e data.
	~Caixa_Eletronico();
	
	bool operator == (const Caixa_Eletronico &c1); //Sobrecarga do operador "==".
	Caixa_Eletronico operator = (const Caixa_Eletronico &c); //Sobrecarga do operador "=".
	
/*	int getNContas();
	
	int getNUsuarios(); //Funções copiadas para a classe Banco
	
	void setUsuario(Usuario u);
	Usuario* getUsuario();*/
	
	//void registrarUsuario(string &); //Registra um usuário novo no Caixa.
	//int registrarConta(Usuario &); //Registra uma conta nova no usuário passado como parâmetro.
	void saque(int); //realiza uma operação de saque no caixa eletrônico.
	//void pagamento(int); //realiza uma operação de pagamento no caixa eletrônico.
	//void mostrarSaldo(int conta) const; //imprime o saldo disponível na conta na tela.
	//int buscaCPF(string); //faz uma busca de um usuario através do seu CPF.
	void info() const; //imprime as informações do caixa na tela.
	//static void mostrarData();//imprime a data na tela.
	//static void incrementaNContas();
};

#endif // CAIXA_ELETRONICO_H
