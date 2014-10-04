#include "Caixa_Eletronico.h"

#include <conio.h>

Data Caixa_Eletronico::data;

const int Caixa_Eletronico::IDBANCO = 55873;
const string Caixa_Eletronico::NOMEBANCO = "Banco Universitario";

Caixa_Eletronico::Caixa_Eletronico()
{
}


Caixa_Eletronico::Caixa_Eletronico(Caixa_Eletronico &c){
	this->nclientes = c.nclientes;
	this->dinheiro = c.dinheiro;
	this->modelo = c.modelo;
	this->conta = c.conta;
	this->saldo = c.saldo;
	this->data = c.data;
}

Caixa_Eletronico::~Caixa_Eletronico()
{
}

void Caixa_Eletronico::saque(string &conta){
	int iconta = -1;
	
	for (unsigned int i = 0; i < this->conta.size();i++)
		if (this->conta[i] == conta)
			iconta = i;
		
	float valor;
	
	do{
		cout<<"\nDigite o valor a ser sacado: ";
		cin >> valor;
			if (valor > this->saldo[iconta]){    //Não permite a inserção de dados maiores que o saldo da conta informada...
				cout << "\nValor maior que o saldo!";
				getch();
			}
			else if (valor < 0){				//...nem a inserção de dados menores que 0.
				cout << "\nValor invalido!!";
				getch();
			}
			else{								//A condição é aceita e o saque ocorre normalmente.
				this->saldo[iconta] -= valor;
				this->dinheiro -= valor;
				
				cout<<"\nO valor de R$"<<valor<<" foi sacado.";
				cout<<"\nSaldo restante: R$"<<this->saldo[iconta]<<".";
			}
		
	}while (valor < 0 || valor > this->saldo[iconta]);
	
}

void Caixa_Eletronico::pagamento(string &conta){
	int iconta1 = -1, iconta2 = iconta1, nconta,achou = 0;
	
	for (unsigned int i = 0; i < this->conta.size();i++)
		if (this->conta[i] == conta)
			iconta1 = i;
		
	float valor;
	
	do{ //laço "do-while" para validar o numero da conta
		cout<<"\nDigite o numero da conta que recebera o pagamento: ";
		cin >> nconta;
		for (unsigned int i = 0;i < this->saldo.size();i++)
			if (this->saldo[i] == nconta){
				iconta2 = i;
				achou = 1;
			}
		if (achou == 0)
			cout<<"\nConta nao encontrada, por favor digite novamente: ";
		else{
			do{ //laço "do - while()" para validar o valor do pagamento.
				cout<<"\nDigite o valor do pagamento: ";
				cin >> valor;
					if (valor > this->saldo[iconta1]){    //Não permite a inserção de dados maiores que o saldo da conta informada...
						cout << "\nValor maior que o saldo!";
						getch();
					}
					else if (valor < 0){				//...nem a inserção de dados menores que 0.
						cout << "\nValor invalido!!";
						getch();
					}
					else{								//A condição é aceita e o pagamento ocorre normalmente.
						this->saldo[iconta1] -= valor;
						this->saldo[iconta2] += valor;
						
						cout<<"\nO pagamento no valor de R$"<<valor<<" foi feito.";
						mostrarSaldo(this->conta[iconta1]);
						mostrarSaldo(this->conta[iconta2]);
						getch();
					}
		
			}while (valor < 0 || valor > this->saldo[iconta1]);
		}
		
	}while(achou == 0);
}

void Caixa_Eletronico::mostrarSaldo(string &conta) const{
	for (unsigned int i = 0;i < this->conta.size();i++)
		if (this->conta[i] == conta)
			cout<<"\nO saldo da conta "<<this->conta[i]<<"e' de: R$"<<this->saldo[i];
}

void Caixa_Eletronico::info() const{
	mostrarData();
	
	cout<<"\n-- Informacoes gerais do caixa eletronico: \n";
	cout<<"\nBanco: "<<NOMEBANCO<<"(ID do banco: "<<IDBANCO<<").";
	cout<<"\nModelo do caixa: "<<this->modelo;
	cout<<"\nNumero de clientes do banco: "<<this->nclientes<<".";
	cout<<"\nDinheiro disponivel no caixa: R$"<<this->dinheiro<<".";
}

void Caixa_Eletronico::mostrarData(){
	cout<<"\n-Data: ";
	Caixa_Eletronico::data.print();
}