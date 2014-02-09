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
    char *ctoprint = (char *) toprint;
    printf("%s\n",ctoprint);
    int *rtnPnt; static int irtn = 0; rtnPnt = &irtn;
    return rtnPnt;
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
    int iHelloWorldReturn = *(int*) HelloWorldReturn;
    printf("Thread returned %d\n",iHelloWorldReturn);
    
    return 0;
}

