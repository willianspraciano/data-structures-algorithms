typedef struct listaDupla ListaDupla;

ListaDupla* lst_dupl_cria();

int lst_dupl_vazia(ListaDupla *l);

ListaDupla* lst_dupl_insere(ListaDupla *l, int info);

void lst_dupl_imprime(ListaDupla *l);

ListaDupla* lst_dupl_busca(ListaDupla *l, int info);

ListaDupla* lst_dupl_remove(ListaDupla *l, int info);

void lst_dupl_libera(ListaDupla *l);





