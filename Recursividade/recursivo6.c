#include <stdio.h>
#include <stdlib.h>

int fibonacci_recursivo(int n){
	if(n <= 2)
		return 1;
	return fibonacci_recursivo(n-1) + fibonacci_recursivo(n-2);
}

int fibonacci_iterativo(int n){
	int aux, inicio = 1, soma = 0;
	for(int i = 1; i < n; i++){
		aux = inicio;
		inicio += soma;
		soma = aux;
	}
	return inicio;
}

int main(){
	int valor = 0;
	printf("Digite o valor de n: ");
	scanf(" %i", &valor);
	
	printf("Fibonacci Iterativo\n");
	int fibo_iter = fibonacci_iterativo(valor);
	printf("%i\n", fibo_iter);
	
	printf("Fibonacci Recursivo\n");
	int fibo_rec = fibonacci_recursivo(valor);
	printf("%i\n\n", fibo_rec);
	return 0;
}

