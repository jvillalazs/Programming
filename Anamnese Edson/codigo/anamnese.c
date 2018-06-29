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
        while(ok == 0){
            printf("\n\n%d) %s\n\n",contador+1,dadosPPP->perguntinha);
            printf("[1]Muitissimo   [2]Muito   [3]Pouco   [0]Nao se aplica\n\n");
            scanf("%d",&temp);
            if(temp <= 3 && temp >= 0){
                dadosPPP->resposta[0] = temp;
                ok = 1;
            }else{
                printf("\n\nresposta invalida!");
            }
        }
        contador = contador + 1;
    }
}

void AlimentaGrafo(TGrafo* graf, char *diretorio){
	char Linhazona[600];
	TDadosGrafo* dadosGraf = graf->dadosGrafo;
	int contador = 0;
	char perguntaa[400];
	int respostaa[10];

	FILE* arquivo = fopen(diretorio,"r");
    if(arquivo != NULL){
        while((fgets(Linhazona,sizeof(Linhazona),arquivo)) != NULL){
            Linhazona[strlen(Linhazona)-1] = '\0';
            while(Linhazona[contador] != "-"){
                char perguntaa[contador] = Linhazona[contador];
                contador = contador + 1;
            }
            contador = contador + 1;
            if(contador == strlen(Linhazona)){
                TPergunta* inserido = criarPergunta(perguntaa);
                TDadosPergunta* dadoInserido = inserido->dadosPergunta;
                dadoInserido->resposta[0] = (int)Linhazona[contador];
            }

            if(contador == strlen(Linhazona)+2){

            }


        }
    }else{
        printf("\n\n Arquivo '%s' Não Encontrado !\n\n",diretorio);
    }
    fclose(arquivo);

	return Vetorzao;
}

int main(){

    TArrayDinamico* Perguntas = getPerguntas("../../Perguntas.txt");

    ColetaRespostas(Perguntas);

    return 0;
}
