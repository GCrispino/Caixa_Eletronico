#include "Caixa_Eletronico.h"

#include <conio.h>
#include <stdlib.h>


//int Caixa_Eletronico::nclientes = 0;
Data Caixa_Eletronico::d(05,10,2014);
//Conta *Caixa_Eletronico::c = 0;		//Inicialização das variáveis 'static'
Usuario *Caixa_Eletronico::u = 0;
vector<float> Caixa_Eletronico::saldo(0);
//int Caixa_Eletronico::ncontas = 0;
int Caixa_Eletronico::nusuarios = 0;
int Caixa_Eletronico::ntotalcontas = 0;

const int Caixa_Eletronico::IDBANCO = 55873;
const string Caixa_Eletronico::NOMEBANCO = "Banco Universitario";

bool Caixa_Eletronico::operator == (const Caixa_Eletronico &c1)
{
	if (this->modelo == c1.modelo && this->dinheiro == c1.dinheiro && this->u == c1.u && this->saldo == c1.saldo && this->d == c1.d)
		return true;
	else
		return false;
}

ostream &operator << (ostream &output,const Caixa_Eletronico &c)
{
	output << c.modelo << " (" << c.NOMEBANCO<<")";

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

Caixa_Eletronico::Caixa_Eletronico(float dinheiro,string *modelo, Data data)
{
	if (dinheiro >= 0)
		this->dinheiro = dinheiro;
	else
		this->dinheiro = 0;
	this->modelo = *modelo;

	//if (nclientes >= 0)
	//Caixa_Eletronico::nclientes = nclientes;

	Caixa_Eletronico::d = d; //variável data não precisa ser validada, pois a validação é feita dentro da classe 'data'
}

Caixa_Eletronico::Caixa_Eletronico(Caixa_Eletronico &c)
{
	//this->nclientes = c.nclientes;
	this->dinheiro = c.dinheiro;
	this->modelo = c.modelo;
}

Caixa_Eletronico::~Caixa_Eletronico()
{
	if (Caixa_Eletronico::nusuarios <= 1)
		delete u;
	else
		delete [] u;
}

int Caixa_Eletronico::getNContas(){
	return Caixa_Eletronico::ntotalcontas;
}

void Caixa_Eletronico::setUsuario(Usuario u){
	if (Caixa_Eletronico::nusuarios == 0){
		//Se o numero de usuarios for igual a zero, é alocada memória para o primeiro usuário
		Caixa_Eletronico::u = new Usuario();
		Caixa_Eletronico::u[0] = u;
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

int Caixa_Eletronico::getNUsuarios()
{
	return this->nusuarios;
}

Usuario* Caixa_Eletronico::getUsuario()
{
	return this->u;
}

/*void Caixa_Eletronico::registrarConta(){
	string nome,telefone,endereco,rg,cpf,senha;
	int idade,numero;
	float saldo;
	Usuario u;

	cout<<endl<<" --Registro de contas-- ";
	getch();

	cout<<endl<<"Informacoes do usuario: ";

	cout<<endl<<"CPF: ";
	cin >> cpf;
		if (u.validaCPF(cpf) != cpf){
			cout<<endl<<"Valor inserido e' invalido. Sera atribuido um valor padrao";
			getch();
		}
		//Se no CPF não for encontrado, é criado um usuário novo.
		if (this->buscaCPF(cpf) == -1){
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

			system("cls");

			cout<<endl<<"Informacoes da conta: ";
			do{
				cout<<endl<<"Numero da conta: ";
				cin >> numero;
					if (Caixa_Eletronico::buscaConta(numero) != -1)
						cout<<endl<<"Conta ja existe!";
			}while(Caixa_Eletronico::buscaConta(numero) != -1);
			cout<<endl<<"Senha: ";
			cin >> senha;
			cout<<endl<<"Saldo: ";
			cin >> saldo;

			Conta conta(numero,senha,saldo);

			u.setContas(numero);

			conta.setUsuario(u);

			this->setConta(conta);
		}
		//Se o CPF for encontrado, e se o dono desse CPF não tiver ultrapassado o limite de número de contas,
		//mais uma conta é registrada em seu nome.
		else if (Caixa_Eletronico::c[this->buscaCPF(cpf)].getUsuario().getNContas() < Caixa_Eletronico::c[this->buscaCPF(cpf)].getUsuario().getQTDMAX()){
			//atribui ao usuário criado o usuário ao qual o CPF pertence, para depois sobrescrevê-lo no término desse método,
			//para que os novos valores sejam atualizados.
			u = Caixa_Eletronico::c[this->buscaCPF(cpf)].getUsuario();
			system("cls");

			cout<<endl<<"Informacoes da conta: ";
			do{
				cout<<endl<<"Numero da conta: ";
				cin >> numero;
					if (Caixa_Eletronico::buscaConta(numero) != -1)
						cout<<endl<<"Conta ja existe!";
			}while(Caixa_Eletronico::buscaConta(numero) != -1);

			cout<<endl<<"Senha: ";
			cin >> senha;
			cout<<endl<<"Saldo: ";
			cin >> saldo;

			Conta conta(numero,senha,saldo);

			//guarda o mesmo usuário que possui o CPF dado na conta nova.
			conta.setUsuario(Caixa_Eletronico::c[this->buscaCPF(cpf)].getUsuario());
			//guarda o numero da conta nova no usuário do CPF dado.
			u.setContas(numero);
			Caixa_Eletronico::c[this->buscaCPF(cpf)].getUsuario().incrementaNContas();

			Caixa_Eletronico::c[this->buscaCPF(cpf)].setUsuario(u);
			this->setConta(conta);
		}
		else{
			cout<<endl<<"Limite de contas por usuario ultrapassado!";
			getch();
		}
}*/

void Caixa_Eletronico::saque(int conta)
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
		} else if(valor > this->dinheiro) { //...nem de um valor maior que o disponivel no caixa.
			cout<<"\nDinheiro insuficiente no caixa!";
			getch();
			return ;
		} else {								//A condição é aceita e o saque ocorre normalmente.
			this->u[iusuario].getContas()[iconta].setSaldo(this->u[iusuario].getContas()[iconta].getSaldo() - valor);
			this->dinheiro -= valor;
			this->u[iusuario].getContas()[iconta].registraOperacao(0,valor);

			cout<<"\nO valor de R$"<<valor<<" foi sacado.";
			cout<<"\nSaldo restante: R$"<<this->u[iusuario].getContas()[iconta].getSaldo()<<".";
			cout<<"\nDinheiro restante no caixa: R$"<<this->dinheiro<<".";
			getch();
		}
	} else {
		cout<<endl<<"Senha invalida!";
		getch();
	}

}

void Caixa_Eletronico::pagamento(int conta)
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

void Caixa_Eletronico::mostrarSaldo(int conta) const
{
	for (int i = 0; i < this->nusuarios; i++)
		for (int j = 0; j < this->u[i].getNContas(); j++)
			if (this->u[i].getContas()[j].getNumero() == conta)
				cout<<"\nO saldo da conta "<<(this->u[i].getContas()[j].getNumero())<<" e' de: R$"<<(this->u[i].getContas()[j].getSaldo());
}


void Caixa_Eletronico::info() const
{
	cout<<"\n-- Informacoes gerais do caixa eletronico: \n";
	cout<<"\nBanco: "<<NOMEBANCO<<"(ID do banco: "<<IDBANCO<<").";
	cout<<"\nModelo do caixa: "<<this->modelo;
	cout<<"\nNumero de contas do banco: "<<this->ntotalcontas<<".";
	cout<<"\nDinheiro disponivel no caixa: R$"<<this->dinheiro<<".";
}

int Caixa_Eletronico::buscaCPF(string cpf)
{

	for (int i = 0; i < Caixa_Eletronico::nusuarios; i++)
		if (Caixa_Eletronico::u[i].getCPF() == cpf)
			return i;

	return -1;
}

void Caixa_Eletronico::mostrarData()
{
	cout<<"\n-Data: ";
	Caixa_Eletronico::d.print();
}

/*void Caixa_Eletronico::incrementaNClientes(){
	Caixa_Eletronico::nclientes++;
}*/

void Caixa_Eletronico::incrementaNContas()
{
	Caixa_Eletronico::ntotalcontas++;
}

void Caixa_Eletronico::registrarUsuario(string &cpf){
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

int Caixa_Eletronico::registrarConta(Usuario &u){
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
