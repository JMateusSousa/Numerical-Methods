#include <stdio.h>

void converteBin(double decimal) {    //Converte o número decimal para binário.
    int inteiro, i = 0, j;
    int aux[20];
    double fracionario;

    inteiro = (int) decimal;    //Pega a somente a parte inteira do decimal.
    fracionario = decimal - inteiro;

    if(inteiro == 0) printf("0");	//Caso a parte inteira seja 0.

    while (inteiro != 0 && i <= 20) {
        aux[i] = inteiro % 2;
        inteiro /= 2;
        i++;
    }

    for (j = i - 1; j >= 0; j--) {
        printf("%d", aux[j]);   //Imprime a parte inteira do número binário.
    }

    i = 0;
    if(fracionario != 0.0) printf(".");

    while (fracionario != 0.0 && i <= 20) {
        fracionario *= 2;

        if (fracionario >= 1) {   //Caso o resultado da multiplicação seja maior que 1 imprime-se 1, caso contrário 0.
            printf("%d", 1);
            fracionario -= 1;   //Retirando a parte inteira.

        } else printf("%d", 0);
    }

    printf("\n");

}

void converteOct(double decimal) {    //Converte o número decimal para Octal.
    int inteiro, i = 0, j;
    int aux[20];
    double fracionario;

    inteiro = (int) decimal;    //Pega a somente a parte inteira do decimal.
    fracionario = decimal - inteiro;

    if(inteiro == 0) printf("0");	//Caso a parte inteira seja 0.

    while (inteiro != 0 && i <= 20) {
        aux[i] = inteiro % 8;
        inteiro /= 8;
        i++;
    }

    for (j = i - 1; j >= 0; j--) {
        printf("%d", aux[j]);   //Imprime a parte inteira do número binário.
    }

    i = 0;
    if(fracionario != 0.0) printf(".");

    while (fracionario != 0.0 && i <= 20) {
        fracionario *= 8;

        if (fracionario > 1) {   //Caso o resultado da multiplicação seja maior que 1 imprime-se a parte inteira, caso contrário 0.
            printf("%d", (int) fracionario);
            fracionario -= (int) fracionario;   //Retirando a parte inteira.

        } else printf("%d", 0);
    }
    printf("\n");
}

void converteHex(double decimal) {    //Converte o número decimal para Hexadecimal.
    int inteiro, i = 0, j;
    int aux[20];
    double fracionario;

    inteiro = (int) decimal;    //Pega a somente a parte inteira do decimal.
    fracionario = decimal - inteiro;

    if(inteiro == 0) printf("0");	//Caso a parte inteira seja 0.

    while (inteiro != 0 && i <= 20) {
        aux[i] = inteiro % 16;
        inteiro /= 16;
        i++;

    }

    for (j = i - 1; j >= 0; j--) {
        if(aux[j] >= 10){
            printf("%c", aux[j] + 55);	//Printando o caractere respectivo ao numero hexadecimal.
        }
        else printf("%d", aux[j]);
    }

    i = 0;
    if(fracionario != 0.0) printf(".");

    while (fracionario != 0.0 && i <= 20) {
        fracionario *= 16;

        if (fracionario > 1) {   //Caso o resultado da multiplicação seja maior que 1 imprime-se a parte inteira, caso contrário 0.
            if(fracionario >= 10){
                printf("%c", (int)fracionario + 55);
            }
            else printf("%d", (int)fracionario);

            fracionario -= (int) fracionario;   //Retirando a parte inteira.

        } else printf("%d", 0);
    }
    printf("\n");
}

void conversao(){
    double decimal;

    printf("Digite o numero decimal: ");
    scanf("%lf", &decimal);

    printf("Binario: ");
    converteBin(decimal);
    printf("Octal: ");
    converteOct(decimal);
    printf("Hexadecimal: ");
    converteHex(decimal);
}

int main() {
    char opcao;

    printf("Digite C para realizar a conversao: ");
    scanf("%c", &opcao);

    switch(opcao){
        case 'C':
            conversao();
            break;
    }

    return 0;
}

