#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adinamico.h"
#include "grafo.h"
#include "pergunta.h"

static Tvertice *criarVertice(char pergunta[400], int resposta[10], int pontuacao){
	Tvertice *aloca = malloc(sizeof(Tvertice));
	if(aloca!= NULL){
		strcpy(aloca->pergunta,pergunta);
        int contador = 0;
        while(contador < 10){
            aloca->resposta[contador] = resposta[contador];
            contador = contador + 1;
        }
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
	TPergunta* novoElemento = elem;
	TDadosPergunta* dadoNovoElemento = novoElemento->dadosPergunta;

	if(fonte == NULL){
	    int pont;
	    switch(dadoNovoElemento->resposta){
            case 1:
                pont = 5;
                break;
            case 2:
                pont = 3;
                break;
            case 3:
                pont = 1;
                break;
            default:
                pont = 0;
                break;
		}
        fonte = criarVertice(dadoNovoElemento->perguntinha,dadoNovoElemento->resposta,pont);
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
