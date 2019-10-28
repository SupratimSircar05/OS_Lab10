#include <stdio.h> 
#include <pthread.h> 

// size of array 
#define MAX 8 

// maximum number of threads 
#define MAX_THREAD 2 
 
int a[] = { 1, 5, 7, 10, 12, 14, 15, 18 }; 
int sum[2] = { 0 }; 
int part = 0; 

void* sum_array(void* arg) 
{ 

	// Each thread computes sum of half of the array 
	int thread_part = part++; 

	for (int i = thread_part * (MAX / 2); i < (thread_part + 1) * (MAX / 2); i++) 
		sum[thread_part] += a[i]; 
} 

// Driver Code 
int main() 
{ 

	pthread_t threads[MAX_THREAD]; 

	// Creating 2 threads 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 

	// joining 2 threads i.e. waiting for all 2 threads to complete 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL); 

	// adding sum of 2 parts 
	int total_sum = 0; 
	for (int i = 0; i < MAX_THREAD; i++) 
		total_sum += sum[i]; 

    printf("Sum = %d\n", total_sum);

	pthread_exit(NULL);
    return 0; 
} 
