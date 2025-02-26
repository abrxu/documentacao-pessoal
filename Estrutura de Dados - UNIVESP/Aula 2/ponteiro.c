#include <stdio.h>
#include <malloc.h>
int main(){
	int* y= (int*) malloc(sizeof(int)); // cria um ponteiro de y para uma memoria alocada do tamanho de um int (4 bytes ou 8 bytes)
	
	// importante: malloc geralmente retorna void* por padrão, por isso o casting
	
	*y=20; // atribui o valor 20 para onde o ponteiro de y referencia
	int z = sizeof(int); // aloca o tamanho de um int (4 bytes ou 8 bytes)
	printf("*y=%i z=%i\n", *y, z); // printa na tela
	return 0;
}