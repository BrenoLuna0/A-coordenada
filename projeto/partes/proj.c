#include<stdio.h>
#include<stdlib.h>

struct par_ordenado {
	int x;
	int y;
	struct par_ordenado *prox;
};




void main(){
	
	
	FILE *entrada = fopen("entrada.txt","r");
	
	struct par_ordenado *mapa = NULL;
	
	leitura(entrada,&mapa);
}

void leitura(FILE *entrada, struct par_ordenado **mapa){
	
	int a;
	int b;
	
	while(fscanf(entrada,"%d") != EOF){
		
		fscanf(entrada,"%d",&a);
		
		fscanf(entrada,"%d",&b);
		
		cria_lista(&(*mapa),a,b);
		
		
	}
	
}

void cria_lista(struct par_ordenado **mapa, int a, int b){
	
	
	if((*mapa) == NULL){
		
		(*mapa) = malloc(sizeof(struct par_ordenado));
		
		(*mapa)->x = a;
		
		(*mapa)->y = b;
		
		(*mapa)->prox = NULL;
		
	}
	
	if((*mapa)->prox != NULL){
		
		cria_lista(&(*mapa)->prox,a,b);
		
	}
	else{
		
		struct par_ordenado *novo;
		
		novo  = malloc(sizeof(struct par_ordenado));
		
		novo->x = a;
		
		novo->y = b;
		
		(*mapa)->prox = novo;
		
		novo->prox = NULL;
		
	}
}








































