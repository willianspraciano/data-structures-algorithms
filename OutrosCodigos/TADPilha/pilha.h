typedef struct pilha Pilha;
typedef struct lista Lista;

Pilha* pilha_cria(void);

int pilha_vazia(Pilha *p);

void pilha_push(Pilha *p, int info);

int pilha_pop(Pilha *p);

void pilha_imprime(Pilha *p);

void pilha_libera(Pilha *p);


//=======//AP1 2018.1 questão 3////=======//
//========================================//
void pilha_push_maior(Pilha *p, int info);
int pilha_pop_par(Pilha *p);

//========================================//
//========================================//