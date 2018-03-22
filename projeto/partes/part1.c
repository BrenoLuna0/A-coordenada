#include<stdio.h>
#include<stdlib.h>

struct Lista{
	int x;
	int y;
	
	struct Lista *prox;
};

struct No{
	int x_max;
	int x_min;
	int y_max;
	int y_min;
	
	int x_centroide;
	int y_centroide;
	
	int peso;
	
	struct Lista *fila;
	
	struct No *esq;
	struct No *dir;
};

// assinaturas das funções//

int calc_centx(struct Lista *fila);
int calc_centy(struct Lista *fila);
void arborizar(struct No *base, struct Lista *fila1);

// fim das assinaturas//

int main(int argc, char **argv){
	
	struct Lista *fila1;
	
	struct No *base;
	
	int ar;
	
	//colocando os valores iniciais pra o primeiro nó da árvore//
	base->x_max = 10;
	base->x_min = 0;
	base->y_max = 10;
	base->y_min = 0;
	
	base->x_centroide = calc_centx(fila1);
	base->y_centroide = calc_centy(fila1);
	
	base->peso = 0;
	
	base->fila = fila1;
	
	base->esq = NULL;
	base->dir = NULL;
	
	
	arborizar(base,fila1);
}

int calc_centx(struct Lista *fila){
	int i = 0;
	int soma = 0;
	
	while(fila != NULL){
		
		soma = soma + fila->x;
		
		i++;
		fila = fila->prox;
	}
	
	return soma/i;
	
}

int calc_centy(struct Lista *fila){
	int i = 0;
	int soma = 0;
	
	while(fila != NULL){
		
		soma = soma + fila->y;
		
		i++;
		fila = fila->prox;
	}
	
	return soma/i;
	
}


void arborizar(struct No *base, struct Lista *fila1){
	
}