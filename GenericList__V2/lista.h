#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include "object.h"

#define new(Type) Type##_construtor()
void wait();

typedef struct Lista{
    Object head;
    Object tail;
    void (*push)(struct Lista *, Object);
    void (*enqueue)(struct Lista *, Object);
    Object (*pop)(struct Lista *);
    void (*print)(struct Lista *);
    Object (*get)(struct Lista *, int index); //
    void (*destroy)(struct Lista *, int index);
    void (*clear)(struct Lista *);
    int size;
}*List;

List List_construtor(); 

void pushList(struct Lista *lst, Object obj) {
    if (!lst || !obj) return;
	obj->next = lst->head;
	obj->prev = NULL;
	if(lst->head){
		lst->head->prev = obj;
	}else{
		lst->tail = obj;
	}
	lst->head = obj;
}

Object popList(struct Lista *lst) {
    if (!lst || !lst->tail) return NULL;
	Object obj = lst->head;
	if(lst->head->next){
		lst->head = lst->head->next;
		lst->head->prev = NULL;
	}else{
		lst->head = lst->tail = NULL;
	}
	obj->next = obj->prev = NULL;
	return obj;
}

void enqueueList(struct Lista *lst, Object obj) {
    if (!lst || !obj) return;

    obj->prev = lst->tail;
    obj->next = NULL;

    if (lst->tail)
        lst->tail->next = obj;
    else
        lst->head = obj;

    lst->tail = obj;
}


void printList(struct Lista *lst) {
	system("clear");
	printf(" - - - - - Exibir Lista - - - - - \n");
    if (!lst) return;
    Object obj = lst->head;
    while (obj) {
        if (obj->print)
            obj->print(obj);
        obj = obj->next;
    }
    wait();
}

void clearList(struct Lista *lst) {
    if (!lst) return;
    Object obj = lst->head;
    while (obj) {
        Object next = obj->next;
        if (obj->destroy)
            obj->destroy(obj);
        obj = next;
    }
    lst->head = lst->tail = NULL;
}

Object listGet(struct Lista *lst, int index){
	if(index < 1 || !lst) return NULL;
	
	Object obj = lst->head;
	int cont = 1;

	while(obj && cont < index){
		obj = obj->next;
		cont++;
	}
	return obj;
}

void deleteInList(struct Lista *lst, int index){
	if(index < 1 || !lst) return;
	
	Object obj_prev = NULL;
	Object obj = lst->head;
	int cont = 1;
    while (obj) {
        if (cont == index) {
            if (obj_prev == NULL)
                lst->head = obj->next;
            else
                obj_prev->next = obj->next;

            obj->destroy(obj);
            lst->size--;
            return;
        }
        obj_prev = obj;
        obj = obj->next;
        cont++;
    }
}

List List_construtor(){
    List lst = (List)malloc(sizeof(struct Lista));
    if (!lst) return NULL;
    lst->head = lst->tail = NULL;
    lst->push = pushList;
    lst->pop = popList;
    lst->enqueue = enqueueList;
    lst->print = printList;
    lst->get = listGet;
    lst->destroy = deleteInList;
    lst->clear = clearList;
    lst->size = 0;
    return lst;
}

#endif
