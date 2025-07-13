#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_BIT 8 //usando 8 inves de quatro pro registradorPC;

void wait(){
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    printf("Pressione Enter para continuar...\n");
    getchar();
}

void mostraProcesso(int *tempo_Restante, int *contador_Instrucoes, 
												int *registra_PC){
    system("clear");
    printf("--- Processo em execução ---\n");
    printf("Tempo restante: %i segundos\n", *tempo_Restante);
    printf("Instruções executadas: %i\n", *contador_Instrucoes);
    printf("Registrador PC: %i\n", *registra_PC);
    printf("----------------------------\n");
    system("sleep 0.5");
}

void executaProcesso(int *tempo_Restante, int *contador_Instrucoes, int *registra_PC){
        for(;*tempo_Restante>0;){ //usando um for como while
        (*tempo_Restante)--;
        (*contador_Instrucoes)++;
        (*registra_PC) += TAMANHO_BIT;
        mostraProcesso(tempo_Restante, contador_Instrucoes, registra_PC);
    }
}

int main(){
    
    int burstTime;
    printf("Digite o tempo de execução em segundos\n");
    scanf("%i", &burstTime);
	system("clear");
	
	// Contexto de Software;
    int tempo_Restante_execucao = burstTime;  //representa o tempo que falta para o processo acabar;
    int contador_InstrucoesExecutadas = 0; //informa quantas instruções foram executadas;
	
    // Contexto de Hardware;
    //Registrador de instrução, simulando o PC Counter;
    int registrador_PC = 1000;
    
    // Espaço de Endereçamento;
    // Onde cada processo tem seu devido espaço na memória;
    int contador_instrucoes_endereco = 2004;
    int tempo_restante_execucao_endereco = 2000;
    
    printf("Processo pronto para execução...\n");
    printf("Tempo de execução: %i segundos\n", burstTime);
    printf("Instruções executadas: %i\n", contador_InstrucoesExecutadas);
    printf("Endereço: %i\n", tempo_restante_execucao_endereco);
    printf("Endereço: %i\n", contador_instrucoes_endereco);
    wait();

    executaProcesso(&tempo_Restante_execucao, &contador_InstrucoesExecutadas, &registrador_PC);

    system("clear");
    printf("--- Resumo do processo ---\n");
    printf("Total de instruções executadas: %i\n\n", contador_InstrucoesExecutadas);
    printf("Processo finalizado com sucesso.\n");

    return 0;
}
