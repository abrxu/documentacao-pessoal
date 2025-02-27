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

// BUSCA SEQUENCIAL

int buscaSequencial(ARRAY* a, TIPOCHAVE ch) {
	int i = 0;
	while (i < a->nroElem) {
		if (ch == a->A[i].chave) return i;
		else i++
	}
	return -1;
}