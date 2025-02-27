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

// INSERÇÃO DE UM ELEMENTO: em posição específica

bool inserirElemArray(ARRAY* a, REGISTRO reg, int i) { // a = array | reg = elemento a ser inserido | i = posição do elemento a ser inserido
	int j;
	if ((a->nroElem == MAX) || (i < 0) || (i > a->nroElem)) // verifica se estrutura já está lotada, etc.
		return false;
	for (j = a->nroElem;j > i;j--) a->A[j] = a->A[j-1]; // move os elementos do array para a direita, de modo que consiga inserir o novo elemento
	a->A[i] = reg; // atribui o valor à posição especificada pelo usuário
	a->nroElem++; // aumenta o nroElem indicando aumento no array
	return true;
}