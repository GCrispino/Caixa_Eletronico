#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include "Data.h"

using namespace std;

class Device
{
	friend ostream &operator <<(ostream &,const Device &); //sobrecarga do operador "<<"
	
protected:
	int serial; //número serial do dispositivo.
	string modelo; //modelo do dispositivo.
	Data datafabricacao; //data de fabricação do dispositivo.
public:
	Device(int serial = 0, string modelo = "", Data = Data()); //Construtor default
	Device(const Device &); //Construtor de cópia
	~Device(); //destrutor

	Device operator =(const Device &); //sobrecarga do operador "="

};

#endif // DEVICE_H
