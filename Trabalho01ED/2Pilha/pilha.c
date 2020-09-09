#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct lista{
	int info;
	Lista *prox;
};

struct pilha{
	Lista *prim;
};


Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

void pilha_push (Pilha *p, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = p->prim;
	p->prim = l;
}

void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

void pilha_libera(Pilha *p){
	Lista* l = p->prim;
	Lista* lAux;
	while(l!=NULL){
		lAux = l->prox;
		free(l);
		l = lAux;
	}
	free(p);
}

int pilha_vazia(Pilha *p){
	return p->prim == NULL;
}

int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if (pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	l = p->prim;
	a = l->info;
	p->prim = l->prox;
	free(l);
	return a;
}

//---------------------------------------//
//--------------TRABALHO-----------------//
//---------------------------------------//

int topo(Pilha* p){
	if(p->prim == NULL){
		printf("Pilha vazia!!!\n");
		exit(1);
	}
	Lista *lAux = p->prim;
	return lAux->info;
}

int impares(Pilha *p){
	if(p->prim == NULL){
		printf("Pilha vazia!!!\n");
		exit(1);
	}
	Lista *laux = p->prim;
	int cont=0;
	while(laux != NULL){
		if(laux->info%2 != 0){
			cont++;
		}
		laux=laux->prox;	
	}
	return cont;
}


Pilha* empilha_pares(Pilha* p1, Pilha* p2){
	Lista *l = NULL;
	Lista *laux = p1->prim;

	while(laux != NULL){
		if((laux->info)%2 == 0){
			l = lst_insere(l, laux->info);
			//printf("Foi inserido %d\n", laux->info);
		}
		laux=laux->prox;
	}

	laux = l;
	Lista *laux2 = l;
	int x;
	while(laux != NULL){
		x=laux->info;
		//printf("O numero é %d\n",x );
		while(laux2 != NULL){
			if(laux2->info < x){
				x = laux2->info;
			}
			//printf("o numero ehhhh %d\n", laux2->info);
			laux2 = laux2->prox;
		}
		l=lst_remove(l, x);
		pilha_push(p2, x);
		laux2 = l;
		laux=l;
	}
	return p2;
}

//---------------------------------------//
//---------------------------------------//
//---------------------------------------//




//======================================================================//
//FUNÇÕES lst_remove E lst_inserer PARA AUXILIAR NA FUNÇÃO empilha_pares//
//======================================================================//

Lista* lst_remove(Lista *l, int info){
	if(l != NULL){
		Lista* laux = l->prox;
		if(l->info == info){
			free(l);
			return laux;
		}else{
			Lista* lant = l;
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

Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}

//======================================================================//
//======================================================================//


