#ifndef BANCO_H
#define BANCO_H

#include <iostream>

using namespace std;

class Banco
{
private:
	int id;
	string nome;
public:
	Banco();
	virtual ~Banco();
	
	void info();
};

#endif // BANCO_H
