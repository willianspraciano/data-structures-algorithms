#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

int main(void){

	int maior;

	ListaDupla* l = lst_dupl_cria();

	l = lst_dupl_insere(l,10);
	l = lst_dupl_insere(l,13);
	l = lst_dupl_insere(l,25);
	l = lst_dupl_insere(l,29);
	l = lst_dupl_insere(l,40);
	
	printf("Lista completa:\n");
	lst_dupl_imprime(l);

	l = lst_dupl_remove(l,10);
	printf("Lista depois do 10 ter sido removido:\n");
	lst_dupl_imprime(l);

	lst_dupl_libera(l);
/*
	printf("Lista depois de ter sido liberada:\n");
	lst_dupl_imprime(l);
*/	
	system("PAUSE");
	return 0;
}