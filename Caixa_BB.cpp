#include "Caixa_BB.h"
#include <windows.h>
#include <conio.h>
#include <cstdlib>

const string Caixa_BB::NOMEBANCO = "Banco do Brasil";

ostream &operator << (ostream &output, const Caixa_BB &cx){
	cout<<endl<<"Banco do caixa eletronico: "<<cx.NOMEBANCO<<".";
	cout<<endl<<static_cast<const Caixa_Eletronico&>(cx);
	
	return output;
}

Caixa_BB::Caixa_BB(const string &modelo, float dinheiro, int serial,Data datafabricacao,string senhaadm)
:Caixa_Eletronico(modelo,dinheiro,serial,datafabricacao,senhaadm)
{
}

Caixa_BB::Caixa_BB(const Caixa_BB &bb) 
:Caixa_Eletronico(bb){}

Caixa_BB::~Caixa_BB()
{
}

void Caixa_BB::ligar(){
	cout<<endl<<"Aguarde enquanto o caixa esta sendo ligado";
	
	for (int i = 0;i < 5;i++){
		cout<<endl<<"...";
		Sleep(300);
	}
	
	this->ligado = true;
	
	
	cout<<endl<<"Caixa ligado!";
	getch();
	
	system("cls");
	cout<<endl<<"Bem vindo ao caixa eletronico do Banco do Brasil! O banco que é bom para todos!";
	cout<<endl<<"Pressione qualquer tecla para continuar...";
	getch();
	
}