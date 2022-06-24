#include <stdio.h>
#include <semaphore.h>
#include <stdbool.h>
#include <pthread.h>

sem_t rw_mutex;
sem_t mutex;
int read_count = 0;

void *write_lock(){
    sem_wait(&rw_mutex);
    printf("write_lock \n");
    sem_post(&rw_mutex);
}

void *read_lock(){
    sem_wait(&mutex);
    read_count++;
    if(read_count == 1)
	sem_wait(&rw_mutex);
    sem_post(&mutex);
    printf("read_lock \n");
    sem_wait(&mutex);
    read_count--;
    if(read_count == 0)
	sem_post(&rw_mutex);
    sem_post(&mutex);
}

int main(int argc, char *argv[]){
    int num_t = 2;
    pthread_t write_t;
    pthread_t read_t[2];

    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    pthread_create(&write_t, NULL, write_lock, NULL);
    for(int i = 0; i<num_t; i++)
	pthread_create(&read_t[i], NULL, read_lock, NULL);

    pthread_join(write_t, NULL);
    for(int i = 0; i<num_t; i++)
	pthread_join(read_t[i], NULL);

    return 0;
}
