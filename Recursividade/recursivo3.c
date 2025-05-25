#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO_MAX 10

int arrayMaior(int array[], int size){
	if(size == 1){
		return array[0];
	}
	int maior = arrayMaior(array, size-1);
	if(maior < array[size-1]){
		return array[size-1];
	}
	return maior;
}

void botaNoVetor(int array[], int size){
	srand(time(NULL));
	if(size == 0)
		return;
	botaNoVetor(array, size-1);
	array[size-1] = rand()%10;
}

int main(){
	
	int vetor[10];
	botaNoVetor(vetor, TAMANHO_MAX);
	for(int i = 0; i < TAMANHO_MAX; i++){
		printf("[%i] ", vetor[i]);
	}
	printf("\n\nMaior do Array: %i ", arrayMaior(vetor, TAMANHO_MAX));
	return 0;
}
