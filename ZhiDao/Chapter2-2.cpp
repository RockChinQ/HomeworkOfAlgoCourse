#include <iostream>
#include <malloc.h>

using namespace std;

struct LNode {
    int value;
    LNode *next;
};

//插入元素,插入成功返回1
int insert(LNode *list,int loc,int value){
    LNode *work=list;

    while(work->next!=NULL){
        if(work->next->value==loc){
            LNode *temp=(LNode *)malloc(sizeof(LNode));
            temp->value=value;
            temp->next=work->next;
            work->next=temp;
            return 1;
        }
        work=work->next;
    }
    return 0;
}
