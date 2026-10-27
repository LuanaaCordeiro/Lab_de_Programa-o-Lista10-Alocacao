#include <stdio.h>
#include <stdlib.h>

int main()
{

    int capacidade = 3;
    int tamanho = 0;
    int numero;

    int *vetor = (int *)malloc(capacidade * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro na alocacao inicial de memoria.\n");
        return 1;
    }

    while (1)
    {
        printf("Digite um numero inteiro (0 para parar): ");
        if (scanf("%d", &numero) != 1)
        {
            break;
        }

        if (numero == 0)
        {
            break;
        }

        if (tamanho == capacidade)
        {
            capacidade *= 2;
            int *temp = (int *)realloc(vetor, capacidade * sizeof(int));
            if (temp == NULL)
            {
                printf("Erro na realocacao de memoria.\n");
                free(vetor);
                return 1;
            }
            vetor = temp;
        }

        vetor[tamanho] = numero;
        tamanho++;
    }

    printf("\nNumeros armazenados no vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\nTamanho final alocado na memoria Heap: %d bytes (%d posicoes de inteiros)\n", (int)(capacidade * sizeof(int)), capacidade);

    free(vetor);
    vetor = NULL;

    return 0;
}