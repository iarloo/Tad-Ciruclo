#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "Ponto.h" //inclui os prototipos

struct ponto{      //definiçao do tipo de dado
    float x;
    float y;
};

Ponto* Ponto_cria(float x, float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

void Ponto_libera(Ponto* p){
    free(p);
}

int Ponto_acessa(Ponto* p, float* x, float* y){
    if(p == NULL)
        return 0;
    *x = p->x;
    *y = p->y;
    return 1;
}

int Ponto_atribui(Ponto* p, float x, float y){
    if(p == NULL) {
        return 0;
    }
    p->x = x;
    p->y = y;
    return 1;
}

float Ponto_distancia(Ponto* p1, Ponto* p2){
    if(p1 == NULL || p2 == NULL)
        return -1;
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

void Ponto_lista(int numPontos, Ponto **pontos, int exception){
    //-1 para nenhuma exceção
    float xt,yt;
    for (int i = 0; i < numPontos; i++) {
        if (i != exception) {
            Ponto_acessa(pontos[i],&xt,&yt);
            printf("Ponto %d - (%.2f,%.2f)\n", i, xt, yt);
        }
    }
}