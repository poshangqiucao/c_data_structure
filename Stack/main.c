#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define INIT_LENGTH 100
#define INCR_LENGTH 10

typedef struct {
    int *base;
    int *top;
    int stack_length;
} SqStack;

int InitStack(SqStack *S){
    S->base = (int*)malloc(INIT_LENGTH*sizeof(int));
    if(!S->base){
        printf("alloc init memory error!\n");
        return -1;
    }
    S->top = S->base;
    S->stack_length = INIT_LENGTH;
    return 1;
}

int DestroyStack(SqStack *S){
    free(S->base);
    return 1;

}

void ClearStack(SqStack *S){
    S->top = S->base;
}

int StackEmpty(SqStack *S){
    if(S->base == S->top){
        return 1;
    }else{
        return 0;
    }
}

int StackLength(SqStack *S){
    return S->top-S->base;
}

int GetTop(SqStack *S){
    return *(S->top-1);
}

int Push(SqStack *S,int data){
    if(StackLength(S) == S->stack_length){
        S->base = (int*)realloc(S->base,(S->stack_length+INCR_LENGTH)*sizeof(int));
        if(!S->base){
            printf("realloc error!\n");
            return -1;
        }
        S->top = S->base+S->stack_length;
        S->stack_length = S->stack_length+INCR_LENGTH;
    }
    *(S->top) = data;
    S->top++;
    return 1;
}

int Pop(SqStack *S){
    if(StackEmpty(S)){
        printf("Stack empty!\n");
        return -1;
    }
    S->top--;
    return *(S->top);
}

void StackTraverse(SqStack *S){
    int i = 0;
    while(S->base+i != S->top){
        printf("index=%d,data=%d\n",i,*(S->base+i));
        i++;
    }
}

int main()
{
    SqStack S;
    int i;

    InitStack(&S);
    printf("init stack length:%d\n",S.stack_length);
    for(i=0;i<101;i++){
        Push(&S,i);
    }
    StackTraverse(&S);
    printf("stack length:%d\n",StackLength(&S));
    printf("stack sum length:%d\n",S.stack_length);
    printf("pop data:%d\n",Pop(&S));
    StackTraverse(&S);
    printf("stack length:%d\n",StackLength(&S));
    return 0;
}
