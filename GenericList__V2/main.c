#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

#include "lista.h"
#include "disciplina.h"
#include "aluno.h"

#include "menu.h"
#include "capsula.h"


int main(){
    List lst = new(List);
    
	do{
		switch(menu_principal()){
			case 1: cadastrarDisciplina(lst);
					break;
			case 2: cadastrarAluno(lst);
					break;
			case 3: interface_Lista(lst);
					break;
			case 0: lst->clear(lst);
					return 0;
		}
	}while(1);

    return 0;
}
