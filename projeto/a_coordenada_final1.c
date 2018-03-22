#include<stdio.h>
#include<stdlib.h>

struct par_ordenado { // struct usada p ser o nó da lista encadeada
	int x;
	int y;
	struct par_ordenado *prox;
};

struct No{ // struct usada p ser a folha da arvore
	int x_max;
	int x_min;
	int y_max;
	int y_min;
	
	int x_centroide;
	int y_centroide;
	
	int peso;
	
	struct par_ordenado *fila;
	
	struct No *esq;
	struct No *dir;
};

struct Final{
	int pes;
	int centx;
	int centy;
	
	struct Final *prox;
};


// assinaturas das funções//


void leitura (FILE *entrada, struct par_ordenado **mapa, int *c);

int cria_lista(struct par_ordenado **mapa, int a, int b);

int calc_centx(struct par_ordenado **mapa);

int calc_centy(struct par_ordenado **mapa);

void dividir(struct No *base, int c, struct par_ordenado *mapa, int i, struct Final **dados);

void vetorizarx(struct par_ordenado *mapa, int **arrayx, int *nx);

void vetorizary(struct par_ordenado *mapa, int **arrayy, int *ny);

void sort(int **array, int comeco, int fim);

void merge(int **array,int inicio,int meio,int fim);

void preencher(struct No **base, struct par_ordenado *mapa, int i, int c);


// função principal


void main(){
	
	int c = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int cx;
	int cy;
	
	int numx[32];
	int numy[32];
	int nump[32];
	
	struct par_ordenado *mapa = NULL;
	
	struct No *base = NULL;
	
	struct Final *dados = malloc(sizeof(struct Final));
	
	FILE *entrada = fopen("entrada.txt","r");
	
	leitura(entrada,&mapa,&c);
	
	dividir(base,c,mapa,i,&dados);
	
	while(dados != NULL){
		numx[j] = dados->centx;
		numy[j] = dados->centy;
		nump[j] = dados->pes;
		
		dados = dados->prox;
		j++;
	}
	
	while(k<32){
		cx = cx + (numx[k] * nump[k]);
		cy = cy + (numy[k] * nump[k]);
		
		k++;
	}
	printf("%d %d\n", cx, cy);
}


// funções


void leitura (FILE *entrada, struct par_ordenado **mapa, int *c){ // leitura do arquivo
	
	int a;
	int b;
	
	while(feof(entrada)==0){
		
		fscanf(entrada,"%d",&a);
		
		fscanf(entrada,"%d",&b);
		
		++*c;
		
		cria_lista(&(*mapa),a,b); // enquanto for lendo o arquivo insere as cordenadas numa lista encadeada
		
		
	}
	
}

int cria_lista(struct par_ordenado **mapa, int a, int b){ // criação da lista com as cordenadas
	
	
	if((*mapa) == NULL){
		
		(*mapa) = malloc(sizeof(struct par_ordenado));
		
		(*mapa)->x = a;
		
		(*mapa)->y = b;
		
		(*mapa)->prox = NULL;
		
		return 0;
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

int calc_centx(struct par_ordenado **mapa){ // calculo do centroide em x
	
	int i = 0;
	int soma = 0;
	
	struct par_ordenado *aux2;
	
	aux2 = malloc(sizeof(struct par_ordenado));
	
	aux2 = (*mapa);
	
	while(aux2 != NULL){
		
		soma = soma + aux2->x;
		
		i++;
		
		aux2 = aux2->prox;
	}
	free(aux2);
	
	return soma/i;	
	
}


int calc_centy(struct par_ordenado **mapa){ //calculo do centroide em y
	
	int i = 0;
	int soma = 0;
	
	struct par_ordenado *aux;
	
	aux = malloc(sizeof(struct par_ordenado));
	
	aux = (*mapa);
	
	while(aux != NULL){
		
		soma = soma + aux->y;
		
		i++;
		
		aux = aux->prox;
	}
	free(aux);
	
	return soma/i;
	
}

void vetorizarx(struct par_ordenado *mapa, int **arrayx, int *nx){
	struct par_ordenado *tmp = malloc(sizeof(struct par_ordenado));
	
	tmp = mapa;
	
	int i = 0;
	
	while(tmp != NULL){
		(*arrayx)[i] = tmp->x;
		tmp = tmp->prox;
		i++;
	}
	
	*nx = i;
	
	free(tmp);
}

void vetorizary(struct par_ordenado *mapa, int **arrayy, int *ny){
	struct par_ordenado *temp;
	temp = mapa;
	
	int i = 0;
	
	while(temp != NULL){
		(*arrayy)[i] = temp->y;
		temp = temp->prox;
		i++;
	}
	
	free(temp);
	
	*ny = i;
}

void sort(int **array, int comeco, int fim){
	int meio;
	if(comeco<fim){
		meio = ((comeco+fim)/2);
		sort(array,comeco,meio);
		sort(array,meio+1,fim);
		merge(array,comeco,meio,fim);
	}
}

void merge(int **array,int inicio,int meio,int fim){
	int i;
	int j;
	int k;
	int b = fim - inicio + 1;
	int tmp[b];
	i=inicio;
	j=meio+1;
	k=0;
	
	while(i<meio+1 || j<fim+1){
		if(i==meio+1){
			tmp[k]=(*array)[j];
			j++;
			k++;
		}
		else{
			if(j==fim+1){
				tmp[k]=(*array)[i];
				i++;
				k++;
			}
			else{
				if((*array)[i]<(*array)[j]){
					tmp[k]=(*array)[i];
					i++;
					k++;
				}
				else{
					tmp[k]=(*array)[j];
					j++;
					k++;
				}
			}
		}
	}
	for(i=inicio;i<=fim;i++){
		(*array)[i]= tmp[i-inicio];
	}
}

void dividir(struct No *base, int c, struct par_ordenado *mapa, int i, struct Final **dados){
	
	i++; 
	
	if(c == 1 || c == 0){
		return;
	}
	
	if(i<=3){
		
		base = malloc(sizeof(struct No));
		
		preencher(&base,mapa,i,c);
		
		if(i == 3){
			struct Final *novo = malloc(sizeof(struct Final));
			
			novo->pes = base->peso;
			novo->centx = base->x_centroide;
			novo->centy = base->y_centroide;
			
			if((*dados)->centx > 9){
				(*dados) = novo;
				(*dados)->prox = NULL;
			}else{
				struct Final *som = malloc(sizeof(struct Final));
				som = (*dados);
				
				while(som->prox != NULL){
					som = som->prox;
				}
			
				som->prox = novo;
				som = NULL;
				free(som);
			}
			
		}
		
		int *arrayx = malloc(c * sizeof(int));
		int *arrayy = malloc(c * sizeof(int));
		
		if(i%2 == 0){
			struct par_ordenado *guia1 = malloc(sizeof(struct par_ordenado));
			
			struct par_ordenado *guia2 = malloc(sizeof(struct par_ordenado));
			
			guia1 = mapa;
			guia2 = mapa;
			
			int t;
			int u;
			int h = 0;
			int ny;
			
			vetorizary(mapa,&arrayy,&ny);
			
			sort(&arrayy,0,ny);
			
			u = ny/2;
			
			t = arrayy[u];
			
			while(guia1->y != t){
				guia1 = guia1->prox;
				h++;
			}
			
			guia2 = guia1->prox;
			
			guia1->prox = NULL;
			
			dividir(base->esq,h,mapa,i,dados);
			dividir(base->dir,c-h,guia2,i,dados);
		}
		
		if(i%2 != 0){
			struct par_ordenado *guia1 = malloc(sizeof(struct par_ordenado));
			
			struct par_ordenado *guia2 = malloc(sizeof(struct par_ordenado));
			
			guia1 = mapa;
			guia2 = mapa;
			
			int t;
			int u;
			int h = 0;
			int nx;
			
			
			vetorizarx(mapa,&arrayx,&nx);
			
			sort(&arrayx,0,nx);
            
			u = nx/2;
			
			t = arrayx[u];
			
			while(guia1->x != t){
				guia1 = guia1->prox;
				h++;
			}
			
			guia2 = guia1->prox;
			
			guia1->prox = NULL;
			
			dividir(base->esq,h,mapa,i,dados);
			dividir(base->dir,c-h,guia2,i,dados);
		 
		 
		 }	
      

   }
}


void preencher(struct No **base, struct par_ordenado *mapa, int i, int c){
	
	int *arrayx = malloc(c * sizeof(int));
	int *arrayy = malloc(c * sizeof(int));
	
	int nx;
	int ny;
	
	vetorizarx(mapa,&arrayx,&nx);
	vetorizary(mapa,&arrayy,&ny);
	
	sort(&arrayx,0,nx);
	sort(&arrayy,0,ny);
	
	(*base)->x_max = arrayx[nx];
	(*base)->x_min = arrayx[0];
	(*base)->y_max = arrayy[ny];
	(*base)->y_min = arrayy[0];
	
	(*base)->x_centroide = calc_centx(&mapa);
	(*base)->y_centroide = calc_centy(&mapa);
	
	(*base)->fila = mapa;
	
	if(i = 1){
		(*base)->peso = 0;
	}
	
	if(i != 1){
		int ai;
		
		ai = ((*base)->x_max - (*base)->x_min) * ((*base)->y_max - (*base)->y_min);
		
		(*base)->peso = (1 - (ai/100))/ (2^(i-1)) - 1;
	}
	
	(*base)->esq = NULL;
	(*base)->dir = NULL;
}