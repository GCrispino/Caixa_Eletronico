#include "Device.h"
#include "stringDigitos.h"
#include <conio.h>

ostream &operator <<(ostream &output,const Device &d){
	output<<endl<<"Informacoes do dispositivo: ";
	output<<endl<<" - Numero serial: "<<d.serial<<" .";
	output<<endl<<" - Modelo: "<<d.modelo<<" .";
	output<<endl<<" - Data de fabricacao: "; d.datafabricacao.print();
	
	return output;
}

Device::Device(int serial, string modelo,Data datafabricacao,string senha)
:serial(serial),modelo(modelo),senhaadm(senha)
{
	if (serial < 0)
		this->serial = 0;
	
	if (stringDigitos(&senha) && senha.size() == 6)
		this->senhaadm = senha;
	else
		this->senhaadm = "123456";	
	
	this->datafabricacao= datafabricacao;
	this->datasmanutencao = 0;
	this->ndatasmanutencao = 0;
}

Device::Device(const Device &d){
	this->serial = d.serial;
	this->modelo = d.modelo;
	this->senhaadm = d.senhaadm;
	this->datafabricacao = d.datafabricacao;
	this->ndatasmanutencao = d.ndatasmanutencao;
	
	//Cópia dos ponteiros
	if (this->ndatasmanutencao == 1)
		delete this->datasmanutencao;
	else if(this->ndatasmanutencao > 1)
		delete [] this->datasmanutencao;
	
	if (this->ndatasmanutencao == 0)
		this->datasmanutencao = 0;
	else if (this->ndatasmanutencao == 1){
		this->datasmanutencao = new Data();
		this->datasmanutencao[0] = d.datasmanutencao[0];
	}
	else{
		this->datasmanutencao = new Data[this->ndatasmanutencao];
		for (int i = 0;i < this->ndatasmanutencao;i++)
			this->datasmanutencao[i] = d.datasmanutencao[i];
	}
}

Device::~Device()
{
	if (this->ndatasmanutencao == 1)
		delete this->datasmanutencao;
	else
		delete [] this->datasmanutencao;
}


/*const Device & Device::operator =(const Device &d){
	this->serial = d.serial;
	this->modelo = d.modelo;
	this->senhaadm = d.senhaadm;
	this->datafabricacao = d.datafabricacao;
	this->ndatasmanutencao = d.ndatasmanutencao;
	
	//Cópia dos ponteiros
	if (this->ndatasmanutencao <= 1)
		delete this->datasmanutencao;
	else
		delete [] this->datasmanutencao;
	
	if (this->ndatasmanutencao == 0)
		this->datasmanutencao = 0;
	else if (this->ndatasmanutencao == 1){
		this->datasmanutencao = new Data();
		this->datasmanutencao[0] = d.datasmanutencao[0];
	}
	else{
		this->datasmanutencao = new Data[this->ndatasmanutencao];
		for (int i = 0;i < this->ndatasmanutencao;i++)
			this->datasmanutencao[i] = d.datasmanutencao[i];
	}
	
	return &(*this);
}*/

void Device::setDatasManutencao(const Data &d){
	Data * aux;
	if (this->ndatasmanutencao == 0){
		this->datasmanutencao = new Data(d);
		this->ndatasmanutencao++;
	}
	else{
		aux = new Data[this->ndatasmanutencao];
		int i;
		
		for (i = 0;i < this->ndatasmanutencao;i++)
			aux[i] = this->datasmanutencao[i];
			
		if (this->ndatasmanutencao == 1)
			delete this->datasmanutencao;
		else
			delete [] this->datasmanutencao;
			
		this->datasmanutencao = new Data[this->ndatasmanutencao];
		
		for (i = 0;i < this->ndatasmanutencao;i++)
			this->datasmanutencao[i] = aux[i];
			
		this->datasmanutencao[this->ndatasmanutencao++] = Data(d);
		delete [] aux;
	}
}

void Device::imprimeDatasManutencao(){
	
	if (this->ndatasmanutencao == 0){
		cout<<endl<<"Nenhuma manutencao foi feita!";
		getch();
	}
	else{
		cout<<endl<<"- Datas em que o dispositivo sofreu manutencao: ";
		for (int i = 0;i < this->ndatasmanutencao;i++){
			this->datasmanutencao[i].print();
			cout<<endl;
			getch();
		}
	}
}

bool Device::verificaSenha(const string &senha){
	if (this->senhaadm == senha)
		return true;
	else 
		return false;
}

bool Device::isLigado(){
	return (this->ligado);
}