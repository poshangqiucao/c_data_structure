#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_LENGTH 100;

typedef struct {
    int *base;
    int front;
    int rear;
}SqQueue;

/*
int InitQueue(SqQueue &Q){
    Q.base = (int*)malloc(MAX_LENGTH*sizeof(int));
    if(!Q.base){
        printf("malloc memory fail!");
    }
    Q.front = Q.rear = 0;
    return 1;
}
*/
int main()
{
    SqQueue Q;
    //InitQueue(Q);
    return 0;
}
