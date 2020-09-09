#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"

#define N 10

struct fila{
	int n;
	int ini;
	int v[N];
};


Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if (f==NULL){
		printf("Memória insuficiente!!1");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila_insere(Fila *f, int info){
	int fim;
	if (f->n == N){
		printf("Capacidade da Fila Estourou!!!\n");
		exit(1);
	}
	fim = (f->ini + f->n)%N;
	f->v[fim] = info;
	f->n++;
}

int fila_vazia (Fila *f){
	return f->n==0;
}


int fila_remove(Fila *f){
	int a;
	if(fila_vazia(f)){
		printf("Fila vazia!!!");
		exit(1);
	}
	a = f->v[f->ini];
	//printf("O numero que vai ser removido eh o %d\n", a);
	f->ini = (f->ini+1)%N;
	f->n--;
	return a;
}

void fila_imprime(Fila *f){
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



//======================================//
//==============TRABALHO================//
//======================================//

int qtd_maior(Fila* f, int n){
	int i, k;
	int cont=0;

	for(i=0; i < f->n; i++){
		k = (f->ini+i)%N;
		if (f->v[k] > n){
			cont++;
			//printf(" É maior que 20: %d\n", f->v[k]);
		}
	}

	return cont;
}

void inverte(Fila* f){
	int i, k;
	int j=f->n-1;
	int v[f->n];
/*	
	//printf("Estou aqui\n");
	for(i=f->n; i != f->ini; i--){
			v[j] = f->v[i-1];
			//printf("%d\n",f->v[i-1]);
			j++;
	}
*/
	for(i=0; i < f->n; i++){
		k = (f->ini+i)%N;

		v[j] = f->v[k];
		j--;
	}

	for(i=0; i < f->n; i++){
		k = (f->ini+i)%N;
		f->v[k] = v[k];
	}
	
}


int pares(Fila* f){
	int i, k;
	int cont=0;
/*	
	for(i=f->ini; i <= f->n; i++){
		if(f->v[i]%2 == 0){
			cont++;
		}
	}
*/
	for(i=0; i < f->n; i++){
		k = (f->ini+i)%N;
		if (f->v[k]%2 == 0 && f->v[k] != 0){
			cont++;
			//printf("O numero par eh: %d\n", f->v[k]);
		}
	}
	return cont;
}

//======================================//
//======================================//
//======================================//

