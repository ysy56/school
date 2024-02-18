#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int sum; // 공유변수

pthread_mutex_t mutex_lock; // 

void *t_function(); // 1~5000000 계산
struct timeval do_single_thread();
struct timeval do_multi_thread();
void print_diff(struct timeval *single_time, struct timeval *multi_time);

int main(int argc, char* argv[]){
    struct timeval single_thread_processing_time = do_single_thread();
    struct timeval multi_thread_processing_time = do_multi_thread();
    print_diff(&single_thread_processing_time, &multi_thread_processing_time);
    return 0;
};

struct timeval do_single_thread(){
    struct timeval startTime, endTime;
    struct timeval diffTime;

    gettimeofday(&startTime, NULL);
    int num_thread = 1;
    pthread_t p_thread; 
    int thr_id;
    int status;
    sum = 0; 
    
    pthread_create(&p_thread, NULL, t_function, &num_thread);
    pthread_join(p_thread, (void**)&status);
    printf("single thread result: %d \n", sum);
    
    gettimeofday(&endTime, NULL);
    diffTime.tv_sec = endTime.tv_sec - startTime.tv_sec;
    diffTime.tv_usec = endTime.tv_usec - startTime.tv_usec;
    return diffTime;
}

struct timeval do_multi_thread(){
    struct timeval startTime, endTime;
    struct timeval diffTime;
   
    int num_thread = 4; 
    pthread_t p_thread[num_thread];
    int thr_id;
    int status;
    sum = 0;

    gettimeofday(&startTime, NULL);
    
    pthread_mutex_init(&mutex_lock, NULL); 
    for (int i = 0; i<num_thread; i++){
	pthread_create(&p_thread[i], NULL, t_function, &num_thread);
    }

    for (int i = 0; i<num_thread; i++){
	pthread_join(p_thread[i], (void**)&status);
    }
    printf("%d multi thread result: %d \n", num_thread, sum);

    gettimeofday(&endTime, NULL);
    diffTime.tv_sec = endTime.tv_sec - startTime.tv_sec;
    diffTime.tv_usec = endTime.tv_usec - startTime.tv_usec;
    return diffTime;
}

void *t_function(int *num_thread){
    int localsum = 0;
    for(int i = 0; i<50000000/ *num_thread; i++){
	localsum++;
    }
    pthread_mutex_lock(&mutex_lock);
    sum = sum + localsum;
    pthread_mutex_unlock(&mutex_lock);
}

void print_diff(struct timeval *single_time, struct timeval *multi_time){
    double diffTime1, diffTime2;
    diffTime1 = single_time->tv_sec + ((double)single_time->tv_usec/1000000);
    printf("single thread time: %lf s\n", diffTime1);
    diffTime2 = multi_time->tv_sec + ((double)multi_time->tv_usec/1000000);
    printf("multi thread time: %lf s\n", diffTime2);
}
