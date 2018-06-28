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
	Tvertice* fonte;
} TDadosGrafo;

struct Grafo{
	void *dadosGrafo;
	TinserirGrafo inserir;
	TbuscarGrafo buscar;
	TDestroiGrafo destruir;
};

TGrafo *criarGrafo(char nome[100], char sigla[50]);
#endif /* GRAFO_H_ */