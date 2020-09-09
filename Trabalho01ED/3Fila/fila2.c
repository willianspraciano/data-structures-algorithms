#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"


struct lista{
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
};

Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

void fila_insere(Fila *f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f)){
		f->fim->prox = l;
	}else{
		f->ini = l;
	}
	f->fim = l;
}

int fila_vazia(Fila *f){
	return f->ini==NULL;
}

int fila_remove(Fila *f){
	Lista *l;
	int a;
	if(fila_vazia(f)){
		printf("Fila vazia!!!");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->prox;
	free(l);
	if (fila_vazia(f)){
		f->fim=NULL;
	}
	return a;
}

void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->prox;
	}
}

void fila_libera(Fila *f){
	Lista* l = f->ini;
	Lista* laux;
	while(l!=NULL){
		laux = l->prox;
		free(l);
		l = laux;
	}
	free(f);
}


//======================================//
//==============TRABALHO================//
//======================================//

int qtd_maior(Fila* f, int n){
	Lista *laux = f->ini;
	int cont=0;
	/*
	if(fila_vazia(f)){
		printf("Fila vazia!!!");
		exit(1);
	}
	*/
	while(laux != NULL){
		if (laux->info > n){
			cont++;
			//printf("%d\n",laux->info);
		}
		laux = laux->prox;
	}
	return cont;
}


void inverte(Fila* f){
	Lista *l = NULL;
	while(f->ini != NULL){
		l = lst_insere(l, f->ini->info);
		fila_remove(f);
	}

    Lista *laux = l;
	while(laux != NULL){
		fila_insere(f, laux->info);
		laux=laux->prox;
	}
}


int pares(Fila* f){
	Lista *laux = f->ini;
	int cont=0;
	//precisa testar se a lista é vazia ou eu posso retornar 0 quando for vazia
	while(laux != NULL){
		if ((laux->info)%2 == 0){
			cont++;
		}
		laux = laux->prox;
	}
	return cont;
}

//======================================//
//======================================//
//======================================//



Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}