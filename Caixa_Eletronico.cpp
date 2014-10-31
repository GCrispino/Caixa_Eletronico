#include "Caixa_Eletronico.h"

#include <conio.h>
#include <stdlib.h>

bool Caixa_Eletronico::operator == (const Caixa_Eletronico &c1)
{
	if (this->modelo == c1.modelo && this->dinheiro == c1.dinheiro)
		return true;
	else
		return false;
}

ostream &operator << (ostream &output,const Caixa_Eletronico &c)
{
	output << c.modelo << " (" << c.nome<<")";

	return output;
}

Caixa_Eletronico Caixa_Eletronico::operator =(const Caixa_Eletronico &c)
{
	this->dinheiro = c.dinheiro;
	this->modelo = c.modelo;

	return *this;
}

Caixa_Eletronico::Caixa_Eletronico(float dinheiro,string modelo)
:dinheiro(dinheiro), modelo(modelo)
{
	if (dinheiro >= 0)
		this->dinheiro = dinheiro;
	else
		this->dinheiro = 0;
}

Caixa_Eletronico::Caixa_Eletronico(const Caixa_Eletronico &c)
{
	//this->nclientes = c.nclientes;
	this->dinheiro = c.dinheiro;
	this->modelo = c.modelo;
}

Caixa_Eletronico::~Caixa_Eletronico()
{
	if (this->nusuarios <= 1)
		delete this->userpadrao;
	else
		delete [] this->userpadrao;
}

void Caixa_Eletronico::saque(const int conta)
{
	int iconta = -1,iusuario = -1,achou = 0;
	string senha;
	bool achousenha = false;

	for (int i = 0; i < this->getNUsuarios(); i++) //Procura o numero da conta recebido no vetor de contas.
		for (int j = 0; j < this->userpadrao[i].getNContas(); j++)
			if (this->userpadrao[i].getContas()[j].getNumero() == conta) {
				iusuario = i;
				iconta = j;
				achou = 1;

				cout<<endl<<"Digite a sua senha: ";
				cin >> senha;
				if (this->userpadrao[i].getContas()[j].verificaSenha(senha))
					achousenha = true;
			}
	if (achou == 0) {
		cout<<"\nConta nao encontrada!";
		getch();
		return ;
	} else if(achousenha) {
		float valor;

		cout<<"\nDigite o valor a ser sacado: ";
		cin >> valor;
		if (valor > this->userpadrao[iusuario].getContas()[iconta].getSaldo()) {   //Não permite a inserção de dados maiores que o saldo da conta informada...
			cout << "\nSaldo insuficiente!";
			getch();
			return ;
		} else if (valor <= 0) {				//...nem a inserção de dados menores que 0...
			cout << "\nValor invalido!!";
			getch();
			return ;
		} else if(valor > this->dinheiro) { //...nem de um valor maior que o disponivel no caixa.
			cout<<"\nDinheiro insuficiente no caixa!";
			getch();
			return ;
		} else {								//A condição é aceita e o saque ocorre normalmente.
			this->userpadrao[iusuario].getContas()[iconta].setSaldo(this->userpadrao[iusuario].getContas()[iconta].getSaldo() - valor);
			this->dinheiro -= valor;
			this->userpadrao[iusuario].getContas()[iconta].registraOperacao(0,valor);

			cout<<"\nO valor de R$"<<valor<<" foi sacado.";
			cout<<"\nSaldo restante: R$"<<this->userpadrao[iusuario].getContas()[iconta].getSaldo()<<".";
			cout<<"\nDinheiro restante no caixa: R$"<<this->dinheiro<<".";
			getch();
		}
	} else {
		cout<<endl<<"Senha invalida!";
		getch();
	}

}


void Caixa_Eletronico::info() const
{
	cout<<"\n-- Informacoes gerais do caixa eletronico: \n";
	cout<<"\nModelo do caixa: "<<this->modelo;
	cout<<"\nNumero de contas do banco: "<<this->ntotalcontas<<".";
	cout<<"\nDinheiro disponivel no caixa: R$"<<this->dinheiro<<".";
}