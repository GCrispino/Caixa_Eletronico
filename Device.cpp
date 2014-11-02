#include "Device.h"

ostream &operator <<(ostream &output,const Device &d){
	output<<endl<<"Informacoes do dispositivo: ";
	output<<endl<<" - Numero serial: "<<d.serial<<" .";
	output<<endl<<" - Modelo: "<<d.modelo<<" .";
	output<<endl<<" - Data de fabricacao: "; d.datafabricacao.print();
	
	return output;
}

Device::Device(int serial, string modelo, Data datafabricacao)
:modelo(modelo)
{
	if (serial >= 0)
		this->serial = serial;
	
	
	this->datafabricacao= datafabricacao;
}

Device::Device(const Device &d){
	this->serial = d.serial;
	this->modelo = d.modelo;
	this->datafabricacao = d.datafabricacao;
}

Device::~Device()
{
}


Device Device::operator =(const Device &d){
	this->serial = d.serial;
	this->modelo = d.modelo;
	this->datafabricacao = d.datafabricacao;
	
	return *this;
}
