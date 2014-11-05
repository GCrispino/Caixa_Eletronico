#ifndef CAIXA_CXECONOMICA_H
#define CAIXA_CXECONOMICA_H

#include "Caixa_Eletronico.h"
#include <iostream>

using namespace std;

class Caixa_CxEconomica : public Caixa_Eletronico
{
	friend ostream &operator << (ostream &,const Caixa_CxEconomica&);
	
private:
	const static string NOMEBANCO;
public:
	Caixa_CxEconomica(const string &modelo = "",float dinheiro = 0,int serial = 0,Data = Data(),string senhaadm = "123456");
	~Caixa_CxEconomica();


	void ligar();
};

#endif // CAIXA_CXECONOMICA_H
