/*
 * Tema 2 ASC
 * 2018 Spring
 * Bechir Sibel-Leila
 */
#include "utils.h"
#include "cblas.h"

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A) {
	printf("BLAS SOLVER\n");

	double *C = malloc(N * N * 2 * sizeof(double));
	
	int alpha = 1;
	int beta = 0;

	cblas_zsyrk(CblasRowMajor, CblasUpper, CblasTrans, N, N, (const void *) (&alpha), (const void *) A, N, (const void *) (&beta), (void *) C, N);
	
	return C;
}
