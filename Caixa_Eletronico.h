/*
 *     Requisitos para quarta tarefa: 
        X Diagrama de classes (obrigatório salvar também o png do diagrama no gitHub)
        X Herança pública
        X Construtor de cópia, e sobrecargas dos operadores de atribuição (=) e << (cout << base) para a classe base e derivada
        X Usar Protected acessando diretamente os atributos na classe derivada
        Alocação dinâmica de memória na classe base(X) e derivada
        Sobrescrita de método: chamar dentro do método da classe derivada o método correspondente da classe base usando ::
        No main: criar um ponteiro da classe base para alocar memória para a classe derivada e chamar os vários métodos implementados
 */
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
	
	
public:
	Caixa_Eletronico(float dinheiro = 0, string modelo = ""); //Construtor default que inicializa as variaveis dinheiro e modelo.
	Caixa_Eletronico(Caixa_Eletronico &); //Construtor de cópia
	~Caixa_Eletronico();
	
	bool operator == (const Caixa_Eletronico &c1); //Sobrecarga do operador "==".
	Caixa_Eletronico operator = (const Caixa_Eletronico &c); //Sobrecarga do operador "=".
	
	
	void saque(int); //realiza uma operação de saque no caixa eletrônico.
	void info() const; //imprime as informações do caixa na tela.
};

#endif // CAIXA_ELETRONICO_H
