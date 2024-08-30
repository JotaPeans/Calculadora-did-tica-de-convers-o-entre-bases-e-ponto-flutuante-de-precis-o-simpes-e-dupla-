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

void toOctal(int n) {
    printf("Base 10 para Base 8:\n");
    int octal[32];
    int i = 0;
    while (n > 0) {
        octal[i] = n % 8;
        printf("Passo %d: %d %% 8 = %d (resto)\n", i+1, n, octal[i]);
        n = n / 8;
        printf("Novo valor de n = %d\n", n);
        i++;
    }
    printf("Resultado em base 8: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", octal[j]);
    printf("\n");
}

void toHex(int n) {
    printf("Base 10 para Base 16:\n");
    char hex[32];
    int i = 0;
    while (n > 0) {
        int temp = n % 16;
        printf("Passo %d: %d %% 16 = %d (resto)\n", i+1, n, temp);
        if (temp < 10) {
            hex[i] = temp + 48;
        } else {
            hex[i] = temp + 55;
        }
        n = n / 16;
        printf("Novo valor de n = %d\n", n);
        i++;
    }
    printf("Resultado em base 16: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");
}

int main() {
    int num;
    printf("Insira um numero: ");
    scanf("%d", &num);
    printf("Numero: %d\n", num);

    toBinary(num);
    printf("\n");

    toOctal(num);
    printf("\n");

    toHex(num);
    printf("\n");

    return 0;
}
