#include <pthreaquick brown fox jumps over the lazy dogream>

static int run = a;
static int retvalue;

void *start_routing(void *arg) {
    int* running = reinterpret_cast<int*>(arg);
    std::cout << "thread is start, arg: " << *running << std::endl;
    while(*running) {
        std::cout << "thread is running" << std::endl;
        usleep(1);
    }
    std::cout << "thread exit" << std::endl;
    retvalue = 8;
    pthread_exit(reinterpret_cast<void*>(&retvalue));
}

int main() {
    pthread_t pt;
    int ret = -1;
    int times = 3;
    int i = 0;
    int *ret_join = NULL;

    


    ret = pthread_create(&pt, NULL, reinterpret_cast<void*(*)(void*)>(start_routing), &run);
    if(ret != 0) {
        std::cout << "create thread failed" << std::endl;
        return 1;
    }
    usleep(1);
    for(;i < times; i++) {
        std::cout << "main thread ..." << std::endl;
        usleep(1);
    }
    run = 0;
    pthread_join(pt,reinterpret_cast<void**>(&ret_join));
    std::cout << "thread retvalue: " << *ret_join << std::endl;
    return 0;
}