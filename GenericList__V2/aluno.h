#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

typedef struct Aluno {
    int matricula;
    char nome[100];
    char curso[100];
} Aluno;

void printAluno(Object obj) {
    if (!obj || !obj->item) return;
    Aluno *aluno = (Aluno *) obj->item;
    printf("\nNome do Aluno: %s\n", aluno->nome);
    printf("Matrícula: %d\n", aluno->matricula);
    printf("Curso: %s\n\n", aluno->curso);
}

void setAluno(Object obj, const char nome[], const char* curso) {
    static int proximaMatricula = 0;

    Aluno *a = (Aluno*)obj->item;
    a->matricula = (proximaMatricula++);
    strcpy(a->nome, nome);
    strcpy(a->curso, curso);
}

Object Aluno_construtor() {
    Aluno *a = (Aluno *)malloc(sizeof(Aluno));
    if (!a) return NULL;
    a->matricula = 0;
    strcpy(a->nome, "");
    strcpy(a->curso, "");
    return new_Object(a, ALUNO, printAluno, setAluno);
}

#endif
