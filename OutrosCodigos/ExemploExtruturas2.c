#include <stdio.h>

struct ponto{
	float x;
	float y;
};

void captura(struct ponto *pp){
	printf("Digite a coordenada x do ponto:\n");
	scanf("%f", &pp->x);
	printf("Digite a coordenada y do ponto:\n");
	scanf("%f", &(*pp).y);
}

void imprime(struct ponto *pp){
	printf("Ponto (%.2f, %.2f)\n", pp->x, pp->y);
}

int main(void){
	struct ponto p;
	captura(&p);
	imprime(&p);

	

	return 0;
}