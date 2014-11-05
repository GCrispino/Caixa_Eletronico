#include "Caixa_CxEconomica.h"
#include <cstdlib>
#include <conio.h>
#include <windows.h>

const string Caixa_CxEconomica::NOMEBANCO = "Caixa Economica";

ostream &operator << (ostream &output, const Caixa_CxEconomica &cx){
	cout<<endl<<"Banco do caixa eletronico: "<<cx.NOMEBANCO<<".";
	cout<<endl<<static_cast<const Caixa_Eletronico&>(cx);
	
	return output;
}

Caixa_CxEconomica::Caixa_CxEconomica(const string &modelo, float dinheiro, int serial,Data datafabricacao,string senhaadm)
:Caixa_Eletronico(modelo,dinheiro,serial,datafabricacao,senhaadm)
{
}

 Caixa_CxEconomica::Caixa_CxEconomica(const Caixa_CxEconomica &cxe): Caixa_Eletronico(cxe){}

Caixa_CxEconomica::~Caixa_CxEconomica()
{
}

void Caixa_CxEconomica::ligar(){
	cout<<endl<<"Aguarde enquanto o caixa esta sendo ligado";
	
	for (int i = 0;i < 5;i++){
		cout<<endl<<"...";
		Sleep(300);
	}
	
	this->ligado = true;
	
	cout<<endl<<"Caixa ligado!";
	getch();
	
	system("cls");
	cout<<endl<<"Bem vindo ao caixa eletronico da Caixa Econômica! Vem pra caixa você também!";
	cout<<endl<<"Pressione qualquer tecla para continuar...";
	getch();
}