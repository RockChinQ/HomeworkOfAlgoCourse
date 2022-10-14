//8. 实验一：停车场管理问题
#include <iostream>
#include <malloc.h>

using namespace std;

struct SNode {//停车位栈,和便道队列
    int start;
    SNode *next;
};

int main(){
    int n=0;
    cin>>n;//读入停车位数量

    SNode *spaces=(SNode *)malloc(sizeof(SNode));//停车位栈
    spaces->next=NULL;

    SNode *pending=(SNode *)malloc(sizeof(SNode));//便道队列

    SNode *rear=pending;//便道尾节点

    int used=0;//已使用的停车位数量

    int amt=0;
    cin>>amt;//操作次数

    int oper=0;
    for(int i=0;i<amt;i++){
        cin>>oper;//读入操作
        switch(oper){
            case 1:{//入库
                //判断库是否满了
                SNode *temp=(SNode *)malloc(sizeof(SNode));
                cin>>temp->start;
                if(used<n){//未满,进栈
                    temp->next=spaces->next;
                    spaces->next=temp;
                    used++;
                }else{//满了,进队列
                    temp->next=NULL;
                    rear->next=temp;
                    rear=temp;
                }
                break;
            }case 2:{//出库
                //读入位号和出库时间
                int x,t;
                cin>>x>>t;

                int no=x-(n-used);//此车位位于栈第几个节点

                //从栈中删除此节点
                SNode *work=spaces;
                while(work->next!=NULL){
                    no--;
                    if(no==0){//找到
                        SNode *dlt=work->next;
                        work->next=work->next->next;

                        //输出
                        cout<<(t-dlt->start)<<endl;

                        free(dlt);
                        used--;
                        //从队列中出一个到栈
                        if(rear!=pending){
                            SNode *target=pending->next;
                            //这里做出队操作
                            pending->next=pending->next->next;
                            if(pending->next==rear){//最后一个
                                rear=pending;
                            }
                            target->start=t;
                            target->next=spaces->next;
                            spaces->next=target;
                            used++;
                        }
                        break;
                    }
                    work=work->next;
                }

                break;
            }
        }
    }
}