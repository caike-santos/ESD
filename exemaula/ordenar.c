#include <stdio.h>
#include <stdlib.h>

struct entrevistados{
	char nome[30];
	int idade;
	int notas[5];
};
typedef struct entrevistados entre;

void preenche(entre pessoas[], int tam, entre *vnomes[], entre *vidades[], int *quant){
	int i, j;
	
	for(i=0;i<tam;i++){
		printf("Digite seu nome: \n");
		scanf("%s", pessoas[i].nome);
		
		printf("Digite sua idade: \n");
		scanf("%d", &pessoas[i].idade);
		
		for(j = 0; j<5; j++){
			printf("Digite sua nota: \n");
			scanf("%d", &pessoas[i].notas[j]);
		}
		
		vnomes[i] = &pessoas[i];
		vidades[i] = &pessoas[i];
		(*quant)++;
	}
}

void exibir(int *tam, entre pessoas[]){
		int i, j;
	
	for(i=0;i<(*tam);i++){
		printf("\nnome: %s \n", pessoas[i].nome);
		
		
		printf("idade: %d\n", pessoas[i].idade);
	
		printf("nota: \n");
		for(j = 0; j<5; j++){
			printf("%d, ", pessoas[i].notas[j]);
		}
		
	}
}

void exibirNomes(int *tam, entre *vnomes[]){
	int i;
	for(i=0;i<*tam;i++){
		printf("\nnome: %s \n", vnomes[i]->nome);
	}
}

void exibirIdades(int *tam, entre *vidades[]){
	int i;
	for(i=0;i<*tam;i++){
		printf("idade: %d\n", vidades[i]->idade);
	}
}


void ordernarNomes(entre *vnomes[], int *n){
    int i, j, min_idx;
    entre *temp;
    // Move o limite da sublista ordenada
    for (i = 0; i < (*n)-1; i++) {
        // Encontra o menor elemento na sublista não ordenada
        min_idx = i;
        for (j = i+1; j < (*n); j++) {
            if (strcmp(vnomes[j]->nome, vnomes[min_idx]->nome) < 0) {
                min_idx = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento
        temp = vnomes[min_idx];
        vnomes[min_idx] = vnomes[i];
        vnomes[i] = temp;
    }
        
}


void ordernarIdades(entre *vidades[], int *n){
	int i, j, min_idx;
	entre *temp;
	for (i = 0; i < (*n)-1; i++) {
        // Encontra o menor elemento na sublista não ordenada
        min_idx = i;
        for (j = i+1; j < (*n); j++) {
            if (vidades[j]->idade < vidades[min_idx]->idade) {
                min_idx = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento
        temp = vidades[min_idx];
        vidades[min_idx] = vidades[i];
        vidades[i] = temp;
    }
}

void adicionar(entre pessoas[], entre *vnomes[], entre *vidades[], int *quant){
	int j;
	
		printf("Digite seu nome: \n");
		scanf("%s", pessoas[*quant].nome);
		
		printf("Digite sua idade: \n");
		scanf("%d", &pessoas[*quant].idade);
		
		for(j = 0; j<5; j++){
			printf("Digite sua nota: \n");
			scanf("%d", &pessoas[*quant].notas[j]);
		}
		
		vnomes[*quant] = &pessoas[*quant];
		vidades[*quant] = &pessoas[*quant];
		
		(*quant)++;
	}
		
		


int main(void){
	int quant = 0;
	entre pessoas[10];
	entre *vnomes[10];
	entre *vidades[10];
	
	preenche(pessoas, 2, vnomes, vidades, &quant);
	printf("%d", quant);
	exibir(&quant, pessoas);
	printf("\n\n");
	ordernarNomes(vnomes, &quant);
	ordernarIdades(vidades, &quant);
	exibirNomes(&quant, vnomes);
	exibirIdades(&quant, vidades);
	adicionar(pessoas, vnomes, vidades, &quant);
	exibir(&quant, pessoas);
	ordernarNomes(vnomes, &quant);
	ordernarIdades(vidades, &quant);
	exibirNomes(&quant, vnomes);
	exibirIdades(&quant, vidades);
	
}