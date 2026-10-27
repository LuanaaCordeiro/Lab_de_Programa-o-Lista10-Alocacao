#include<stdio.h>
#include<stdlib.h>

int main(){

    int *v1 = (int *)malloc(10 * sizeof(int));
    int *v2 = (int *)calloc(10, sizeof(int));

    if (v1 == NULL || v2 == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    printf("\nElementos de V1:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", v1[i]);
    }
    
    printf("\nElementos de V2:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", v2[i]);
    }

    free(v1);
    free(v2);
    
    v1 = NULL;
    v2 = NULL;

    /*
    EXPLICAÇÃO 
    A diferença ocorre pois um se utiliza malloc e o outro se utiliza calloc.
    A função malloc() apenas reserva o bloco de memória e não o limpa, o que significa 
    que V1 conterá lixo de memória, ou seja, valores imprevisíveis que já estavam na RAM.
    Já a função calloc() aloca a memória e inicializa todos os bits com zero, 
    garantindo que todos os elementos de V2 comecem com o valor 0.
    */

    return 0;
}