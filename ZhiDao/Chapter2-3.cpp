#include <malloc.h>
#include <iostream>

using namespace std;

struct LNode {
    int value;
    LNode *next;
};

const int test[]={10,15,10,18,15},len=5;

void duplicateRemoval(LNode *L){
    LNode *work0,*work1;

    work0=L;
    int crtValue=0;
    while(work0->next!=NULL){
        crtValue=work0->next->value;
        work1=work0->next;
        while(work1->next!=NULL){
            if(work1->next->value==crtValue){//重复
                LNode *pending=work1->next;

                work1->next=work1->next->next;
                free(pending);
            }else{
                work1=work1->next;
            }
        }
        work0=work0->next;
    }
}

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

    duplicateRemoval(L);
    work=L;
    while(work->next!=NULL){
        cout<<work->next->value<<" ";
        work=work->next;
    }
    cout<<endl;
}