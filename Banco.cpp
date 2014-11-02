#include "Banco.h"
#include "stringDigitos.h"
#include <conio.h>

const Data Banco::dataAtual(05,10,2014);

ostream &operator << (ostream &output,const Banco &b){
	output<<endl<<"-- Informacoes do banco --";
	output<<endl<<"- Nome do banco: "<<b.nome;
	output<<endl<<"- ID do banco: "<<b.id;
	output<<endl<<"- Numero de usuarios: "<<b.nusuarios;
	output<<endl<<"- Numero total de contas: "<<b.ntotalcontas;
	
	return output;
}

Banco::Banco(string nome,int id){
	if (stringDigitos(&nome))
		this->nome = "";
	else 
		this->nome = nome;
	
	if (id < 0)//não permite a entrada de números negativos.
		this->id = 12345;
	else
		this->id = id;		
	
	this->nusuarios = 0;
	this->ntotalcontas = 0;
	this->userpadrao = 0;
	
}

Banco::Banco(const Banco &b){
	this->id = b.id;
	this->nome = b.nome;
	this->nusuarios = b.nusuarios;
	this->ntotalcontas = b.ntotalcontas;
	
	//Cópia do conteúdo ponteiro 'u':
	if (this->nusuarios == 0)
		this->userpadrao = 0;
	else if (this->nusuarios == 1){
		this->userpadrao = new Usuario();
		this->userpadrao[0] = this->userpadrao[0];
	}
	else{
		this->userpadrao = new Usuario[this->nusuarios];
		for (int i = 0;i < this->nusuarios;i++)
			this->userpadrao[i] = this->userpadrao[i];
	}
}

Banco::~Banco()
{
	if (nusuarios <= 1)
		delete this->userpadrao;
	else
		delete [] this->userpadrao;
}

Banco Banco::operator =(const Banco &b){
	this->id = b.id;
	this->nome = b.nome;
	this->nusuarios = b.nusuarios;
	this->ntotalcontas = b.ntotalcontas;
	
	//Cópia do conteúdo ponteiro 'u':
	if (nusuarios <= 1)
		delete this->userpadrao;
	else
		delete [] this->userpadrao;
		
	if (this->nusuarios == 0)
		this->userpadrao = 0;
	else if (this->nusuarios == 1){
		this->userpadrao = new Usuario();
		this->userpadrao[0] = this->userpadrao[0];
	}
	else{
		this->userpadrao = new Usuario[this->nusuarios];
		for (int i = 0;i < this->nusuarios;i++)
			this->userpadrao[i] = this->userpadrao[i];
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

void Banco::setUsuario(const Usuario &u){
	if (this->nusuarios == 0){
		//Se o numero de usuarios for igual a zero, é alocada memória para o primeiro usuário
		this->userpadrao = new Usuario();
		this->userpadrao[0] = u;
		this->nusuarios++;
	}
	else{
		//Se não for igual a zero, faz a realocação para mais um elemento.
		Usuario *aux = new Usuario[nusuarios];

			for (int i = 0;i < nusuarios;i++)
				aux[i] = this->userpadrao[i];

			delete this->userpadrao;

			this->userpadrao = new Usuario[++this->nusuarios];

			for (int i = 0;i < nusuarios-1;i++)
				this->userpadrao[i] = aux[i];

			this->userpadrao[nusuarios-1] = u;

			delete [] aux;
	}
}

/*void Banco::info() const{
	
	cout<<endl<<"-- Informacoes do banco --";
	cout<<endl<<"- Nome do banco: "<<this->nome;
	cout<<endl<<"- ID do banco: "<<this->id;
	cout<<endl<<"- Numero de usuarios: "<<this->nusuarios;
	cout<<endl<<"- Numero total de contas: "<<this->ntotalcontas;
}*/

void Banco::registrarUsuario(const string &cpf){
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
	//bool achouconta;
	const Conta *contabusca;
	
	if (u.getNContas() == u.getQTDMAX()){
		cout<<endl<<"Numero maximo de contas por usuario ja alcancado!";
		getch();
		return -1;
	}

	cout<<endl<<"Informacoes da conta: ";
	do{
		//achouconta = false;
		cout<<endl<<"Numero da conta: ";
		cin >> numero;
		contabusca = this->buscaConta(numero);
		
			if (contabusca != 0){
				cout<<endl<<"Conta informada ja existe!";
				getch();
				cout<<endl<<"Entre com outro numero: ";
			}
	}while(contabusca != 0);
			
	cout<<endl<<"Senha: ";
	cin >> senha;
	cout<<endl<<"Saldo: ";
	cin >> saldo;
		
	Conta conta(numero,senha,saldo);
	
	u.setConta(conta);
	
	return 0;
}

void Banco::pagamento(const int conta)
{
	int nconta;
	string senha;
	bool achousenha = false;
	const Conta * contabusca = this->buscaConta(conta);
	
	if (contabusca != 0) {

		cout<<endl<<"Digite a sua senha: ";
		cin >> senha;
		if (contabusca->verificaSenha(senha))
			achousenha = true;
	}
	if (contabusca == 0) {
		cout<<"\nConta nao encontrada!";
		getch();
		return ;
	} else if (achousenha) {

		float valor;

		do{
			cout<<"\nDigite o numero da conta que recebera o pagamento: ";
			cin >> nconta;
				if (nconta == conta)
					cout<<endl<<"Valor invalido!";
		}while(nconta == conta);

		const Conta *contabusca2 = this->buscaConta(nconta);
		
			if (contabusca2 == 0) {
				cout<<"\nConta nao encontrada! ";
				getch();
				return ;
			} else {
				do { //laço "do - while()" para validar o valor do pagamento.
					cout<<"\nDigite o valor do pagamento: ";
					cin >> valor;
					if (valor > contabusca2->getSaldo()) {   //Não permite a inserção de dados maiores que o saldo da conta informada...
						cout << "\nValor maior que o saldo!";
						getch();
					} else if (valor <= 0) {				//...nem a inserção de dados menores ou igual a 0.
						cout << "\nValor invalido!!";
						getch();
					} else {								//A condição é aceita e o pagamento ocorre normalmente.
						const_cast<Conta &>(*contabusca).setSaldo(contabusca->getSaldo() - valor - Conta::getTaxa());
						const_cast<Conta &>(*contabusca2).setSaldo(contabusca2->getSaldo() + valor);
						const_cast<Conta &>(*contabusca).registraOperacao(1,valor);

						cout<<"\nO pagamento no valor de R$"<<valor<<" foi feito.";
						mostrarSaldo(contabusca->getNumero());
						mostrarSaldo(contabusca2->getNumero());
						getch();
						break;
					}

				} while (valor < 0 || valor > contabusca->getSaldo());
			}
		} else {
			cout<<endl<<"Senha invalida!";
			getch();
		}
}

void Banco::saque(const int conta)
{
	int achou = 0;
	string senha;
	bool achousenha = false;
	const Conta * contabusca = this->buscaConta(conta);
	
			if (contabusca->getNumero() == conta) {

				cout<<endl<<"Digite a sua senha: ";
				cin >> senha;
				if (contabusca->verificaSenha(senha))
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
		if (valor > contabusca->getSaldo()) {   //Não permite a inserção de dados maiores que o saldo da conta informada...
			cout << "\nSaldo insuficiente!";
			getch();
			return ;
		} else if (valor <= 0) {				//...nem a inserção de dados menores que 0...
			cout << "\nValor invalido!!";
			getch();
			return ;
		} else {								//A condição é aceita e o saque ocorre normalmente.
			const_cast<Conta &>(*contabusca).setSaldo(contabusca->getSaldo() - valor);
			const_cast<Conta &>(*contabusca).registraOperacao(0,valor);

			cout<<"\nO valor de R$"<<valor<<" foi sacado.";
			cout<<"\nSaldo restante: R$"<<contabusca->getSaldo()<<".";
			getch();
		}
	} else {
		cout<<endl<<"Senha invalida!";
		getch();
	}

}

void Banco::mostrarSaldo(const int nconta) const
{
	const Conta * conta = const_cast<Banco*>(this)->buscaConta(nconta);
	
	cout<<"\nO saldo da conta "<<conta->getNumero()<<" e' de: R$"<<conta->getSaldo();
}

void Banco::incrementaNContas(){
	this->ntotalcontas++;
}

void Banco::mostrarData()
{
	cout<<"\n-Data: ";
	Banco::dataAtual.print();
}

const Conta * Banco::buscaConta(const int nconta){
	const Conta *c = 0;
	
	for (int i = 0;i < this->nusuarios;i++)
		if (this->userpadrao[i].buscaConta(nconta) != 0)
			c = userpadrao[i].buscaConta(nconta);
			
	return c;
}

const Usuario * Banco::buscaCPF(const string &cpf)
{

	for (int i = 0; i < this->nusuarios; i++)
		if (this->userpadrao[i].getCPF() == cpf)
			return &userpadrao[i];

	return 0;
}