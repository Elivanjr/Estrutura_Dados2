#ifndef OBJECT_H
#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>

typedef enum{
    DISCIPLINA,
    ALUNO
}typeObject;

#define new(Type) Type##_construtor()

typedef struct Node {
    void *item;
    typeObject tipo;
    void (*print)(struct Node *);
    void (*set)(struct Node *, const char *, const char *);
    void (*destroy)(struct Node *);
    struct Node* next;
    struct Node* prev;
} Node;

typedef Node* Object;

Object Aluno_construtor();
Object Disciplina_construtor();

#include "lista.h" 
List List_construtor(); 

void destroyObject(Object obj);

Object new_Object(void *item, typeObject tipo, void (*print)(Object), void (*set)(Object, const char *, const char *)) {
    Object self = (Object)malloc(sizeof(Node));
    if (!self) return NULL;
    self->item = item;
    self->tipo = tipo;
    self->print = print;
    self->set = set;
    self->destroy = destroyObject;
    self->next = NULL;
    self->prev = NULL;
    return self;
}

void destroyObject(Object obj) {
    if (obj) {
        if (obj->item)
			free(obj->item);
			
		free(obj);
    }
}

void wait(){
    setbuf(stdin, NULL);
    getchar();
}


#endif
