<<<<<<< HEAD
#ifndef GRAFO_H_
#define GRAFO_H_

typedef struct Grafo TGrafo;

typedef void (*TinserirGrafo)(TGrafo *graf,void* elem);
typedef int (*TbuscarGrafo)(TGrafo *graf, void* param1, void* param2);
typedef void (*TDestroiGrafo) (TGrafo* graf);

typedef struct Tvertice{
	char pergunta[400];
	char resposta[200];
	int pontuacao;
	int visitado;
	int marcado;
	Tvertice* coleguinha;
} Tvertice;

typedef struct dadosGrafo{
	char nome[100];
	char sigla[50];
	int vertices;
	int visitados;
	int marcados;
	Tvertice fonte;
} TDadosGrafo;

struct Grafo{
	void *dadosGrafo;
	TinserirGrafo inserir;
	TbuscarGrafo buscar;
	TDestroiGrafo destruir;
};

TGrafo *criarGrafo(char nome[100], char sigla[50]);
#endif /* GRAFO_H_ */
=======
#ifndef Grafo_H_
#define Grafo_H_

typedef struct Grafo TGrafo;

//Métodos do Tipo TArrayDinamico
typedef void (*TinserirGrafo)(TGrafo *vet,void* elem);
typedef int (*TbuscarGrafo)(TGrafo *vet, void* valor);
typedef void (*TDestroiGrafo) (TGrafo* vet);
typedef struct Vertice TVertice { }

//Dados do Tipo TArrayDinamico
typedef struct dadoGrafo{
	int vertices;
	int arestas;
	void* *;
} TDadosADI;

struct ArrayDinamico{
	void *dadosADI; //Dados encapsulados
	TinserirADI inserir;//Tipo Inserir
	TinserirADIposicao inserirposicao; //Tipo insere na posicao
	TremoverADI remover;//Tipo Remover
	TbuscarADI buscar;//Tipo Buscar
	TordenaADI ordenar; //Tipo Ordena
	TDestroiADI destruir; //Tipo destroi
};

//Funcao construtor do TArrayDinamico
TArrayDinamico *criarADI(int tamanhoInicial);
#endif /* ADINAMICO_H_ */

>>>>>>> b8f0cf8a23a3dea63543409863f15c322ede4f6c
