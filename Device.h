/*	Requisitos herança
	Diagrama de classes (obrigatório salvar também o png do diagrama no gitHub) 
	Herança pública OK
	Construtor de cópia, e sobrecargas dos operadores de atribuição (=) e << (cout << base) para a classe base e derivada OK
	Usar Protected acessando diretamente os atributos na classe derivada OK
	Alocação dinâmica de memória na classe base e derivada OK
	Sobrescrita de método: chamar dentro do método da classe derivada o método correspondente da classe base usando :: OK ?
	No main: criar um ponteiro da classe base para alocar memória para a classe derivada e chamar os vários métodos implementados OK
*/

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
	string senhaadm; //senha do administrador, que permite a manutenção do dispositivo.
	Data datafabricacao; //data de fabricação do dispositivo.
	Data *datasmanutencao; //array que guarda as datas em que o dispositivo sofreu manutenção.
	int ndatasmanutencao;//número de datas de manutenção.
	bool ligado; //indica se o device está ligado ou não.
public:
	Device(int serial = 0, string modelo = "",Data = Data(),string senha = "123456"); //Construtor default
	Device(const Device &); //Construtor de cópia
	virtual ~Device(); //destrutor

	//const Device &operator =(const Device &); //sobrecarga do operador "="
	
	void setDatasManutencao(const Data &);
	
	virtual void imprimeDatasManutencao() ;//Imprime as datas em que o dispositivo sofreu manutenção.
	bool verificaSenha(const string &); //verifica a senha de administrador.
	bool isLigado(); //verifica se o dispositivo está ligado
	
	virtual void ligar() = 0; //liga o dispositivo
};

#endif // DEVICE_H
