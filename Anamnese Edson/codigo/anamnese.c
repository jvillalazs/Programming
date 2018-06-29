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
            TPergunta* inserido = criarPergunta(perguntaa);
            TDadosPergunta* dadoInserido = inserido->dadosPergunta;

            if(contador == strlen(Linhazona)){
                dadoInserido->resposta[0] = (int)Linhazona[contador];
            }

            if(contador == strlen(Linhazona)-2){
                dadoInserido->resposta[0] = (int)Linhazona[contador];
                dadoInserido->resposta[1] = (int)Linhazona[contador+2];
            }

            if(contador == strlen(Linhazona)-3){
                dadoInserido->resposta[0] = (int)Linhazona[contador];
                dadoInserido->resposta[1] = (int)Linhazona[contador+2];
                dadoInserido->resposta[2] = (int)Linhazona[contador+3];
            }

            graf->inserirGrafo(dadosGraf->fonte,inserido);

        }
    }else{
        printf("\n\n Arquivo '%s' Não Encontrado !\n\n",diretorio);
    }
    fclose(arquivo);

	return graf;
}

int main(){

    TArrayDinamico* Perguntas = getPerguntas("../../Perguntas.txt");

    ColetaRespostas(Perguntas);

    TDadosADI* dadoPerguntas = Perguntas->dadosADI;

    TGrafo* arg = criarGrafo("ARGENT NIT","ARG");
    TGrafo* ars = criarGrafo("ARSEN ALB","ARS");
    TGrafo* calc = criarGrafo("CALC CARB","CALC");
    TGrafo* graph = criarGrafo("GRAPHITIES","GRAPH");
    TGrafo* ign = criarGrafo("IGNATIA","IGN");
    TGrafo* lach = criarGrafo("LACHESIS","LACH");
    TGrafo* lyc = criarGrafo("LYCOPODIUM","LYC");
    TGrafo* merc = criarGrafo("MERC SOL","MERC");
    TGrafo* nm = criarGrafo("NATRUM MUR","NM");
    TGrafo* nv = criarGrafo("NUX VOMICA","NV");
    TGrafo* phos = criarGrafo("PHOS","PHOS");
    TGrafo* puls = criarGrafo("PULSATILA","PULS");
    TGrafo* sep = criarGrafo("SEPIA","SEP");
    TGrafo* sil = criarGrafo("SILICEA","SIL");
    TGrafo* sulph = criarGrafo("SULPHUR","SULPH");

    AlimentaGrafo(arg,"../../TiposConstitucionais/ARG.txt");
    AlimentaGrafo(ars,"../../TiposConstitucionais/ARS.txt");
    AlimentaGrafo(calc,"../../TiposConstitucionais/CALC.txt");
    AlimentaGrafo(graph,"../../TiposConstitucionais/GRAPH.txt");
    AlimentaGrafo(ign,"../../TiposConstitucionais/IGN.txt");
    AlimentaGrafo(lach,"../../TiposConstitucionais/LACH.txt");
    AlimentaGrafo(lyc,"../../TiposConstitucionais/LYC.txt");
    AlimentaGrafo(merc,"../../TiposConstitucionais/MERC.txt");
    AlimentaGrafo(nm,"../../TiposConstitucionais/NM.txt");
    AlimentaGrafo(nv,"../../TiposConstitucionais/NV.txt");
    AlimentaGrafo(phos,"../../TiposConstitucionais/PHOS.txt");
    AlimentaGrafo(puls,"../../TiposConstitucionais/PULS.txt");
    AlimentaGrafo(sep,"../../TiposConstitucionais/SEP.txt");
    AlimentaGrafo(sil,"../../TiposConstitucionais/SIL.txt");
    AlimentaGrafo(sulph,"../../TiposConstitucionais/SULPH.txt");

    int contador = 0;
    while(contador < dadoPerguntas->ocupacao){
        TPergunta* pp2 = dadoPerguntas->vetor[contador];
        arg->buscarGrafo(pp2);
        ars->buscarGrafo(pp2);
        calc->buscarGrafo(pp2);
        graph->buscarGrafo(pp2);
        ign->buscarGrafo(pp2);
        lach->buscarGrafo(pp2);
        lyc->buscarGrafo(pp2);
        merc->buscarGrafo(pp2);
        nm->buscarGrafo(pp2);
        nv->buscarGrafo(pp2);
        phos->buscarGrafo(pp2);
        puls->buscarGrafo(pp2);
        sep->buscarGrafo(pp2);
        sil->buscarGrafo(pp2);
        sulph->buscarGrafo(pp2);
    }

    maior(arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,arg->medeCaminhoGrafo,sulph->medeCaminhoGrafo)

    return 0;
}
