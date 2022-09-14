//3. 实验一：一元稀疏多项式简单的计算器
#include <iostream>
#include <malloc.h>

using namespace std;

struct LNode {
    int coef,power;
    LNode *next;
};

//输出一个多项式
void printExp(LNode *exp){
    LNode *work=exp;

    while(work->next!=NULL){
        if(work!=exp&&work->next->coef>0){//如果不是第一个而且系数大于零
            cout<<"+";
        }
        cout<<work->next->coef<<"X^"<<work->next->power;
        work=work->next;
    }
    cout<<endl;
    return;
}

//两个多项式相加
LNode* add(LNode *poly0,LNode *poly1,int oper){
    
	//开始扫描

    LNode *work0,*work1,*product=(LNode *)malloc(sizeof(LNode)),*workp,*workt;
	
	work0=poly0->next;
	work1=poly1->next;
	
	workp=product;
	
	while(work0!=NULL&&work1!=NULL){
		if(work0->power==work1->power){
            if(oper==2){
                if(work0->coef+work1->coef!=0){
                    //添加到结果链尾
                    LNode *temp=(LNode *)malloc(sizeof(LNode));
                    temp->power=work0->power;
                    temp->coef=work0->coef+work1->coef;
                    temp->next=NULL;
                    
                    workp->next=temp;
                    
                    workp=workp->next;
                }
            }else if(oper==3){
                if(work0->coef-work1->coef!=0){
                    //添加到结果链尾
                    LNode *temp=(LNode *)malloc(sizeof(LNode));
                    temp->power=work0->power;
                    temp->coef=work0->coef-work1->coef;
                    temp->next=NULL;
                    
                    workp->next=temp;
                    
                    workp=workp->next;
                }
            }
			//无论是否添加到了结果链，此处两个多项式指针都加一
			work0=work0->next;
			work1=work1->next;
		}else{
			//不一样，把小的项添加到结果链
            int symbol=1;
			if(work0->power>work1->power){
				workt=work1;
				work1=work1->next;
                symbol=-1;
			}else{
				workt=work0;
				work0=work0->next;
			}
			
			
			LNode *temp=(LNode *)malloc(sizeof(LNode));
			temp->power=workt->power;
			temp->coef=workt->coef*symbol;
			temp->next=NULL;
			
			workp->next=temp;
			
			workp=workp->next;
		}
		
		//验证是否有一个多项式已经到尾部
		if(work0!=NULL&&work1!=NULL){
			continue;
		}else{
            int symbol=1;
			if(work0==NULL){
				workt=work1;
                symbol=-1;
			}else{
				workt=work0;
			}
			//把未见底的多项式剩余项全部移到结果链
			// workp->next=workt;
			while(workt!=NULL){
                LNode *temp=(LNode *)malloc(sizeof(LNode));
                temp->power=workt->power;
                temp->coef=workt->coef*symbol;
                temp->next=NULL;

                workp->next=temp;
                workp=workp->next;

                workt=workt->next;
            }

			break;
		}
	}
    return product;
}

int main(){
    int n;
    cin>>n;//测试数据组数
    for(int i=0;i<n;i++){
        int exp0amt,exp1amt;//两个多项式的项数
        cin>>exp0amt;
        cin>>exp1amt;

        //初始化俩多项式链表
        LNode *exp0=(LNode *)malloc(sizeof(LNode));
        LNode *exp1=(LNode *)malloc(sizeof(LNode));

        //读入第一个多项式
        LNode *work=exp0;
        for(int j=0;j<exp0amt;j++){
            LNode *temp=(LNode *)malloc(sizeof(LNode));
            cin>>temp->coef;
            cin>>temp->power;

            temp->next=NULL;

            work->next=temp;

            work=temp;
        }

        //读入第二个多项式
        work=exp1;
        for(int j=0;j<exp1amt;j++){
            LNode *temp=(LNode *)malloc(sizeof(LNode));
            cin>>temp->coef;
            cin>>temp->power;

            temp->next=NULL;

            work->next=temp;

            work=temp;
        }

        //读入操作步骤数
        int step;
        cin>>step;

        int code;
        for(int j=0;j<step;j++){
            cin>>code;//读入操作代码

            switch(code){
                case 1:{//输出两个多项式
                    printExp(exp0);
                    printExp(exp1);
                    break;
                }case 2:{//将多项式2加到多项式1
                    exp0=add(exp0,exp1,2);
                    break;
                }case 3:{
                    exp0=add(exp0,exp1,3);
                    break;
                }
            }
        }
    }
}