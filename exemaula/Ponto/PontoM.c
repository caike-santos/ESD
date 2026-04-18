#include "PontoM.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* ImplementaC'C#o TAD: Ponto (x,y) */
/*definiC'C#o do tipo exportado*/
struct ponto {
	double x;
	double y;
};

/*definiC'C#o das funC'C5es exportadas*/
/* FunC'C#o cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* pto_cria(float x, float y) {
	Ponto* p = (Ponto*) malloc(sizeof(Ponto));
	if (p == NULL) {
		printf("MemC3ria insuficiente!\n");
	}
	else {
		p->x = x;
		p->y = y;
	}
	return p;
}

/* FunC'C#o libera - Libera a memC3ria de um ponto previamente criado */
void pto_libera(Ponto* p) {
	free(p);
}

/* FunC'C#o acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto* p, float* x, float* y) {
	*x=p->x;
	*y=p->y;
}

void pto_acessax(Ponto* p, float* x) {
	*x=p->x;
}

void pto_acessay(Ponto* p, float* y) {
	*y=p->y;
}

/* FunC'C#o atribui - Atribui novos valores C s coordenadas de um ponto */
void pto_atribui(Ponto* p, float x, float y) {
	p->x=x;
	p->y=y;
}

void pto_atribuix(Ponto* p, float x) {
	p->x=x;
}

void pto_atribuiy(Ponto* p, float y) {
	p->y=y;
}

/* FunC'C#o distancia - Retorna a distC"ncia entre dois pontos */
float pto_distancia(Ponto* p1, Ponto* p2) {
	float dx = p2->x - p1->x;
	float dy = p2->y - p1->y;
	return sqrt(dx*dx + dy*dy);


}

/* FunC'C#o getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char* pto_getPonto(Ponto* p1) {
	char* pt;
	int tam = sizeof(*p1)+ 8;
	pt = (char*)malloc(tam);
	sprintf(pt,"( %.2f , %.2f )", p1->x, p1->y);
	return pt;

}

/* FunC'C#o exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto* p) {
	printf(" (%.2f,%.2f) ",p->x,p->y);
}

/* funC'C#o compara -1:se o pt1 < pt2, 0 se pt1 == pt2, +1 se o pt1 > pt2  */
/* um ponto C) menor do que o outro se estiver mais prC3ximo da origem*/
int pto_compara(Ponto*p1,Ponto*p2) {
	if (p1->x ==p2->x  && p1->y ==p2->y)
		return 0;
	Ponto* origem=pto_cria(0,0);
	float dist1=pto_distancia(p1,origem);
	float dist2=pto_distancia(p2,origem);
	pto_libera(origem);
	if (dist1 == dist2)
		if (p1->x < p2->x ||p1->y < p2->y )
			return -1;
		else
			return 1;
	else if (dist1 < dist2)
		return -1;
	else
		return 1;

}

int pto_quadrante(Ponto*p) {
	if(p->x > 0 && p->y > 0) {
		return 1;
	} else if(p->x < 0 && p->y > 0) {
		return 2;
	} else if(p->x > 0 && p->y < 0) {
		return 3;
	} else {
		return 4;
	}
}

Ponto* pto_copia(Ponto*p){
    if (p == NULL) return NULL;
    return pto_cria(p->x, p->y);
}


