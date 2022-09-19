#include <iostream>
#include <malloc.h>

using namespace std;

struct LNode {
    int value;
    LNode *next;
};

LNode* reverse(LNode *L){
    LNode *work=L->next;
    LNode *n=(LNode *)malloc(sizeof(LNode));
    n->next=NULL;
    LNode *nwork=n;

    while(work!=NULL){
        cout<<work->value<<endl;
        LNode *next=work->next;

        work->next=nwork->next;
        nwork->next=work;

        work=next;
    }
    LNode *dlt=L;
    free(dlt);
    return n;
}

const int test[]={10,15,10,18,15},len=5;

int main(){
    
    LNode *L=(LNode *)malloc(sizeof(LNode));

    LNode *work=L;

    //将测试数据生成链表
    for(int i=0;i<len;i++){
        LNode *temp=(LNode *)malloc(sizeof(LNode));
        temp->value=test[i];
        temp->next=NULL;

        work->next=temp;

        work=temp;
    }

    work=L;
    while(work->next!=NULL){
        cout<<work->next->value<<" ";
        work=work->next;
    }
    cout<<endl;

    
    work=reverse(L);
    while(work->next!=NULL){
        cout<<work->next->value<<" ";
        work=work->next;
    }
    cout<<endl;
}