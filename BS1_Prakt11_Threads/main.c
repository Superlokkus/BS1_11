//
//  main.c
//  BS1_Prakt11_Threads
//
//  Created by Markus Klemm on 05.02.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>

void HelloWorld (void)
{
    printf("Hello World!\n");
}

int main(int argc, const char * argv[])
{
    pthread_t helloworldThread;
    if (pthread_create(&helloworldThread, NULL, HelloWorld, NULL) != 0) {
        perror("Creating helloworldThread failed");
    }
    
    if (pthread_join(helloworldThread, NULL) != 0) {
        perror("Joining helloworldThread failed");
    }
    
    return 0;
}

