#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <sched.h>
#include <semaphore.h>

void *producter_f(void *arg);
void *consumer_f(void* arg);

sem_t sem;
int buffer_has_item = 0;
int running = 1;

int main() {
    pthread_t c_t;
    pthread_t p_t;

    sem_init(&sem,0,16);
    
    pthread_create(&p_t, NULL, reinterpret_cast<void*(*)(void*)>(producter_f), NULL);
    pthread_create(&c_t, NULL, reinterpret_cast<void*(*)(void*)>(consumer_f), NULL);
    sleep(1);
    running = 0;
    pthread_join(c_t, NULL);
    pthread_join(p_t, NULL);

    sem_destroy(&sem);
    
    return 0;
}

void* producter_f(void* arg) {
    int semval = 0;
    while(running) {
        usleep(1);
        sem_post(&sem);
        sem_getvalue(&sem, &semval);
        std::cout << "Producter: " << semval << std::endl;
    }
}

void* consumer_f(void *arg) {
    int semval = 0;
    while(running) {
        usleep(1);
        sem_wait(&sem);
        sem_getvalue(&sem, &semval);
        std::cout << "Consumer: " << semval << std::endl;
 
    }
}