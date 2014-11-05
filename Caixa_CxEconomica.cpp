#include "Caixa_CxEconomica.h"
#include <cstdlib>
#include <conio.h>
#include <windows.h>

const string Caixa_CxEconomica::NOMEBANCO = "Caixa Economica";

Caixa_CxEconomica::Caixa_CxEconomica(const string &modelo, float dinheiro, int serial,Data datafabricacao,string senhaadm)
:Caixa_Eletronico(modelo,dinheiro,serial,datafabricacao,senhaadm)
{
}

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
	
	system("cls");
	cout<<endl<<"Caixa ligado!";
	getch();
	
	cout<<endl<<"Bem vindo ao caixa eletronico da Caixa Econômica! Vem pra caixa você também!";
	cout<<endl<<"Pressione qualquer tecla para continuar...";
	getch();
}