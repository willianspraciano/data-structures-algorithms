#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
};

ArvB* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(ArvB* a){
	return a == NULL;
}

ArvB* arvb_busca(ArvB *a,int c){
	if(arvb_vazia(a)){
		return NULL;
	}else if(a->info < c){
		return arvb_busca(a->dir,c);
	}else if(a->info > c){
		return arvb_busca(a->esq,c);
	}else {//(a->info == c)
		return a;
	}
}

void arvb_imprime(ArvB* a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d\n", a->info);
		arvb_imprime(a->dir);
	}
}

/*
int arvb_pertence(ArvB *a, char c){
	if(arvb_vazia(a)){
		return 0;
	}else{
		return a->info == c || arvb_pertence(a->esq,c ) || arvb_pertence(a->dir, c);
	}
}
*/

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->dir = NULL;
		a->esq = NULL;
	}else if(a->info > c){
		a->esq = arvb_insere(a->esq, c);
	}else if(a->info < c){
		a->dir = arvb_insere(a->dir, c);
	}else{ //(a->info == c)
		printf("O elemento ja pertence a arvore!!!\n");
	}
	return a;
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c){
			a->esq = arvb_remove(a->esq, c);
		}else if(a->info < c){
			a->dir = arvb_remove(a->dir, c);
		}else{ //(a->info == c)
			ArvB* t;
			if(a->dir == NULL){
				t = a;
				a=a->esq;
				free(t);
			}else if(a->esq == NULL){
				t = a;
				a=a->dir;
				free(t);
			}else{ //Quando o nó que queremos remover tem a SAD e a SAE
				
				t = a->esq; //O elemento de "a" vai ser trocado com o elemento mais 
							//a direita da subarvore esquerda
				while(t->dir != NULL){
					t = t->dir;
				}
				a->info = t->info;
				t->info = c;
				a->esq = arvb_remove(a->esq, c); //Depois removemos o c que foi trocado de lugar, 
												//essa vez iremos cair em algum dos outros casos mais simples

			}
		}
	}
	return a;
}

void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

int arvb_altura(ArvB *a){
	if(arvb_vazia(a)){
		return -1;
	}else{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD){
			return 1+hSAE;
		}else{
			return 1+hSAD;
		}

	}
}