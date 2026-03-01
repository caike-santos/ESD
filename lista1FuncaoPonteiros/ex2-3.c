#include <stdio.h>
//2a
int divisaoInteira(int divis, int divid, int *q, int *r){
	if(divis == 0 && divid == 0){
		return -1;
	}else if(divid == 0){
		return 0;
	}else{
		*q = divis/divid;
		*r = divis%divid;
		return 1; 
	}
}
//3a
void horario(int m, int *h, int *min){
	divisaoInteira(m, 60, h, min);
}

//3b
void treino(){
	int i=1, m, h, min, tempoMax=0, alunTempoMax=1;
	while(i!=11){
		printf("Digite os minutos de treino: ");
		scanf("%d", &m);
		horario(m, &h, &min);
		printf("Aluno %d: %d:%d\n", i, h, min);
		if(m>tempoMax){
			tempoMax=m;
		}else if(m == tempoMax){
			alunTempoMax++;
		}
		i++;
	}
	printf("%d aluno(s) fizeram o maior tempo de treino de %d minutos\n", alunTempoMax, tempoMax);
}

int main (void)
{
//2b	
/*int a, b, q, r, st;
printf("Digite dois valores: ");
   scanf ("%d%d",&a,&b);
   if (divisaoInteira (a, b, &q, &r)==1){
 		printf ("%d /%d = %d com resto %d\n", a,b,q,r);
   }
else {
 		printf ("Erro- divisor eh  0 \n");
   }*/
   
   
   /*int h, min;
   horario(145, &h, &min);
   printf("%d horas e %d minutos\n", h, min);
return 0;*/

treino();

}
	