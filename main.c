#include <stdio.h>

void converteBin(double decimal) {    //Converte o número decimal para binário.
    int inteiro, i = 0;
    int aux[20];
    double fracionario;

    inteiro = (int) decimal;    //Pega a somente a parte inteira do decimal.
    fracionario = decimal - inteiro;

    if(inteiro > 0){    //verifica se a parte inteira é maior que 0.
        while (inteiro != 0 && i <= 20) {
            aux[i] = inteiro % 2;
            inteiro /= 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            printf("%d", aux[j]);   //Imprime a parte inteira do número binário.
        }
    }
    else printf("0");

    i = 0;

    if (fracionario > 0.0) {    //Verifica se existe parte fracionária.
        printf(".");

        while (fracionario != 0.0 && i <= 20) {
            fracionario *= 2;

            if (fracionario >=
                1) {   //Caso o resultado da multiplicação seja maior que 1 imprime-se 1, caso contrário 0.
                printf("%d", 1);
                fracionario -= 1;   //Retirando a parte inteira.

            } else printf("%d", 0);
        }
    }
}

void converteOct(double decimal) {    //Converte o número decimal para Octal.
    int inteiro, i = 0;
    int aux[20];
    double fracionario;

    inteiro = (int) decimal;    //Pega a somente a parte inteira do decimal.
    fracionario = decimal - inteiro;

    if(inteiro > 0){    //verifica se a parte inteira é maior que 0.
        while (inteiro != 0 && i <= 20) {
            aux[i] = inteiro % 8;
            inteiro /= 8;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            printf("%d", aux[j]);   //Imprime a parte inteira do número binário.
        }
    }
    else printf("0");

    i = 0;

    if (fracionario > 0.0) {    //Verifica se existe parte fracionária.
        printf(".");

        while (fracionario != 0.0 && i <= 20) {
            fracionario *= 8;

            if (fracionario > 1) {   //Caso o resultado da multiplicação seja maior que 8 imprime-se a parte inteira, caso contrário 0.
                printf("%d", (int) fracionario);
                fracionario -= (int) fracionario;   //Retirando a parte inteira.

            } else printf("%d", 0);
        }
    }
}

int main() {
    double decimal;

    printf("Digite o numero decimal: ");
    scanf("%lf", &decimal);

    converteOct(decimal);
    return 0;
}
