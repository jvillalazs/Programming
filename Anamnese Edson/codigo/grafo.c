#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adinamico.h"
#include "grafo.h"

static Tvertice *criarVertice(char pergunta[400], char resposta[200], int pontuacao){
	Tvertice *aloca = malloc(sizeof(Tvertice));
	if(aloca!= NULL){
		strcpy(aloca->pergunta,pergunta);
		strcpy(aloca->resposta,resposta);
		aloca->pontuacao = pontuacao;
		aloca->coleguinha = NULL;
	}
	return aloca;
}

static TDadosGrafo *criarDadosGrafo(char nome[100], char sigla[50]){
	TDadosGrafo *aloca = malloc(sizeof(TDadosGrafo));
	if(aloca != NULL){
		strcpy(aloca->nome,nome);
		strcpy(aloca->sigla,sigla);
		aloca->vertices = 0;
		aloca->visitados = 0;
		aloca->marcados = 0;
		aloca->fonte = NULL;
	}
	return aloca;
}

static Tvertice* InserirGrafo(Tvertice *fonte, void* elem){
	Tvertice* novoElemento = elem;

	if(fonte == NULL){
		fonte = elem;
	}else{
		InserirGrafo(fonte->coleguinha,elem);
	}

	return fonte;
}

static void DestroiGrafo(TGrafo* graf) {
    graf->inserirGrafo = NULL;
	graf->buscarGrafo = NULL;
	graf->dadosGrafo = NULL;
    free(graf);
}


TGrafo *criarGrafo(char nome[100], char sigla[50]){
	TGrafo *graf = malloc(sizeof(TGrafo));
	if(graf != NULL){
		graf->dadosGrafo = criarDadosGrafo(nome,sigla);
		graf->inserirGrafo = InserirGrafo;
		graf->destruirGrafo = DestroiGrafo;
	}
	return graf;
}
