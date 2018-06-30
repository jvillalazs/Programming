#ifndef GRAFO_H_
#define GRAFO_H_

typedef struct Grafo TGrafo;
typedef struct vertice Tvertice;

typedef Tvertice* (*TinserirGrafo)(Tvertice *fonte,void* elem);
typedef Tvertice* (*TbuscarGrafo)(Tvertice *fonte, void* elem);
typedef int (*TmedeCaminho)(Tvertice* fonte);
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
	int pontuacaoGeral;
	Tvertice* fonte;
} TDadosGrafo;

struct Grafo{
	void *dadosGrafo;
	TinserirGrafo inserirGrafo;
	TbuscarGrafo buscarGrafo;
	TmedeCaminho medeCaminhoGrafo;
	TDestroiGrafo destruirGrafo;
};

TGrafo *criarGrafo(char nome[100], char sigla[50]);
#endif /* GRAFO_H_ */
