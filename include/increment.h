#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <iostream>
#include "../include/fifo.h"

extern Fifo fifo;
extern pthread_mutex_t sharedVariableMutex;
// extern int32_t gSharedVariable;
int counter = 1;
extern Fifo fifo;

void *incrementTask(void*param){
    while(1){
        /*Delay for 3seconds.*/
        sleep(3);
        /*Wait for the mutex to be come available.*/
        pthread_mutex_lock(&sharedVariableMutex);
        // gSharedVariable++;

        fifo.put(counter);
        counter++;
        // std::cout <<"IncrementTask: shared var is ";
        // std::cout << gSharedVariable << std::endl;
        /*Release the mutex for other task to use.*/
        pthread_mutex_unlock(&sharedVariableMutex);
    }
}