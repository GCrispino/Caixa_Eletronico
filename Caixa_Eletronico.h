/*
 *     Requisitos para quarta tarefa: 
        X Diagrama de classes (obrigatório salvar também o png do diagrama no gitHub)
        X Herança pública
        X Construtor de cópia, e sobrecargas dos operadores de atribuição (=) e << (cout << base) para a classe base e derivada
        X Usar Protected acessando diretamente os atributos na classe derivada
        Alocação dinâmica de memória na classe base(X) e derivada
        Sobrescrita de método: chamar dentro do método da classe derivada o método correspondente da classe base usando ::
        No main: criar um ponteiro da classe base para alocar memória para a classe derivada e chamar os vários métodos implementados
 */
 /*
  * ERROS A SEREM CORRIGIDOS: 
  * - Nomes genéricos: -CORRIGIDO!
  * - sobrecarregado o operador da classe data - CORRIGIDO PREVIAMENTE
  * - evitar retornar vetores. - CORRIGIDO
  * - "const string &" - consertar.-CORRIGIDO!
  * - validação de dados na classe banco - CORRIGIDO
  * - 3 construtores - CORRIGIDO
  * - função inline - CORRIGIDO
  * - método com passagem por referência usando ponteiro -CORRIGIDO
  * - Sobrecarga de operador "=" tem vazamento de memória - CORRIGIDO
  * - Operator friend << incompleto - CORRIGIDO
  */
#ifndef CAIXA_ELETRONICO_H
#define CAIXA_ELETRONICO_H

using namespace std;

#include<iostream>

#include "Device.h"
#include "Data.h"
#include "Usuario.h"

class Caixa_Eletronico: public Device
{
friend ostream &operator << (ostream &,const Caixa_Eletronico &); //sobrecarga do operador "<<".

private:
	float dinheiro; //Dinheiro disponível no caixa eletrônico.
	Usuario *userpadrao; //array de usuários registrados no caixa
	int nusuarios; //número de usuários registrados no caixa
	int ntotalcontas; //número total de contas registradas no caixa
	
	const static Data dataAtual; //Data atual
	
public:
	Caixa_Eletronico(const string &modelo = "",float dinheiro = 0,int serial = 0,Data = Data(),string senhaadm = "123456"); //Construtor default que inicializa as variaveis dinheiro e modelo.
	//Construtor alternativo que define as variáveis modelo e serial e ja define automaticamente a variável dinheiro com o valor padrão 3000.
	Caixa_Eletronico(const string &modelo);
	Caixa_Eletronico(const Caixa_Eletronico &); //Construtor de cópia
	~Caixa_Eletronico();
	
	//Métodos get e set
	int getNContas();
	
	int getNUsuarios();
	
	void setUsuario(const Usuario &u);
	
	
	
	bool operator == (const Caixa_Eletronico &c1); //Sobrecarga do operador "==".
	Caixa_Eletronico operator = (const Caixa_Eletronico &c); //Sobrecarga do operador "=".
	
	void registrarUsuario(const string &); //Registra um usuário novo no Caixa.
	int registrarConta(Usuario &); //Registra uma conta nova no usuário passado como parâmetro.
	const Conta * buscaConta(const int); //busca uma conta em todos os usuários.
	const Usuario * buscaCPF(const string &); //faz uma busca de um usuario através do seu CPF.
	void saque(const int); //realiza uma operação de saque no caixa eletrônico.
	void pagamento(const int); //realiza uma operação de pagamento de uma conta para outra.
	void mostrarSaldo(const int) const; //imprime o saldo disponível na conta na tela.
	void incrementaNContas();
	static void mostrarData();//imprime a data na tela.
};

#endif // CAIXA_ELETRONICO_H
