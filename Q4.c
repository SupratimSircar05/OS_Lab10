// one thread prints odd nos. from 1 to 50
// another thread prints even nos. from 1 to 50
// so basically printing 1 to 50

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mtx;
pthread_cond_t cond1;

static int isOdd;

void *PrintOdd(void *args)
{
	for(int i = 1; i <= 50; i += 2) {
		pthread_mutex_lock(&mtx);
		while(isOdd) {
			pthread_cond_wait(&cond1, &mtx);
		}
		printf("%d\n", i);
		isOdd = 1;
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&cond1);
	}
	return NULL;
}

void *PrintEven(void *args)
{
	for(int i = 2; i <= 50; i += 2) {
		pthread_mutex_lock(&mtx);
		while(!isOdd) {
			pthread_cond_wait(&cond1, &mtx);
		};
		printf("%d\n", i);
		isOdd = 0;
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&cond1);
	}
	return NULL;
}

int main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&mtx, NULL);
	pthread_cond_init(&cond1, NULL);
 
	pthread_create(&t1, NULL, &PrintOdd, NULL);
	pthread_create(&t2, NULL, &PrintEven, NULL);
 
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
 
	pthread_cond_destroy(&cond1);
	pthread_mutex_destroy(&mtx);
 
    pthread_exit(NULL);
	return 0;
}