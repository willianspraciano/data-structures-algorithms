#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void){
	Lista *l = lst_cria();
	if(lst_vazia(l)){
		printf("Lista vazia!!!\n");
	}
	//l = lst_insere(l,1);
	//l = lst_insere(l,2);
	//l = lst_insere(l,3);
	//l = lst_insere(l,4);
	l = lst_insere(l,5);
	
	if(!lst_vazia(l)){
		printf("Foram inseridos elemento na lista!!!\n");
	}
	
	lst_imprime(l);
	
	int rem = 5;

	printf("\nRemoveu o 5\n");
	l = lst_remove(l, rem);
	

	lst_imprime(l);


//=======//AP1 2018.1 questão 2////=======//
//========================================//

	int quantidade = qtd_lista(l,1,5);
	printf("\n\nQuantidade maior que 1 e menor que 5 éh: %d\n", quantidade);

	l = insere_fim_lista(l, 1);
	printf("Iserimos o numero 1 no fim da lista:\n");
	lst_imprime(l);

//========================================//
//========================================//

	lst_libera(l);
	printf("Depois de liberar a lista\n");
	if(lst_vazia(l)){
		printf("Lista vazia!!!\n");
	}else{
		lst_imprime(l);
	}


	return 0;
}