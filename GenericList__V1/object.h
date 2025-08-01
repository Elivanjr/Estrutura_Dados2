#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

//Cria um node que aponta para uma estrutura útil, próximo e anterior;
typedef struct Node{
	void *item;
	struct Node* next;
	struct Node* prev;
}Node;

//a criação de um Objeto que é um ponteiro para Node que é um ponteiro para uma estrutura util.
typedef Node *Object;

Object new_Object(void *item){
	Object self = (Object)malloc(sizeof(Node));
	if(!self) return NULL;
	self->item = item;
	self->next = NULL;
	self->prev = NULL;
	return self;
}

//Destrói o objeto e libera memoria
Object destroy(Object item){
	if(item){
		free(item);
	}
	return NULL;
}

#endif
