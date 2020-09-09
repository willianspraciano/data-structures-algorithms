#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define N 3

struct fila{
	int n; //Total de elementos
	int ini; //Indica a casa do vetor que está o elemento incial
	int v[N]; //vetor que guarda os elementos
};

Fila* fila_cria(void){
	Fila* f = (Fila*)malloc(sizeof(Fila));
	if(f == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	f->n = 0;
	f->ini =0;
	return f;
}

int fila_vazia(Fila* f){
	return f->n == 0;
}

void fila_insere(Fila* f, int info){
	int fim;
	if(f->n == N){
		printf("Capacidade da fila estourou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N;
	f->v[fim] = info;
	f->n++;
}

int fila_remove(Fila* f){
	int a; //crio uma variavel que vai receber o numero que sai da fila
	if(fila_vazia(f)){ //testo se a fila está vazia, porque se estiver vazia não tem o que remover
		printf("Vila vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini]; //a varivel "a" vai receber o valor que está na casa "f>ini" do vetor "v"
	f->ini = (f->ini+1) % N; //A variavel "f->ini" passa a ser o proximo elemento da fila, o %N é para haver uma circularidade
	f->n--; //A quantidade "n" de elementos diminui
	return a; //Retorno o elemento removido
}

void fila_imprime(Fila* f){
	int i;
	int k;

	for(i=0; i < f->n; i++){
		
		k = (f->ini+i)%N;

		printf("%d\n", f->v[k]);
	}
}

void fila_libera(Fila *f){
	free(f);
}