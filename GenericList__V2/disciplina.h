#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

typedef struct Disciplina {
    int id;
    char nome[100];
    char professor[100];
} Disciplina;

void printDisciplina(Object obj) {
    if (!obj || !obj->item) return;
    Disciplina *materia = (Disciplina *) obj->item;
    printf("\nNome da matéria: %s\n", materia->nome);
    printf("ID: %d\n", materia->id);
    printf("Professor: %s\n\n", materia->professor);
}

void setDisciplina(Object obj, const char* nome, const char* professor) {
    static int proximoId = 0;

    Disciplina *d = (Disciplina*)obj->item;
    d->id = (proximoId++);
    strcpy(d->nome, nome);
    strcpy(d->professor, professor);
}


Object Disciplina_construtor() {
    Disciplina *d = (Disciplina *)malloc(sizeof(Disciplina));
    if (!d) return NULL;
    d->id = 0;
    strcpy(d->nome, "");
    strcpy(d->professor, "");
    return new_Object(d, DISCIPLINA, printDisciplina, setDisciplina);
}

#endif
