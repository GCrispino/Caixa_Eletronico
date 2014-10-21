#include "Caixa_Eletronico.h"

#include <conio.h>
#include <stdlib.h>


int Caixa_Eletronico::nclientes = 0;
Data Caixa_Eletronico::d(05,10,2014);
Conta *Caixa_Eletronico::c = 0;		//Inicialização das variáveis 'static'
vector<float> Caixa_Eletronico::saldo(0);
int Caixa_Eletronico::ncontas = 0;

const int Caixa_Eletronico::IDBANCO = 55873;
const string Caixa_Eletronico::NOMEBANCO = "Banco Universitario";

bool Caixa_Eletronico::operator == (const Caixa_Eletronico &c1){
	if (this->modelo == c1.modelo && this->dinheiro == c1.dinheiro && this->c == c1.c && this->saldo == c1.saldo && this->d == c1.d)
		return true;
	else
		return false;
}

ostream &operator << (ostream &output,const Caixa_Eletronico &c){
	output << c.modelo << " (" << c.NOMEBANCO<<")";
	
	return output;
}

Caixa_Eletronico Caixa_Eletronico::operator =(const Caixa_Eletronico &c){
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

Caixa_Eletronico::Caixa_Eletronico(float dinheiro,string *modelo, int nclientes, Data data){
	if (dinheiro >= 0)
		this->dinheiro = dinheiro;
	else
		this->dinheiro = 0;
	this->modelo = *modelo;
	
	if (nclientes >= 0)
		Caixa_Eletronico::nclientes = nclientes;
		
	Caixa_Eletronico::d = d; //variável data não precisa ser validada, pois a validação é feita dentro da classe 'data'
}

Caixa_Eletronico::Caixa_Eletronico(Caixa_Eletronico &c){
	this->nclientes = c.nclientes;
	this->dinheiro = c.dinheiro;
	this->modelo = c.modelo;
}

Caixa_Eletronico::~Caixa_Eletronico()
{
	if (Caixa_Eletronico::ncontas <= 1)
		delete c;
	else
		delete [] c;
}

int Caixa_Eletronico::setConta(Conta conta){
	if (conta.getNumero() < 0){
		cout<< "\nValor invalido!";
		getch();
		return -1;
	}
	else if (Caixa_Eletronico::ncontas == 0){
		//Se o numero de contas for 0, é alocada a memória para o primeiro elemento.
		Caixa_Eletronico::c = new Conta();
		Caixa_Eletronico::c[0] = conta;
		incrementaNClientes();
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
			
			incrementaNClientes();
			return 0;
		}
	}
}

/*void Caixa_Eletronico::setSaldo(int conta, float saldo){
	if (saldo < 0){
		cout<<"\nValor invalido!!";
		return ;
	}
	else
		for (int i = 0;i < this->ncontas;i++)
			if(conta == this->conta[i])
				this->saldo.push_back(saldo);
}*/

int Caixa_Eletronico::getNContas(){
	return this->ncontas;
}

void Caixa_Eletronico::registrarConta(){
	string nome,telefone,endereco,rg,cpf,senha;
	int idade,numero;
	float saldo;
	Usuario u;
	
	cout<<endl<<" --Registro de contas-- ";
	getch();
	
	cout<<endl<<"Informacoes do usuario: ";
	cout<<endl<<"Nome: ";
	cin >> nome;
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
	cin >> endereco;
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
	
	cout<<endl<<"CPF: ";
	cin >> cpf;
		if (u.validaCPF(cpf) != cpf){
			cout<<endl<<"Valor inserido e' invalido. Sera atribuido um valor padrao";
			getch();
		}
	u.setCPF(cpf);
	
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
	conta.setUsuario(u);
	
	this->setConta(conta);
}

void Caixa_Eletronico::saque(int conta){
	int iconta = -1,achou = 0;
	string senha;
	bool achousenha = false;
	
	for (int i = 0; i < this->ncontas;i++) //Procura o numero da conta recebido no vetor de contas.
		if (this->c[i].getNumero() == conta){
			iconta = i;
			achou = 1;
			
			cout<<endl<<"Digite a sua senha: ";
			cin >> senha;
			if (this->c[i].verificaSenha(senha))
				achousenha = true;
		}
	if (achou == 0){
		cout<<"\nConta nao encontrada!";
		getch();
		return ;
	}	
	else if(achousenha){
		float valor;
		
		cout<<"\nDigite o valor a ser sacado: ";
		cin >> valor;
			if (valor > this->c[iconta].getSaldo()){    //Não permite a inserção de dados maiores que o saldo da conta informada...
				cout << "\nSaldo insuficiente!";
				getch();
				return ;
			}
			else if (valor <= 0){				//...nem a inserção de dados menores que 0...
				cout << "\nValor invalido!!";
				getch();
				return ;
			}
			else if(valor > this->dinheiro){  //...nem de um valor maior que o disponivel no caixa.
					cout<<"\nDinheiro insuficiente no caixa!";
					getch();
					return ;
			}
			else{								//A condição é aceita e o saque ocorre normalmente.
				this->c[iconta].setSaldo(c[iconta].getSaldo() - valor);
				this->dinheiro -= valor;
				this->c[iconta].registraOperacao(0,valor);
			
				cout<<"\nO valor de R$"<<valor<<" foi sacado.";
				cout<<"\nSaldo restante: R$"<<this->c[iconta].getSaldo()<<".";
				cout<<"\nDinheiro restante no caixa: R$"<<this->dinheiro<<".";
				getch();
			}
	}
	else{
		cout<<endl<<"Senha invalida!";
		getch();
	}
	
}

void Caixa_Eletronico::pagamento(int conta){
	int iconta1 = -1, iconta2 = iconta1, nconta,achou = 0;
	string senha;
	bool achousenha = false;
	
	for (int i = 0; i < this->ncontas;i++)	//Procura a conta passada como argumento
		if (this->c[i].getNumero() == conta){
			iconta1 = i;
			achou = 1;
			
			cout<<endl<<"Digite a sua senha: ";
			cin >> senha;
			if (this->c[i].verificaSenha(senha))
				achousenha = true;
		}
	if (achou == 0){
		cout<<"\nConta nao encontrada!";
		getch();
		return ;
	}
	else if (achousenha){
		
		float valor;
	
		cout<<"\nDigite o numero da conta que recebera o pagamento: ";
		cin >> nconta;
	
		achou = 0;
		for (int i = 0;i < this->ncontas;i++)  //Procura o numero da conta que recebera o pagamento
			if (this->c[i].getNumero() == nconta){
				iconta2 = i;
				achou = 1;
			}
		if (achou == 0){
			cout<<"\nConta nao encontrada! ";
			getch();
			return ;
		}
		else{
			do{ //laço "do - while()" para validar o valor do pagamento.
				cout<<"\nDigite o valor do pagamento: ";
				cin >> valor;
					if (valor > this->c[iconta1].getSaldo()){    //Não permite a inserção de dados maiores que o saldo da conta informada...
						cout << "\nValor maior que o saldo!";
						getch();
					}
					else if (valor <= 0){				//...nem a inserção de dados menores ou igual a 0.
						cout << "\nValor invalido!!";
						getch();
					}
					else{								//A condição é aceita e o pagamento ocorre normalmente.
						this->c[iconta1].setSaldo(c[iconta1].getSaldo() - valor);
						this->c[iconta2].setSaldo(c[iconta2].getSaldo() + valor);
						this->c[iconta1].registraOperacao(1,valor);
						
						cout<<"\nO pagamento no valor de R$"<<valor<<" foi feito.";
						mostrarSaldo(this->c[iconta1].getNumero());
						mostrarSaldo(this->c[iconta2].getNumero());
						getch();
						break;
					}
	
			}while (valor < 0 || valor > this->c[iconta1].getSaldo());
		}
	}
	else{
		cout<<endl<<"Senha invalida!";
		getch();
	}
}

void Caixa_Eletronico::mostrarSaldo(int conta) const{
	for (int i = 0;i < this->ncontas;i++)
		if (this->c[i].getNumero() == conta)
			cout<<"\nO saldo da conta "<<(Caixa_Eletronico::c[i].getNumero())<<" e' de: R$"<<(Caixa_Eletronico::c[i].getSaldo());
}


void Caixa_Eletronico::info() const{
	cout<<"\n-- Informacoes gerais do caixa eletronico: \n";
	cout<<"\nBanco: "<<NOMEBANCO<<"(ID do banco: "<<IDBANCO<<").";
	cout<<"\nModelo do caixa: "<<this->modelo;
	cout<<"\nNumero de clientes do banco: "<<this->nclientes<<".";
	cout<<"\nDinheiro disponivel no caixa: R$"<<this->dinheiro<<".";
}

int Caixa_Eletronico::buscaConta(int nconta){
	bool achou = false;
	int i;
	
	for (i = 0; i < Caixa_Eletronico::ncontas;i++)
		if (Caixa_Eletronico::c[i].getNumero() == nconta){
			achou = true;
			break;
		}
		
	if (achou)
		return i;
	else
		return -1;
}

int Caixa_Eletronico::buscaCPF(string cpf){
	
	for (int i = 0; i < Caixa_Eletronico::ncontas;i++)
		if (Caixa_Eletronico::c[i].getUsuario().getCPF() == cpf)
			return i;
	
	return -1;
}

void Caixa_Eletronico::mostrarData(){
	cout<<"\n-Data: ";
	Caixa_Eletronico::d.print();
}

void Caixa_Eletronico::incrementaNClientes(){
	Caixa_Eletronico::nclientes++;
}

void Caixa_Eletronico::incrementaNContas(){
	Caixa_Eletronico::ncontas++;
}