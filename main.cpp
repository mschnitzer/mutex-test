#include <iostream>
#include <pthread.h>

void *Thread1(void *args);
void *Thread2(void *args);

pthread_mutex_t lock;

int main()
{
    pthread_mutex_init(&lock, NULL);

	pthread_t thread[2] = { 0, 0 };

	pthread_create(&thread[0], NULL, Thread1, NULL);
	pthread_create(&thread[1], NULL, Thread2, NULL);

	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}

void *Thread1(void *args)
{
	pthread_mutex_lock(&lock);

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Thread 1: " << i << std::endl;
	}

	pthread_mutex_unlock(&lock);
}

void *Thread2(void *args)
{
	pthread_mutex_lock(&lock);

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Thread 2: " << i << std::endl;
	}

	pthread_mutex_unlock(&lock);
}