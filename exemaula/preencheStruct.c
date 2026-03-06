#include <stdio.h>
#include <stdlib.h>


struct opiniao{
    char nome[10];
    int idade;
    int vPref[4];
};
typedef struct opiniao opinioes;

void preenche(opinioes *pessoa){
    printf("Digite seu nome:");
    scanf("%s", pessoa->nome);

    printf("Digite sua idade:");
    scanf("%d", &pessoa->idade);

    for(int i = 0; i<4; i++){
        printf("Digite as notas");
        scanf("%d", &pessoa->vPref[i]);
    }
}

void exibir(opinioes p[]){
    for(int i = 0; i<3; i++){
        printf("nome: %s\n", p[i].nome);
        printf("idade: %d\n", p[i].idade);
        printf("\n");
        printf("Notas: ");
        for(int j = 0; j<4; j++){
            printf("%d, ", p[i].vPref[j]);
        }
    }
    
}

int main(void){
    int i = 0, flag = 0;
    opinioes *pessoas;
    pessoas = (opinioes*) malloc(sizeof(opinioes) * 3);
    while(flag!=3){
        preenche(&pessoas[i]);
        flag++;
        i++;
    }
    
    exibir(pessoas);
     free(pessoas);   
}

