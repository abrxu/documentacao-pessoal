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

// Inserção de elementos em lista ordenada
bool inserirElementoEmArrayOrd(ARRAY* a, REGISTRO reg) {
	if(a->nroElem >= MAX) return false;
	int pos = a->nroElem;
	while (pos > 0 && a->A[pos-1].chave > reg.chave) {
		a->A[pos] = a->A[pos-1];
		pos--;
	}
	a->A[pos] = reg;
	a->nroElem++;
}