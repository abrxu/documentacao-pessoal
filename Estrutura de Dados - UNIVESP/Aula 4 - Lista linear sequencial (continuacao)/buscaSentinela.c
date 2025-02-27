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

// 'Busca Sentinela' -> garante que o elemento buscado ESTÁ no array inserindo-o no final como "Sentinela"
int buscaSentinela(ARRAY* a, TIPOCHAVE ch) {
	int i = 0;
	a->A[a->nroElem].chave = ch; // insere elemento que está tentando ser buscado na ultima posição do array
	while(a->A[i] != ch) i++;
	if (i == a->nroElem) return -1;
	else return i;
}