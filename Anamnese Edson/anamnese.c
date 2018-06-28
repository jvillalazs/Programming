#include <stdio.h>
#include <stdlib.h>
#include "adinamico.h"
#include "grafo.h"

TArrayDinamico* getPerguntas(char *diretorio){
	TArrayDinamico* Vetorzao = criarADI(400);
	char Pergunta[400];
	FILE* arquivo = fopen(diretorio,"r");
    if(arquivo != NULL){
        while((fscanf(arquivo,"%s\n",Pergunta)) != EOF){
            Vetorzao->inserir(Vetorzao,Pergunta);
        }
    }else{
        printf("\n\n Arquivo Nao Encontrado!\n\n");
    }
	return Vetorzao;
}

void ImprimePerguntas(TArrayDinamico* vet){
    TDadosADI* dadosVet = vet->dadosADI;
    int contador = 0;
    while(contador < dadosVet->ocupacao){
        printf("%s\n",dadosVet->vetor[contador]);
    }
}

int main(){

    TArrayDinamico* Persona = getPerguntas("Perguntas/PersonalidadeEtemperamento.txt");
    TArrayDinamico* Alimentares = getPerguntas("Perguntas/PreferenciasAlimentares.txt");
    TArrayDinamico* Medos = getPerguntas("Perguntas/Medos.txt");
    TArrayDinamico* Caracteristicas = getPerguntas("Perguntas/CaracteristicasGerais.txt");

    ImprimePerguntas(Persona);

    return 0;
}