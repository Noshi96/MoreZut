#include <stdio.h>
#include <cuda_runtime.h>
#include <math.h>
#include <device_launch_parameters.h>
#include<time.h>
#include<stdlib.h>

#define N 1000000
#define  BLOCK_SIZE 2

typedef struct {
	int width;
	int height;
	int stride;
	float *elements;
} Matrix;



clock_t start_gpu_2, stop_gpu_2, start_gpu_1, stop_gpu_1;

double czas_gpu_2, czas_gpu_1;


// funkcja do odczytywania wartoœci elementu wskazanej macierzy

__device__ float GetElement(const Matrix A, int row, int col)
{
	return A.elements[row * A.stride + col];
}

// funkcja do zapisywania wartoœci elementu wskazanej macierzy
__device__ void SetElement(Matrix A, int row, int col, float value)
{
	A.elements[row * A.stride + col] = value;
}

// wykreowanie opisu podmacierzy o rozmiarze BLOCK_SIZExBLOCK_SIZE, która
// ulokowana jest col podmacierzy w prawo i row podmacierzy w dó³
// licz¹c od lewego wierzcho³ka danej macierzy
__device__ Matrix GetSubMatrix(Matrix A, int row, int col)
{
	Matrix Asub;
	Asub.width = BLOCK_SIZE;
	Asub.height = BLOCK_SIZE;
	Asub.stride = A.stride;
	Asub.elements = &A.elements[A.stride * BLOCK_SIZE * row + BLOCK_SIZE * col];
	return Asub;
}

__global__ void MatMulKernelWspol(Matrix A, Matrix B, Matrix C) {

	// ustalenie numeru wiersza i kolumny wewn¹trz bloku
	int blockRow = blockIdx.y;
	int blockCol = blockIdx.x;

	float Cvalue = 0;

	// ka¿dy blok oblicza jedn¹ podmacierz Csub macierzy C
	Matrix Csub = GetSubMatrix(C, blockRow, blockCol);

	// ustalenie numeru wiersza i kolumny wewn¹trz w¹tku
	int row = threadIdx.y;
	int col = threadIdx.x;

	// iterujemy wszystkie podmacierze A i B, które
	// s¹ potrzebne do obliczenia Csub – mno¿ymy ze sob¹ ka¿d¹ parê
	// podmacierzy i akumulujemy wynik
	for (int m = 0; m < (A.width / BLOCK_SIZE); ++m) {

		// kreujemy podmacierz Asub macierzy A
		Matrix Asub = GetSubMatrix(A, blockRow, m);

		// kreujemy podmacierz Bsub macierzy B
		Matrix Bsub = GetSubMatrix(B, m, blockCol);

		// deklarujemy obszar pamiêci dzielonej dla podmacierzy Asub i Bsub
		__shared__ float As[BLOCK_SIZE][BLOCK_SIZE];
		__shared__ float Bs[BLOCK_SIZE][BLOCK_SIZE];

		// za³aduj Asub i Bsub z pamiêci globalnej do dzielonej
		// (ka¿dy w¹tek ³aduje jeden element z ka¿dej podmacierzy)
		As[row][col] = GetElement(Asub, row, col);
		Bs[row][col] = GetElement(Bsub, row, col);

		// poczekajmy, a¿ wszystkie dane zostan¹ skopiowane
		__syncthreads();

		// mno¿ymy Asub i Bsub
		for (int e = 0; e < BLOCK_SIZE; ++e)
			Cvalue += As[row][e] * Bs[e][col];

		// poczekajmy, a¿ obliczenia zostan¹ zakoñczone zanim zabierzemy
		// siê za przetwarzanie nastêpnej podmacierzy
		__syncthreads();
	}

	// odsy³amy obliczone Cvalue do pamiêci urz¹dzenia
	SetElement(Csub, row, col, Cvalue);
}

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

	start_gpu_2 = clock();
	MatMulKernel << <dimGrid, dimBlock >> >(d_A, d_B, d_C);
	cudaThreadSynchronize();
	stop_gpu_2 = clock();
	czas_gpu_2 = (double)1000 * (stop_gpu_2 - start_gpu_2) / CLOCKS_PER_SEC;

	// odbieramy obliczon¹ macierz C z pamiêci globalnej urz¹dzenia
	cudaMemcpy(C.elements, d_C.elements, size, cudaMemcpyDeviceToHost);

	printf("CZAS GPU %f\n", czas_gpu_2);

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


void MatMulWspol(const Matrix A, const Matrix B, Matrix C) {
	// kopiujemy macierze A i B to globalnej pamiêci urz¹dzenia
	// najpierw A

	Matrix d_A;
	d_A.width = d_A.stride = A.width;
	d_A.height = A.height;
	size_t size = A.width * A.height * sizeof(float);
	cudaMalloc((void **)&d_A.elements, size);
	cudaMemcpy(d_A.elements, A.elements, size, cudaMemcpyHostToDevice);

	// potem B
	Matrix d_B;
	d_B.width = d_B.stride = B.width;
	d_B.height = B.height;
	size = B.width * B.height * sizeof(float);
	cudaMalloc((void **)&d_B.elements, size);
	cudaMemcpy(d_B.elements, B.elements, size, cudaMemcpyHostToDevice);

	// przydzielamy macierz C w globalnej pamiêci urz¹dzenia
	Matrix d_C;
	d_C.width = d_C.stride = C.width;
	d_C.height = C.height;
	size = C.width * C.height * sizeof(float);
	cudaMalloc((void**)&d_C.elements, size);

	// preparujemy œrodowisko i wywo³ujemy kernel
	dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
	dim3 dimGrid(B.width / dimBlock.x, A.height / dimBlock.y);

	start_gpu_1 = clock();
	MatMulKernelWspol << <dimGrid, dimBlock >> >(d_A, d_B, d_C);
	cudaThreadSynchronize();
	stop_gpu_1 = clock();
	czas_gpu_1 = (double)1000 * (stop_gpu_1 - start_gpu_1) / CLOCKS_PER_SEC;

	// odbieramy obliczon¹ macierz C z pamiêci globalnej urz¹dzenia
	cudaMemcpy(C.elements, d_C.elements, size, cudaMemcpyDeviceToHost);

	printf("CZAS GPU z pamiecia dzielona %f\n", czas_gpu_1);

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
	int  devCnt;

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

	MatMulWspol(A, B, C);
	MatMul(A, B, C);

	free(A.elements);
	free(B.elements);
	free(C.elements);
}