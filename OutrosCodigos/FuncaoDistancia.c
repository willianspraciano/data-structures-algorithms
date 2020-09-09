//Distancia entre dois ponto
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto{
	float x,y;
} Ponto;

typedef struct circulo{
	Ponto p;
	float r;
}Circulo;


int distancia (Circulo *c, Ponto *p){
	//float distancia = sqrt((p->x - c->p.x)*(p->x - c->p.x) + (p->y - c->p.y)*(p->y - c->p.y));
	float distancia = sqrt(((*p).x - (*c).p.x)*((*p).x - (*c).p.x) + ((*p).y - (*c).p.y)*((*p).y - (*c).p.y));

	return (distancia <= c->r);

}


int main(void){
	Circulo c;
	Ponto p;
	printf("Digite as coordenadas (x,y) do centro do circulo:\n");
	scanf("%f %f", &c.p.x, &c.p.y);

	printf("Digite o raio do circulo:\n");
	scanf("%f", &c.r);

	printf("Digite as coordenadas (x,y) de um ponto qualquer:\n");
	scanf("%f", &p.x);
	scanf("%f", &p.y);
	

	
	if(distancia(&c, &p)){
		printf("O ponto PERTENCE ao circulo!!!\n");
	}else{
		printf("O ponto NAO pertence ao circulo!!!\n");
	}
	


	return 0;


}