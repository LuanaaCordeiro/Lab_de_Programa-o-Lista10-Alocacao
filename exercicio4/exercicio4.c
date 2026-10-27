#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverter_string(char *s) {
    int inicio = 0;
    int fim = strlen(s) - 1;
    
    if (fim >= 0 && s[fim] == '\n') {
        s[fim] = '\0';
        fim--;
    }
    
    while (inicio < fim) {
        char temp = s[inicio];
        s[inicio] = s[fim];
        s[fim] = temp;
        inicio++;
        fim--;
    }
}

int main() {
    int tamanho_maximo;
    
    printf("Digite o tamanho maximo da frase: ");
    scanf("%d", &tamanho_maximo);
    getchar(); 
    
    char *frase = (char *)malloc((tamanho_maximo + 1) * sizeof(char));
    
    if (frase == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }
    
    printf("Digite a frase: ");
    fgets(frase, tamanho_maximo + 1, stdin);
    
    inverter_string(frase);
    
    printf("Frase invertida: %s\n", frase);
    
    free(frase);
    frase = NULL;


    return 0;
}