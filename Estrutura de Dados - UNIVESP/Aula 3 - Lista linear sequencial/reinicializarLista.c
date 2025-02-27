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

// EXCLUSÃO DE UM ELEMENTO: elemento especificado pelo usuário (exemplo: QUERO EXCLUIR O NÚMERO 2, ONDE QUER QUE ELE ESTEJA)

void reinicializarArray(ARRAY* a, TIPOCHAVE ch) { // a = array | reg = elemento a ser inserido | i = posição do elemento a ser inserido
	a->nroElem = 0;
}