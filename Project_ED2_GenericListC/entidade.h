#ifndef ENTIDADE_H
#define ENTIDADE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

typedef struct Disciplina{
	int id;
	char nome[100];
	char professor[100];
	int ch;
}Disciplina;


int menu(){
	int opc;
	printf("[1] - Criar disciplina\n");
	printf("[2] - Mostrar disciplina\n");
	printf("[3] - Apagar disciplina\n");
	
	printf("\n\n[0] - Fechar programa\n");
	scanf(" %i", &opc);
	return opc;
}

Object Disciplina_construtor(){
	Disciplina *materia = (Disciplina*) malloc(sizeof(Disciplina));
	if(!materia) return NULL;
	materia->id = 0;
	strcpy(materia->nome, "");
	strcpy(materia->professor, "");
	materia->ch = 0;
	return new_Object(materia);
}

void setDisciplina(Object novo, char *nome, char *professor, int ch, int contID	){
	if(!novo || !novo->item) 
		return;
	Disciplina *materia = (Disciplina *) novo->item;
	materia->id = contID;
	strcpy(materia->nome, nome);
	strcpy(materia->professor, professor);
	materia->ch = ch;
}



void printDisciplina(Object obj){
	if(obj == NULL || obj->item == NULL) 
		return;
		
	Disciplina *materia = (Disciplina *) obj->item;
	if(materia){
		printf("Nome da materia: %s\n", materia->nome);
		printf("ID: %i\n", materia->id);
		printf("Profesor: %s\n", materia->professor);
		printf("Carga Horaria: %i h\n\n", materia->ch);
	}
}

#endif
