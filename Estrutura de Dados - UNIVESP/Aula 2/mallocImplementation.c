#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 255

typedef struct{
	int peso;
	int altura;	
} PesoAltura;

int main() {
	PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura)); // criando ponteiro para uma estrutura
	
	// quando se tem um ponteiro, se acessa o campo no endereço de memória via '->'
	pessoa1->peso = 80;
	pessoa1->altura = 185;
	
	printf("Peso: %i, Altura: %i\n", pessoa1->peso, pessoa1->altura);
	
	if(pessoa->altura>alturaMaxima) printf("Altura acima da máxima.\n");
	else printf("Altura abaixo da máxima.\n")
}