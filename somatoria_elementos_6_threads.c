////////////////////////////////////////////////////////////
////////         EDSON LOMBA - 41525388        /////////////
////////////////////////////////////////////////////////////
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define TAMANHO 200000000

struct timeval t1, t2;

int vetor[TAMANHO], soma;

int preencheVetor(int *v){
  int i;
  for (i = 0; i < TAMANHO; i++) {
    v[i] += 1;
  }
}

int main(int argc, char const *argv[]) {
  int i;
  omp_set_num_threads(6);
  int vSoma[omp_get_thread_num()];

  preencheVetor(vetor);
  printf("Número de threads utilizadas: %d\n\n", omp_get_max_threads());

  //Soma intermediária em um vetor intermediário

  gettimeofday(&t1, NULL);
  #pragma omp parallel
  {
  	vSoma[omp_get_thread_num()] = 0;
  	#pragma omp for
      for(i = 0; i < TAMANHO; i++){
        vSoma[omp_get_thread_num()]+=vetor[i];
      }
    soma+=vSoma[omp_get_thread_num()];
  }
  gettimeofday(&t2, NULL);
  printf("Somatoria utilizando soma intermediaria em um vetor intermediario: %d\nTempo de execucao: %f seconds\n\n", soma,
         (double) (t2.tv_usec - t1.tv_usec) / 1000000 +
         (double) (t2.tv_sec - t1.tv_sec));

  //Somatoria utilizando controle de seção crítica
  soma = 0;
  gettimeofday(&t1, NULL);
  #pragma omp parallel for
  	for(i = 0; i < TAMANHO; i++){
  	   #pragma omp critical
       {
         soma += vetor[i];
       }
     }
  gettimeofday(&t2, NULL);
  printf("Somatoria utilizando controle de seção crítica: %d\nTempo de execucao: %f seconds\n\n", soma,
         (double) (t2.tv_usec - t1.tv_usec) / 1000000 +
         (double) (t2.tv_sec - t1.tv_sec));

  //Somatoria utilizando reduction
  soma = 0;
  gettimeofday(&t1, NULL);
  #pragma omp parallel for reduction(+ :soma)
    for(i = 0;i < TAMANHO;i++){
      soma += vetor[i];
    }
  gettimeofday(&t2, NULL);
  printf("Somatoria utilizando reduction: %d\nTempo de execucao: %f seconds\n\n", soma,
         (double) (t2.tv_usec - t1.tv_usec) / 1000000 +
         (double) (t2.tv_sec - t1.tv_sec));

  return 0;
}
