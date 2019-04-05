#include <stdio.h>
#include <cuda_runtime.h>
#include <math.h>
#include <device_launch_parameters.h>
#include<time.h>
#include<stdlib.h>


#define N 128
#define  BLOCK_SIZE	8

typedef struct {
	int width;
	int height;
	float *elements;
} Matrix;


clock_t start_cpu, stop_cpu, start_gpu, stop_gpu;

double czas_cpu, czas_gpu;


__global__ void MatMulKernel(Matrix A, Matrix B, Matrix C) {

	// ka¿dy w¹tek oblicza jeden element macierzy C
	// akumuluj¹c wynik w zmiennej Cvalue
	float Cvalue = 0;
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;
	for (int e = 0; e < A.width; ++e)
		Cvalue += A.elements[row * A.width + e] * B.elements[e * B.width + col];
	C.elements[row * C.width + col] = Cvalue;
}

void MatMul(const Matrix A, const Matrix B, Matrix C) {
	// kopiujemy macierze A i B to globalnej pamiêci urz¹dzenia
	// najpierw A

	Matrix d_A;
	d_A.width = A.width;

	d_A.height = A.height;
	size_t size = A.width * A.height * sizeof(float);
	cudaMalloc((void **)&d_A.elements, size);
	cudaMemcpy(d_A.elements, A.elements, size, cudaMemcpyHostToDevice);

	// potem B 
	Matrix d_B;
	d_B.width = B.width;
	d_B.height = B.height;
	size = B.width * B.height * sizeof(float);
	cudaMalloc((void **)&d_B.elements, size);
	cudaMemcpy(d_B.elements, B.elements, size, cudaMemcpyHostToDevice);

	// przydzielamy macierz C w globalnej pamiêci urz¹dzenia
	Matrix d_C;
	d_C.width = C.width;
	d_C.height = C.height;
	size = C.width * C.height * sizeof(float);
	cudaMalloc((void**)&d_C.elements, size);

	// preparujemy œrodowisko i wywo³ujemy kernel
	dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
	dim3 dimGrid(B.width / dimBlock.x, A.height / dimBlock.y);

	start_gpu = clock();

	MatMulKernel << <dimGrid, dimBlock >> >(d_A, d_B, d_C);
	cudaThreadSynchronize();

	stop_gpu = clock();

	czas_gpu = (double)1000 * (stop_gpu - start_gpu) / CLOCKS_PER_SEC;

	// odbieramy obliczon¹ macierz C z pamiêci globalnej urz¹dzenia
	cudaMemcpy(C.elements, d_C.elements, size, cudaMemcpyDeviceToHost);

	printf("CZAS GPU %f\n", czas_gpu);
	 
	printf("Macierz GPU \n");
	/*
	for (int i=0;i<C.height;i++){
		for (int j=0;j<C.width;j++){
			printf("%.2f ", C.elements[i*C.height+j]);
		}
	}
	//*/

	printf("\n");
	// zwalniamy pamiêæ 
	cudaFree(d_A.elements);
	cudaFree(d_B.elements);
	cudaFree(d_C.elements);
}

int main(int argc, char** argv)
{
	int	 devCnt;

	Matrix A, B, C;

	cudaGetDeviceCount(&devCnt);
	if (devCnt == 0) {
		perror("No CUDA devices available -- exiting.");
		return 1;
	}
	
	A.width = N;
	A.height = N;
	A.elements = (float*)malloc(A.width*A.height * sizeof(float));
	for (int i = 0; i<A.width*A.height; i++) {
		A.elements[i] = ((float)(rand() % 100) / 100) + (rand() % 50);
	}

	B.width = N;
	B.height = N;
	B.elements = (float*)malloc(B.width*B.height * sizeof(float));
	for (int i = 0; i<B.width*B.height; i++) {
		B.elements[i] = ((float)(rand() % 100) / 100) + (rand() % 50);
	}

	C.width = B.width;
	C.height = A.height;
	C.elements = (float*)malloc(C.width*C.height * sizeof(float));


	float **A2D = new float*[A.width];
    for (int i = 0; i < A.height; i++)
        A2D[i] = new float[A.width];

    float **B2D = new float*[A.width];
    for (int i = 0; i < A.height; i++)
        B2D[i] = new float[A.width];

    float **C2D = new float*[A.width];
    for (int i = 0; i < A.height; i++)
        C2D[i] = new float[A.width];


	

	for (int i = 0; i<A.width; i++) {
		for (int j = 0; j<A.height; j++) {
			A2D[i][j] = A.elements[i*A.width + j];
		}
	}
	for (int i = 0; i<B.width; i++) {
		for (int j = 0; j<B.height; j++) {
			B2D[i][j] = B.elements[i*B.width + j];
		}
	}
	for (int i = 0; i<C.width; i++) {
		for (int j = 0; j<C.height; j++) {
			C2D[i][j] = 0;
		}
	}

	start_cpu = clock();

	for (int i = 0; i<A.height; i++) {
		for (int j = 0; j<A.width; j++) {
			for (int k = 0; k<B.width; k++) {
				C2D[i][k] += A2D[i][j] * B2D[j][k];
			}
		}
	}

	stop_cpu = clock();

	czas_cpu = (double)1000 * (stop_cpu - start_cpu) / CLOCKS_PER_SEC;
	printf("Czas dla CPU %.2f \n", czas_cpu);

	printf("Macierz CPU \n");

	/*
	for (int i=0;i<C.height;i++){
		for (int j=0;j<C.width;j++){
			printf("%.2f ", C2D[i][j]);
		}
	}

	//*/
	printf("\n");
	

	MatMul(A, B, C);

	//printf("N = 8\n");
	//printf("Block SIZE = 4\n");

	for (int i = 0; i < A.width; i++) {
		delete [] A2D[i];
		delete [] B2D[i];
		delete [] C2D[i];
	}

	delete[] A2D;
	delete[] B2D;
	delete[] C2D;

	free(A.elements);
	free(B.elements);
	free(C.elements);
}