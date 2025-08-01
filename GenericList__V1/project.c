#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "list.h"
#include "entidade.h"

static int id_cont = 1;
void scoreCont(); //Função externa TEMPORARIA, apenas para a contagem de objetos em Disciplina.

int main(){
	
	List list1 = new(List);	
	Object m1 = new(Disciplina);
	
	setDisciplina(m1, "S.O", "Felipe Mota", 120, id_cont);
	scoreCont();
	listPush(m1, list1);
	m1 = new(Disciplina);
	setDisciplina(m1, "BD1", "Felipe Mota", 80, id_cont);
	scoreCont();
	listPush(m1, list1);
	Object m2 = list_pop(list1);
	printDisciplina(m2);
	destroy(m2);
	list_lista(list1, printDisciplina);

	return 0;
}

void scoreCont(){
	id_cont++;
}
