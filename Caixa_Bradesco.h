#ifndef CAIXA_BRADESCO_H
#define CAIXA_BRADESCO_H

#include "Caixa_Eletronico.h"
#include <iostream>

using namespace std;

class Caixa_Bradesco: public Caixa_Eletronico
{
	friend ostream &operator << (ostream &,const Caixa_Bradesco&);
	
private:
	const static string NOMEBANCO;
public:
	Caixa_Bradesco(const string &modelo = "",float dinheiro = 0,int serial = 0,Data = Data(),string senhaadm = "123456");
	Caixa_Bradesco(const Caixa_Bradesco &);
	~Caixa_Bradesco();

	void ligar();
};

#endif // CAIXA_BRADESCO_H
