#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
	Pilha *p = pilha_cria();
	//pilha_push(p, 1);
	//pilha_push(p, 2);
	//pilha_push(p, 3);


	//pilha_imprime(p);
	
	//int a = pilha_pop(p);
	//printf("Depois de remover %d:\n", a);
	//pilha_imprime(p);


//=======//AP1 2018.1 questão 3////=======//
//========================================//
	int b= 4;
	//pilha_push_maior(p, b);
	printf("\n\nO numero %d será inserido se ele for maior que o topo:\n",b);
	//pilha_imprime(p);


	int c = pilha_pop_par(p);
	printf("Se o %d (primeiro elemento da fila) for par ele será removido:\n", c);
	pilha_imprime(p);

//========================================//
//========================================//

	return 0;
}