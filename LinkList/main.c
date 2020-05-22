#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct LNode
{
    int data;
    struct LNode *next;

}LNode, *LinkList;

//初始化单链表
LinkList init(){
    LinkList L = (LinkList)malloc(sizeof(LNode));
    LNode* header = (LNode*)malloc(sizeof(LNode));
    header->next = NULL;
    L = header;
    return L;
}

//获得指定索引节点数据
int get_index_i(LinkList L,int i){
    LNode* p = L->next;
    int j = 1;
    while(p && j<i){
        p = p->next;
        ++j;
    }
    if(!p || j>i){
        printf("happen error!");
        return -1;
    }
    return p->data;
}

//插入节点
int insert_node(LinkList L,LNode* node,int pos){
    int j = 1;
    LNode* p = L->next;
    while(p && j<pos-1){
        p = p->next;
        ++j;
    }
    if(!p || j>pos-1){
        printf("insert node error!");
        return -1;
    }
    node->next = p->next;
    p->next = node;
    return 1;
}

//删除节点
int delete_node(LinkList L,int pos) {
    int j = 1;
    int data;
    LNode* p = L->next;
    while(p && j<pos-1){
        p = p->next;
        ++j;
    }
    if(!p || j>pos-1){
        printf("delete node error!");
        return -1;
    }
    LNode* node = p->next;
    p->next = node->next;
    data = node->data;
    free(node);
    return data;
}

//尾插法
int end_insert(LinkList L,LNode* node){
    LNode* ptr;
    node->next = NULL;
    ptr = L->next;
    if(ptr != NULL){
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = node;
    }else{
        L->next = node;
    }
    return 1;
}

//头插法
int head_insert(LinkList L,LNode* node){
    node->next = L->next;
    L->next = node;
    return 1;
}
int main()
{
    LinkList L = init();

    if(L->next==NULL){
        printf("L is null\n");
    }else{
        printf("L is not null\n");
    }
    int i;
    for(i=0;i<10;i++){
        LNode* node = (LNode*)malloc(sizeof(LNode));
        node->data = i;
        head_insert(L,node);
        //end_insert(L,node);

    }
    printf("L data is %d\n",L->data);
    printf("first node data is %d\n",L->next->data);
    if(L->next==NULL){
        printf("L is null\n");
    }else{
        printf("L is not null\n");
    }
    printf("get index i=6,data=%d\n",get_index_i(L,6));
    LNode* node = (LNode*)malloc(sizeof(LNode));
    node->data = 1314;
    insert_node(L,node,6);
    printf("get index i=6,data=%d\n",get_index_i(L,6));
    return 0;
}
