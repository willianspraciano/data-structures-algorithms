#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

struct lista_circ{
	int info;
	ListaCirc *prox;
};

ListaCirc* lst_circ_cria(){
	return NULL;
}

int lst_circ_vazia(ListaCirc *l){
	return (l==NULL);
}







//***Tem nos slides
ListaCirc* lst_circ_insere(ListaCirc *l, int info){
	ListaCirc* ln = (ListaCirc*)malloc(sizeof(ListaCirc));
	ln->info = info;
	if(l==NULL){
		ln->prox = ln;
	}else{
		ln->prox = l->prox;
		l->prox = ln;
	}
	return ln;
}

//Não é igual à lista encadeada normal
ListaCirc* lst_circ_busca(ListaCirc *l, int info){
	ListaCirc* lAux = l;

		do{
			if(lAux->info == info){
				return lAux;
			}
			lAux = lAux->prox;
		}while(lAux != l);
	
	return NULL;
}


//***Tem nos slides
void lst_circ_imprime(ListaCirc *l){
	if(l != NULL){
		ListaCirc* lAux = l;
		//printf("Lista de elementos: \n");
		do{
			printf("info = %d \n",lAux->info);
			lAux = lAux->prox;
		}while(lAux != l); //como é circular então quando lc = lcAux então a lista voltou pro começo
	}
}

//Não é igual à lista encadeada normal
/*
ListaCirc* lst_circ_remove(ListaCirc *l, int info){
	ListaCirc* lAux = lst_circ_busca(l,info);
	ListaCirc* lAux2 = l;


	if(lAux == NULL){
		printf("\nO elemento nao foi encontrado para ser removido\n");
		return l;
	}else if(l->prox == lAux){
		l->prox = lAux->prox;
		free(lAux);
			
	}else {
		while(lAux2->prox != lAux){
			lAux2=lAux2->prox;
		}
		lAux2->prox = lAux->prox;
		free(lAux);
	}
	return lAux2;
}
*/

//Não é igual à lista encadeada normal
ListaCirc* lst_circ_remove(ListaCirc *l, int info){
	if(l != NULL){
		ListaCirc *laux = l->prox;
		
		if(l->info == info){
			if(laux==l){ //quando so tiver um elemento na lista
				free(l);
				return NULL;
			}else{
				while(laux->prox != l){
					laux=laux->prox;
				}
				laux->prox = l->prox;
				free(l);
				return laux;
			}

		}else{
			ListaCirc *lant = l;
			while(laux != l){
				if(laux->info == info){
					lant->prox = laux->prox;
					free(laux);
					break;
				}else{
					lant = laux;
					laux = laux->prox;
				}
			}
		}

	}

	return l;
}

/*
void lst_circ_libera(ListaCirc *l){
	if(!lst_circ_vazia(l)){
		ListaCirc *lAux = l->prox;
		ListaCirc *lTemp;
		while(lAux != l){
			lTemp = lAux->prox;
			lst_circ_remove(lAux, lAux->info);
			lAux=lTemp;
		}
		free(l);
	}
}
*/

//Não é igual à lista encadeada normal
void lst_circ_libera(ListaCirc *l){
	if(l != NULL){
		ListaCirc *lprox = l->prox;
		ListaCirc *lant = l;

		do{
			free(lant);
			lant = lprox;
			lprox=lprox->prox;
		}while(lant!= l);
	}
}

