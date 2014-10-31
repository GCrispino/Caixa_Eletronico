#include "Banco.h"
#include "stringDigitos.h"
#include <conio.h>

const Data Banco::d(05,10,2014);

ostream &operator << (ostream &output,const Banco &b){
	output << b.nome << "(" << b.id << ").";
	
	return output;
}

Banco::Banco(string nome,int id)
:id(id)
{
	if (stringDigitos(nome))
		this->nome = "";
	else 
		this->nome = nome;
	
	this->nusuarios = 0;
	this->ntotalcontas = 0;
	this->u = NULL;
	
}

Banco::Banco(Banco &b){
	this->id = b.id;
	this->nome = b.nome;
	this->nusuarios = b.nusuarios;
	this->ntotalcontas = b.ntotalcontas;
	
	//Cópia do conteúdo ponteiro 'u':
	if (this->nusuarios == 0)
		this->u = NULL;
	else if (this->nusuarios == 1){
		this->u = new Usuario();
		this->u[0] = this->u[0];
	}
	else{
		this->u = new Usuario[this->nusuarios];
		for (int i = 0;i < this->nusuarios;i++)
			this->u[i] = this->u[i];
	}
}

Banco::~Banco()
{
	if (nusuarios <= 1)
		delete this->u;
	else
		delete [] this->u;
}

Banco Banco::operator =(const Banco &b){
	this->id = b.id;
	this->nome = b.nome;
	this->nusuarios = b.nusuarios;
	this->ntotalcontas = b.ntotalcontas;
	
	//Cópia do conteúdo ponteiro 'u':
	if (this->nusuarios == 0)
		this->u = NULL;
	else if (this->nusuarios == 1){
		this->u = new Usuario();
		this->u[0] = this->u[0];
	}
	else{
		this->u = new Usuario[this->nusuarios];
		for (int i = 0;i < this->nusuarios;i++)
			this->u[i] = this->u[i];
	}
	
	return *this;
}

int Banco::getNContas(){
	return this->ntotalcontas;
}

int Banco::getNUsuarios()
{
	return this->nusuarios;
}

void Banco::setUsuario(Usuario u){
	if (this->nusuarios == 0){
		//Se o numero de usuarios for igual a zero, é alocada memória para o primeiro usuário
		this->u = new Usuario();
		this->u[0] = u;
		this->nusuarios++;
	}
	else{
		//Se não for igual a zero, faz a realocação para mais um elemento.
		Usuario *aux = new Usuario[nusuarios];

			for (int i = 0;i < nusuarios;i++)
				aux[i] = this->u[i];

			delete this->u;

			this->u = new Usuario[++this->nusuarios];

			for (int i = 0;i < nusuarios-1;i++)
				this->u[i] = aux[i];

			this->u[nusuarios-1] = u;

			delete [] aux;
	}
}

Usuario* Banco::getUsuario()
{
	return this->u;
}

void Banco::info() const{
	
	cout<<endl<<"-- Informacoes do banco --";
	cout<<endl<<"- Nome do banco: "<<this->nome;
	cout<<endl<<"- ID do banco: "<<this->id;
	cout<<endl<<"- Numero de usuarios: "<<this->nusuarios;
	cout<<endl<<"- Numero total de contas: "<<this->ntotalcontas;
}

void Banco::registrarUsuario(string &cpf){
	string nome,telefone,endereco,rg,senha;
	int idade;
	Usuario u;
	
	u.setCPF(cpf);
	cout<<endl<<"Nome: ";
	cin.sync();
	getline(cin,nome);
		if (u.validaNome(nome) != nome){
			cout<<endl<<"Valor inserido e' invalido. Sera atribuido um valor padrao";
			getch();
		}
	u.setNome(nome);

	cout<<endl<<"Idade: ";
	cin >> idade;
		if (u.validaIdade(idade) != idade){
			cout<<endl<<"Valor inserido e' invalido. Sera atribuido um valor padrao";
			getch();
		}
	u.setIdade(idade);

	cout<<endl<<"Telefone: ";
	cin >> telefone;
		if (u.validaTelefone(telefone) != telefone){
			cout<<endl<<"Valor inserido e' invalido. Sera atribuido um valor padrao";
			getch();
		}
	u.setTelefone(telefone);

	cout<<endl<<"Endereco: ";
	cin.sync();
	getline(cin,endereco);

		if (u.validaEndereco(endereco) != endereco){
			cout<<endl<<"Valor inserido e' invalido. Sera atribuido um valor padrao";
			getch();
		}
	u.setEndereco(endereco);

	cout<<endl<<"RG: ";
	cin >> rg;
		if (u.validaRG(rg) != rg){
			cout<<endl<<"Valor inserido e' invalido. Sera atribuido um valor padrao";
			getch();
		}
	u.setRG(rg);
	
	this->registrarConta(u);
	
	this->setUsuario(u);
	
}

int Banco::registrarConta(Usuario &u){
	string senha;
	int numero;
	float saldo;
	bool achouconta;
	
	if (u.getNContas() == u.getQTDMAX()){
		cout<<endl<<"Numero maximo de contas por usuario ja alcancado!";
		getch();
		return -1;
	}

	cout<<endl<<"Informacoes da conta: ";
	do{
		achouconta = false;
		cout<<endl<<"Numero da conta: ";
		cin >> numero;
			for (int i = 0;i < this->getNUsuarios();i++){
				if (this->getUsuario()[i].buscaConta(numero) != -1){
				//cout<<endl<<"Conta informada nao encontrada!";
					achouconta = true;
					break;
				}
			}
			if (achouconta){
				cout<<endl<<"Conta informada ja existe!";
				getch();
				cout<<endl<<"Entre com outro numero: ";
			}
			//if (u.buscaConta(numero) != -1)
			//	cout<<endl<<"Conta ja existe!";
	}while(achouconta == true);
			
	cout<<endl<<"Senha: ";
	cin >> senha;
	cout<<endl<<"Saldo: ";
	cin >> saldo;
		
	Conta conta(numero,senha,saldo);
	
	u.setConta(conta);
	
	return 0;
}

void Banco::pagamento(int conta)
{
	int iconta1 = -1, iconta2 = iconta1, iusuario1 = -1, iusuario2 = -1,nconta,achou = 0;
	string senha;
	bool achousenha = false;
	
	
	for (int i = 0; i < this->getNUsuarios(); i++) //busca a conta que realizará o pagamento.
		for (int j = 0; j < this->u[i].getNContas(); j++)
		if (this->u[i].getContas()[j].getNumero() == conta) {
			iusuario1 = i;
			iconta1 = j;
			achou = 1;

			cout<<endl<<"Digite a sua senha: ";
			cin >> senha;
			if (this->u[i].getContas()[j].verificaSenha(senha))
				achousenha = true;
		}
	if (achou == 0) {
		cout<<"\nConta nao encontrada!";
		getch();
		return ;
	} else if (achousenha) {

		float valor;

		cout<<"\nDigite o numero da conta que recebera o pagamento: ";
		cin >> nconta;

		achou = 0;
		for (int i = 0; i < this->getNUsuarios(); i++) //Procura o numero da conta que recebera o pagamento
			for (int j = 0; j < this->u[i].getNContas(); j++)
				if (this->u[i].getContas()[j].getNumero() == nconta) {
					iusuario2 = i;
					iconta2 = j;
					achou = 1;
				}
			if (achou == 0) {
				cout<<"\nConta nao encontrada! ";
				getch();
				return ;
			} else {
				do { //laço "do - while()" para validar o valor do pagamento.
					cout<<"\nDigite o valor do pagamento: ";
					cin >> valor;
					if (valor > this->u[iusuario1].getContas()[iconta1].getSaldo()) {   //Não permite a inserção de dados maiores que o saldo da conta informada...
						cout << "\nValor maior que o saldo!";
						getch();
					} else if (valor <= 0) {				//...nem a inserção de dados menores ou igual a 0.
						cout << "\nValor invalido!!";
						getch();
					} else {								//A condição é aceita e o pagamento ocorre normalmente.
						this->u[iusuario1].getContas()[iconta1].setSaldo(this->u[iusuario1].getContas()[iconta1].getSaldo() - valor - Conta::getTaxa());
						this->u[iusuario2].getContas()[iconta2].setSaldo(this->u[iusuario2].getContas()[iconta2].getSaldo() + valor);
						this->u[iusuario1].getContas()[iconta1].registraOperacao(1,valor);

						cout<<"\nO pagamento no valor de R$"<<valor<<" foi feito.";
						mostrarSaldo(this->u[iusuario1].getContas()[iconta1].getNumero());
						mostrarSaldo(this->u[iusuario2].getContas()[iconta2].getNumero());
						getch();
						break;
					}

				} while (valor < 0 || valor > this->u[iusuario1].getContas()[iconta1].getSaldo());
			}
		} else {
			cout<<endl<<"Senha invalida!";
			getch();
		}
}

void Banco::saque(int conta)
{
	int iconta = -1,iusuario = -1,achou = 0;
	string senha;
	bool achousenha = false;

	for (int i = 0; i < this->getNUsuarios(); i++) //Procura o numero da conta recebido no vetor de contas.
		for (int j = 0; j < this->u[i].getNContas(); j++)
			if (this->u[i].getContas()[j].getNumero() == conta) {
				iusuario = i;
				iconta = j;
				achou = 1;

				cout<<endl<<"Digite a sua senha: ";
				cin >> senha;
				if (this->u[i].getContas()[j].verificaSenha(senha))
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
		if (valor > this->u[iusuario].getContas()[iconta].getSaldo()) {   //Não permite a inserção de dados maiores que o saldo da conta informada...
			cout << "\nSaldo insuficiente!";
			getch();
			return ;
		} else if (valor <= 0) {				//...nem a inserção de dados menores que 0...
			cout << "\nValor invalido!!";
			getch();
			return ;
		} else {								//A condição é aceita e o saque ocorre normalmente.
			this->u[iusuario].getContas()[iconta].setSaldo(this->u[iusuario].getContas()[iconta].getSaldo() - valor);
			this->u[iusuario].getContas()[iconta].registraOperacao(0,valor);

			cout<<"\nO valor de R$"<<valor<<" foi sacado.";
			cout<<"\nSaldo restante: R$"<<this->u[iusuario].getContas()[iconta].getSaldo()<<".";
			getch();
		}
	} else {
		cout<<endl<<"Senha invalida!";
		getch();
	}

}

void Banco::mostrarSaldo(int conta) const
{
	for (int i = 0; i < this->nusuarios; i++)
		for (int j = 0; j < this->u[i].getNContas(); j++)
			if (this->u[i].getContas()[j].getNumero() == conta)
				cout<<"\nO saldo da conta "<<(this->u[i].getContas()[j].getNumero())<<" e' de: R$"<<(this->u[i].getContas()[j].getSaldo());
}

void Banco::incrementaNContas(){
	this->ntotalcontas++;
}

void Banco::mostrarData()
{
	cout<<"\n-Data: ";
	Banco::d.print();
}

int Banco::buscaCPF(string cpf)
{

	for (int i = 0; i < this->nusuarios; i++)
		if (this->u[i].getCPF() == cpf)
			return i;

	return -1;
}