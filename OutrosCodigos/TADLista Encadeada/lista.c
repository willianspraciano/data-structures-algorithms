#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	int info;
	Lista* prox;
};

Lista* lst_cria(void){
	return NULL;

}

int lst_vazia(Lista* l){
	return l == NULL;
}

Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;

}

Lista* lst_busca(Lista *l, int info){
	Lista* laux = l;
	while(laux != NULL){
		if(laux->info == info){
			return laux;
		}
		laux = laux->prox;
	}
	return NULL;
}

void lst_imprime(Lista *l){
	Lista *laux = l;
	while(laux != NULL){
		printf("info = %d\n", laux->info );
		laux = laux->prox;
	}
}

/*
Lista* lst_remove(Lista *l, int info){
	if(!lst_vazia(l)){
		Lista *ln = lst_busca(l, info);
		Lista *lant = l;
		

		if(ln == NULL){
			printf("O %d nao esta na lista!!!\n",info);
			return l;
		}else if(ln->prox == NULL && ln!=l){ //Quando é o ultimo elemento da lista
			
			while (lant->prox != ln){
				lant = lant->prox;
			}			

			lant->prox = NULL;
			free(ln);

		}else if(ln == l){ //Quando é o primeiro elemento da lista
			
				lant = ln->prox;
				free(ln);
				l=lant;

		}else{ //Quando está no meio da lista

			while (lant->prox != ln){
				lant = lant->prox;
			}			

			lant->prox = ln->prox;
			free(ln);

		}

		printf("O %d foi removido da lista!!!\n", info);
		return l;
	}
}
*/


Lista* lst_remove(Lista* l, int info){
	if(l != NULL){
		Lista *laux = l->prox;
		
		if(l->info == info){
			
			free(l);
			return laux;

		}else{
			Lista *lant = l;
			while(laux != NULL){
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


void lst_libera(Lista *l){
	Lista *lprox;
	while(l != NULL){
		lprox = l->prox;
		free(l);
		l=lprox;
	}
}

//=======//AP1 2018.1 questão 2////=======//
//========================================//

int qtd_lista(Lista *l, int x, int y){
	Lista* laux = l;
	int cont =0;
	while(laux != NULL){
		if(laux->info > x  &&  laux->info < y){
			cont++;
		}
		laux=laux->prox;
	}
	return cont;
}


/*
int qtd_lista(Lista *l, int x, int y){
	Lista *laux;
	int cont =0;
	if(l==NULL){
		printf("Lista vazia!!!\n");
		exit(1);
	}
	for(laux=l; laux ->prox != NULL; laux = laux->prox){
		if(laux->info > x  &&  laux->info < y){
			cont++;
		}
	}
	return cont;
}
*/


Lista* insere_fim_lista(Lista* l, int x){
	Lista *ln = (Lista*)malloc(sizeof(Lista));
	ln->info = x;
	ln->prox = NULL;

	if(l == NULL){
		return ln;
	}else{
		Lista *laux = l; 
		while(laux->prox != NULL){
			laux = laux->prox;
		}

		laux->prox = ln;
		return l;
	}

}

//========================================//
//========================================//