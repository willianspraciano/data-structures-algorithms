#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	int info;
	Lista* prox;
};

Lista* lst_cria(){
	return NULL;
}


int lst_vazia(Lista *l){
	return l == NULL;
}

Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}


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


Lista* lst_busca(Lista *l,int info){
	Lista *laux=l;
	while(laux!=NULL){
		if(laux->info==info){
			return laux;
		}else{
			laux=laux->prox;
		}
	}
	return NULL;
}
void lst_imprime(Lista *l){
	Lista *laux = l;
	while(laux != NULL){
		printf("Info = %d\n",laux->info);
		laux=laux->prox;
	}
}

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

void lst_libera(Lista *l){
	Lista *lprox;
	while(l!=NULL){
		lprox = l->prox;
		free(l);
		l=lprox;
	}
}


Lista* lst_remove_par(Lista *l){
	if(l!=NULL){
			if(l->info%2!=0){
				Lista* lAux = l;
				l = l->prox;
				free(lAux);
				l = lst_remove_par(l);
			}else{
				l->prox = lst_remove_par(l->prox);
			}
	}
	return l;
}

void lst_imprime_invertida_rec(Lista* l){
	if(lst_vazia(l)){
		return;
	}
	else{
		lst_imprime_invertida_rec(l->prox);
		printf("info: %d\n",l->info);
	}
}


//-----------------------------------------------------//
//--------------------TRABALHO-------------------------//
//-----------------------------------------------------//

int comprimento (Lista* l){
	Lista* laux = l;
	int comp = 0;
	
	if(laux == NULL){ 
		return 0; //Se a lista for vazia o comprimento é zero
	}else{
		while(laux != NULL){
			comp++; //Se a lista não for vazia cada nó vai ser contado
			laux = laux->prox; //A variavel auxiliar passa a apontar para o próximo elemento da lista
		}
		return comp; //Retorna o comprimento total depois de contar todos os nós
	}
}

int menores (Lista* l, int n){

	Lista* laux =l;
	int men=0;

	if(laux == NULL){
		return 0; //Se a lista for vazia então não tem elemento menor que "n", vai tetornar 0
	}else{
		while(laux != NULL){ //O laço é repetido até laux ser diferente de vazio
			if (laux->info < n){ 
				men++; //Testa se o elemento da lista é menor que "n", se for é somado 1 a variavel "men"
			}
			laux = laux->prox; //"laux" passa a apontar para o próximo elemento da lista para ser testado
		}
		return men; //Retorna a quantidade de elementos menores que "n" depois de percorrer toda a lista
	}

}

int soma(Lista *l){
	Lista* laux = l;
	int som = 0; //0 é o valor inicial da soma

	if (laux == NULL){
		return 0; //Se a lista for vazia a soma dos seus elementos é zero
	}else{
		while(laux != NULL){ //Enquanto a lista "laux" não for vazia o laço se repete 
			som = som + laux->info; // Os elementos da lista são incrementados na variável "som"
			laux = laux->prox; //A lista "laux" passa a apontar para o proximo elemento da lista
		}
		return som;
	}
}

int perfeito (Lista* l){
	Lista* laux = l;
	int perf=0;
	int cont=0;
	int i;

	if(laux == NULL){
		return 0;
	}else{
		while(laux != NULL){	//Entra no laço se laux for diferente de vazio
			
			for (i=1; i < laux->info; i++){  //O laço vai de 1 ate o número antecessor ao laux->info
				if(laux->info != 0 && laux->info%i == 0){ //Testa se o resto da divisão é zero, se sim então o numero é um divisor de laux->info
					cont = cont + i; //Somo todos os divisores de laux->info a variável "cont"
				}
			}
			
			if (cont == laux->info){ //Testa se a soma dos divisores é igual ao laux->info
				perf++; //Se for igual então é um Número perfeito
			}
			
			laux = laux->prox; //faz "laux" apontar para o próximo elemento da lista
			cont =0; //zera a variavel contador
		}
		return perf; //retorna a quantidade de números perfeitos da lista
	}
}


Lista* lst_conc (Lista* l1, Lista* l2){
	Lista* ln = lst_cria();
	Lista* laux;

	//Insere os elementos da lista l1 na nova lista ln 
	laux = l1;
	while(laux != NULL){
		ln=insere_fim_lista(ln, laux->info);
		laux=laux->prox;
	}

	//Insere os elementos da lista l2 na nova lista ln 
	laux = l2;
	while(laux != NULL){
		ln = insere_fim_lista(ln, laux->info);
		laux=laux->prox;
	}	

	return ln;

	
	
	/*
	if(l1 == NULL){
		return l2;

	}else if(l2 == NULL){
		return l1;
	}else{

		Lista* laux = l1;

		while(laux->prox != NULL){ 
			laux = laux->prox; //percorre toda a lista l1 até chegar no ultimo elemento
		}

		laux->prox = l2; //faz o ultimo elemento apontar para o primeiro elemento da lista l2
		printf("Esse aqui !!!\n");
		return l1;

	}
	*/
}


Lista* lst_diferenca (Lista* l1, Lista* l2){
	Lista* laux1 = l1;
	Lista* laux2 = l2;

		while (laux1 != NULL){
			while(laux2 != NULL){				
				if (laux1->info == laux2->info){
					l1 = lst_remove(l1, laux2->info);
				}
				laux2=laux2->prox;
			}
			
			laux2=l2;		
			laux1=laux1->prox;
		}
	return l1;
}

//-----------------------------------------------------//
//-----------------------------------------------------//
//-----------------------------------------------------//





