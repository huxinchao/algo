#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <sched.h>

void *producter_f(void *arg);
void *consumer_f(void* arg);

pthread_mutex_t mutex;
int buffer_has_item = 0;
int running = 1;

int main() {
    pthread_t c_t;
    pthread_t p_t;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&p_t, NULL, reinterpret_cast<void*(*)(void*)>(producter_f), NULL);
    pthread_create(&c_t, NULL, reinterpret_cast<void*(*)(void*)>(consumer_f), NULL);
    sleep(1);
    running = 0;
    pthread_join(c_t, NULL);
    pthread_join(p_t, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}

void* producter_f(void* arg) {
    while(running) {
        pthread_mutex_lock(&mutex);
        buffer_has_item++;
        std::cout << "Producter: " << buffer_has_item << std::endl;
        pthread_mutex_unlock(&mutex);
    }
}

void* consumer_f(void *arg) {
    while(running) {
        pthread_mutex_lock(&mutex);
        buffer_has_item--;
        std::cout << "Consumer: " << buffer_has_item << std::endl;
        pthread_mutex_unlock(&mutex);
    }
}