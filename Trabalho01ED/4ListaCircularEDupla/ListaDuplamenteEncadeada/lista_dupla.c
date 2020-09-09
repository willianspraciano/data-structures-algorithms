#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

struct listaDupla{
	int info;
	ListaDupla *prox;
	ListaDupla *ant;
};

//
ListaDupla* lst_dupl_cria(){
	return NULL;
}

//
int lst_dupl_vazia(ListaDupla *l){
	return (l == NULL);
}





//Tem no slide do professor
ListaDupla* lst_dupl_insere(ListaDupla *l, int info){
	ListaDupla* ln = (ListaDupla*)malloc(sizeof(ListaDupla));
	ln->info = info;
	ln->prox = l;
	ln->ant = NULL;
	if(l!=NULL){
		l->ant = ln;
	}

	return ln;
}


//
void lst_dupl_imprime(ListaDupla *l){
	ListaDupla *laux = l;
	while(laux != NULL){
		printf("info = %d\n", laux->info );
		laux = laux->prox;
	}
}

//Tem no slide do professor
ListaDupla* lst_dupl_busca(ListaDupla *l, int info){
	ListaDupla* lAux = l;
	while(lAux != NULL){
		if(lAux->info == info){
			return lAux;
		}
		lAux = lAux->prox;
	}
	return NULL;
}

//Tem no slide do professor
ListaDupla* lst_dupl_remove(ListaDupla *l, int info){
	ListaDupla* lAux = lst_dupl_busca(l,info);


	if(lAux == NULL){
		printf("\nO elemento nao foi encontrado para ser removido\n");
		return l;
	}

	if(lAux == l){
		l = lAux->prox;
	}else{
		lAux->ant->prox = lAux->prox;
	}

	if(lAux->prox != NULL){
		lAux->prox->ant =lAux->ant;
	}	

	free(lAux);
	return l;
}



void lst_dupl_libera(ListaDupla *l){
	ListaDupla *lprox;
	while(l != NULL){
		lprox = l->prox;
		free(l);
		l=lprox;
	}
}