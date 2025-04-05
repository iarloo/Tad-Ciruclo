#include "Circulo.h"
#include "Ponto.h"
#include <stdlib.h>
#include <stdio.h>
struct circulo {
    float r;
    Ponto *p;
};

Circulo* circ_cria(float x, float y, float r) {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    c->p = Ponto_cria(x,y);
    c->r = r;
    return c;
}

void circ_libera(Circulo* c) {
    Ponto_libera(c->p);
    free(c);
}

float circ_area ( Circulo* c){
    return PI*((c->r)*(c->r));
}

int circ_interior ( Circulo* c, Ponto* p){
    float d = Ponto_distancia(c->p,p);
    return (d<c->r);
}

int circ_acessa(Circulo *c, float *x, float *y, float *r) {
    if (c == NULL || c->p == NULL) {
        return 0;
    }

    Ponto_acessa(c->p, x, y);
    *r = c->r;
    return 1;
}

void circ_lista(Circulo **c, int numCirculos) {
    float xt,yt,rt;
    if (numCirculos == 0) {
        printf("Não há circulos");
    }

    for (int i = 0; i < numCirculos; i++) {
        circ_acessa(c[i],&xt,&yt,&rt);
        printf("Circulo %d - Centro (%.2f,%.2f) e Raio %.2f\n", i, xt, yt, rt);
    }
}

    int indice_valido(int indice, int total) {
        return (indice >= 0 && indice < total);
    }
