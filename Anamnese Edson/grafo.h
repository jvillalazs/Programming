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

