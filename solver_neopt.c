/*
 * Tema 2 ASC
 * 2018 Spring
 * Bechir Sibel-Leila
 */
#include "utils.h"

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A) {
	printf("NEOPT SOLVER\n");

	double *C = calloc(N * N * 2, sizeof(double));
	double *B = calloc(N * N * 2, sizeof(double));

	int i, j, k;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			B[2 * (j * N + i)] = A[2 * (i * N + j)];
			B[2 * (j * N + i) + 1] = A[2 * (i * N + j) + 1];
		}
	}

	for (i = 0; i < N; i++) {
		for (j = i; j < N; j++) {
			C[2 * (i * N + j)] = 0;
			C[2 * (i * N + j) + 1] = 0;
			
			for (k = 0; k < N; k++) {
				// parte reala
				C[2 * (i * N + j)] = C[2 * (i * N + j)] + A[2 * (i * N + k)] * B[2 * (k * N + j)] - A[2 * (i * N + k) + 1] * B[2 * (k * N + j) + 1];
				
				// parte imaginara
				C[2 * (i * N + j) + 1] = C[2 * (i * N + j) + 1] + A[2 * (i * N + k)] * B[2 * (k * N + j) + 1] + A[2 * (i * N + k) + 1] * B[2 * (k * N + j)];
			}
		}
	}

	free(B);
	return C;
}
