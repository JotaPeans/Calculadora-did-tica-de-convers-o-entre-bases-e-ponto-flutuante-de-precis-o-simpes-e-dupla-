/*
    Autor: João Pedro Fontes Ferreira
    Turma: A
    Data: 29/08/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

void toBCD(int num) {
    printf("Passos para converter %d em BCD:\n", num);
    
    int digits[10]; // Máximo de 10 dígitos para um inteiro
    int count = 0;

    // Extrai cada dígito do número
    while (num > 0) {
        digits[count] = num % 10;
        num /= 10;
        count++;
    }

    int showSplitedCount = 1;
    printf("Separando os digitos\n");
    for (int j = count - 1; j >= 0; j--) {
        printf("Digito %d: %d\n", showSplitedCount, digits[j]);
        showSplitedCount++;
    }

    // Imprime os dígitos em BCD
    printf("Convertendo cada digito em binario\n");
    printf("Resultado em BCD: ");
    for (int i = count - 1; i >= 0; i--) {
        int n = digits[i];

        int binary[32];
        int i = 0;

        while (n > 0) {
            binary[i] = n % 2;
            n = n / 2;
            i++;
        }

        int arrayDigitsIntegerNum = 0;
        for (int j = i - 1; j >= 0; j--) {
            arrayDigitsIntegerNum = arrayDigitsIntegerNum * 10 + binary[j];
        }

        printf("%04d", arrayDigitsIntegerNum);

        printf(" ");
    }
    printf("\n");
}

void toComplement2(int num) {
    int bits = 16;
    printf("Passos para converter %d para complemento a 2 (%d bits):\n", num, bits);

    if (num < 0) {
        num = (1 << bits) + num; // Soma o número negativo ao valor máximo para obter o complemento
    }

    printf("Resultado em complemento a 2: ");
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1); // Imprime cada bit
    }
    printf("\n");
}

void floatToBinary(float f) {
    uint32_t bits;
    memcpy(&bits, &f, sizeof(bits));

    uint32_t sinal = (bits >> 31) & 1;
    uint32_t expoente = (bits >> 23) & 0xFF;
    uint32_t fracao = bits & 0x7FFFFF;

    printf("Float: %f\n", f);
    printf("Bits: ");
    for (int i = 32 - 1; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\nSinal: %u\n", sinal);
    printf("Expoente com vies: %u\n", expoente);
    printf("Fracao: ");
    for (int i = 23 - 1; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
}

void doubleToBinary(double d) {
    uint64_t bits;
    memcpy(&bits, &d, sizeof(bits));

    uint64_t sinal = (bits >> 63) & 1;
    uint64_t expoente = (bits >> 52) & 0x7FF;
    uint64_t fracao = bits & 0xFFFFFFFFFFFFF;

    printf("\nDouble: %lf\n", d);
    printf("Bits: ");
    for (int i = 64 - 1; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
    }
    printf("\nSinal: %llu\n", sinal);
    printf("Expoente com vies: %llu\n", expoente);
    printf("Fracao: ");
    for (int i = 52 - 1; i >= 0; i--) {
        printf("%d", (fracao >> i) & 1);
    }
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

    toBCD(num);
    printf("\n");

    toComplement2(num * -1);
    printf("\n");

    float realNum;
    printf("Insira um numero real: ");
    scanf("%f", &realNum);

    floatToBinary(realNum);
    printf("\n");

    doubleToBinary((double) realNum);
    printf("\n");

    return 0;
}
