//
//  main.c
//  BS1_Prakt11_Threads
//
//  Created by Markus Klemm on 05.02.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

long lnumber; pthread_mutex_t changeLnumberMutex = PTHREAD_MUTEX_INITIALIZER;

void* hundredMillionDecrement(void *redherring)
{
    int_least32_t i;
    for (i=0; i<100000000; i++) {
        if (pthread_mutex_lock(&changeLnumberMutex)) {
            perror("Locking mutex in 2nd thread failed");
            return NULL;
        }
        lnumber--;
        if (pthread_mutex_unlock(&changeLnumberMutex)) {
            perror("Unlocking mutex in 2nd thread failed");
            return NULL;
        }
    }
    return NULL;
}

int main(int argc, const char * argv[])
{
    printf("Global number initialized with %ld\n",lnumber);
    
    
    
    pthread_t secondThread;
    if (pthread_create(&secondThread, NULL, hundredMillionDecrement, NULL)) {
        perror("Creating 2nd thread failed");
        return EXIT_FAILURE;
    }
    
    int_least32_t i;
    for (i=0; i<100000000; i++) {
        if (pthread_mutex_lock(&changeLnumberMutex))
        {
            perror("Locking the mutex failed in main thread");
            return EXIT_FAILURE;
        }
        lnumber++;
        if (pthread_mutex_unlock(&changeLnumberMutex)) {
            perror("Unlocking the mutex failed in main thread");
            return EXIT_FAILURE;
        }
    }
    
    if (pthread_join(secondThread, NULL)) {
        perror("Joining 2nd thread failed");
        return EXIT_FAILURE;
    }
    
    printf("Result of global number: %ld\n",lnumber);
    
    //Cleanup
    if (pthread_mutex_destroy(&changeLnumberMutex))
    {
        perror("Destroying mutex failed");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

