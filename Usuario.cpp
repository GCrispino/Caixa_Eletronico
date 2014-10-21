#include "Usuario.h"

#include <string>

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
}

Usuario::Usuario(const Usuario &u){
	this->nome = u.nome;
	this->idade = u.idade;
	this->telefone = u.telefone;
	this->endereco = u.endereco;
	this->rg = u.rg;
	this->cpf = u.cpf;
}

Usuario::~Usuario()
{
}

Usuario Usuario::operator = (const Usuario &u){
	this->nome = u.nome;
	this->idade = u.idade;
	this->telefone = u.telefone;
	this->endereco = u.endereco;
	this->rg = u.rg;
	this->cpf = u.cpf;
	
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
}

void Usuario::imprimeUsuario(){
	cout<<*this;
}

bool Usuario::stringDigitos(const string &s){
	if (s.empty())
		return false;
	for (unsigned int i = 0;i < s.size();i++)
		if (isdigit(s[i]) == 0)
			return false;
	
	return true;
}