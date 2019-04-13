#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** alocaMatriz(int limite);
void imprimeMatriz (double** matriz, int limite);
void leMatriz(double** matriz, int limite, FILE* file);
char metodoJordan(double** matriz, int limite);
char determina(double **matriz, int limite);        // DETERMINA SE É INCOMPATÍVEL OU COMPATÍVEL INDETERMINADO
void mostraSolucao(double **matriz, int limite);


int main(){
    char fileName[100], i, result = 2;
    int limite;
    FILE *file;
    double **matrizA;

    printf("Escreva o nome do arquivo:");
    gets(fileName);

    file = fopen(fileName, "r");
    if(file == NULL){
        printf("O arquivo nao existe");
        return 0;
    }

    fscanf(file, "%d", &limite);                    //     LENDO A DIMENSÃO DA MATRIZ (LIMITE X LIMITE)
    matrizA = alocaMatriz(limite);
    leMatriz(matrizA, limite, file);
    fclose(file);
    printf("===== Matriz de Entrada =====\n");
    imprimeMatriz(matrizA, limite);
    result = metodoJordan(matrizA, limite);         //      RETORNO DO TIPO DO SISTEMA ADQUIRIDO
    if (result == 0)
		printf("SL INCOMPATIVEL \n");
    else if(result == 1){
        printf("SL COMPATIVEL INDETERMINADO --> ");
        printf("Uma possivel solucao para esse sistema: ");
        mostraSolucao(matrizA, limite);
        printf("\n\n\n");
        }
	else{
		printf ("SL COMPATIVEL DETERMINADO\n");
		mostraSolucao(matrizA, limite);
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

void mostraSolucao(double **matriz, int limite){
    char i;
    for(i = 0; i < limite; i++){
        if(matriz[i][i] == 0)
           printf("x[%d] = %lf ", i+1, matriz[i][i]);
        else
            printf("x[%d] = %lf ", i+1, (matriz[i][limite] / matriz[i][i]));
    }
}

char metodoJordan(double **matriz, int limite){
    char i, j, k, result = 2, troca, flag = 0;
    double mult, item;

    for(j = 0; j < limite; j++){
        if(matriz[j][j] == 0){
            troca = 1;
            while(matriz[j][j + troca] == 0 && (j + troca) < limite)
                troca++;
            if ((j + troca) == limite)  
            { 
                for(i = 0; i< limite; i++)
                    matriz[i][j] = 0;
                    flag = 1;
            }
            else{
                for(i = j, k = 0; k < limite; k++){
                    item = matriz[j][k];
                    matriz[i][k] = matriz[i][k + troca];
                    matriz[i][k + troca] = item;
                }
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
    printf("===== Matriz Diagonal =====\n");
    imprimeMatriz(matriz, limite);
    if(flag == 1)
        result = determina(matriz, limite);
    return result;
}

void imprimeMatriz(double** matriz, int limite){
    char i, j;
    for (i = 0; i < limite; i++){
		for (j = 0; j < limite; j++)
			printf("%lf\t", matriz[i][j]);
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
            else
                matriz[i][j] = caracter;
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
