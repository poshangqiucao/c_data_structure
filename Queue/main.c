#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_LENGTH 100

//循环队列实现
typedef struct {
    int *base;
    int front;
    int rear;
}SqQueue;


int InitQueue(SqQueue *Q){
    Q->base = (int*)malloc(MAX_LENGTH*sizeof(int));
    if(!Q->base){
        printf("malloc memory fail!\n");
        return -1;
    }
    Q->front = Q->rear = 0;
    return 1;
}

int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MAX_LENGTH) % MAX_LENGTH;
}
int EnQueue(SqQueue *Q,int data){
    if((Q->rear + 1) % MAX_LENGTH == Q->front){
        printf("queue fully!\n");
        return -1;
    }
    Q->base[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAX_LENGTH;
    return 1;
}
int DeQueue(SqQueue *Q){
    int data;
    if(Q->front == Q->rear){
        printf("queue is nothing!\n");
        return -1;
    }
    data = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAX_LENGTH;
    return data;

}

int main()
{
    SqQueue Q;
    int i;

    InitQueue(&Q);
    for(i=0;i<10;i++){
        EnQueue(&Q,i);
    }
    for(i=0;i<5;i++){
        printf("dequeue data=%d\n",DeQueue(&Q));
    }
    printf("queue length:%d\n",QueueLength(Q));

    return 0;
}
