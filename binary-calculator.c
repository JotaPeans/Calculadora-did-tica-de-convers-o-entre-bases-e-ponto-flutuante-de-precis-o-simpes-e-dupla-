/*
    Autor: João Pedro Fontes Ferreira
    Turma: A
    Data: 29/08/2024
*/

#include <stdio.h>
#include <stdlib.h>

void toBinary(int n) {
    printf("Base 10 para Base 2:\n");
    int binary[32];
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        printf("Passo %d: %d %% 2 = %d (resto)\n", i+1, n, binary[i]);
        n = n / 2;
        printf("Novo valor de n = %d\n", n);
        i++;
    }
    printf("Resultado em base 2: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
    printf("\n");
}

int main() {
    int num;
    printf("Insira um numero: ");
    scanf("%d", &num);
    printf("Numero: %d\n", num);

    toBinary(num);
    printf("\n");

    return 0;
}
