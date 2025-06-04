#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_MAX 10

void botaNoVetor(int array[], int size){
	if(size == 0)
		return;
	botaNoVetor(array, size-1);
	array[size-1] = rand()%10;
}

int buscadorRecursivo(int array[], int tamanho, int chave){
	if(tamanho == 0)
		return -1;
	if(array[tamanho - 1] == chave){
		return tamanho - 1;
	}
	return buscadorRecursivo(array, tamanho - 1, chave);
}

int main(){
	srand(time(NULL));
	int lista[TAMANHO_MAX];
	botaNoVetor(lista, TAMANHO_MAX);
	for(int i = 0; i < TAMANHO_MAX; i++){
		printf("[%i] ", lista[i]);
	}

	int busca = buscadorRecursivo(lista, TAMANHO_MAX, 10);
	if(busca != -1){
		printf("\nElemento encontrado na posicao %i\n", busca);
	}else{
		printf("\nIt's over, não foi encontrado\n");
	}
	
	return 0;
}
