#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <iostream>
#include "../include/fifo.h"


extern pthread_mutex_t sharedVariableMutex;
// extern int32_t gSharedVariable;
extern Fifo fifo;

void *decrementTask(void*param)
{
    
    while(1){
    /*Delay for 7 seconds.*/
    sleep(7);
    /*Wait for the mutex to become available.*/
    pthread_mutex_lock(&sharedVariableMutex);
    // gSharedVariable--;

    fifo.get();

    // std::cout << "DecrementTask: shared var is ";
    // std::cout << gSharedVariable << std::endl;
    /*Release the mutex.*/
    pthread_mutex_unlock(&sharedVariableMutex);
    }
}