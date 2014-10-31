/*
	X Operator =
    X Alocação dinâmica - se houver vazamento de memória a classe toda é desconsiderada
    X Usar o destrutor
    X Construtor de cópia
    X Operator << friend
    X Um const static 

 * A classe "conta" tem como objetivo guardar atributos e operaçãoes referentes a uma conta de um banco.
 * A sua estrutura é composta por dados comuns de uma conta de banco, contendo dados como número e senha da conta, e operações
 * como mostrar as informações da conta e mostrar o histórico de operações.
*/

#include <iostream>

using namespace std;

#ifndef CONTA_H
#define CONTA_H

class Conta
{
	
	friend ostream &operator << (ostream &,const Conta &); //sobrecarga do operador "<<".
	
private:
	int numero;  //Número da conta.
	string senha;   //Senha da conta
	float saldo; //Saldo da conta
	float *historico[2]; //indica atraves de um vetor de ponteiros as ultimas operações feitas e quanto dinheiro foi movimentado...
						//...onde a posição zero indica o dinheiro movimentado nos últimos saques...
						//...e a posição 1 indica o dinheiro movimentado nos últimos pagamentos.
	int noperacoes[2]; //variável utilizada na alocação dinâmica feita pelo array de ponteiros 'historico'.
	const static float TAXA; //variável que guarda a taxa fixa aplicada à qualquer pagamento de uma conta.
public:
	Conta(int numero = 0, string senha = "123456", float saldo = 0); //Construtor default.
	Conta(Conta &); //Construtor de cópia
	~Conta(); //Destrutor
	
	Conta operator = (const Conta &);//Sobrecarga do operador "=" para atribuição.
	bool operator == (const Conta &);
	
	float getSaldo(){
		return this->saldo;
	}
	void setSaldo(float saldo){
		this->saldo = saldo;
	}
	int getNumero(){
		return this->numero;
	}
	static const float getTaxa(){
		return TAXA;
	}
	
	void info(); //mostra as informações da conta.
	bool verificaSenha(const string &); //verifica se a senha dada é a senha da conta.
	void registraOperacao(int tipo,float valor); //registra uma operação na matriz(array de ponteiros) 'historico'.
	void imprimeHistorico();//imprime o histórico de operações da conta.
	
	//Função auxiliar utilizada para verifica se uma string dada é formada por números, para validar os atributos nome e senha.
};

#endif // CONTA_H
