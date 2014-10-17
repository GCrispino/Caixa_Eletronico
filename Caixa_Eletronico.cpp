#include "Caixa_Eletronico.h"

#include <conio.h>
#include <stdlib.h>


int Caixa_Eletronico::nclientes = 0;
Data Caixa_Eletronico::d(05,10,2014);
int *Caixa_Eletronico::conta = 0;		//Inicialização das variáveis 'static'
vector<float> Caixa_Eletronico::saldo(0);
int Caixa_Eletronico::ncontas = 0;

const int Caixa_Eletronico::IDBANCO = 55873;
const string Caixa_Eletronico::NOMEBANCO = "Banco Universitario";

bool operator == (const Caixa_Eletronico &c1, const Caixa_Eletronico &c2){
	if (c1.modelo == c2.modelo && c1.dinheiro == c2.dinheiro && c1.conta == c2.conta && c1.saldo == c2.saldo && c1.d == c2.d)
		return true;
	else
		return false;
}

ostream &operator << (ostream &output,const Caixa_Eletronico &c){
	output << c.modelo << " (" << c.NOMEBANCO<<")";
	
	return output;
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
}

int Caixa_Eletronico::setConta(int conta){
	if (conta < 0){
		cout<< "\nValor invalido!";
		getch();
		return -1;
	}
	else if (Caixa_Eletronico::ncontas == 0){
		//Se o numero de contas for 0, é alocada a memória para o primeiro elemento.
		Caixa_Eletronico::conta = new int;
		Caixa_Eletronico::conta[0] = conta;
		incrementaNClientes();
		incrementaNContas();
		return 0;
	}
	else{//se não for igual a 0, faz a busca para checar se a conta dada ja existe..
		int achou = 0;
		for (int i = 0;i < this->ncontas;i++)
			if (this->conta[i] == conta){
				achou = 1;
				break;
			}
		
		if (achou == 1){//...se ja existe, retorna um erro na funcao.
			cout<<"\nConta ja existe!";
			getch();
			return -1;
		}
		else{//caso contrário, aloca memória para um novo elemento.
			int *aux = new int[ncontas];
			
			for (int i = 0;i < ncontas;i++)
				aux[i] = this->conta[i];
				
			delete this->conta;

			this->conta = new int[++this->ncontas];
			
			for (int i = 0;i < ncontas-1;i++)
				this->conta[i] = aux[i];	
				
			this->conta[ncontas-1] = conta;
			
			delete [] aux;
			
			incrementaNClientes();
			incrementaNContas();
			return 0;
		}
	}
}

void Caixa_Eletronico::setSaldo(int conta, float saldo){
	if (saldo < 0){
		cout<<"\nValor invalido!!";
		return ;
	}
	else
		for (int i = 0;i < this->ncontas;i++)
			if(conta == this->conta[i])
				this->saldo.push_back(saldo);
}

int Caixa_Eletronico::getNContas(){
	return this->ncontas;
}

void Caixa_Eletronico::saque(int conta){
	int iconta = -1,achou = 0;;
	
	for (int i = 0; i < this->ncontas;i++) //Procura o numero da conta recebido no vector de contas.
		if (this->conta[i] == conta){
			iconta = i;
			achou = 1;
		}
	if (achou == 0){
		cout<<"\nConta nao encontrada!";
		getch();
		return ;
	}	
	else{
		float valor;
		
		cout<<"\nDigite o valor a ser sacado: ";
		cin >> valor;
			if (valor > this->saldo[iconta]){    //Não permite a inserção de dados maiores que o saldo da conta informada...
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
				this->saldo[iconta] -= valor;
				this->dinheiro -= valor;
			
				cout<<"\nO valor de R$"<<valor<<" foi sacado.";
				cout<<"\nSaldo restante: R$"<<this->saldo[iconta]<<".";
				cout<<"\nDinheiro restante no caixa: R$"<<this->dinheiro<<".";
				getch();
			}
	}
	
}

void Caixa_Eletronico::pagamento(int conta){
	int iconta1 = -1, iconta2 = iconta1, nconta,achou = 0;
	
	for (int i = 0; i < this->ncontas;i++)	//Procura a conta passada como argumento
		if (this->conta[i] == conta){
			iconta1 = i;
			achou = 1;
		}
	if (achou == 0){
		cout<<"\nConta nao encontrada!";
		getch();
		return ;
	}
	else{
		
		float valor;
	
		cout<<"\nDigite o numero da conta que recebera o pagamento: ";
		cin >> nconta;
	
		achou = 0;
		for (int i = 0;i < this->ncontas;i++)  //Procura o numero da conta que recebera o pagamento
			if (this->conta[i] == nconta){
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
					if (valor > this->saldo[iconta1]){    //Não permite a inserção de dados maiores que o saldo da conta informada...
						cout << "\nValor maior que o saldo!";
						getch();
					}
					else if (valor <= 0){				//...nem a inserção de dados menores ou igual a 0.
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
						break;
					}
	
			}while (valor < 0 || valor > this->saldo[iconta1]);
		}
	}
}

void Caixa_Eletronico::mostrarSaldo(int conta) const{
	for (int i = 0;i < this->ncontas;i++)
		if (this->conta[i] == conta)
			cout<<"\nO saldo da conta "<<this->conta[i]<<" e' de: R$"<<this->saldo[i];
}


void Caixa_Eletronico::info() const{
	cout<<"\n-- Informacoes gerais do caixa eletronico: \n";
	cout<<"\nBanco: "<<NOMEBANCO<<"(ID do banco: "<<IDBANCO<<").";
	cout<<"\nModelo do caixa: "<<this->modelo;
	cout<<"\nNumero de clientes do banco: "<<this->nclientes<<".";
	cout<<"\nDinheiro disponivel no caixa: R$"<<this->dinheiro<<".";
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