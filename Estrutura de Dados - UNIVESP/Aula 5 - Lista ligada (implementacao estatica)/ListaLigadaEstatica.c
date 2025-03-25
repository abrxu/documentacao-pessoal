#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct{
  REGISTRO reg;
  int prox;
} ELEMENTO;

typedef struct{
  ELEMENTO A[MAX];
  int inicio;
  int dispo;
} LISTA;