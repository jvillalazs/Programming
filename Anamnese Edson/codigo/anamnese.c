#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adinamico.h"
#include "grafo.h"
#include "pergunta.h"

TArrayDinamico* getPerguntas(char *diretorio){
	TArrayDinamico* Vetorzao = criarADI(500);
	char Pergunta[400];

	FILE* arquivo = fopen(diretorio,"r");
    if(arquivo != NULL){
        while((fgets(Pergunta,sizeof(Pergunta),arquivo)) != NULL){
            Pergunta[strlen(Pergunta)-1] = '\0';
            TPergunta* pergunt = criarPergunta(Pergunta);
            Vetorzao->inserir(Vetorzao,pergunt);
        }
    }else{
        printf("\n\n Arquivo '%s' Não Encontrado !\n\n",diretorio);
    }
    fclose(arquivo);

	return Vetorzao;
}

void ColetaRespostas(TArrayDinamico* vet){
    TDadosADI* dadosVet = vet->dadosADI;
    int contador = 0;
    while(contador < dadosVet->ocupacao){
        TPergunta* ppp = dadosVet->vetor[contador];
        TDadosPergunta* dadosPPP = ppp->dadosPergunta;
        printf("\n\n%d) %s\n\n",contador+1,dadosPPP->perguntinha);
        printf("[1]Muitissimo   [2]Muito   [3]Pouco   [0]Nao se aplica\n");
        scanf("%d",&dadosPPP->resposta);
        contador = contador + 1;
    }
}

int main(){

    TArrayDinamico* Perguntas = getPerguntas("../../Perguntas.txt");

    ColetaRespostas(Perguntas);

    return 0;
}
