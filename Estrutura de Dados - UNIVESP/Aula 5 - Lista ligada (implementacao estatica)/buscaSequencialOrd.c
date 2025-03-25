#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
	// outros campos...
} REGISTRO;

typedef struct{
	REGISTRO reg;
	int prox;
} ELEMENTO;

typedef struct{
	ELEMENTO A[MAX];
	int inicio;
	int dispo; // indice do primeiro elemento disponivel
} LISTA;

void inicializarLista(LISTA* l) {
	int i;
	for (i=0; i<MAX-1; i++) {
		l->A[i].prox = i + 1;
	}
	l->A[MAX-1].prox = INVALIDO; // indica que não há ninguem disponivel apos o ultimo elemento
	l->inicio = INVALIDO; // indica que ainda nao há nenhum elemento válido, visto que a estrutura está sendo inicializada
	l->dispo = 0; // indica que indice de elemento disponivel (0 pois ainda não há elementos)
}

int buscaSequencialOrd(LISTA* l, TIPOCHAVE ch) {
	int i = l->inicio;
	while(i != INVALIDO && l->A[i].chave < ch) { // 'l->A[i].chave < ch' impede que busque por elementos maiores que o pedido (visto que lista está ORDENADA)
		i = l->A[i]
	}
	if (i != INVALIDO && l->A[I].reg.chave = ch)
		return i;
	else return INVALIDO;
}