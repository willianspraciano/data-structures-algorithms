typedef struct lista Lista;
typedef struct pilha Pilha;

Pilha* pilha_cria(void);

int pilha_vazia (Pilha *p);

void pilha_push(Pilha *p, int info);

void pilha_imprime(Pilha *p);

int pilha_pop(Pilha *p);

void pilha_libera(Pilha *p);

//---------------------------------------//
//--------------TRABALHO-----------------//
//---------------------------------------//

int topo(Pilha* p);

int impares(Pilha *p);

Pilha* empilha_pares(Pilha* p1, Pilha* p2);
//---------------------------------------//
//---------------------------------------//
//---------------------------------------//


//======================================================================//
//FUNÇÕES lst_remove E lst_inserer PARA AUXILIAR NA FUNÇÃO empilha_pares//
//======================================================================//
Lista* lst_remove(Lista *l, int info);
Lista* lst_insere(Lista *l, int info);
//======================================================================//
//======================================================================//

