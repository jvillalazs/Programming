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
    int temp;
    int ok;
    while(contador < dadosVet->ocupacao){
        ok = 0;
        TPergunta* ppp = dadosVet->vetor[contador];
        TDadosPergunta* dadosPPP = ppp->dadosPergunta;
        printf("\n\n%d) %s\n\n",contador+1,dadosPPP->perguntinha);
        printf("[1]Muitissimo   [2]Muito   [3]Pouco   [0]Nao se aplica\n");
        while(ok == 0){
            scanf("%d",&temp);
            if(temp <= 3 || temp >= 0){
                dadosPPP->resposta = temp;
                ok = 1;
            }else{
                printf("\n\nresposta invalida!");
            }
        }
        contador = contador + 1;
    }
}



int main(){

    TArrayDinamico* Perguntas = getPerguntas("../../Perguntas.txt");

    ColetaRespostas(Perguntas);

    TDadosADI* dadosPerguntas = Perguntas->dadosADI;
    TPergunta* per = dadosPerguntas->vetor[0];
    TDadosPergunta* dadosPer = per->dadosPergunta;

    printf("%s",dadosPer->perguntinha);
    printf(" - %d",dadosPer->resposta);

    return 0;
}
