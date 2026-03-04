#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencheVetorLinha(int **m, int *v, int lin, int col){
	int i, j, soma;
	

	
	for(i=0; i<lin; i++){
		soma = 0;
		for(j=0; j<col; j++){
			soma += m[i][j];
		}
		v[i] = soma;
	}
}

void preencheVetorColuna(int **m, int *v, int lin, int col){
	int i, j, soma;
	

	
	for(i=0; i<col; i++){
		soma = 0;
		for(j=0; j<lin; j++){
			soma += m[j][i];
		}
		v[i] = soma;
	}
}

void exibePrincipal(int **m, int lin, int col){
	int i, j;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if(i == j){
				printf("%d ", m[i][j]);
			}
		}
	
	}
}

void exibeSecundaria(int **m, int lin, int col){
	int i, j, pl = 0, pc = col-1;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if(i==pl && j==pc){
				printf("%d ", m[i][j]);
			}
		}
		pl++;
		pc--;
	
	}
}

void exibeSemPrincipal(int **m, int lin, int col){
	int i, j;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if(i != j){
				printf("%d ", m[i][j]);
			}
		}
		printf("\n");
	
	}
}

void multInteiro(int **m, int lin, int col, int num){
	int i, j;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			m[i][j] *= num;
		}
	
	
	}
}

void somaMatrizes(int **m1, int **m2, int lin, int col){
	int i, j, soma;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			soma = m1[i][j] + m2[i][j];
			printf("%d ", soma);
		}
		printf("\n");
	
	}
	
	
}

void zeraMult(int **m, int lin, int col){
	int i, j;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if(i == 0 && j == 0){
				continue;
			}else if(i == 0 && j != 0){
				if(m[i][j]%j == 0){
					m[i][j] = 0;
				}
			}else if(i != 0 && j == 0){
				if(m[i][j]%i == 0){
					m[i][j] = 0;
				}
			}else{
				if((m[i][j]%i == 0) || (m[i][j]%j == 0)){
				
				m[i][j] = 0;
			}	
			}
			
			
		}
		
	
	}
}

int matrizEhSimetrica(int **m, int lin, int col){
	int i, j, k=0, l=0, quantv, *v1, *v2;
	quantv = ((lin*col) - lin)/2;
	
	v1 = malloc (sizeof(int) * quantv);
	
	v2 = malloc (sizeof(int) * quantv);
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if(i!=j){
				if(i<j){
					v1[k] = m[i][j];
					k++;
				}else{
					v2[l] = m[i][j];
					l++;
				}
			}
		}
	}
	
	/*for(i=0; i<quantv; i++){
		printf("%d ", v1[i]);
	}
	printf("\n");
	for(i=0; i<quantv; i++){
		printf("%d ", v2[i]);
	}
	printf("\n");*/
	
	for(i=0; i<quantv; i++){
		if(v1[i] != v2[i]){
			free(v1);
			free(v2);
			return 0;
		}
	}
	free(v1);
	free(v2);
	return 1;
}

int transposta(int **m, int lin, int col){
	int **mt, i, j;
	
	mt = malloc(sizeof(int*) * lin);
	
	for(i=0; i<lin; i++){
		mt[i] = malloc(sizeof(int)*col);
	}
	
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			mt[j][i] = m[i][j];
		}
	}
	
		for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%d ", mt[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<lin; i++){
		free(mt[i]);
	}
	free(mt);
}


int main(void){
	srand(time(NULL));
	int **m, **m1, **m2, i, j, lin =3, col = 3, *v;
	
	v = malloc(sizeof(int) * lin);
	
	m = malloc(sizeof (int*) * lin);
	
	m1 = malloc(sizeof (int*) * lin);
	
	m2 = malloc(sizeof (int*) * lin);
	
	for(i=0; i<lin; i++){
		m[i] =  malloc(sizeof(int) * col);
	}
	
	/*for(i=0; i<lin; i++){
		m1[i] =  malloc(sizeof(int) * col);
	}
	
	for(i=0; i<lin; i++){
		m2[i] =  malloc(sizeof(int) * col);
	}*/
	
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			m[i][j] = rand()%100;
		}
	}
	
	//simetrica
	/*int n = 0;
	
	for(i=0; i<lin;i++){
		for(j=n; j<col;j++){
			if(i==j){
				m[i][j] = 0;
			}else{
				m[i][j]= rand()%100;
				m[j][i] = m[i][j];
			}
			
		}
		n++;
	}*/
	
	/*for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			m1[i][j] = rand()%100;
		}
	}
	
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			m2[i][j] = rand()%100;
		}
	}*/
	
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	
	/*for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\n");
	
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}*/
	
	printf("\n\n");
	
	/*preencheVetorLinha(m, v, lin, col);
	printf("\n");
	for(i=0; i<lin; i++){
		printf("%d, ", v[i]);
	}*/
	
	/*preencheVetorColuna(m, v, lin, col);
	printf("\n");
	for(i=0; i<col; i++){
		printf("%d, ", v[i]);
	}*/
	
	//exibePrincipal(m, lin, col);
	
	//exibeSecundaria(m, lin, col);
	
	//exibeSemPrincipal(m, lin, col);
	
	/*multInteiro(m, lin, col, 4);
	printf("\n");
		for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}*/
	
	//somaMatrizes(m1, m2, lin, col);
	
	/*zeraMult(m, lin, col);
	for(i=0;i<lin;i++){
		for(j=0;j<col;j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}*/
	
	
	/*if(matrizEhSimetrica(m, lin, col)){
		printf("Eh\n");
	}else{
		printf("Nao eh\n");
	}*/
	
	transposta(m, lin, col);
	
	for(i=0; i<lin; i++){
		free(m[i]);
	}
	free(m);
	
	/*for(i=0; i<lin; i++){
		free(m1[i]);
	}
	free(m1);
	
	for(i=0; i<lin; i++){
		free(m2[i]);
	}
	free(m2);*/
	
	
}

