
#include <stdio.h>
#include <cuda_runtime.h>
#include <math.h>
#include <device_launch_parameters.h>
#include<time.h>

#define  N   		100000000
#define  BLOCK_SIZE	1024
float 	   hArray[N];
float     *dArray;
int 	   blocks;

clock_t cpu_start, cpu_stop, gpu_start, gpu_stop, gpup_start, gpup_stop, gpue_start, gpue_stop, gpul_start, gpul_stop;
double cpu_ile, gpu_ile, gpup_ile, gpue_ile, gpul_ile;

void prologue(void) {
	cudaMemset(hArray, 0, sizeof(hArray));
	for (int i = 0; i < N; i++) {
		hArray[i] = i + 1;
	}
	cudaMalloc((void**)&dArray, sizeof(hArray));
	cudaMemcpy(dArray, hArray, sizeof(hArray), cudaMemcpyHostToDevice);
}

void epilogue(void) {
	cudaMemcpy(hArray, dArray, sizeof(hArray), cudaMemcpyDeviceToHost);
	cudaFree(dArray);
}


__global__ void pow3(float *A) {
	int x = blockDim.x * blockIdx.x + threadIdx.x;

	if (x < N)
		A[x] = A[x] * A[x] * A[x] + A[x] * A[x] + A[x];
}

void pow3cpu(float *B) {
	for (int x = 0; x<N; x++) {
		B[x] = B[x] * B[x] * B[x] + B[x] * B[x] + B[x];
	}
}

int main(int argc, char** argv)
{
	int	 devCnt;
	
	cudaGetDeviceCount(&devCnt);
	if (devCnt == 0) {
		perror("No CUDA devices available -- exiting.");
		return 1;
	}


	cpu_start = clock();

	for (int i = 0; i<N; i++) {
		hArray[i]=i+1;
	}

	pow3cpu(hArray);

	cpu_stop = clock();


	cpu_ile = (double)1000 * (cpu_stop - cpu_start) / CLOCKS_PER_SEC;

	gpu_start = clock();
	
	gpu_start = clock();
	gpup_start = clock();
	prologue();
	gpup_stop = clock();

	gpul_start = clock();
	blocks = N / BLOCK_SIZE;
	if (N % BLOCK_SIZE) {
		blocks++;
	}
	pow3 << <blocks, BLOCK_SIZE >> > (dArray);
	cudaThreadSynchronize();
	gpul_stop = clock();
	gpue_start = clock();
	epilogue();
	gpue_stop = clock();
	gpu_stop = clock();

	gpu_ile = (double)1000 * (gpu_stop - gpu_start) / CLOCKS_PER_SEC;
	gpup_ile = (double)1000 * (gpup_stop - gpup_start) / CLOCKS_PER_SEC;
	gpue_ile = (double)1000 * (gpue_stop - gpue_start) / CLOCKS_PER_SEC;
	gpul_ile = (double)1000 * (gpul_stop - gpul_start) / CLOCKS_PER_SEC;

	printf("Wyniki: \n");
	printf("Czas CPU: %f\n", cpu_ile);
	printf("Czas pracy GPU: %f\n\n", gpu_ile);
	printf("Czas liczenie GPU: %f\n", gpul_ile);
	printf("Czas prologu GPU: %f % \n", gpup_ile);
	printf("Czas epilogu GPU: %f % \n", gpue_ile);

	return 0;
}
//