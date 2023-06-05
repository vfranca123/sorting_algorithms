#include <stdio.h>
#include <stdlib.h>

#ifndef _ordenacoes_h 
#define _ordenacoes_h 
// estruturas ultilizadas para os testes -------------------------------------
typedef struct teste{
    int chave;
    char T[50][50];
}teste;

typedef struct apenas_chave{
    int chave;
}apenas_chave;

//funcoes para teste simples -------------------------------------
void encher_vetor_int(apenas_chave *vet, int n);
void printar_vetor_int(apenas_chave *vet,int n);
void selecao_int( apenas_chave *vet,int n);
void insercao_int( apenas_chave *vet, int n);
void shellsort_int(apenas_chave *vet , int n);
void quicksort_int(apenas_chave *vet, int esq, int dir);
void construir_int( apenas_chave *vet ,  int inicio , int final);
void heapsort_int( apenas_chave *vet , int n);
void merge_sort_int(apenas_chave *vet, int inicio, int fim);
void merge_int(apenas_chave *vet ,int p ,int q ,int r);

//funcoes para teste com string  -------------------------------------
void encher_vetor_complexa(teste *vet, int n);
void printar_vetor_complexa(teste *vet, int n);
void selecao_complexa( teste *vet,int n);
void insercao_complexa( teste *vet, int n);
void shellsort_complexa(teste *vet , int n);
void quicksort_complexa(teste *vet, int esq, int dir);
void construir_complexa(teste *vet, int raiz, int fundo);
void heapsort_complexa(teste *vet,int n );
void merge_sort_complexa(teste *vet, int inicio, int fim);
void merge_complexa(teste *vet, int inicio, int meio, int fim);
#endif 