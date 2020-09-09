#include <stdio.h>

struct ponto{
	float x;
	float y;
};

int main(void){
	struct ponto p;
	printf("Digite a coordenada x do ponto:\n");
	scanf("%f", &p.x);
	printf("Digite a coordenada y do ponto:\n");
	scanf("%f", &p.y);

	printf("Ponto (%.2f, %.2f)\n", p.x, p.y);

	return 0;
}