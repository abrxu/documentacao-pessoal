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

int buscaSequencial(ARRAY* a, TIPOCHAVE ch) {
	int i = 0;
	while (i < a->nroElem) {
		if (ch == a->A[i].chave) return i;
		else i++
	}
	return -1;
}

// EXCLUSÃO DE UM ELEMENTO: elemento especificado pelo usuário (exemplo: QUERO EXCLUIR O NÚMERO 2, ONDE QUER QUE ELE ESTEJA)

bool excluirElemArray(ARRAY* a, TIPOCHAVE ch) { // a = array | reg = elemento a ser inserido | i = posição do elemento a ser inserido
	int pos, j;
	pos = buscaSequencial(a, ch);
	if (pos == -1) return false; // significa que não foi achado
	for (j = pos; j < a->nroElem-1; j++)
		a->A[j] = a->A[j+1]; // puxa o elemento para trás
	a->nroElem--;
	return true;
}