#include <stdio.h>
#include <sdtlib.h>
#include "arvore.h"

struct arv{
	char info;
	Arv *esq;
	Arv *dir;
};

Arv* arv_cria_vazia(void){
	return NULL;
}

Arv* arv_cria_no(char c, Arv* sae, Arv* sad){
	Arv *a = (Arv*)malloc(sizeof(Arv));
	a->info = c;
	a->esq = sae;
	a->dir = sad;
	return a;
}

int arv_vaiza(Arv* a){
	return a == NULL;
}

void arv_imprime(Arv* a){
	if(!arv_vaiza(a)){
		printf("%c\n", a->info);
		arv_imprime(a->esq);
		arv_imprime(a->dir);
	}
}

int arv_pertence(Arv *a, char c){
	if(arv_vaiza(a)){
		return 0;
	}else{
		return a->info == c || arv_pertence(a->esq,c ) || arv_pertence(a->dir, c);
	}
}

void arv_libera(Arv *a){
	if(!arv_libera(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
}

int arv_altura(Arv *a){
	if(arv_vazia(a)){
		return -1;
	}else{
		int hSAE = arv_altura(a->esq);
		int hDIR = arv_altura(a->dir);
		if(hSAE > hDIR){
			return 1+hSAE;
		}else{
			return 1+hSAD;
		}

	}
}