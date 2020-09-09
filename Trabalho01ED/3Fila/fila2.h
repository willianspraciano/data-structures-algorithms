typedef struct lista Lista;
typedef struct fila Fila;

Fila* fila_cria(void);

int fila_vazia(Fila *f);

void fila_insere(Fila *f, int info);

int fila_remove(Fila *f);

void fila_imprime(Fila *f);

void fila_libera(Fila *f);


//======================================//
//==============TRABALHO================//
//======================================//
int qtd_maior(Fila* f, int n);
void inverte(Fila* f);
int pares(Fila* f);
//======================================//
//======================================//
//======================================//


Lista* lst_insere(Lista *l, int info);