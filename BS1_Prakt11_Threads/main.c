//
//  main.c
//  BS1_Prakt11_Threads
//
//  Created by Markus Klemm on 05.02.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>

void* HelloWorld (void *toprint)
{
    toprint = (char *) toprint;
    printf("%s\n",toprint);
    return 0;
}

int main(int argc, const char * argv[])
{
    pthread_t HelloWorldThread;
    if (pthread_create(&HelloWorldThread, NULL, HelloWorld, "Hello World") != 0) {
        perror("Creating helloworldThread failed");
    }
    
    void *HelloWorldReturn;
    if (pthread_join(HelloWorldThread, &HelloWorldReturn) != 0) {
        perror("Joining helloworldThread failed");
    }
    HelloWorldReturn = (int *) HelloWorldReturn;
    printf("Thread returned %d\n",HelloWorldReturn);
    
    return 0;
}

