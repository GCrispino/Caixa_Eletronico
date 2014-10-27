#include "Usuario.h"

#include <string>
#include <conio.h>

const int Usuario::QTDMAX = 3; //inicialização da variável const static 'QTDMAX'.

ostream &operator << (ostream &output, const Usuario &u){
	output << u.nome << "(" << u.cpf << ")";
	
	return output;
}

Usuario::Usuario(string nome, int idade, string cpf, string telefone, string endereco, string rg)
{
	this->nome = this->validaNome(nome);
	this->idade = this->validaIdade(idade);
	this->telefone = this->validaTelefone(telefone);
	this->rg = this->validaRG(rg);
	this->cpf = this->validaCPF(cpf);
	this->ncontas = 0;
	this->contas = NULL;
}

Usuario::Usuario(const Usuario &u){
	this->nome = u.nome;
	this->idade = u.idade;
	this->telefone = u.telefone;
	this->endereco = u.endereco;
	this->rg = u.rg;
	this->cpf = u.cpf;
	this->ncontas = u.ncontas;
	
	//Cópia dos ponteiros: 
	if (this->ncontas == 0)
		this->contas = NULL;
	else if(this->ncontas == 1){
			this->contas = new Conta();
			this->contas[0] = u.contas[0];
	}
	else{
		this->contas = new Conta[this->ncontas];
		for (int i = 0;i < this->ncontas;i++)
			this->contas[i] = u.contas[i];
	}
}

Usuario::~Usuario()
{
	if (this->ncontas <= 1)
		delete this->contas;
	else
		delete [] this->contas;
}

Usuario Usuario::operator = (const Usuario &u){
	this->nome = u.nome;
	this->idade = u.idade;
	this->telefone = u.telefone;
	this->endereco = u.endereco;
	this->rg = u.rg;
	this->cpf = u.cpf;
	this->ncontas = u.ncontas;
	
	//Cópia dos ponteiros: 
	if (this->ncontas == 0)
		this->contas = NULL;
	else if(this->ncontas == 1){
			this->contas = new Conta();
			this->contas[0] = u.contas[0];
	}
	else{
		this->contas = new Conta[this->ncontas];
		for (int i = 0;i < this->ncontas;i++)
			this->contas[i] = u.contas[i];
	}
	
	return *this;
}

bool Usuario::operator ==(const Usuario &u){
	return (this->nome==nome && this->idade==idade && this->telefone==telefone && this->endereco==endereco && this->rg==rg && this->cpf==cpf);
}

string Usuario::validaNome(string &nome){
	bool achoudigito = false;
	
	for (unsigned int i = 0;i < nome.size();i++)
		if (isdigit(nome[i]))
			achoudigito = true;
			
	if (achoudigito)
		return "";
	else
		return nome;
}

int Usuario::validaIdade(int idade){
	if (idade <= 0 || idade >= 180)
		return 1; //se a idade for inválida, retorna uma idade default igual a 1.
	else
		return idade; //caso contrário, a idade passada é válida e é retornada.
	
}

string Usuario::validaTelefone(string &telefone){
	if (stringDigitos(telefone) && telefone.size() == 8)
		return telefone;
	else 
		return "11111111";
}

string Usuario::validaEndereco(string &endereco){
	if (stringDigitos(endereco))
		return "";
	else
		return endereco;
}

string Usuario::validaRG(string &rg){
	if (stringDigitos(rg))
		return rg;
	else
		return "00000000";
}

string Usuario::validaCPF(string &cpf){
	if (stringDigitos(cpf) && cpf.size() == 11)
		return cpf;
	else
		return "00000000000";
}

void Usuario::info(){
	cout<<endl<<"--Informacoes do usuario: ";
	cout<<endl<<"  - Nome: "<<this->nome<<".";
	cout<<endl<<"  - Idade: "<<this->idade<<".";
	cout<<endl<<"  - Telefone: "<<this->telefone<<".";
	cout<<endl<<"  - Endereco: "<<this->endereco<<".";
	cout<<endl<<"  - RG: "<<this->rg<<".";
	cout<<endl<<"  - CPF: "<<this->cpf<<".";
	cout<<endl<<"  - Numero de contas do usuario: "<<this->ncontas<<".";
}

void Usuario::incrementaNContas(){
	this->ncontas = this->ncontas + 1;
}

void Usuario::imprimeContas(){
	for (int i = 0;i < this->ncontas;i++){
		cout<<endl<<"Numero da conta: "<<this->contas[i]<<".";
		getch();
	}
}

/*int Caixa_Eletronico::setConta(Conta conta){
	if (conta.getNumero() < 0){
		cout<< "\nValor invalido!";
		getch();
		return -1;
	}
	else if (Caixa_Eletronico::ncontas == 0){
		//Se o numero de contas for 0, é alocada a memória para o primeiro elemento.
		Caixa_Eletronico::c = new Conta();
		Caixa_Eletronico::c[0] = conta;
//		incrementaNClientes();
		incrementaNContas();
		return 0;
	}
	else{//se não for igual a 0, faz a busca para checar se a conta dada ja existe..
		int achou = 0;
		for (int i = 0;i < this->ncontas;i++)
			if (this->c[i] == conta){
				achou = 1;
				break;
			}
		
		if (achou == 1){//...se ja existe, retorna um erro na funcao.
			cout<<"\nConta ja existe!";
			getch();
			return -1;
		}
		else{//caso contrário, aloca memória para um novo elemento.
			Conta *aux = new Conta[ncontas];
			
			for (int i = 0;i < ncontas;i++)
				aux[i] = this->c[i];
				
			delete this->c;

			this->c = new Conta[++this->ncontas];
			
			for (int i = 0;i < ncontas-1;i++)
				this->c[i] = aux[i];	
				
			this->c[ncontas-1] = conta;
			
			delete [] aux;
			
//			incrementaNClientes();
			return 0;
		}
	}
}*/

/*void Usuario::setContas(Conta nconta){
	if (this->ncontas == 0){
		this->contas = new Conta();
		this->contas[0] = nconta;
		this->incrementaNContas();
	}
	else{
		Conta *aux = new Conta[this->ncontas];
		int i;
		
		for (i = 0;i < this->ncontas;i++)
			aux[i] = this->contas[i];
			
		delete this->contas;
		
		this->contas = new Conta[++this->ncontas];
		
		for (i = 0;i < this->ncontas;i++)
			this->contas[i] = aux[i];
			
		this->contas[this->ncontas - 1] = nconta;
		
		delete [] aux;
	}
}*/


int Usuario::setConta(Conta conta){
	if (conta.getNumero() < 0){
		cout<< "\nValor invalido!";
		getch();
		return -1;
	}
	else if (this->ncontas == 0){
		//Se o numero de contas for 0, é alocada a memória para o primeiro elemento.
		this->contas = new Conta();
		this->contas[0] = conta;
		this->ncontas++;
		return 0;
	}
	else{//se não for igual a 0, faz a busca para checar se a conta dada ja existe..
		int achou = 0;
		for (int i = 0;i < this->ncontas;i++)
			if (this->contas[i] == conta){
				achou = 1;
				break;
			}
		
		if (achou == 1){//...se ja existe, retorna um erro na funcao.
			cout<<"\nConta ja existe!";
			getch();
			return -1;
		}
		else{//caso contrário, aloca memória para um novo elemento.
			Conta *aux = new Conta[ncontas];
			
			for (int i = 0;i < ncontas;i++)
				aux[i] = this->contas[i];
				
			delete this->contas;

			this->contas = new Conta[++this->ncontas];
			
			for (int i = 0;i < ncontas-1;i++)
				this->contas[i] = aux[i];	
				
			this->contas[ncontas-1] = conta;
			
			delete [] aux;
			
//			incrementaNClientes();
			return 0;
		}
	}
}

int Usuario::buscaConta(int nconta){
	
	if (this->ncontas == 0)
		return -1;
	
	for (int i = 0; i < this->ncontas;i++)
		if (this->contas[i].getNumero() == nconta)
			return i;
		
	return -1;
}