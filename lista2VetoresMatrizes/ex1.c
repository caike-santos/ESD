


#include <stdio.h>
#include <stdlib.h>

1:void lerVal(int *v){
    int flag = 0, i=0, val;
    while(flag!=10){
        printf("Digite um numero: ");
        scanf("%d", &val);
        v[flag] = val;
        flag++;
    }
    
}

2:void lerVal(int *v1, int *v2){
    int flag = 0, i=0, val, vmulti = 0;
    while(flag!=4){
        printf("Digite um numero: ");
        scanf("%d", &val);
        v1[flag] = val;
        flag++;
    }
    flag = 0;
    while(flag!=4){
        printf("Digite um numero: ");
        scanf("%d", &val);
        v2[flag] = val;
        flag++;
    }
    
    for(i=0; i<4;i++){
        vmulti += v2[i] * v1[i];
        if(i==3){
            printf("%d*%d ", v1[i], v2[i]);
        }else{
            printf("%d*%d +", v1[i], v2[i]);
        }
    }
    printf("= %d\n", vmulti);
}

3:void exibirInv(int *v, int tam){
    int i;
    
    for(i=tam-1; i>=0;i--){
        if(i==0){
            printf(" %d", v[i]);
        }else{
            printf("%d, ", v[i]);
        }
        
    }
}

4:void exibirParImp(int *v, int tam){
    int i;
    printf("Pares: ");
    for(i=0; i<tam;i++){
        if(i%2 == 0){
            printf("%d, ",v[i]);
        }
    }
    printf("Impares: ");
    for(i=0; i<tam;i++){
        if(i%2 != 0){
            printf("%d, ",v[i]);
        }
    }

5:void exibirPedido(int *v, int tam){
    bool flag = false;
    int pos;
    
    while(!flag){
        printf("Digite a posiçao(de 0 a %d): ", tam-1);
        scanf("%d", &pos);
        if(pos<0 || pos>=tam){
            printf("Posiçao invalida\n");
        }else{
            flag = true;
            printf("Numero escolhido: %d\n", v[pos]);
        }
        
    }
}

6:void exibirMaiorValor(int *v, int tam){
    int i, maior = -999999;
    for(i = 0; i<tam; i++){
        if(v[i]>maior){
            maior=v[i];
        }
    }
    printf("Maior valor do vetor: %d", maior);
}

7:void exibirSoma(int *v, int tam){
    int i, soma=0;
    for(i=0;i<tam;i++){
        soma += v[i];
    }
    printf("Soma dos valores: %d", soma);
}

8:int quantImpares(int *v, int tam){
    int i, quant = 0;
    for(i=0;i<tam;i++){
        if(v[i]%2 != 0){
            quant++;
        }
    }
    return quant;
}

9:void exibirMenores(int *v, int tam){
    int i;
    printf("Numeros menores que %d: ", v[tam-1]);
    for(i=0; i<tam-1; i++){
        if(v[i]<v[tam-1]){
        printf("%d, ", v[i]);
}
    }
}

10: void exibirMedia(int *v, int tam){
    int i, soma = 0;
    float media;
    for(i=0;i<tam;i++){
        soma += v[i];
    }
    media = (float) soma/tam;
    printf("Media = %.2f", media);
}

11:void exibirQuantMenoresMedia(int *v, int tam){
    int i, soma = 0, quant = 0;
    float media;
    for(i=0;i<tam;i++){
        soma += v[i];
    }
    media = (float) soma/tam;
    
    printf("Quantidades de numeros menores que a media %.2f: ", media);
    for(i=0; i<tam; i++){
        if(v[i] < media){
           quant++;
        }
    }
     printf("%d", quant);
}

12:void exibirMaioresMedia(int *v, int tam){
    int i, soma = 0, quant = 0;
    float media;
    for(i=0;i<tam;i++){
        soma += v[i];
    }
    media = (float) soma/tam;
    
    printf("Numeros menores que a media %.2f: ", media);
    for(i=0; i<tam; i++){
        if(v[i] > media){
           printf("%d, ", v[i]);
        }
    }
     
}

13:int busca(int *v, int tam){
	int alvo, i, pos = -1;
	printf("Digite o numero alvo: ");
	scanf("%d", &alvo);
	
	for(i=0; i<tam;i++){
		if(v[i] == alvo){
			pos = i;
		}
	}
	
	return pos;
}

int main() {
   int *v, i;
   v = (int*) malloc(10*sizeof(int));
   lerVal(v);
   
   for(i=0; i<10; i++){
       printf("%d, ", v[i]);
       
   }
free(v);
    return 0;
}


