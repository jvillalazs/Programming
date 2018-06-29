#ifndef PERGUNTA_H_
#define PERGUNTA_H_

typedef struct Pergunta TPergunta;

typedef struct dadosPergunta{
	char perguntinha[400];
	int resposta;
} TDadosPergunta;

struct Pergunta{
	void *dadosPergunta; //Dados encapsulados
};

TPergunta *criarPergunta(char pergunta[400]);
#endif /* PERGUNTA_H_ */
