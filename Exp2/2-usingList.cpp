//2. 实验一：约瑟夫问题
//使用链表解决
#include <malloc.h>
#include <iostream>

using namespace std;

struct LNode{
    int m;
    int no;
    LNode *next;
};

int main(){
    int a;//测试数据组数
    cin>>a;
    for (int i=0;i<a;i++){
        int n=0;
        cin>>n;//有n个人

        LNode *crt=(LNode *)malloc(sizeof(LNode));
        
        LNode *work=crt;
        for(int j=0;j<n;j++){//读入每个人的数字
            LNode *temp=(LNode *)malloc(sizeof(LNode));
            cin>>temp->m;
            temp->no=j+1;

            temp->next=NULL;
            work->next=temp;

            work=temp;
        }

        //初始密码m
        int m=0;
        cin>>m;

        //遍历链表
        LNode *ergo=crt;
        int iter=0;
        while(1){
            iter++;
            if(crt->next==NULL){
                break;
            }
            if(iter==m){//找到出列者
                m=ergo->next->m;
                cout<<ergo->next->no<<" ";
                LNode *pending=ergo->next;
                ergo->next=ergo->next->next;
                free(pending);
                iter=0;
            }else{
                ergo=ergo->next;
            }
            if(ergo->next==NULL){
                ergo=crt;
            }
        }
        cout<<endl;
    }
}