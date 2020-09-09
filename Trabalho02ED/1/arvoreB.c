#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

struct arvb{
	char info;
	ArvB *esq;
	ArvB *dir; 
};


//Função do Slide do professor
ArvB* arvb_cria_vazia(void){
	return NULL;
}

//Função do Slide do professor
int arvb_vazia(ArvB *a){
	return a==NULL;
}

//Função do Slide do professor
ArvB* arvb_busca(ArvB* a, int c){
	if(arvb_vazia(a)){
		return NULL;
	}else if(a->info < c){
		return arvb_busca(a->dir, c);
	}else if(a->info > c){
		return arvb_busca(a->esq, c);
	}else{ //Quando a->info == c
		return a;
	}

}

//Função do Slide do professor
void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ", a->info);
		arvb_imprime(a->dir);
	}
}

//Função do Slide do professor
ArvB* arvb_insere(ArvB* a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}else if (a->info > c){
		a->esq = arvb_insere(a->esq, c);
	}else if(a->info < c){
		a->dir = arvb_insere(a->dir,c);
	}else{ //quando a->info == c
		printf("\nElemento ja pertence a arvores \n");
	}

	return a;

}

//Função do Slide do professor
ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c){
			a->esq = arvb_remove(a->esq,c);
		}else if (a->info < c){
			a->dir = arvb_remove(a->dir,c);
		}else{
			ArvB* t;
			if (a->esq == NULL){
				t = a; a = a->dir;
				free(t);
			}else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}else{
				t = a->esq;
				while(t->dir!=NULL){
					t = t->dir;
				}	
				a->info = t->info; 
				t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
	return a;
}

//Função do Slide do professor
void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
		
	}
}

//Função do Slide do professor
int arvb_altura(ArvB *a){
	if(arvb_vazia(a)){
		return -1;
	}
	else{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD){	
			return 1+hSAE;
		}else{
			return 1+hSAD;
		}	
	}
}


//===========================================================================//
//======================== FUNÇÕES DO 2º TRABALHO ED ========================//
//===========================================================================//

//QUESTÃOO 1, ITEM (a)
int folhas_primos(ArvB* a){
	if (!arvb_vazia(a)){
		int cont = 0;
		int nPrimos = 0;

		if (a->info > 0){
			for (int i = 1; i <= (a->info); i++){  
				if(a->info%i == 0){
					cont++; 				
				}
			}
			if (cont == 2){ 
				nPrimos++;
				cont = 0;
			}else{
				cont = 0;
			}
		}
		return nPrimos + folhas_primos(a->esq) + folhas_primos(a->dir);
	}else{
		return 0;
	}
}

//QUESTÃO 1, ITEM (b)
int dois_filhos(ArvB* a){
	if(!arvb_vazia(a)){
		int doisFilhos = 0;
		if(a->esq != NULL && a->dir != NULL){
			doisFilhos++;
			//printf("%d\n",a->info );
		}
		return doisFilhos + dois_filhos(a->esq) + dois_filhos(a->dir);
	}else{
		return 0;
	}
}  

//QUESTÃO 1, ITEM (c)
int nos_iguais_altura(ArvB* a){ 
	if(!arvb_vazia(a)){
		int nosIgualAltura=0;
		if (arvb_altura(a->esq) == arvb_altura(a->dir)){
			nosIgualAltura++;
			//printf("%d\n",a->info );
		}
		return nosIgualAltura + nos_iguais_altura(a->esq) + nos_iguais_altura(a->dir);
	}else{
		return 0; //Se a arvore for vazia então ela não tem nenhum nó, logo ela tem zero nós cujas as alturas da subarvore esquerda e direita são iguais
	}

	 
}   

//QUESTÃO 1, ITEM (d)
int iguais(ArvB* a, ArvB* b){
	if(arvb_vazia(a) && arvb_vazia(b)){
		return 1;
	}else if(arvb_vazia(a) || arvb_vazia(b)){
		return 0;
	}else if(a->info == b->info && iguais(a->esq,b->esq) && iguais(a->dir,b->dir)){
		return 1;
	}else{
		return 0;
	}
}

//===========================================================================//
//===========================================================================//
//===========================================================================//