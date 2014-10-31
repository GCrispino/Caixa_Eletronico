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
	this->contausuario = 0;
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
		this->contausuario = 0;
	else if(this->ncontas == 1){
			this->contausuario = new Conta();
			this->contausuario[0] = u.contausuario[0];
	}
	else{
		this->contausuario = new Conta[this->ncontas];
		for (int i = 0;i < this->ncontas;i++)
			this->contausuario[i] = u.contausuario[i];
	}
}

Usuario::~Usuario()
{
	if (this->ncontas <= 1)
		delete this->contausuario;
	else
		delete [] this->contausuario;
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
		this->contausuario = 0;
	else if(this->ncontas == 1){
			this->contausuario = new Conta();
			this->contausuario[0] = u.contausuario[0];
	}
	else{
		this->contausuario = new Conta[this->ncontas];
		for (int i = 0;i < this->ncontas;i++)
			this->contausuario[i] = u.contausuario[i];
	}
	
	return *this;
}

bool Usuario::operator ==(const Usuario &u){
	return (this->nome==nome && this->idade==idade && this->telefone==telefone && this->endereco==endereco && this->rg==rg && this->cpf==cpf);
}

string Usuario::validaNome(const string &nome){
	bool achoudigito = false;
	
	for (unsigned int i = 0;i < nome.size();i++)
		if (isdigit(nome[i]))
			achoudigito = true;
			
	if (achoudigito)
		return "";
	else
		return nome;
}

int Usuario::validaIdade(const int idade){
	if (idade <= 0 || idade >= 180)
		return 1; //se a idade for inválida, retorna uma idade default igual a 1.
	else
		return idade; //caso contrário, a idade passada é válida e é retornada.
	
}

string Usuario::validaTelefone(const string &telefone){
	if (stringDigitos(&telefone) && telefone.size() == 8)
		return telefone;
	else 
		return "11111111";
}

string Usuario::validaEndereco(const string &endereco){
	if (stringDigitos(&endereco))
		return "";
	else
		return endereco;
}

string Usuario::validaRG(const string &rg){
	if (stringDigitos(&rg))
		return rg;
	else
		return "00000000";
}

string Usuario::validaCPF(const string &cpf){
	if (stringDigitos(&cpf) && cpf.size() == 11)
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
		cout<<endl<<"Numero da conta: "<<this->contausuario[i]<<".";
		getch();
	}
}

int Usuario::setConta(Conta conta){
	if (conta.getNumero() < 0){
		cout<< "\nValor invalido!";
		getch();
		return -1;
	}
	else if (this->ncontas == 0){
		//Se o numero de contas for 0, é alocada a memória para o primeiro elemento.
		this->contausuario = new Conta();
		this->contausuario[0] = conta;
		this->ncontas++;
		return 0;
	}
	else{//se não for igual a 0, faz a busca para checar se a conta dada ja existe..
		int achou = 0;
		for (int i = 0;i < this->ncontas;i++)
			if (this->contausuario[i] == conta){
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
				aux[i] = this->contausuario[i];
				
			delete this->contausuario;

			this->contausuario = new Conta[++this->ncontas];
			
			for (int i = 0;i < ncontas-1;i++)
				this->contausuario[i] = aux[i];	
				
			this->contausuario[ncontas-1] = conta;
			
			delete [] aux;
			
			return 0;
		}
	}
}

int Usuario::buscaConta(int nconta){
	
	if (this->ncontas == 0)
		return -1;
	
	for (int i = 0; i < this->ncontas;i++)
		if (this->contausuario[i].getNumero() == nconta)
			return i;
		
	return -1;
}