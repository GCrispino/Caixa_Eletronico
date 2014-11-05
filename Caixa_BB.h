/*
 *Requisitos funcionais
Polimorfismo

1. Duas classes abstratas, sendo que uma classe abstrata herda da outra classe abstrata na hierarquia de classes;  OK
2. Cada classe abstrata deve ter pelo menos um parâmetro, o construtor vazio e o construtor default. Deve ter também um método não virtual, que não pode ser set ou get;  OK
3. Pelo menos três classes concretas na hierarquia de classes;  OK
4. Usar coerção de tipo C++ e não C, ou seja usar o static_cast para fazer o máximo de reutilização de código.  OK
5. Usar um vector de classes concretas, o dynamic_cast e o typeid como indicado aqui: https://basecamp.com/2595605/projects/7018448/messages/33080741 OK
6. Criar uma função no arquivo do main, que aceita um ponteiro da classe genérica e mostrar o seu uso para as classes concretas;  OK
 * 
 */
#ifndef CAIXA_BB_H
#define CAIXA_BB_H

#include "Caixa_Eletronico.h"
#include <iostream>

using namespace std;

class Caixa_BB: public Caixa_Eletronico
{
	friend ostream &operator << (ostream &,const Caixa_BB &);
	
private:
	const static string NOMEBANCO;
public:
	Caixa_BB(const string &modelo = "",float dinheiro = 0,int serial = 0,Data = Data(),string senhaadm = "123456");
	Caixa_BB(const Caixa_BB &);
	~Caixa_BB();
	
	
	void ligar();
};

#endif // CAIXA_BB_H
