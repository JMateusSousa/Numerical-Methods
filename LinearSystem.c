#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double** alocaMatriz(int limite);
void imprimeMatriz (double** matriz, int limite);
void leMatriz(double** matriz, int limite, FILE* file);
void metodoJordan(double** matriz, int limite);

int main(){
    char fileName[50], i, j;
    int limite;
    FILE *file;
    double **matrizA;

    printf("Escreva o nome do arquivo:");
    gets(fileName);

    file = fopen(fileName, "r");
    if(file == NULL){
        printf("O arquivo está vazio!");
        return 0;
    }

    fscanf(file, "%d", &limite);
    matrizA = alocaMatriz(limite);
    leMatriz(matrizA, limite, file);
    fclose(file);
    imprimeMatriz(matrizA, limite);
    metodoJordan(matrizA, limite);
    return 0;
}

void metodoJordan(double** matriz, int limite){
    char i, j, k;
    double mult;
    for(j = 0; j < limite; j++){
        for ( i = 0; i < limite; i++){
            if(i != j){
                mult = -(matriz[i][j] / matriz[j][j]);
                for(k = 0; k <= limite; k++)
                    matriz[i][k] = matriz[i][k] + (mult * matriz[j][k]);
            }
        }
    }
    imprimeMatriz(matriz, limite);
    for(i = 0; i <= limite; i++){
        printf("x%d = %.6lf\n", i+1, matriz[i][limite] / matriz[i][i]);
    }
}

void imprimeMatriz(double** matriz, int limite){
    char i, j;
    for (i = 0; i < limite; i++){
		for (j = 0; j < limite; j++)
			printf("%lf ", matriz[i][j]);
		printf("\n");
	}
    printf("\n");
}

void leMatriz(double**matriz, int limite, FILE* file){
	int i,j;
    double caracter;
	for (i = 0; i < limite; i++){
		for (j = 0; j < (limite + 1); j++){
            fscanf(file, "%lf", &caracter);
            if((char)caracter == ' ')
                j--;
            else{
                //printf("m[%d][%d]: ", i+1, j+1);
                matriz[i][j] = caracter;
                //printf("%lf\n", caracter);
            }
		}
	}
	
}

double** alocaMatriz(int limite){
   double** matriz;
   char i, j;
   matriz = malloc(sizeof(matriz) * limite);
   if (matriz != NULL){
   	    for (i=0; i < limite; i++){
   		    matriz[i] = malloc(sizeof(double) * (limite + 1));
   		    if (matriz[i] == NULL){
   		    for(j = 0; j < i; j++)
		        free(matriz[j]);
		    free(matriz);
		    return NULL;
		   
			}
		}
	}
	return matriz;
}
