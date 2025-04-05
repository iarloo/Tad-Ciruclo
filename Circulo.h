#ifndef CIRCULO_H
#define CIRCULO_H
#define PI 3.14
#include "Ponto.h"

typedef struct circulo Circulo;

Circulo* circ_cria(float x, float y, float r);

void circ_libera(Circulo *c);

float circ_area(Circulo *c);

int circ_interior(Circulo *c, Ponto *p);

int circ_acessa(Circulo *c, float *x, float *y, float *r);

void circ_lista(Circulo **c, int numCirculos);

int indice_valido(int indice, int total);

#endif //CIRCULO_H
