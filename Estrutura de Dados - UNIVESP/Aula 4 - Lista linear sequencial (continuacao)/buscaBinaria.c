#define MAX 50 // numero max. da lista linear sequencial(array/arranjo)

typedef int TIPOCHAVE; // especifica que o int usado é uma CHAVE, para evitar confusoes

typedef struct{
	TIPOCHAVE chave;
	// outros campos...
} REGISTRO;

typedef struct{
	REGISTRO A[MAX+1]; // criando array com 50 slots + 1 para o 'elemento Sentinela'
	int nroElem;
} ARRAY;

// Busca Binária
int buscaBinaria(ARRAY* a, TIPOCHAVE ch) {
	int esq, dir, meio;
	esq = 0;
	dir = a->nroElem-1;
	while (esq <= dir) {
		meio = ((esq + dir) / 2);
		if (a->A[meio].chave == meio) return meio;
		else {
			if (a->A[meio].chave < ch) esq = meio + 1;
			else dir = meio - 1;
		}
	}
	return -1;
}