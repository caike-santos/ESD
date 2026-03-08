#include <stdio.h>
#include <stdlib.h>

struct entrevistados{
	char nome[30];
	int idade;
};
typedef struct entrevistados entre;

void preenche(entre *v, entre **vnome, entre **vidade, int *quant, int tam){
	int i;
	for(i=0; i<tam; i++){
		printf("Digite seu nome: \n");
		scanf("%s", v[i].nome);
		
		printf("Digite sua idade: \n");
		scanf("%d", &v[i].idade);
		
		vnome[i] = &v[i];
		vidade[i] = &v[i];
		(*quant)++;
	}
}

void exibir(entre *v, entre **vnome, entre **vidade, int *tam){
	int i;
	
	for(i=0;i<(*tam);i++){
		printf("\nnome: %s \n", vnome[i]->nome);
			
		printf("idade: %d\n", vnome[i]->idade);
		
	}
}



int main(void){
	entre *v;
	entre **vnome;
	entre **vidade;
	int quant = 0;
	
	v = malloc(sizeof(entre) * 10);
	vnome = malloc(sizeof(entre*) * 10);
	vidade = malloc(sizeof(entre*) * 10);
	
	preenche(v, vnome, vidade, &quant, 2);
	
	exibir(v, vnome, vidade, &quant);
	
}