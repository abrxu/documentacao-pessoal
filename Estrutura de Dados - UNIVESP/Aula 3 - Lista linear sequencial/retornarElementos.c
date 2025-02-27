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

// RETORNAR NUMERO DE ELEMENTOS

int tamanho(ARRAY* a) {
	return a->nroElem;
}