typedef struct lista Lista;

Lista* lst_cria(void);

int lst_vazia(Lista *l);

Lista* lst_insere(Lista *l, int info);

Lista* lst_busca(Lista *l, int info);

void lst_imprime(Lista *l);

Lista* lst_remove(Lista *l, int info);

void lst_libera(Lista *l);


//=======//AP1 2018.1 questão 2////=======//
//========================================//

int qtd_lista(Lista *l, int x, int y);
Lista* insere_fim_lista(Lista* l, int x);

//========================================//
//========================================//