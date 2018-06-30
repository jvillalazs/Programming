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

void MostrarRespostas(TArrayDinamico* respostas){
    char* diretorio = "../../Respostas.txt";
	FILE* arquivo = fopen(diretorio,"w");
	int contador = 0;
	TDadosADI* dadosRespostas = respostas->dadosADI;
	char rep[50];

    if(arquivo != NULL){
        while(contador < dadosRespostas->ocupacao){
            TPergunta* pergAtual = dadosRespostas->vetor[contador];
            TDadosPergunta* dadosPergAtual = pergAtual->dadosPergunta;

            if(dadosPergAtual->resposta[0]==1){
                strcpy(rep,"Muitissimo");
            }
            if(dadosPergAtual->resposta[0]==2){
                strcpy(rep,"Muito");
            }
            if(dadosPergAtual->resposta[0]==3){
                strcpy(rep,"Pouco");
            }
            if(dadosPergAtual->resposta[0]==0){
                strcpy(rep,"Nao se aplica");
            }
            fprintf(arquivo,"%s\nR: %s",dadosPergAtual->perguntinha,rep);
            contador = contador + 1;
        }
    }else{
        printf("\n\n Arquivo '%s' Não Encontrado !\n\n",diretorio);
    }
    fclose(arquivo);
}

void AlimentaGrafo(TGrafo* graf, char *diretorio){
	char Linhazona[600];
	TDadosGrafo* dadosGraf = graf->dadosGrafo;
	int contador = 0;
	char perguntaa[400];

	FILE* arquivo = fopen(diretorio,"r");
    if(arquivo != NULL){
        while((fgets(Linhazona,sizeof(Linhazona),arquivo)) != NULL){
            Linhazona[strlen(Linhazona)-1] = '\0';
            while(Linhazona[contador] != '-'){
                perguntaa[contador] = Linhazona[contador];
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
}

TGrafo* MaiorSemelhanca(TGrafo* graf1,TGrafo* graf2,TGrafo* graf3,TGrafo* graf4,TGrafo* graf5,TGrafo* graf6,TGrafo* graf7,TGrafo* graf8,TGrafo* graf9,TGrafo* graf10,TGrafo* graf11,TGrafo* graf12,TGrafo* graf13,TGrafo* graf14,TGrafo* graf15){
    TDadosGrafo* dadosGraf1 = graf1->dadosGrafo;
    TDadosGrafo* dadosGraf2 = graf2->dadosGrafo;
    TDadosGrafo* dadosGraf3 = graf3->dadosGrafo;
    TDadosGrafo* dadosGraf4 = graf4->dadosGrafo;
    TDadosGrafo* dadosGraf5 = graf5->dadosGrafo;
    TDadosGrafo* dadosGraf6 = graf6->dadosGrafo;
    TDadosGrafo* dadosGraf7 = graf7->dadosGrafo;
    TDadosGrafo* dadosGraf8 = graf8->dadosGrafo;
    TDadosGrafo* dadosGraf9 = graf9->dadosGrafo;
    TDadosGrafo* dadosGraf10 = graf10->dadosGrafo;
    TDadosGrafo* dadosGraf11 = graf11->dadosGrafo;
    TDadosGrafo* dadosGraf12 = graf12->dadosGrafo;
    TDadosGrafo* dadosGraf13 = graf13->dadosGrafo;
    TDadosGrafo* dadosGraf14 = graf14->dadosGrafo;
    TDadosGrafo* dadosGraf15 = graf15->dadosGrafo;

    TGrafo* retorno = criarGrafo("none","none");
    TDadosGrafo* dadoRetorno = retorno->dadosGrafo;

    TDadosGrafo* tudao[] = {dadosGraf1,dadosGraf2,dadosGraf3,dadosGraf4,dadosGraf5,dadosGraf6,dadosGraf7,dadosGraf8,dadosGraf9,dadosGraf10,dadosGraf11,dadosGraf12,dadosGraf13,dadosGraf14,dadosGraf15};

    int contador = 0;
    int maior = 0;
    int esse = 0;

    while(contador < 15){
        if(tudao[contador]->pontuacaoGeral > maior){
            maior = tudao[contador]->pontuacaoGeral;
            esse = contador;
        }

        contador = contador + 1;
    }

    dadoRetorno = tudao[esse];

    return retorno;

}

int main(){

    //CRIA UM ARRAY COM PERGUNTAS SEM RESPOSTA
    TArrayDinamico* Perguntas = getPerguntas("../../Perguntas.txt");

    //PREENCHE AS RESPOSTAS NO ARRAY DE PERGUNTAS
    ColetaRespostas(Perguntas);

    TDadosADI* dadoPerguntas = Perguntas->dadosADI;

    //CRIA GRAFOS DE POSSIBILIDADES DE RESPOSTAS PARA CADA TIPO CONSTITUCIONAL
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

    TDadosGrafo* dadosArg = arg->dadosGrafo;
    TDadosGrafo* dadosArs = ars->dadosGrafo;
    TDadosGrafo* dadosCalc = calc->dadosGrafo;
    TDadosGrafo* dadosGraph = graph->dadosGrafo;
    TDadosGrafo* dadosIgn = ign->dadosGrafo;
    TDadosGrafo* dadosLach = lach->dadosGrafo;
    TDadosGrafo* dadosLyc = lyc->dadosGrafo;
    TDadosGrafo* dadosMerc = merc->dadosGrafo;
    TDadosGrafo* dadosNm = nm->dadosGrafo;
    TDadosGrafo* dadosNv = nv->dadosGrafo;
    TDadosGrafo* dadosPhos = phos->dadosGrafo;
    TDadosGrafo* dadosPuls = puls->dadosGrafo;
    TDadosGrafo* dadosSep = sep->dadosGrafo;
    TDadosGrafo* dadosSil = sil->dadosGrafo;
    TDadosGrafo* dadosSulph = sulph->dadosGrafo;

    int contador = 0;
    while(contador < dadoPerguntas->ocupacao){
        TPergunta* pp2 = dadoPerguntas->vetor[contador];

        //MARCA OS VERTICES QUE POSSUEM OCORRENCIA NO ARRAY DE RESPOSTAS DO USUARIO
        arg->buscarGrafo(dadosArg->fonte,pp2);
        ars->buscarGrafo(dadosArs->fonte,pp2);
        calc->buscarGrafo(dadosCalc->fonte,pp2);
        graph->buscarGrafo(dadosGraph->fonte,pp2);
        ign->buscarGrafo(dadosIgn->fonte,pp2);
        lach->buscarGrafo(dadosLach->fonte,pp2);
        lyc->buscarGrafo(dadosLyc->fonte,pp2);
        merc->buscarGrafo(dadosMerc->fonte,pp2);
        nm->buscarGrafo(dadosNm->fonte,pp2);
        nv->buscarGrafo(dadosNv->fonte,pp2);
        phos->buscarGrafo(dadosPhos->fonte,pp2);
        puls->buscarGrafo(dadosPuls->fonte,pp2);
        sep->buscarGrafo(dadosSep->fonte,pp2);
        sil->buscarGrafo(dadosSil->fonte,pp2);
        sulph->buscarGrafo(dadosSulph->fonte,pp2);
    }

    //CALCULA PONTUACAO GERAL DE CADA TIPO CONSTITUCIONAL BASEADO NAS RESPOSTAS DO USUARIO
    dadosArg->pontuacaoGeral = arg->medeCaminhoGrafo(dadosArg->fonte);
    dadosArs->pontuacaoGeral = ars->medeCaminhoGrafo(dadosArs->fonte);
    dadosCalc->pontuacaoGeral = calc->medeCaminhoGrafo(dadosCalc->fonte);
    dadosGraph->pontuacaoGeral = graph->medeCaminhoGrafo(dadosGraph->fonte);
    dadosIgn->pontuacaoGeral = ign->medeCaminhoGrafo(dadosIgn->fonte);
    dadosLach->pontuacaoGeral = lach->medeCaminhoGrafo(dadosLach->fonte);
    dadosLyc->pontuacaoGeral = lyc->medeCaminhoGrafo(dadosLyc->fonte);
    dadosMerc->pontuacaoGeral = merc->medeCaminhoGrafo(dadosMerc->fonte);
    dadosNm->pontuacaoGeral = nm->medeCaminhoGrafo(dadosNm->fonte);
    dadosNv->pontuacaoGeral = nv->medeCaminhoGrafo(dadosNv->fonte);
    dadosPhos->pontuacaoGeral = phos->medeCaminhoGrafo(dadosPhos->fonte);
    dadosPuls->pontuacaoGeral = puls->medeCaminhoGrafo(dadosPuls->fonte);
    dadosSep->pontuacaoGeral = sep->medeCaminhoGrafo(dadosSep->fonte);
    dadosSil->pontuacaoGeral = sil->medeCaminhoGrafo(dadosSil->fonte);
    dadosSulph->pontuacaoGeral = sulph->medeCaminhoGrafo(dadosSulph->fonte);

    //DETERMINA A MAIOR PONTUACAO
    TGrafo* grafoFinal = MaiorSemelhanca(arg,ars,calc,graph,ign,lach,lyc,merc,nm,nv,phos,puls,sep,sil,sulph);

    TDadosGrafo* dadosGrafoFinal = grafoFinal->dadosGrafo;

    MostrarRespostas(Perguntas);

    printf("\n\nDe acordo com a anamnese homeopatica voce tem um perfil muito proximo do tipo: %s - %d pontos",dadosGrafoFinal->nome,dadosGrafoFinal->pontuacaoGeral);
    printf("\n\nSuas respostas estao no arquivo Respostas.txt");

    return 0;
}
