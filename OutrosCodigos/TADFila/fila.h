
typedef struct fila Fila;
typedef struct lista Lista;

Fila* fila_cria(void);

int fila_vazia(Fila *f);

void fila_insere(Fila *f, int info);

int fila_remove(Fila *f);

void fila_imprime(Fila *f);

void fila_libera(Fila *f);

//=======//AP1 2018.1 questão 4////=======//
//========================================//

int fila_retira_par(Fila *f);

//========================================//
//========================================//