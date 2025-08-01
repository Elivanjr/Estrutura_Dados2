#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include "object.h"
#include "disciplina.h"
#include "lista.h"
#include "aluno.h"
#include "capsula.h"

int menu_lista();
void interface_Lista(List lst);
int menu_principal();

int menu_principal(){
	int opc;
	system("clear");
	printf(" - - - - - - MENU PRINCIPAL - - - - - - \n\n");
	printf("[1] - Cadastrar disciplina\n");
	printf("[2] - Cadastrar aluno\n");
	printf("[3] - Opções de lista\n");
	printf("\n\nOpçao desejada: \n");
	scanf(" %i", &opc);
	return opc;
}

int menu_lista(){
	int opc;
	system("clear");
	printf(" - - - - - - OPÇÕES DA LISTA - - - - - - \n\n");
	printf("[1] - Exibir Lista\n");
	printf("[2] - Cadastrar disciplina\n");
	printf("[3] - Cadastrar aluno\n");
	printf("[4] - Remover primeiro item da Lista\n");
	printf("[5] - Deletar objeto especifico da Lista\n");
	printf("[6] - Obter objeto especifico da Lista\n");
	printf("[7] - Limpar Lista\n");
	printf("\n\nOpçao desejada: \n");
	scanf(" %i", &opc);
	return opc;
}

int buscaIndex(){
	system("clear");
	int bsc;
	printf("Digite o index que procura: \n");
	scanf(" %i", &bsc);
	return bsc;	
}

void interface_Lista(List lst){
    do {
        switch(menu_lista()){
            case 1:
                lst->print(lst);
                break;
            case 2:
                cadastrarDisciplina(lst);
                break;
            case 3:
                cadastrarAluno(lst);
                break;
            case 4: {
                Object obj = lst->pop(lst);
                if (obj) obj->destroy(obj);
                break;
            }
			case 5: lst->destroy(lst, buscaIndex());
					break;
			
            case 6: lst->get(lst, buscaIndex());
					break;
            case 7:
                lst->clear(lst);
                break;
            case 0:
                return;
        }
    } while(1);
}

#endif
