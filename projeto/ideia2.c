
// Esse é o código base//


//A ideia é o seguinte, vc vai aplicar isso na sua função kdtree para quando a struct No for diferente de NULL. Leve em consideração q eu fiz isso antes de vc criar a função kdtree.


//Boa parte das coisas q estão aqui, já estao sendo feitas na função kdtree, mas vou comentá-las mesmo assim.



void dividir(struct No *base, int c, struct par_ordenado *mapa, int i){
	
	if(base != NULL){
		
		int *arrayx = malloc(c * sizeof(int)); //cria um vetor com o tamanho dado pelo contador c para armazenar os valores de x
		int *arrayy = malloc(c * sizeof(int)); // mesma coisa de cima, mas agora em y
		
		if(i%2 == 0){ // esse if é para ver se o 'i' é impar ou par. Se quiser ver de onde veio esse 'i', vou deixar algumas observações logo após o código. 
			struct par_ordenado *guia1 = malloc(sizeof(struct par_ordenado));
																				//Esses guias servem para auxiliar a partir a lista encadeada ao meio
			struct par_ordenado *guia2 = malloc(sizeof(struct par_ordenado));
			
			guia1 = mapa; //direciono as guias
			guia2 = mapa;
			//como esse é o caso do 'i' par, faremos a divisão no eixo y. 
			int t;
			int ny;
			int h = 0; //adição de última hora. esse int vai dizer em q ponto a nossa lista foi quebrada.
			
			vetorizary(mapa,arrayy,&ny); //pega todas as coordenadas y coloca no array.
			
			sort(arrayy,0,ny); // ordena o array.
			
			t = arrayy[ny/2]; // pega a mediana.
			
			while(guia1->y != t){ // aqui vai acontecer a mágica da divisão da lista. 
				guia1 = guia1->prox;// vou percorrer a lista, procurando o elemento q tem o y igual ao t. Como aqui tem elementos repetidos, pode ser q a lista nao seja quebrada exatamente ao meio.
				h++;
			}
			
			guia2 = guia1->prox; //guia1 está apontando para o elemento q possui o y igual a mediana, e o guia2 aponta para o proximo elemento. 
			
			guia1->prox = NULL; // aqui, o proximo elemento do guia1 se torna NULL, tornando-o o último elemento da lista.
			                    // nao esqueça q o guia2 esta apontando para o q era antes, o prox do guia1, logo ele marca o início de outra lista. 
			
			dividir(base->esq,h,mapa,i); // aqui é a parte da recursão. vou mandar para a função os filhos direito e esquerdo, em seguida o tamanho da nova lista q pertence a ele, a lista* e o contador.
			dividir(base->dir,c - h,guia2,i); // na função de cima eu mandei a lista 'mapa', pq como ela foi partida, eu preciso dos primeiros elementos das novas listas. No caso da de cima, 'mapa' aponta para o início de uma lista, e na de baixo, 'guia2' aponta para o início da outra.
		}
		
		if(i%2 != 0){ //mesma coisa aqui, só q com o 'i' impar.
			struct par_ordenado *guia1 = malloc(sizeof(struct par_ordenado));
			
			struct par_ordenado *guia2 = malloc(sizeof(struct par_ordenado));
			
			guia1 = mapa;
			guia2 = mapa;
			
			int t;
			int nx;
			int i = 0;
			
			vetorizarx(mapa,arrayx,&nx);
			
			sort(arrayy,0,nx);
			
			while(i<nx){
				printf("%d\n", arrayx[i]);
				i++;
			}
			
			t = arrayy[nx/2];
			
			while(guia1->x != t){
				guia1 = guia1->prox;
			}
			
			guia2 = guia1->prox;
			
			guia1->prox = NULL;
			
			dividir(base->esq,c/2,mapa,i);
			dividir(base->dir,(c/2+1),guia2,i);
		}
		
	}else{
		return;
	}
	
	
	
}


//quando eu estava pensando nisso, a minha ideia principal era q a função q agora é a kdtree seria chamada dentro de um laço de repetição//
//esse 'i' seria justamente o  índice q estaria sendo incrementado no laço, mudando seu valor, sempre q uma nova geração é formada//