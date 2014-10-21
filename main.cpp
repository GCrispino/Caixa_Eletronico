#include <iostream>

using namespace std;

#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Caixa_Eletronico.h"

void Menu1(); //Menu principal do programa
void MenuOperacao(); //Menu aberto quando se escolhe a opção de realizar uma operação no menu principal.
void MenuInformacoes(); //Menu que controla as operações de mostrar informações sobre determinada classe.

int main(int argc, char **argv)
{
	int opcao1,opcao2,opcao3,nconta;
	float dinheiro;
	char r;
	string modelo,cpf;
	Conta conta;
	Caixa_Eletronico c(2000,"Caixa1"); //Dinheiro disponível no caixa e seu modelo definidos na declaração do objeto.
	Caixa_Eletronico c2(c);
	
	cout << "\n---Caixa eletronico---: ";
	cout << "\nPressione qualquer tecla para continuar: ";
	getch();
	do{
		Menu1();
		cin >> opcao1;
		switch(opcao1){
			case 1:
				system("cls");
				c.registrarConta();
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
								cin >> nconta;
								c.saque(nconta);
								break;
							case 2:
								cout<<"\nDigite o numero da sua conta: ";
								cin >> nconta;
								c.pagamento(nconta);
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
				do{
					MenuInformacoes();
					cin >> opcao3;
					
					switch(opcao3){
						case 1:
						
							if (c.getNContas() == 0)
								cout<<endl<<"Nenhuma conta cadastrada!";
							else{
								cout<<endl<<"Digite o numero da conta: ";
								cin >> nconta;
									if (c.buscaConta(nconta) == -1)
										cout<<endl<<"Conta informada nao encontrada!";
									else{
										system("cls");
										Caixa_Eletronico::mostrarData();
										Caixa_Eletronico::getConta()[c.buscaConta(nconta)].info();	//mostra as informacoes da conta dada, se ela existir.
										cout<<endl<<"Deseja visualizar o historico de operacoes recentes da conta(S ou N)?";
										cin >> r;
										r = toupper(r);
										if (r == 'S'){// se o usuário desejar, mostra o histórico da conta.
											Caixa_Eletronico::getConta()[c.buscaConta(nconta)].imprimeHistorico();
											getch();
										}
										else
											cout<<endl<<"Opcao invalida!";
									}
								
								getch();
							}
							
							break;
						case 2:
							cout<<endl<<"Digite o CPF do usuario: ";
							cin >> cpf;
							if (c.buscaCPF(cpf) == -1)
								cout<<endl<<"CPF nao encontrado!";
							else{
								//Mostra as informações do usuário.
								system("cls");
								Caixa_Eletronico::getConta()[c.buscaCPF(cpf)].getUsuario().info(); 
							}
							getch();
							break;
						case 3:
							system("cls");
							Caixa_Eletronico::mostrarData();
							c.info();
							getch();
							break;
						case 4:
							break;
					}
				}while (opcao3 != 4);
				
				break;
			case 4:
			{
				cout << "\nDigite o modelo do novo caixa(digite sem espacos, por favor): ";
				cin >> modelo;
				cout << "\nDigite a quantidade de dinheiro que estara armazenada no novo caixa: ";
				cin >> dinheiro;
				
				Caixa_Eletronico c2(dinheiro,modelo);
				
				if (c2 == c){ //Uso da sobrecarga do operador "==".
					cout <<"\n Um caixa com os mesmos dados de outro nao pode ser inserido!";
					getch();
					break;
				}
				else{
					cout<< endl <<"Caixa "<<c<<" trocado pelo caixa "<<c2; //Uso da sobrecarga do operador "<<".
					c = c2; //Uso da sobrecarga do operador "=".
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
	cout << "\n1. Registrar uma conta. ";
	cout << "\n2. Realizar alguma operacao. ";
	cout << "\n3. Informacoes.";
	cout << "\n4. Usar outro caixa eletronico.";
	cout << "\n5. Sair do programa.";
}

void MenuOperacao(){
	cout<<"\nEscolha a operacao que voce deseja fazer: \n";
	cout<<"\n1. Saque.";
	cout<<"\n2. Pagamento.";
	cout<<"\n3. Voltar ao primeiro menu.";
}

void MenuInformacoes(){
	system("cls");
	cout<<endl<<"Escolha quais informacoes voce deseja obter. "<<endl;
	cout<<endl<<"1. Informacoes sobre uma conta. ";
	cout<<endl<<"2. Informacoes sobre um usuario de uma conta. ";
	cout<<endl<<"3. Informacoes sobre o caixa eletronico. ";
	cout<<endl<<"4. Voltar ao menu principal. ";
}