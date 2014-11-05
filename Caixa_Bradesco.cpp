#include "Caixa_Bradesco.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>

const string Caixa_Bradesco::NOMEBANCO = "Bradesco";

Caixa_Bradesco::Caixa_Bradesco(const string &modelo, float dinheiro, int serial,Data datafabricacao,string senhaadm)
:Caixa_Eletronico(modelo,dinheiro,serial,datafabricacao,senhaadm)
{
}

Caixa_Bradesco::~Caixa_Bradesco()
{
}

void Caixa_Bradesco::ligar(){
	cout<<endl<<"Aguarde enquanto o caixa esta sendo ligado";
	
	for (int i = 0;i < 5;i++){
		cout<<endl<<"...";
		Sleep(300);
	}
	
	this->ligado = true;
	
	system("cls");
	cout<<endl<<"Caixa ligado!";
	getch();
	
	cout<<endl<<"Bem vindo ao caixa eletronico do Bradesco! Tudo de BRA para voce!";
	cout<<endl<<"Pressione qualquer tecla para continuar...";
	getch();
}