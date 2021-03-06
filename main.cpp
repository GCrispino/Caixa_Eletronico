#include <iostream>
#include <typeinfo>
#include <vector>

#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Caixa_BB.h"
#include "Caixa_CxEconomica.h"
#include "Caixa_Bradesco.h"
#include "stringDigitos.h"

using namespace std;

void Menu0(); //primeiro menu que aparece no programa
void MenuCaixas(); //imprime as opções de caixa disponíveis.
void MenuCaixaEletronico(); //Menu do caixa eletrônico do programa
void MenuOperacao(); //Menu aberto quando se escolhe a opção de realizar uma operação no menu principal.
void MenuInformacoes(); //Menu que controla as operações de mostrar informações sobre determinada classe.

void print(Caixa_Eletronico *);// função que imprime informações de um caixa eletrônico em questão usando polimorfismo
void desaloca(vector <Caixa_Eletronico*> &); //funcão que desaloca os ponteiros armazenados no vector de referências
void imprimeCaixas(vector <Caixa_Eletronico *> &); //função que procura no vector e conta quantos caixas de cada classe concreta estão registrados.

int main(int argc, char **argv)
{
	bool achousenha = false,laco;
	int opcaocaixa,opcao0,opcao1,opcao2,opcao3,nconta,serial,dia,mes,ano;;
	float dinheiro;
	char r;
	string modelo,cpf,senha,senhaadm;
	Conta conta;
	Caixa_Eletronico *cprincipal = 0,*csecundario = 0;
	Device *dprincipal = 0;
	
	Caixa_BB bb1,bb2;
	Caixa_Bradesco bradesco1,bradesco2;
	Caixa_CxEconomica cxeconomica1,cxeconomica2;
	vector<Caixa_Eletronico*> ptrcaixa;
	
	ptrcaixa.push_back(&bb1);
	ptrcaixa.push_back(&bb2);
	ptrcaixa.push_back(&bradesco1);
	ptrcaixa.push_back(&bradesco2);
	ptrcaixa.push_back(&cxeconomica1);
	ptrcaixa.push_back(&cxeconomica2);
	
	
	do{
		system("cls");
		MenuCaixas();
		cin >> opcaocaixa;
		laco = false; //variável bool que mantém o laço enquanto ela for verdadeira
		
		switch(opcaocaixa){
			case 1: 
				cprincipal = new Caixa_BB("Caixa1",3000,12345,Data(30,1,2010),"654321");
				break;
			case 2:
				cprincipal = new Caixa_CxEconomica("Caixa1",3000,12345,Data(30,1,2010),"654321");
				break;
			case 3:
				cprincipal = new Caixa_Bradesco("Caixa1",3000,12345,Data(30,1,2010),"654321");
				break;
			case 4:
				imprimeCaixas(ptrcaixa);
				laco = true; //mantém o laço "do-while"
				break;
			case 5:
				cout<<endl<<"Programa encerrado!";
				desaloca(ptrcaixa);
				getch();
				return 0;
			default:
				laco = true;
				cout<<endl<<"Opcao invalida!";
				getch();
				break;
	}
		dprincipal = cprincipal;
	}while(laco);
	
	if (cprincipal->isLigado() == 0){
		cout<<endl<<"Deseja ligar o caixa eletronico(S ou N)?";
		cin >> r;
		r = toupper(r);
		if (r == 'S'){
			cprincipal->ligar();
		}
		
	}
	
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
										//cout<<static_cast<Device*>(cprincipal);
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

	if (cprincipal != 0)
		delete cprincipal;
	if (csecundario != 0)
		delete csecundario;
	if (dprincipal != 0)
		delete dprincipal;
		
	desaloca(ptrcaixa);

	return 0;
}

void Menu0(){
	system("cls");
	cout << "Selecione uma opcao: ";
	cout<<endl<<"1. Usar o caixa eletronico. ";
	cout<<endl<<"2. Abrir o menu de manutencao. ";
	cout<<endl<<"3. Sair do programa.";
}

void MenuCaixas(){
	cout<<endl<<"Seja bem vindo! Escolha qual caixa voce deseja utilizar: ";
	cout<<endl<<" 1. Banco do Brasil";
	cout<<endl<<" 2. Caixa Economica";
	cout<<endl<<" 3. Bradesco";
	cout<<endl<<" 4. Imprimir a quantidade de caixas de cada banco disponiveis: ";
	cout<<endl<<" 5. Sair do programa";
	cout<<endl;
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
			cout<<*static_cast<Caixa_CxEconomica*>(cx);
		else if (typeid(*cx) == typeid(Caixa_Bradesco))
			cout<<*static_cast<Caixa_Bradesco*>(cx);
}

void desaloca(vector<Caixa_Eletronico*> &ptrcaixa){
	for (unsigned int i = 0;i < ptrcaixa.size();i++){
		cout<<endl<<"Deletando objeto da classe "<<(typeid(*ptrcaixa[i]).name());
		delete ptrcaixa[i];
	}
}

void imprimeCaixas(vector <Caixa_Eletronico*> &ptrcaixa){
	Caixa_BB *ptrbb;
	Caixa_Bradesco *ptrbradesco;
	Caixa_CxEconomica *ptrcxeconomica;
	
	int cbb = 0,cbr = 0,ccx = 0; //contadores de cada banco
	
	for (unsigned int i = 0;i < ptrcaixa.size();i++){
		ptrbb = dynamic_cast<Caixa_BB*>(ptrcaixa[i]);
		
		if (ptrbb != 0)
			cbb++;
		else{
			ptrbradesco = dynamic_cast<Caixa_Bradesco*>(ptrcaixa[i]);
			
			if (ptrbradesco != 0)
				cbr++;
			else{
				ptrcxeconomica = dynamic_cast<Caixa_CxEconomica*>(ptrcaixa[i]);
				if (ptrcxeconomica != 0)
					ccx++;
			}
		}
	}
	
	cout<<endl<<"Quantidade de caixas registrados: ";
	cout<<endl<<"Caixas do Banco do Brasil: "<<cbb;
	cout<<endl<<"Caixas do Banco Bradesco: "<<cbr;
	cout<<endl<<"Caixas da Caixa Economica: "<<ccx;
	
	getch();
	
	if (ptrbb != 0)
		delete ptrbb;
	if (ptrbradesco != 0)
		delete ptrbradesco;
	if (ptrcxeconomica != 0)
		delete ptrcxeconomica;
}