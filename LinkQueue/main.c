#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct QNode{
    int data;
    struct QNode *next;
} QNode, *QNodeptr;

typedef struct {
    QNodeptr front;
    QNodeptr rear;
    int queue_length;
} LinkQueue;

int InitQueue(LinkQueue *Q){
    QNodeptr ptr;
    ptr = (QNodeptr)malloc(sizeof(QNode));
    if(!ptr){
        printf("malloc error!\n");
        return -1;
    }
    ptr->next = NULL;
    Q->front = Q->rear = ptr;
    Q->queue_length = 0;
    return 1;
}

int QueueLength(LinkQueue *Q){
    return Q->queue_length;
}

int EnQueue(LinkQueue *Q,int data){
    QNodeptr ptr;
    ptr = (QNodeptr)malloc(sizeof(QNode));
    if(!ptr){
        printf("malloc error!\n");
        return -1;
    }
    ptr->data = data;
    ptr->next = NULL;
    Q->rear->next = ptr;
    Q->rear = ptr;
    Q->queue_length++;
    return 1;
}

int DeQueue(LinkQueue *Q){
    if(Q->front== Q->rear){
        printf("LinkQueue is nothing!\n");
        return -1;
    }
    int data;
    QNodeptr ptr;
    ptr = Q->front->next;
    Q->front->next = ptr->next;
    if(ptr->next == NULL){
        Q->rear = Q->front;
    }
    data = ptr->data;
    free(ptr);
    Q->queue_length--;
    return data;
}
int main()
{
    LinkQueue Q;
    int i;

    InitQueue(&Q);
    for(i=0;i<10;i++){
        EnQueue(&Q,i);
    }
    printf("linkqueue length:%d\n",QueueLength(&Q));
    for(i=0;i<10;i++){
        printf("dequeue data=%d\n",DeQueue(&Q));
    }
    printf("linkqueue length:%d\n",QueueLength(&Q));

    return 0;
}
