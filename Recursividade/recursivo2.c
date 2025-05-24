#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_MAX 10

int somaArray(int array[], int size){
	int soma=0;
	if(size == 0)
		return 0;
	soma = somaArray(array, size-1);
	soma += array[size-1];
	return soma;
}

void botaNoVetor(int array[], int size){
	if(size == 0)
		return;
	botaNoVetor(array, size-1);
	array[size-1] = rand()%10;
}

int main(){
	
	int vetor[TAMANHO_MAX];
	botaNoVetor(vetor, TAMANHO_MAX);
	
	printf("SOMA: %i\n\n", somaArray(vetor, TAMANHO_MAX));
	for(int i = 0; i < TAMANHO_MAX; i ++){
		printf("[%i] ", vetor[i]);
	}
	return 0;
}
