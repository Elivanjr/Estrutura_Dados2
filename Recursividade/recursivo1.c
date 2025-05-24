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
	
    int base = 9, expoent = 2;
    int resposta = potenciaXY(base, expoent);
    
    printf("Potencia: %i", resposta);
    return 0;
}

    
