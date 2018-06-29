#ifndef GRAFO_H_
#define GRAFO_H_

typedef struct Grafo TGrafo;
typedef struct vertice Tvertice;

typedef void (*TinserirGrafo)(TGrafo *graf,void* elem);
typedef int (*TbuscarGrafo)(TGrafo *graf, void* param1, void* param2);
typedef void (*TDestroiGrafo) (TGrafo* graf);

struct vertice{
	char pergunta[400];
	int resposta[10];
	int pontuacao;
	int visitado;
	int marcado;
	Tvertice* coleguinha;
};

typedef struct dadosGrafo{
	char nome[100];
	char sigla[50];
	int vertices;
	int visitados;
	int marcados;
	Tvertice* fonte;
} TDadosGrafo;

struct Grafo{
	void *dadosGrafo;
	TinserirGrafo inserirGrafo;
	TbuscarGrafo buscarGrafo;
	TDestroiGrafo destruirGrafo;
};

TGrafo *criarGrafo(char nome[100], char sigla[50]);
#endif /* GRAFO_H_ */
