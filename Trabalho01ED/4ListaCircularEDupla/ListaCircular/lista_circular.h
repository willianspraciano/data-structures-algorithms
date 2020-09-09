typedef struct lista_circ ListaCirc;

ListaCirc* lst_circ_cria();

int lst_circ_vazia(ListaCirc *lc);

ListaCirc* lst_circ_insere(ListaCirc *lc, int info);

ListaCirc* lst_circ_busca(ListaCirc *lc, int info);

void lst_circ_imprime(ListaCirc *lc);

ListaCirc* lst_circ_remove(ListaCirc *lc, int info);

void lst_circ_libera(ListaCirc *lc);