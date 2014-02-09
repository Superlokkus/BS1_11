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

long lnumber;

void* hundredMillionDecrement(void *redherring)
{
    int_least32_t i;
    for (i=0; i<100000000; i++) {
        lnumber--;
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
        lnumber++;
    }
    
    if (pthread_join(secondThread, NULL)) {
        perror("Joining 2nd thread failed");
    }
    
    printf("Main exiting, global number is %ld\n",lnumber);
    
    return EXIT_SUCCESS;
}

