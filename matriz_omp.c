
////////////////////////////////////////////////////////////////////////////////
////////								////////
////////		Edson Lomba - 41525388				////////
////////								////////
////////////////////////////////////////////////////////////////////////////////

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define TAM 1000

int A[TAM][TAM];
int B[TAM][TAM];
int C[TAM][TAM];
struct timeval t1, t2;

void preencheMatriz(){
	for(int i=0;i<TAM;i++){
		for(int j=0;j<TAM;j++){
			A[i][j] = B[i][j] = (i*TAM)+(j+1);
		}
	}
}

void printMatrizA(){
	printf("\n\nMATRIZ A\n");
	
	for(int i=0;i<TAM;i++){
		printf("\n");
		for(int j=0;j<TAM;j++){
			printf("%d\t",A[i][j]);
		}
	}
}

void printMatrizB(){
	printf("\n\nMATRIZ B\n");
	
	for(int i=0;i<TAM;i++){
		printf("\n");
		for(int j=0;j<TAM;j++){
			printf("%d\t",B[i][j]);
		}
	}
}

void printMatrizC(){
	printf("\n\nMATRIZ C\n");
	
	for(int i=0;i<TAM;i++){
		printf("\n");
		for(int j=0;j<TAM;j++){
			printf("%d\t",C[i][j]);
		}
	}
}

void limpaMatrizC(){
	for(int i=0;i<TAM;i++){
		for(int j=0;j<TAM;j++){
			C[i][j] = 0;
		}
	}

}

int main(int argc, char *argv[])
{

	preencheMatriz();

    printf("\n*** MULTIPLICACAO SEQUENCIAL ***\n");
	gettimeofday(&t1, NULL);
	for(int i=0;i<TAM;i++){
		for(int j=0;j<TAM;j++){
			for(int k=0;k<TAM;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	gettimeofday(&t2, NULL);
	printf("\nTempo de execucao da multiplicacao: %f seconds", (double) (t2.tv_usec - t1.tv_usec) / 1000000 + (double) (t2.tv_sec - t1.tv_sec));

	//printMatrizC();
	limpaMatrizC();

    printf("\n\n*** MULTIPLICACAO PARALELA ***\n");
    omp_set_num_threads(1);

    printf("\nNúmero de threads utilizadas: %d\n", omp_get_max_threads());

	gettimeofday(&t1, NULL);
	#pragma omp parallel for
        for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
                for(int k=0;k<TAM;k++){
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
	gettimeofday(&t2, NULL);
	printf("\nTempo de execucao da multiplicacao: %f seconds", (double) (t2.tv_usec - t1.tv_usec) / 1000000 + (double) (t2.tv_sec - t1.tv_sec));
    printf("\n");

    limpaMatrizC();

    omp_set_num_threads(2);

    printf("\nNúmero de threads utilizadas: %d\n", omp_get_max_threads());

    gettimeofday(&t1, NULL);
    #pragma omp parallel for
        for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
                for(int k=0;k<TAM;k++){
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
    gettimeofday(&t2, NULL);
    printf("\nTempo de execucao da multiplicacao: %f seconds", (double) (t2.tv_usec - t1.tv_usec) / 1000000 + (double) (t2.tv_sec - t1.tv_sec));
    printf("\n");

    limpaMatrizC();

    omp_set_num_threads(3);

    printf("\nNúmero de threads utilizadas: %d\n", omp_get_max_threads());

    gettimeofday(&t1, NULL);
    #pragma omp parallel for
        for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
                for(int k=0;k<TAM;k++){
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
    gettimeofday(&t2, NULL);
    printf("\nTempo de execucao da multiplicacao: %f seconds", (double) (t2.tv_usec - t1.tv_usec) / 1000000 + (double) (t2.tv_sec - t1.tv_sec));
    printf("\n");
    
    limpaMatrizC();

    omp_set_num_threads(4);

    printf("\nNúmero de threads utilizadas: %d\n", omp_get_max_threads());

    gettimeofday(&t1, NULL);
    #pragma omp parallel for
        for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
                for(int k=0;k<TAM;k++){
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
    gettimeofday(&t2, NULL);
    printf("\nTempo de execucao da multiplicacao: %f seconds", (double) (t2.tv_usec - t1.tv_usec) / 1000000 + (double) (t2.tv_sec - t1.tv_sec));
    printf("\n");
    
    limpaMatrizC();

    omp_set_num_threads(5);

    printf("\nNúmero de threads utilizadas: %d\n", omp_get_max_threads());

    gettimeofday(&t1, NULL);
    #pragma omp parallel for
        for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
                for(int k=0;k<TAM;k++){
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
    gettimeofday(&t2, NULL);
    printf("\nTempo de execucao da multiplicacao: %f seconds", (double) (t2.tv_usec - t1.tv_usec) / 1000000 + (double) (t2.tv_sec - t1.tv_sec));
    printf("\n");
    
    limpaMatrizC();

    omp_set_num_threads(6);

    printf("\nNúmero de threads utilizadas: %d\n", omp_get_max_threads());

    gettimeofday(&t1, NULL);
    #pragma omp parallel for
        for(int i=0;i<TAM;i++){
            for(int j=0;j<TAM;j++){
                for(int k=0;k<TAM;k++){
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
    gettimeofday(&t2, NULL);
    printf("\nTempo de execucao da multiplicacao: %f seconds", (double) (t2.tv_usec - t1.tv_usec) / 1000000 + (double) (t2.tv_sec - t1.tv_sec));
    printf("\n");
	//printMatrizC();

	
	printf("\n");

}
