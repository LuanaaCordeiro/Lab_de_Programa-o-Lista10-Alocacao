#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    float *vetor = NULL;
    float soma =0;
    float media = 0;

    printf("Digite a quantidade N de elementos: ");
    scanf("%d", &N);
    if(N <=0){
        printf("Quantidade inválida! \n");
        return 1;
    }

    vetor = (float *) malloc(N * sizeof(float));

    if(vetor == NULL){
        printf("Erro!");
        return 1;
    }

   printf("Digite os %d valores:\n", N);
    for (int i = 0; i < N; i++) {
        printf("Valor %d: ", i + 1);
        if (scanf("%f", &vetor[i]) != 1) {
            printf("Entrada inválida!\n");
            free(vetor);
            vetor = NULL;
            return 1;
        }
    }

    for (int i = 0; i < N; i++) {
        soma += vetor[i];
    }
    media = soma / N;

    printf("Média aritmética dos elementos: %.2f\n", media);

    free(vetor);
    vetor = NULL;

    return 0;
}