#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.000001

double** alocaMatriz(int limite);
void imprimeMatriz (double** matriz, int limite);
void leMatriz(double** matriz, int limite, FILE* file);
char metodoJordan(double** matriz, int limite, double x[]);
char determina(double **matriz, int limite); 

int main(){
    char fileName[100], i, result;
    int limite;
    FILE *file;
    double **matrizA, *x;

    printf("Escreva o nome do arquivo:");
    gets(fileName);

    file = fopen(fileName, "r");
    if(file == NULL){
        printf("O arquivo nao existe");
        return 0;
    }

    fscanf(file, "%d", &limite);
    x = malloc (sizeof(double) * limite);
    matrizA = alocaMatriz(limite);
    leMatriz(matrizA, limite, file);
    fclose(file);
    imprimeMatriz(matrizA, limite);
    result = metodoJordan(matrizA, limite, x);
    if (result == 0)
		printf("SL INCOMPATIVEL \n");
	else {
		printf ("SL %sDETERMINADO\n", result ? "IN":"");
		for (i = 0; i < limite; i++)
		    printf("x[%d]=%10.3lf ",i+1, x[i]);
	}
	return 0;
}

char determina(double **matriz, int limite) { 
    int i, j; 
    double sum; 
    char result = 0;
    
    for (i = 0; i < limite; i++)  
    { 
        sum = 0; 
        for (j = 0; j < limite; j++)   
            sum = sum + matriz[i][j]; 
        if (sum == matriz[i][j])  
            result = 1;     
    } 
    return result; 
} 

char metodoJordan(double **matriz, int limite, double x[]){
    char i, j, k, result, troca;
    double mult, item;

    for(j = 0; j < limite; j++){
        if(matriz[j][j] == 0){
            troca = 1;
            while(matriz[j][j + troca] == 0 && (j + troca) < limite)
                troca++;
            if ((j + troca) == limite)  
            { 
                if(determina(matriz, limite) == 0){
                    return 0;
                }
                for(i = 0; i < limite; i++)
                    matriz[i][j] = 0;
                imprimeMatriz(matriz, limite);
            } 
        }
        else{
            for(i = j, k = 0; k < limite; k++){
                item = matriz[j][k];
                matriz[j][k] = matriz[j][k + troca];
                matriz[j][k + troca] = item;
            }
        }
        for ( i = 0; i < limite; i++){
            if(i != j){
                if(matriz[j][j] == 0)
                    mult = 0;
                else
                    mult = -(matriz[i][j] / matriz[j][j]);
                for(k = 0; k <= limite; k++)
                    matriz[i][k] = matriz[i][k] + (mult * matriz[j][k]);
            }
        }
    }
    imprimeMatriz(matriz, limite);
    for(i = 0; i < limite; i++){
        if(matriz[i][i] == 0)
            x[i] = 0;
        else
            x[i] =  matriz[i][limite] / matriz[i][i];
    }
    return 1;
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
