#define MAX 50 // numero max. da lista linear sequencial(array/arranjo)

typedef int TIPOCHAVE; // especifica que o int usado é uma CHAVE, para evitar confusoes

typedef struct{
	TIPOCHAVE chave;
	// outros campos...
} REGISTRO;

typedef struct{
	REGISTRO A[MAX]; // criando array com 50 slots
	int nroElem;
} ARRAY;

// INICIALIZAÇÃO

// faz uma cópia de ARRAY e modifica essa nova cópia, mantendo a original com seu valor.
void inicializarARRAY(ARRAY a) {
	a.nroElem = 0;
}

// faz uma referência ao ponteiro original de ARRAY na memória e modifica o seu valor
void inicializarARRAYPonteiro(ARRAY* a) {
	a->nroElem = 0;
}