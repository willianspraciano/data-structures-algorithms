#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void){

	Fila* f = fila_cria();

	if(fila_vazia(f)){
		printf("Fila vazia!!!\n");
	}

	fila_insere(f,1);
	fila_insere(f,2);
	fila_insere(f,3);
	//fila_insere(f,4);
	//fila_insere(f,5);
	//fila_insere(f,6);

	if(!fila_vazia(f)){
		printf("Fila Não está mais vazia!!!\n");
	}

	printf("Antes de remover:\n");
	fila_imprime(f);

	int a = fila_remove(f);
	printf("Depois de remover o numero %d\n", a);
	fila_imprime(f);

//=======//AP1 2018.1 questão 4////=======//
//========================================//
/*
	printf("\n\nSe o primeiro elemento da fila for par ele sera removido:\n");
	a = fila_retira_par(f);
	fila_imprime(f);
*/
//========================================//
//========================================//
	fila_libera(f);
	printf("Fila liberada!!!\n");
	fila_imprime(f);

	return 0;
}