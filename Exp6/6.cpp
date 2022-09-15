//6. 实验一：括号匹配问题
#include <iostream>
#include <malloc.h>

using namespace std;

struct SNode{
    char symbol;
    SNode *next;
};

int main(){
    char exp[128];
    cin>>exp;//读入表达式

    SNode *stack=NULL;

    int i=0;
    while(exp[i]!='\0'){
        switch(exp[i]){
            case '(':
            case '[':
            case '{':{
                //压栈
                SNode *temp=(SNode *)malloc(sizeof(SNode));
                temp->symbol=exp[i];
                temp->next=stack;

                stack=temp;
                break;
            }
            case ')':
            case ']':
            case '}':{
                //判断是否匹配
                //匹配则出栈
                //不匹配直接退出
                if((exp[i]==')'&&stack->symbol=='(')||(exp[i]==']'&&stack->symbol=='[')||(exp[i]=='}'&&stack->symbol=='{')){
                    SNode *pending;
                    pending=stack;
                    stack=stack->next;
                    free(pending);
                }else{
                    cout<<0;
                    return 0;
                }
                break;
            }
        }
        i++;
    }
    cout<<1;
    return 0;
}