#include <stdio.h>
#include<stdlib.h>
#include "lista_circular.h"

int main(void){

	int maior;
	

	ListaCirc* l = lst_circ_cria();
	l = lst_circ_insere(l,10);
	l = lst_circ_insere(l,13);
	l = lst_circ_insere(l,25);
	l = lst_circ_insere(l,29);
	l = lst_circ_insere(l,40);

	printf("Antes de remover o 10:\n");
	lst_circ_imprime(l);

	l = lst_circ_remove(l,10);
	printf("Depois de remover o 10:\n");
	lst_circ_imprime(l);
	
	
	lst_circ_libera(l);
	
	/*
	printf("Depois de liberar a lista!!\n");
	if(lst_circ_vazia(l)){
		printf("Lista vazia!!!\n");
	}else{
		lst_circ_imprime(l);
	}
	*/

	system("PAUSE");
	return 0;
}