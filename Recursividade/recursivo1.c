#include <stdio.h>
#include <stdlib.h>

int potenciaXY(int base, int expoente){
    int total = 1;
    if(expoente == 0)
        return 1;
    
    total *= potenciaXY(base, expoente-1);
    return total *= base;
}

int main(){
	
    int base, expoent;
    printf("Digite a base e o expoente respectivamente: \n");
    scanf("%i %i", &base, &expoent);
    int resposta = potenciaXY(base, expoent);
    
    printf("%i^%i = %i", base, expoent, resposta);
    return 0;
}

    
