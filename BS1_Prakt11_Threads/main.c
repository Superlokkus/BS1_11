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

void* printString (void *toprint)
{
    char *ctoprint = (char *) toprint;
    int *rtnPnt; static int irtn;
    irtn = printf("%s",ctoprint);
    
    rtnPnt = &irtn; return rtnPnt;
}

int main(int argc, const char * argv[])
{
    pthread_t HelloWorldThread; char msg[] = "Hello World!\n";
    
    if (pthread_create(&HelloWorldThread, NULL, printString, msg) != 0) {
        perror("Creating helloworldThread failed");
    }
    
    void *HelloWorldReturn;
    if (pthread_join(HelloWorldThread, &HelloWorldReturn) != 0) {
        perror("Joining helloworldThread failed");
    }
    int iHelloWorldReturn = *(int*) HelloWorldReturn;
    if (strlen(msg) != iHelloWorldReturn) {
        fprintf(stderr, "Something in printing by HelloWorldThread failed\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

