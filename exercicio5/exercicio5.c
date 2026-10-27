#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void exibir_maior_valor(Produto *vetor, int n) {
    if (n <= 0) return;
    
    int indice = 0;
    float maior_valor = vetor[0].preco * vetor[0].quantidade;
    
    for (int i = 1; i < n; i++) {
        float valor_atual = vetor[i].preco * vetor[i].quantidade;
        if (valor_atual > maior_valor) {
            maior_valor = valor_atual;
            indice = i;
        }
    }
    
    printf("\nProduto com maior valor acumulado no stock:\n");
    printf("Codigo: %d\n", vetor[indice].codigo);
    printf("Nome: %s\n", vetor[indice].nome);
    printf("Preco: %.2f\n", vetor[indice].preco);
    printf("Quantidade: %d\n", vetor[indice].quantidade);
    printf("Valor Total: %.2f\n", maior_valor);
}

int main() {
    int n;
    
    printf("Quantos produtos deseja registar? ");
    scanf("%d", &n);
    
    Produto *produtos = (Produto *)malloc(n * sizeof(Produto));
    
    if (produtos == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("\nDados do Produto %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", produtos[i].nome);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
    }
    
    exibir_maior_valor(produtos, n);
    
    free(produtos);
    produtos = NULL;

    return 0;
}