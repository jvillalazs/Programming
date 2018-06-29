#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pergunta.h"

static TDadosPergunta *criarDadosPergunta(char pergunta[400]){
	TDadosPergunta *aloca = malloc(sizeof(TDadosPergunta));
	if(aloca!= NULL){
		strcpy(aloca->perguntinha,pergunta);
		aloca->resposta = -1;
	}
	return aloca;
}

TPergunta *criarPergunta(char pergunta[400]){
	TPergunta *perg = malloc(sizeof(TPergunta));
	if(perg != NULL){
		perg->dadosPergunta = criarDadosPergunta(pergunta);
	}
	return perg;
}
