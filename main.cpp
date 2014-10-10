#include <iostream>

using namespace std;

#include <conio.h>
#include <stdlib.h>

#include "Caixa_Eletronico.h"

void Menu1(); //Menu principal do programa
void MenuOperacao(); //Menu aberto quando se escolhe a opção de realizar uma operação no menu principal.

int main(int argc, char **argv)
{
	int opcao1,opcao2,conta;
	float saldo,dinheiro;
	string modelo;
	Caixa_Eletronico c(2000,"Caixa1"); //Dinheiro disponível no caixa e seu modelo definidos na declaração do objeto.
	Caixa_Eletronico c2(c);
	
	c.info();
	cout<<endl;
	c2.info();
	
	return 0;
	
	cout << "\n---Caixa eletronico---: ";
	cout << "\nPressione qualquer tecla para continuar: ";
	getch();
	do{
		Menu1();
		cin >> opcao1;
		switch(opcao1){
			case 1:
				cout<<"\nInsira o numero da conta: ";
				cin >> conta;
				if (c.setConta(conta) == -1) //Executa setConta() e verifica a validação do valor dado.
					break;
				else{
					cout<<"\nDigite o valor do saldo dessa conta: ";
					cin >> saldo;
					c.setSaldo(conta,saldo);
				}
				break;
			case 2:
				if (c.getNContas() == 0){
					cout<<"\nNenhuma conta foi cadastrada!";
					getch();
				}
				else{
					do{
						system("cls");
						MenuOperacao();
						cin >> opcao2;
						switch(opcao2){
							case 1:
								cout<<"\nDigite o numero da sua conta: ";
								cin >> conta;
								c.saque(conta);
								break;
							case 2:
								cout<<"\nDigite o numero da sua conta: ";
								cin >> conta;
								c.pagamento(conta);
								break;
							case 3:
								break;
							default:
								cout<<"\nOpcao invalida!";
						}
					}while(opcao2 != 3);
				}
					break;
			case 3:
				system("cls");
				Caixa_Eletronico::mostrarData();
				c.info();
				getch();
				break;
			case 4:
			{
				cout << "\nDigite o modelo do novo caixa(digite sem espaços, por favor): ";
				cin >> modelo;
				cout << "\nDigite a quantidade de dinheiro que estara armazenada no novo caixa: ";
				cin >> dinheiro;
				
				Caixa_Eletronico c2(dinheiro,modelo);
				
				
				//c2.info();
				
				if (c2 == c){ //Uso da sobrecarga do operador "==".
					cout <<"\n Um caixa com os mesmos dados de outro nao pode ser inserido!";
					getch();
					break;
				}
				else{
					cout<< endl <<"Caixa "<<c<<" trocado pelo caixa "<<c2; //Uso da sobrecarga do operador "<<".
					c = c2;
				}
				getch();
				break;
			}
			case 5:
				cout<< "\nPrograma encerrado!";
				break;
			default:
				cout<<"\nOpcao invalida!";
				break;
		}
	}while(opcao1 != 5);
	
	getch();
	return 0;
}

void Menu1(){
	system("cls");
	cout << "Selecione uma opcao: \n";
	cout << "\n1. Entrar com uma conta. ";
	cout << "\n2. Realizar alguma operacao. ";
	cout << "\n3. Mostrar informacoes do caixa.";
	cout << "\n4. Usar outro caixa eletronico.";
	cout << "\n5. Sair do programa.";
}

void MenuOperacao(){
	cout<<"\nEscolha a operacao que voce deseja fazer: \n";
	cout<<"\n1. Saque.";
	cout<<"\n2. Pagamento.";
	cout<<"\n3. Voltar ao primeiro menu.";
}