#ifndef LIST_H
#define LIST_H

#include "object.h"

typedef struct list {
	Object init;
	Object end;
	int size;
}_list;

typedef _list *List;

#define new(Type) Type##_construtor()

List List_construtor() {
	List l = (List)malloc(sizeof(struct list));
	if (!l) return NULL;
	l->init = NULL;
	l->end = NULL;
	l->size = 0;
	return l;
}


void listPush(Object item, List list){
	if(!list || !item) return;
	if(list->size == 0){
		list->init = item;
		list->end = item;
	}else{
		list->end->next = item;
		item->prev = list->end;
		list->end = item;
	}
	list->size++;
}

void listEnqueue(List list, Object item){
	if(!list || !item) return;
	if(list->size == 0){
		list->init = item;
		list->end = item;
	}else{
		item->next = list->init;
		list->init->prev = item;
		list->init = item;
	}
	list->size++;
}

Object list_pop(List list){
	if(!list || list->size == 0) return NULL;
	Object item = list->end;
	if(list->size == 1){
		list->init = NULL;
		list->end = NULL;
	}else{
		list->end = list->end->prev;
		list->end->next = NULL;
	}
	list->size--;
	return item;
}

Object list_dequeue(List list){
	if(!list || list->size == 0) return NULL;
	Object item = list->init;
	if(list->size == 1){
		list->init = NULL;
		list->end = NULL;
	}else{
		list->init = list->init->next;
		list->init->prev = NULL;
	}
	list->size--;
	return item;
}

void list_lista(List list, void (*print)(Object)){
	if(!list || !print) return;
	
	Object self = list->init;
	while(self){
		print(self);
		self = self->next;
	}
}

#endif

