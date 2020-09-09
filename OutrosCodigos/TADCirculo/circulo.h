#include "ponto.h"

typedef struct circulo Circulo;

Circulo* circ_cria(float x, float y, float r);

void circ_libera(Circulo* c);

float circ_area(Circulo *c);

int circ_interior (Circulo *c, Ponto* p);



