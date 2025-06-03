#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

int buscaBinaria(int vetor[], int inicio, int fim, int valor){
    if(fim < inicio)
        return -1;

    int meio = (inicio + fim)/2;
    if(vetor[meio] == valor)
        return meio;
    if(vetor[meio] > valor){
        return buscaBinaria(vetor, inicio, meio - 1, valor);
    } else {
        return buscaBinaria(vetor, meio + 1, fim, valor);
    }
}

void bubbleRecursivo(int vetor[], int tamanho){
    if(tamanho == 1)
        return;
    int i = 0;
    for(;i < tamanho - 1;){
        if(vetor[i] > vetor[i + 1]){
            int temp = vetor[i];
            vetor[i] = vetor[i + 1];
            vetor[i + 1] = temp;
        }
        i++;
    }
    bubbleRecursivo(vetor, tamanho - 1);
}

int main(void){
    int vetor[] = {10, 50, 90, 60, 30, 20, 40, 80, 70, 100};
    int chave = 0;
    bubbleRecursivo(vetor, TAMANHO);
    
    printf("Digite um valor que possa estar no vetor: \n");
    scanf(" %i", &chave);
    
    if(buscaBinaria(vetor, 0, TAMANHO - 1, chave)!= -1){
        printf("Valor %i encontrado na posicao %i.\n", chave, buscaBinaria(vetor, 0, TAMANHO - 1, chave));
    } else {
        printf("Valor %i nao existe ou nao foi encontrado.\n", chave);
    }
    return 0;
}
