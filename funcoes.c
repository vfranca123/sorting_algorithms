#include <stdio.h>
#include <stdlib.h>
#include "ordenacoes.h"
#include <time.h>



// ordenaçoes simples  --------------------------------------------------------
void printar_vetor_int(apenas_chave *vet, int n){
    for(int i =0 ; i < n ; i ++ ){
        printf("%d| ",vet[i].chave);
        
    }
    printf("\n");
}
void selecao_int( apenas_chave *vet,int n){

    
    
    if( vet != NULL){
    int menor;
    apenas_chave auxiliar;
    for(int i = 0 ; i <= n ; i++){
        menor = i ; 
        
        for (int j = i+1 ;j <= n ; j++){
            
            if(vet[j].chave < vet[menor].chave ){ menor = j ;}
        
        }

       
        auxiliar = vet[i];
        vet[i] = vet[menor];
        vet[menor] = auxiliar;
        

    }
    }else exit(1);

}

void insercao_int( apenas_chave *vet, int n){  
    int i , j ;
    apenas_chave aux;

    for( i = 0 ; i < n - 1 ;i++ ){

        if(vet[i].chave > vet[i+1].chave){
            aux = vet[i + 1];
            vet[i+1] = vet[i];
            vet[i] = aux;
            
            j = i - 1 ;

            while(j>=0){

                if(aux.chave < vet[j].chave){
                    vet[j+1] = vet[j];
                    vet[j] = aux;
                }else { break ;}
                j = j - 1 ;
            }
        }
    }

}

void shellsort_int(apenas_chave *vet , int n){
    int h = 1;
    int j;
    apenas_chave aux;
    while(h < n){
        h = 3 * h + 1 ;
    }
    while( h > 1 ){
        h /= 3 ; 
        for( int i = h ; i < n ; i ++  ){
            aux = vet[i];
            j = i - h;
            while(j >= 0 && aux.chave < vet[j].chave){
                vet[j+h] = vet[j];
                j-= h;
            }
            vet[j+h] = aux;
        }
    }
     
}

void quicksort_int(apenas_chave *vet, int esq, int dir) {
    int i, j, x;
    apenas_chave y ;
    i = esq;
    j = dir;
    x = vet[(esq + dir) / 2].chave;
     
    while(i <= j) {
        while(vet[i].chave < x && i < dir) {
            i++;
        }
        while(vet[j].chave > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quicksort_int(vet, esq, j);
    }
    if(i < dir) {
        quicksort_int(vet, i, dir);
    }
}
void construir_int( apenas_chave *vet, int raiz , int fundo){
    int pronto, filhoMax;
    apenas_chave tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && pronto!=1) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2].chave > vet[raiz * 2 + 1].chave) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz].chave < vet[filhoMax].chave) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}

void heapsort_int( apenas_chave *vet , int n){
    int i; 
    apenas_chave aux;

	for (i = (n / 2); i >= 0; i--) {
		construir_int(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		construir_int(vet, 0, i-1);
	}
}
void merge_sort_int(apenas_chave *vet, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort_int(vet, inicio, meio);
        merge_sort_int(vet, meio + 1, fim);
        merge_int(vet, inicio, meio, fim);
    }
}

void merge_int(apenas_chave *vet, int inicio, int meio, int fim) {
    apenas_chave *temp;
    temp = (apenas_chave*)malloc((fim - inicio + 1) * sizeof(apenas_chave));
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;

    p1 = inicio;
    p2 = meio + 1;

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (vet[p1].chave < vet[p2].chave)
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];

                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            } else {
                if (!fim1)
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            vet[k] = temp[j];
    }
    free(temp);
}
void encher_vetor_int(apenas_chave *vet, int n){
    
    
    srand(time(NULL));
    for(int i = 0 ; i < n ; i++){
        vet[i].chave = rand();
    }
    
}

    


//ordençãos com strings --------------------------------------------------------
void encher_vetor_complexa(teste *vet, int n){
    srand(time(NULL));
    for(int i = 0 ; i < n ; i++){
        vet[i].chave = rand();
    }
    
}
void printar_vetor_complexa(teste *vet, int n){
    for(int i =0 ; i < n ; i ++ ){
        printf("%d| ",vet[i].chave);
        
    }
    printf("\n");
}
void selecao_complexa( teste *vet,int n){
      int menor;
      teste auxiliar;
    
    for(int i = 0 ; i <= n ; i++){
        menor = i ; 
        
        for (int j = i+1 ;j <= n ; j++){
            
            if(vet[j].chave < vet[menor].chave ){ menor = j ;}
        
        }

       
        auxiliar = vet[i];
        vet[i] = vet[menor];
        vet[menor] = auxiliar;
        

    }
}
void insercao_complexa( teste *vet, int n){
    int i , j ;
    teste aux;

    for( i = 0 ; i < n - 1 ;i++ ){

        if(vet[i].chave > vet[i+1].chave){
            aux = vet[i + 1];
            vet[i+1] = vet[i];
            vet[i] = aux;
            
            j = i - 1 ;

            while(j>=0){

                if(aux.chave < vet[j].chave){
                    vet[j+1] = vet[j];
                    vet[j] = aux;
                }else { break ;}
                j = j - 1 ;
            }
        }
    }
}
void shellsort_complexa(teste *vet , int n){
    int h = 1;
    int j;
    teste aux;

    while(h < n){
        h = 3 * h + 1 ;
    }
    while( h > 1 ){
        h /= 3 ; 
        for( int i = h ; i < n ; i ++  ){
            aux = vet[i];
            j = i - h;
            while(j >= 0 && aux.chave < vet[j].chave){
                vet[j+h] = vet[j];
                j-= h;
            }
            vet[j+h] = aux;
        }
    }
}
void quicksort_complexa(teste *vet, int esq, int dir){
    int i, j, x;
    teste y ;
     
    i = esq;
    j = dir;
    x = vet[(esq + dir) / 2].chave;
     
    while(i <= j) {
        while(vet[i].chave < x && i < dir) {
            i++;
        }
        while(vet[j].chave > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quicksort_complexa(vet, esq, j);
    }
    if(i < dir) {
        quicksort_complexa(vet, i, dir);
    }
}
void construir_complexa(teste *vet, int raiz, int fundo){
    int pronto, filhoMax;
    teste tmp;

	pronto = 0;
	while ((raiz*2 <= fundo) && pronto!=1) {
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (vet[raiz * 2].chave > vet[raiz * 2 + 1].chave) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (vet[raiz].chave < vet[filhoMax].chave) {
		tmp = vet[raiz];
		vet[raiz] = vet[filhoMax];
		vet[filhoMax] = tmp;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}
void heapsort_complexa(teste *vet,int n ){
    int i; 
    teste aux;

	for (i = (n / 2); i >= 0; i--) {
		construir_complexa(vet, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		construir_complexa(vet, 0, i-1);
	}
}
void merge_sort_complexa(teste *vet, int inicio, int fim){
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort_complexa(vet, inicio, meio);
        merge_sort_complexa(vet, meio + 1, fim);
        merge_complexa(vet, inicio, meio, fim);
    }
}

void merge_complexa(teste *vet, int inicio, int meio, int fim){
     teste *temp;
    temp = (teste*)malloc((fim - inicio + 1) * sizeof(teste));
    int p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;

    p1 = inicio;
    p2 = meio + 1;

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (vet[p1].chave < vet[p2].chave)
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];

                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            } else {
                if (!fim1)
                    temp[i] = vet[p1++];
                else
                    temp[i] = vet[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            vet[k] = temp[j];
    }
    free(temp);
}