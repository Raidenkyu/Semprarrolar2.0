#include <vector>
#include <string>

#ifdef _WIN32         //Para o windows reconhecer os caracteres portugueses
#include <windows.h>
#define SetPTchar() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else 
#define SetPTchar() void
#endif

#ifdef _WIN32 //Para limpar o ecr� quer seja em Windows, quer seja em linux
#define clearScreen() system("cls"); 
#else
#define clearScreen() system("clear");
#endif

using namespace std;

#pragma once

class shift { //class com a informa��o relativa a um turno
private:
	unsigned int idLinha;
	unsigned int idCondutor;
	unsigned int nBus;
	unsigned int inicio;
	unsigned fim;
public:
	//Fun��es que devolvem os parametros da classe
	unsigned int getLinha();
	unsigned int getCondutor();
	unsigned int getBus();
	unsigned int getInicio();
	unsigned int getFim();
	//Fun��es que modificam os par�metros da classe
	void setLinhaID(unsigned int idLinha);
	void setCondutorID(unsigned int idCondutor);
	void setBus(unsigned int nBus);
	void setInicio(unsigned int inicio);
	void setFim(unsigned int fim);
};

class class_linha {        //class com a informa��o relativa a uma linha
private:
	unsigned int ID;
	unsigned int freq;
	vector<string> paragens;
	vector<unsigned int> tempos;
public:
	unsigned int getID();
	unsigned int getFreq();
	vector<string> getParagens();
	vector<unsigned int> getTempos();
};

class class_condutor {       //class com a informa��o relativa a um condutor
private:
	unsigned int ID;
	string nome;
	unsigned int turno;
	unsigned int max;
	unsigned int descanso;
	vector <shift> shifts;
public:
	unsigned int getID();
	string getNome();
	unsigned int getTurno();
	unsigned int getMax();
	unsigned int getDescanso();
	vector <shift> getShifts();
};

class bus {//class com a informa��o de todos os turnos de um autocarro
private:
	unsigned int nBus;
	unsigned int idCondutor;
	unsigned int idLinha;
	vector <shift> schedule;
public:
	bus(unsigned int nBus, unsigned int idCondutor, unsigned int idLinha);
	vector <shift> getSchedule();
	unsigned int getCondutorID() const;
	unsigned int getLinhaID() const;
};

class Empresa {
private:
	string nome;
	vector<class_condutor> vector_condutores;
	vector<class_linha> vector_linhas;
public:
	Empresa(string nome, string fichCondutores, string fichLinhas); //N�o percebi bem, v� se consegues tu
	// metodos get
	string getNome();
	// metodos set
	// outros metodos
	void distribuiServico(); // funcao que implementa a afectacao de servico(incompleta)
};

int linhas_menu();
int condutores_menu();