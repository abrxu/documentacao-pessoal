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

// EXIBIÇÃO/IMPRESSAO DE CADA ELEMENTO

void exibirLista(ARRAY* a) {
	int i;
	printf("Array: \" ");
	
	for(i=0; i < a->nroElem; i++)
		printf("%i ", a->A[I].chave);
	
	printf("\"\n");
}