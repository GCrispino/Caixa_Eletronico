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
	~Caixa_BB();
	
	
	void ligar();
};

#endif // CAIXA_BB_H
