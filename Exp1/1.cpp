//1. 实验一：删除单链表中的元素
#include <malloc.h>
#include <iostream>

using namespace std;

struct LNode{
    int num;
    LNode *next;
};

int main(){
    int T; //T组测试数据
    cin>>T;

    for(int i=0;i<T;i++){
        int len; //长度
        cin>>len;

        LNode *crt=(LNode *)malloc(sizeof(LNode));
        LNode *work;
        work=crt;
        for(int j=0;j<len;j++){
            //读入一个数
            LNode *temp=(LNode *)malloc(sizeof(LNode));
            cin>>temp->num;
            temp->next=NULL;
            
            work->next=temp;

            work=temp;
        }

        int q;//进行q次操作
        cin>>q;

        for(int j=0;j<q;j++){
            int oper=0;//操作代号
            cin>>oper;

            switch(oper){
                case 1:{//遍历链表
                    LNode *ergo=crt->next;
                    while(ergo!=NULL){
                        cout<<ergo->num<<" ";
                        ergo=ergo->next;
                    }
                    cout<<endl;
                    break;
                }case 2:{//删除元素
                    int min,max;
                    cin>>min;//读入区间
                    cin>>max;

                    LNode *ergo=crt;
                    //遍历删除
                    while(ergo->next!=NULL){
                        if(ergo->next->num>min&&ergo->next->num<max){//在区间内
                            LNode *pending=ergo->next;
                            ergo->next=ergo->next->next;
                            free(pending);
                        }else{
                            ergo=ergo->next;
                        }

                    }
                    break;
                }
            }
        }
    }

}