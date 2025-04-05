#include <stdio.h>
#include "Circulo.h"
#define MAX_CIRCULOS 10

int main(void) {

    ///Variaveis principais.
    int funcaoDesejada = 1;
    int numCirculos = 0;
    Circulo *circulos[MAX_CIRCULOS]; //Vetor para guardar 10 circulos

    while (funcaoDesejada < 6 && funcaoDesejada > 0 ) {
        printf("\nNumero Máximo de circulos : %d\n", MAX_CIRCULOS - numCirculos);
        printf("1 - Criar Circulo\n");
        printf("2 - Libera Circulo\n");
        printf("3 - Area Circulo\n");
        printf("4 - Verificar ponto no circulo\n");
        printf("5 - Listar Circulos\n");
        printf("6 - Sair\n");

        printf("Escolha uma função: ");
        //Recolhe a função desejada do usuario;
        scanf("%d", &funcaoDesejada);

        switch (funcaoDesejada) {
            default:
                printf("opção invalida");
                break;

            case 1:
                printf("\n1 - Criar Circulo\n");

                //Verifica se tem circulo pra ser criado.
                if(numCirculos < MAX_CIRCULOS){
                    float x,y,r; //variáveis auxiliares
                    //Output do usuario
                    printf("Digite as coordenadas do centro de seu circulo\n");
                    printf("Digite o valor x :"); scanf("%f", &x);
                    printf("Digite o valor y :"); scanf("%f", &y);

                    printf("Digite o raio do circulo\n");
                    printf("Digite o valor r :"); scanf("%f", &r);


                    circulos[numCirculos] = circ_cria(x,y,r); //utiliza o tad
                    printf("\nCirculo %d criado: Centro: (%.1f, %.1f) Raio: %.1f \n", numCirculos + 1, x, y,r);
                    numCirculos++;
                }else{
                    printf("Numero máximo de circulos atingido, será criados novos circulos uma vez que algum ponto pré existente é liberado.\n");
                }

                break;

            case 2:
                if (numCirculos > 0) {
                    int indice;
                    circ_lista(circulos, numCirculos); //Mostra os circulos
                    printf("\nDigite o indice do circulo a ser liberado:");
                    scanf("%d", &indice);

                    //verifica se o indice do usuario faz sentido
                    if (indice_valido(indice,numCirculos)) {
                        circ_libera(circulos[indice]);  // libera o ponteiro corretamente

                        // Move os ponteiros seguintes para preencher o espaço
                        for (int j = indice; j < numCirculos - 1; j++) {
                            circulos[j] = circulos[j + 1];
                        }
                        numCirculos--;  // atualiza o total
                    }else {
                        printf("Indice invalido\n");
                    }

                }else {
                    printf("não há circulos para serem liberados\n");
                }
                break;

            case 3:

                printf("\n3 - Area do circulo\n");
                if (numCirculos > 0) {
                    int indice;
                    circ_lista(circulos, numCirculos);
                    printf("Escolha o indice do circulo que deseja obter a area:");
                    scanf("%d", &indice);

                    if (indice_valido(indice, numCirculos)) {
                        printf("A area do circulo %d é : %.2f", indice, circ_area(circulos[indice]));
                    }else {
                        printf("Indice invalido!\n");
                    }
                }else {
                    printf("\n Não há circulos suficientes.");
                }
                break;

            case 4:
                printf("\n4 - Verificar ponto no circulo\n");
                if (numCirculos > 0) {
                    int indice;
                    float x,y;
                    float xc,yc,r;
                    circ_lista(circulos, numCirculos);
                    printf("Escolha o indice do circulo que deseja verificar o ponto:");
                    scanf("%d", &indice);

                    if (indice_valido(indice,numCirculos)) {
                        printf("Agora, digite as coordenadas do ponto a ser verificado\n");
                        printf("Digite o valor x :"); scanf("%f", &x);
                        printf("Digite o valor y :"); scanf("%f", &y);

                        Ponto *p = Ponto_cria(x,y);
                        circ_acessa(circulos[indice], &xc, &yc, &r);

                        if (circ_interior(circulos[indice], p)) {
                            printf("O ponto (%.2f, %.2f) pertence ao interior do circulo de centro (%.2f,%.2f) e raio %.2f ", x,y,xc,yc,r);
                        }else {
                            printf("Infelizmente o ponto (%.2f, %.2f) não pertence ao interior do circulo de centro (%.2f,%.2f) e raio %.2f ", x,y,xc,yc,r);
                        }
                    }else {
                        printf("indice invalido!");
                    }
                }else {
                    printf("\n Não existem circulos pra serem verificados\n");
                }
                break;

            case 5:
                printf("\n5 - Listar Circulos\n");
                circ_lista(circulos, numCirculos);
        }
    }



    return 0;
}