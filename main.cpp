#include <iostream>
#include <typeinfo>

using namespace std;

#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Caixa_BB.h"
#include "Caixa_CxEconomica.h"
#include "Caixa_Bradesco.h"
#include "stringDigitos.h"

void Menu0(); //primeiro menu que aparece no programa
void MenuCaixaEletronico(); //Menu do caixa eletrônico do programa
void MenuOperacao(); //Menu aberto quando se escolhe a opção de realizar uma operação no menu principal.
void MenuInformacoes(); //Menu que controla as operações de mostrar informações sobre determinada classe.

void print(Caixa_Eletronico *);// função que imprime informações de um caixa eletrônico em questão usando polimorfismo

int main(int argc, char **argv)
{
	bool achousenha = false;
	int opcao0,opcao1,opcao2,opcao3,nconta,serial,dia,mes,ano;;
	float dinheiro;
	char r;
	string modelo,cpf,senha,senhaadm;
	Conta conta;
	Device *dprincipal;//new Caixa_Eletronico("Caixa1",3000,12345,Data(30,1,2010),"654321");
	Caixa_Eletronico *cprincipal,*csecundario;
	//Caixa_Eletronico c2(c);
	//Device *ptrdispositivo = new Caixa_Eletronico(c);
	
	cprincipal = new Caixa_BB("Caixa1",3000,12345,Data(30,1,2010),"654321");
	dprincipal = cprincipal;
	
	cout << "\n---Caixa eletronico---: ";
	cout << "\nPressione qualquer tecla para continuar: ";
	getch();
	
	do{
		Menu0();
		cin >> opcao0;
		switch(opcao0){
			case 1:
				do{
					MenuCaixaEletronico();
					cin >> opcao1;
					switch(opcao1){
						case 1:
							system("cls");
							do{
								cout<<endl<<"Digite o CPF do dono da nova conta: ";
								cin >> cpf;
					
								if (stringDigitos(&cpf) == 0 && cpf.size() != 11)
									cout<<endl<<"CPF invalido!";
							}while(stringDigitos(&cpf) == 0 && cpf.size() != 11);
				
							const Usuario *u;
							u = cprincipal->buscaCPF(cpf);
				
			
							if (u != 0){
								if (cprincipal->registrarConta(const_cast<Usuario&>(*u)) != -1)
									cprincipal->incrementaNContas();
							}
							else{
								cprincipal->registrarUsuario(cpf);
								cprincipal->incrementaNContas();
							}
				
							break;
						case 2:
							if (cprincipal->getNContas() == 0){
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
											cprincipal->saque(nconta);
											break;
										case 2:
											cout<<"\nDigite o numero da sua conta: ";
											cin >> nconta;
											cprincipal->pagamento(nconta);
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
						
										if (cprincipal->getNContas() == 0){
											cout<<endl<<"Nenhuma conta cadastrada!";
											getch();
										}
										else{
											cout<<endl<<"Digite o numero da conta: ";
											cin >> nconta;
									
											const Conta *conta = cprincipal->buscaConta(nconta);
									
												if (conta != 0){
													do{
														cout<<endl<<"Digite a sua senha: ";
														cin >> senha;
														if (conta->verificaSenha(senha))
															achousenha = true;
														if (achousenha == false){
															cout<<endl<<"Senha invalida!";
															getch();
														}
													}while(conta->verificaSenha(senha) != true);
													system("cls");
													Caixa_Eletronico::mostrarData();
													cout<<*conta;	//mostra as informacoes da conta dada, se ela existir.
													cout<<endl<<"Deseja visualizar o historico de operacoes recentes da conta(S ou N)?";
													cin >> r;
													r = toupper(r);
													if (r == 'S')// se o usuário desejar, mostra o histórico da conta.
														conta->imprimeHistorico();
													else if (r != 'N')
														cout<<endl<<"Opcao invalida!";
												}
												else{
													cout<<endl<<"Conta nao encontrada!";
													getch();
												}
								
											getch();
										}
							
										break;
									case 2:
										if (cprincipal->getNUsuarios() == 0)
											cout<<endl<<"Nenhum usuario cadastrado!";
										else{
											cout<<endl<<"Digite o CPF do usuario: ";
											cin >> cpf;
											u = cprincipal->buscaCPF(cpf); //realiza a busca do CPF
											if (u == 0)//caso o número não seja encontrado, é atribuído o valor 0 ao objeto 'u'.
												cout<<endl<<"CPF nao encontrado!";
											else{
									
												//Mostra as informações do usuário.
												system("cls");
												Caixa_Eletronico::mostrarData();
												cout<<*u; //imrpime os dados do usuário encontrado
												getch();
												cout<<endl<<"Deseja visualizar os numeros das contas desse usuario(S ou N)?";
												cin >> r;
												r = toupper(r);
													if (r == 'S')// se o usuário desejar, mostra o histórico da conta.
														u->imprimeContas();
													else if (r != 'N')
														cout<<endl<<"Opcao invalida!";
											}
										}
											getch();
											break;
									case 3:
										system("cls");
										Caixa_Eletronico::mostrarData();
										cout<<static_cast<Device*>(cprincipal);
										print(cprincipal);
										getch();
										cout<<endl<<"Deseja visualizar as datas de manutencao do caixa(S ou N)?";
										cin >> r;
										r = toupper(r);
										if (r == 'S')// se o usuário desejar, imprime as datas de manutenção do dispsitivo.
											dprincipal->imprimeDatasManutencao();
										else if (r != 'N')
											cout<<endl<<"Opcao invalida!";
										break;
									case 4:
										break;
									default:
										cout<<endl<<"Opcao invalida!";
								}
							}while (opcao3 != 4);
				
							break;
						case 4:
						{
							cout << "\nDigite o modelo do novo caixa(digite sem espacos, por favor): ";
							cin >> modelo;
							cout<<endl<<"Digite o numero serial do novo caixa: ";
							cin >> serial;
							cout << "\nDigite a quantidade de dinheiro que estara armazenada no novo caixa: ";
							cin >> dinheiro;
							cout<<"\nDigite a data de fabricacao do novo caixa: ";
							cout<<endl<<"Dia: ";
							cin >> dia;
							cout<<endl<<"Mes: ";
							cin >> mes;
							cout<<endl<<"Ano: ";
							cin >> ano;
				
							Data datafabricacao(dia,mes,ano);
					
							csecundario = new Caixa_BB(modelo,dinheiro,serial,datafabricacao,"654321");
				
							if (*csecundario == *cprincipal){ //Uso da sobrecarga do operador "==".
								cout <<"\n Um caixa com os mesmos dados de outro nao pode ser inserido!";
								getch();
								break;
							}
							else{
								cout<<endl<<"Caixa antigo: "<<endl<<*cprincipal<<endl;
								cout<<endl<<"Caixa novo: "<<endl<<*csecundario<<endl;
					
								*cprincipal = *csecundario; //Uso da sobrecarga do operador "=".
							}
							getch();
							break;
						}
						case 5:
							break;
						default:
							cout<<"\nOpcao invalida!";
							break;
					}
				}while(opcao1 != 5);
				break;
			
			case 2:
				system("cls");
				cout<<endl<<"Digite a senha de administrador do dispositivo para entrar no menu de manutencao: ";
				cin >> senha;
				if (cprincipal->verificaSenha(senha)){
					cout<<endl<<"--Menu de manutencao--";
					getch();
					cout<<endl<<"Digite a data da manutencao:";
					cout<<endl<<"- Dia: ";
					cin >>dia;
					cout<<endl<<"- Mes: ";
					cin >> mes;
					cout<<endl<<"- Ano: ";
					cin >> ano;
					
					cprincipal->setDatasManutencao(Data(dia,mes,ano));
				}
				else{
					cout<<endl<<"Senha incorreta!";
					getch();
				}
				break;
			
			case 3:
				cout<<endl<<"Programa encerrado!";
				getch();
				break;
				
			default:
				cout<<endl<<"Opcao invalida!";
				getch();
				break;
		}
	}while(opcao0 != 3);
	
	getch();
	return 0;
}

void Menu0(){
	system("cls");
	cout << "Selecione uma opcao: ";
	cout<<endl<<"1. Usar o caixa eletronico. ";
	cout<<endl<<"2. Abrir o menu de manutencao. ";
	cout<<endl<<"3. Sair do programa.";
}

void MenuBanco(){
	system("cls");
	cout << "Selecione uma opcao: \n";
	cout << "\n1. Registrar uma conta. ";
	cout << "\n2. Realizar alguma operacao. ";
	cout << "\n3. Informacoes.";
	cout << "\n4. Usar outro caixa eletronico.";
	cout << "\n5. Sair do caixa eletronico.";
}

void MenuCaixaEletronico(){
	system("cls");
	cout << "Selecione uma opcao: \n";
	cout << "\n1. Registrar uma conta. ";
	cout << "\n2. Realizar alguma operacao. ";
	cout << "\n3. Informacoes.";
	cout << "\n4. Usar outro caixa eletronico.";
	cout << "\n5. Voltar ao primeiro menu.";
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
	cout<<endl<<"2. Informacoes sobre um usuario. ";
	cout<<endl<<"3. Informacoes sobre o caixa eletronico. ";
	cout<<endl<<"4. Voltar ao menu principal. ";
}

void print(Caixa_Eletronico *cx){
		if (typeid(*cx) == typeid(Caixa_BB))
			cout<<*static_cast<Caixa_BB*>(cx);
		else if (typeid(*cx) == typeid(Caixa_CxEconomica))
			cout<<static_cast<Caixa_CxEconomica*>(cx);
		if (typeid(*cx) == typeid(Caixa_Bradesco))
			cout<<static_cast<Caixa_Bradesco*>(cx);
	
}