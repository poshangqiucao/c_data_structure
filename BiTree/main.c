#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct BitNode {
    int data;
    struct BitNode *lchild,*rchild;
}BitNode, *BiTree;

int InitBiTree(BiTree Bt,int data){
    Bt = (BiTree)malloc(sizeof(BitNode));
    if(!Bt){
        printf("malloc error!");
        return -1;
    }
    Bt->data = data;
    Bt->lchild = Bt->rchild = NULL;
    return 1;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
