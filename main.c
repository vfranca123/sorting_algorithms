#include <stdio.h>
#include <stdlib.h>
#include "ordenacoes.h"
#include <sys/time.h>
#include <sys/resource.h>


int main(){
   //deve ser modificado dependendo da estruck que queiro usar----
    int n = 20;
    teste *v=(teste*)malloc(n*sizeof(teste));
    
    // tempo real-------------
    struct timeval start, end;
    
    
    // tempo real-------------

    //tempo CPU--------------
    struct rusage start2, end2;
    
    
    //tempo CPU--------------
    

    encher_vetor_complexa(v,n);
    merge_sort_complexa(v,0, n-1);
    
    
    
    printf("\n");
    // tempo real-------------
    gettimeofday(&start, NULL);
    gettimeofday(&end, NULL);
    long double startTime = start.tv_sec + start.tv_usec / 1000000.0L,
    endTime = end.tv_sec + end.tv_usec / 1000000.0L;
    

    //tempo CPU--------------
    getrusage(RUSAGE_SELF, &start2);
    getrusage(RUSAGE_SELF, &end2);
    long double comecaTime = start2.ru_utime.tv_sec + start2.ru_utime.tv_usec / 1000000.0L,
    terminaTime = end2.ru_utime.tv_sec + end2.ru_utime.tv_usec / 1000000.0L;

    // tempo real ----------------------
    printf("tempo real\n");
    printf("Tempo inicial = %Lf\n", startTime);
    printf("Tempo final = %Lf\n", endTime);
    printf("Tempo decorrido = %Lf\n", endTime - startTime);
    printf("\n");
    //tempo real ---------------------

    //tempo CPU---------------------
    printf("tempo CPU \n");
    printf("Tempo inicial = %Lf\n", comecaTime);
    printf("Tempo final = %Lf\n", terminaTime);
    printf("Tempo decorrido = %Lf\n", terminaTime - comecaTime);
    printf("\n");
    //tempo CPU--------------------
    free(v);
}