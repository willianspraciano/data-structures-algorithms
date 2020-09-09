#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct lista {
	int info;
	Lista *prox;
};

struct fila{
	Lista *ini;
	Lista *fim;
};


Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f == NULL){
		printf("Memori insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int fila_vazia(Fila* f){
	return f->ini == NULL;
}

void fila_insere(Fila* f, int info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->prox = NULL;
	if(!fila_vazia(f)){
		f->fim->prox = l; //Se a fila não for vazia o ultimo elemento passa a ser l;
	}else{
		f->ini = l; //Se a fila for vazia o elemento inicial passa a ser a lista que acabou de ser criada
	}
	f->fim=l; //Tanto se fila for vazia ou não o ultimo elemento passa a ser o novo elemento inserido
}

int fila_remove(Fila* f){
	Lista *l;
	int a;
	if(fila_vazia(f)){
		printf("Fila vazia!!!\n");
		exit(1);
	}
	a = f->ini->info; //Faço a variavel "a" receber o valor do primeiro elemento da fila
	l = f->ini; //Faço a lista "l" apontar para o primeiro elemento da fila
	f->ini=f->ini->prox; //Faço o primeiro elemento da fila apontar para o segundo;
	free(l); //Limpo a Lista "l", ou seja removo o primeiro elemento da fila
	if(fila_vazia(f)){
		f->fim = NULL; /*no caso de uma fila com um elemento,
						Se nós removermos esse elemento a fila
						passa a ser nula. Anteriormente fizemos 
						o primeiro elemento apontar para o segundo
						se a fila só tem um elemento então o 2º elemento
						é nulo, ou seja o primeiro elemento está apontando
						para nulo. Mas o elemento final (f->fim) ainda continua
						apontando para o elemento removido (porque se a fila só
						tem um elemento o primeiro=ultimo), então aqui nós
						fazemos o ultimo elemento apontar para NULL*/
	}
	return a;
}

void fila_imprime(Fila* f){
	Lista *laux = f->ini;
	while(laux != NULL){
		printf("%d\n", laux->info);
		laux = laux->prox;
	}
}
/*
void fila_libera(Fila *f){
	Lista *l = f->ini;
	Lista *laux;
	while(l!=NULL){
		laux = l->prox;
		free(l);
		l=laux;
	}
	free(f);
}
*/

void fila_libera(Fila *f){
	Lista *l = f->ini;
	while(l != NULL){
		f->ini = f->ini->prox;
		free(l);
		l = f->ini;
	}
	//f->fim = NULL;
	free(f);
}

//=======//AP1 2018.1 questão 4////=======//
//========================================//

int fila_retira_par(Fila *f){
	if(fila_vazia(f)){
		printf("Fila vazia!!!\n");
		//exit(1);
	}else if((f->ini->info)%2 == 0){
		int a = f->ini->info;
		Lista* laux = f->ini;
		f->ini = f->ini->prox;
		free(laux);
		if(fila_vazia(f)){
			f->fim = NULL;
		}
		return a;
	}
}

//========================================//
//========================================//