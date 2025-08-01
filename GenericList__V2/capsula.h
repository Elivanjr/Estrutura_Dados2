#ifndef CAPSULA_H
#define CAPSULA_H

#include "object.h"
#include "disciplina.h"
#include "lista.h"
#include "aluno.h"


void cadastrarDisciplina(List l);
void cadastrarAluno(List l);

void cadastrarDisciplina(List l){
	char nome[100], professor[100];
	int esc;
	printf("Nome da disciplina: \n");
    scanf(" %[^\n]s", nome);
    printf("Professor: \n");
    scanf(" %[^\n]s", professor);
    printf("[1] Insere no inicio da Lista ou [2] Insere no fim da Lista?\n");
    scanf(" %i", &esc);
    Object obj = new(Disciplina);
    obj->set(obj, nome, professor);
    esc == 1? l->push(l, obj) : l->enqueue(l, obj);
}

void cadastrarAluno(List l){
	char nome[100], curso[100];
	int esc;
	printf("Nome do aluno: \n");
    scanf(" %[^\n]s", nome);
    printf("Curso: \n");
    scanf(" %[^\n]s", curso);
    printf("[1] Insere no inicio da Lista ou [2] Insere no fim da Lista?\n");
    scanf(" %i", &esc);
    Object obj = new(Aluno);
    obj->set(obj, nome, curso);
    esc == 1? l->push(l, obj) : l->enqueue(l, obj);
}

#endif
