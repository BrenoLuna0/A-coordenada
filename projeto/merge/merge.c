#include<stdio.h>
#include<stdlib.h>

struct Lista{
	int x;
	int y;
	struct Lista *prox;
};

void vetorizarx(struct Lista *fila, int arrayx[14], int *nx);
void vetorizary(struct Lista *fila, int arrayy[14], int *ny);
void sort(int *array, int comeco, int fim);
void merge(int *array,int inicio,int meio,int fim);

int main(int argc, char **argv){
	int arrayx[14];
	int arrayy[14];
	
	struct Lista *fila;
	
	int nx,ny;
	
	vetorizarx(fila,arrayx,&nx);
	vetorizary(fila,arrayy,&ny);
	
	sort(arrayx,0,nx);
	sort(arrayy,0,ny);
}

void vetorizarx(struct Lista *fila, int arrayx[14], int *nx){
	struct Lista *tmp = fila;
	
	int i = 0;
	
	while(tmp != NULL){
		arrayx[i] = tmp->x;
		tmp = tmp->prox;
		i++;
	}
	
	*nx = i;
}

void vetorizary(struct Lista *fila, int arrayy[14], int *ny){
	struct Lista *tmp = fila;
	
	int i = 0;
	
	while(tmp != NULL){
		arrayy[i] = tmp->y;
		tmp = tmp->prox;
		i++;
	}
	
	*ny = i;
}

void sort(int *array, int comeco, int fim){
	int meio;
	if(comeco<fim){
		meio = ((comeco+fim)/2);
		sort(array,comeco,meio);
		sort(array,meio+1,fim);
		merge(array,comeco,meio,fim);
	}
}

void merge(int *array,int inicio,int meio,int fim){
	int i,j,k,*temp;
	temp = (int*) malloc((fim-inicio+1)*sizeof(int));
	i=inicio;
	j=meio+1;
	k=0;
	
	while(i<meio+1 || j<fim+1){
		if(i==meio+1){
			temp[k]=array[j];
			j++;
			k++;
		}
		else{
			if(j==fim+1){
				temp[k]=array[i];
				i++;
				k++;
			}
			else{
				if(array[i]<array[j]){
					temp[k]=array[i];
					i++;
					k++;
				}
				else{
					temp[k]=array[j];
					j++;
					k++;
				}
			}
		}
	}
	for(i=inicio;i<=fim;i++){
		array[i]=temp[i-inicio];
	}
	free(temp);
}

while{i<=5}{
	dividir(....);
}




		vetorizarx(mapa,arrayx,&nx);
		vetorizary(mapa,arrayy,&ny);
		
		sort(arrayx,0,nx);
		sort(arrayy,0,ny);