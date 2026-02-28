#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencheAl(int ***mat, int lin, int col){
    int i , j, n=0 ;
    
    *mat = malloc(lin * sizeof(int*));
    
    for(i = 0; i<lin; i++){
    	(*mat)[i] = malloc(col * sizeof(int));
	}
	
	for(i=0; i<lin;i++){
		for(j=n; j<col;j++){
			if(i==j){
				(*mat)[i][j] = 0;
			}else{
				(*mat)[i][j]= rand()%100;
				(*mat)[j][i] = (*mat)[i][j];
			}
			
		}
		n++;
	}
       
}

void exibirMatriz(int **mat, int lin, int col){
    int i, j;
    
    printf("      "); 
    for(j = 0; j < col; j++){
        printf("%6d", j + 1); 
    }
    printf("\n");
    
    for(i = 0; i < lin; i++){ 
        
        printf("%6d", i + 1); 
        
        for(j = 0; j < col; j++){
            printf("%6d", mat[i][j]); 
        }
        printf("\n");
    }
}


void preencherVetor(int **vetor, int tam){
	int i=0, c;
	*vetor = malloc(tam * sizeof(int));
	
	while(i<tam){
		
		printf("Escolha a cidade(entre 1 a 6): ");
		scanf("%d", &c);
		if(c<1 || c>6){
			printf("Erro!! numero invalido tente novamente \n");
		}else{
			(*vetor)[i] = c;
			i++;
		}
		
		
	}
}

void exibirVetor(int *vetor, int tam){
	int i;
	for(i =0; i<tam; i++){
		printf("%d, ", vetor[i]);
	}
	printf("\n\n");
}

int calcularDistancia(int **m, int l, int c, int *v){
	int i, total = 0;
	for(i=0;i<l-1;i++){
		total += m[v[i] - 1][v[i+1]-1] ;
		if(i== l-2){
			printf("%d\n\n", m[v[i] - 1][v[i+1]-1]);
		}else{
			printf("%d + ", m[v[i] - 1][v[i+1]-1]);
		}
		
	}
	
	return total;
}
int main(void){
    srand(time(NULL));
    int **matriz = NULL;
    int lin = 6;
    int col = 6;
    int i, j;
    int *vetor = NULL;
    
    
    
    preencheAl(&matriz, lin, col);
    exibirMatriz(matriz, lin, col);
    
    preencherVetor(&vetor, lin);
    exibirVetor(vetor, lin);
    
    printf("\n\nDistancia total: %d\n",calcularDistancia(matriz, lin, col, vetor));
    
    for(i=0; i<lin;i++){
    		 free(matriz[i]);
		}
		free(matriz);
		free(vetor);
		return 0;
	}
