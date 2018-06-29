#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adinamico.h"

//CRIA OS DADOS DE UM ARRAY DINÂMICO COM TAMANHO INICIAL
static TDadosADI *criarDadosADI(int tamanho){
	TDadosADI *aloca = malloc(sizeof(TDadosADI));
	if(aloca!= NULL){
		aloca->tamanho = tamanho;
		aloca->ocupacao = 0;
		aloca->vetor = malloc(sizeof(void*)*tamanho);
	}
	return aloca;
}


static void inserirADI(TArrayDinamico *vet, void* elem){
	TDadosADI *dadosVet = vet->dadosADI;

    //Verifica se o vetor está cheio, para redimensioná-lo caso precise
	if (dadosVet->ocupacao == dadosVet->tamanho){
		dadosVet->vetor = realloc(dadosVet->vetor,sizeof(void*)*(2*dadosVet->tamanho));
		dadosVet->tamanho = 2*dadosVet->tamanho;
	}

	dadosVet->vetor[dadosVet->ocupacao] = elem;
	dadosVet->ocupacao += 1;
}

static void DestroiADI(TArrayDinamico* vet) {
    vet->inserir = NULL;
    vet->dadosADI = NULL;
    free(vet);
}


TArrayDinamico *criarADI(int tamanhoInicial){
	TArrayDinamico *adi = malloc(sizeof(TArrayDinamico));
	if(adi != NULL){
		adi->dadosADI = criarDadosADI(tamanhoInicial);
		adi->inserir = inserirADI;
		adi->destruir=DestroiADI;
	}
	return adi;
}
