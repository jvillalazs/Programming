#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adinamico.h"
#include "grafo.h"
#include "pergunta.h"

static Tvertice *criarVertice(char pergunta[400], int resposta[10]){
	Tvertice *aloca = malloc(sizeof(Tvertice));
	if(aloca!= NULL){
		strcpy(aloca->pergunta,pergunta);
        int contador = 0;
        while(contador < 10){
            aloca->resposta[contador] = resposta[contador];
            contador = contador + 1;
        }
		aloca->pontuacao = 0;
		aloca->marcado = 0;
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
        fonte = criarVertice(dadoNovoElemento->perguntinha,dadoNovoElemento->resposta);
	}else{
		return InserirGrafo(fonte->coleguinha,elem);
	}

	return fonte;
}

static int estaNoVetor(int vetor[10], int numero){
    int contador = 0;
    int resposta = 1;
    while(contador < 10 && resposta == 1){
        if(vetor[contador] == numero){
            resposta = 0;
        }
        contador = contador + 1;
    }
}

static Tvertice* BuscaGrafo(Tvertice* fonte, void* elem){
    TPergunta* compara = elem;
    TDadosPergunta* dadosCompara = compara->dadosPergunta;

    if(strcmp(dadosCompara->perguntinha,fonte->pergunta) == 0){
        if(estaNoVetor(fonte->resposta,dadosCompara->resposta[0])==0){
            fonte->marcado = 1;
            return fonte;
        }
    }else{
        return BuscaGrafo(fonte->coleguinha,elem);
    }
}

static int MedeCaminho(Tvertice* fonte){
    int resposta = 0;
    while(fonte->coleguinha != NULL){
        if(fonte->marcado == 1){
            resposta = resposta + fonte->pontuacao;
        }

        fonte = fonte->coleguinha;
    }

    return resposta;
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
		graf->buscarGrafo = BuscaGrafo;
		graf->medeCaminhoGrafo = MedeCaminho;
		graf->destruirGrafo = DestroiGrafo;
	}
	return graf;
}
