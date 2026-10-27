#include <stdio.h>
#include <stdlib.h>

int** alocar_matriz(int linhas, int colunas) {
    int **m = (int **)malloc(linhas * sizeof(int *));
    if (m == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < linhas; i++) {
        m[i] = (int *)malloc(colunas * sizeof(int));
        if (m[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(m[j]);
            }
            free(m);
            return NULL;
        }
    }
    
    return m;
}

void liberar_matriz(int **m, int linhas) {
    if (m == NULL) {
        return;
    }
    
    for (int i = 0; i < linhas; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int linhas, colunas;
    
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    
    if (linhas <= 0 || colunas <= 0) {
        printf("Dimensoes invalidas.\n");
        return 1;
    }
    
    int **matriz = alocar_matriz(linhas, colunas);
    if (matriz == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }
    
    printf("\nPreencha a matriz com valores inteiros:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\nMatriz formatada no ecra:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    
    liberar_matriz(matriz, linhas);
    matriz = NULL;

    return 0;
}