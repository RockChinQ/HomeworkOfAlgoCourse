// 5. 实验二：实现一个哈夫曼编/译码系统
// 这个源码能够正确实现题目中要求的功能，理论上讲，这个程序的解法是正确的，
// 但由于建树方式跟题中的不同，导致使用题中的测试集无法得到期待的结果

#include <iostream>
#include <malloc.h>
#define MAX 2147483647

struct HuffmanTreeNode{
    char value;
    int weight,lchild=-1,rchild=-1,parent=-1;
};

HuffmanTreeNode HTs[100];
int length=0,rawlen=0;

void createHuffmanTree(){
    std::cin>>length;
    // std::cout<<"creating:"<<length<<" ";
    //读入值
    for(int i=0;i<length;i++){
        std::cin>>HTs[i].value;
        // std::cout<<HTs[i].value<<" ";
    }

    //读入权值
    for(int i=0;i<length;i++){
        std::cin>>HTs[i].weight;
        // std::cout<<HTs[i].weight<<" ";
    }
    // std::cout<<std::endl;

    // for(int i=0;i<length;i++){
    //     std::cout<<"i:"<<i<<" w:"<<HTs[i].weight<<" p:"<<HTs[i].parent<<" lc:"<<HTs[i].lchild<<" rc:"<<HTs[i].rchild<<" v:"<<HTs[i].value<<std::endl;
    // }

    int idx_min=0,idx_2nd_min=0;
    int value_min=0,value_2nd_min=0;
    while(1){
        value_min=MAX;
        value_2nd_min=MAX;
        idx_min=-1;
        idx_2nd_min=-1;
        for(int i=0;i<length;i++){
            //查找最小的和次小的
            if(HTs[i].parent==-1){
                if(HTs[i].weight<=value_min){
                    value_2nd_min=value_min;
                    idx_2nd_min=idx_min;

                    value_min=HTs[i].weight;
                    idx_min=i;
                }else if(HTs[i].weight>value_min&&HTs[i].weight<value_2nd_min){
                    value_2nd_min=HTs[i].weight;
                    idx_2nd_min=i;
                }
            }
        }
        int noparentcount=0;
        for(int i=0;i<length;i++){
            if(HTs[i].parent==-1){
                noparentcount++;
            }
        }
        if(noparentcount==1){
            break;
        }
        

        //建新树
        HuffmanTreeNode *newParentNode=(HuffmanTreeNode *)malloc(sizeof(HuffmanTreeNode *));
        newParentNode->lchild=idx_min;
        newParentNode->rchild=idx_2nd_min;
        newParentNode->weight=HTs[idx_min].weight+HTs[idx_2nd_min].weight;
        newParentNode->parent=-1;

        // std::cout<<"new:"<<newParentNode->weight<<" "<<idx_min<<":"<<HTs[idx_min].weight<<" "<<idx_2nd_min<<":"<<HTs[idx_2nd_min].weight<<std::endl;

        HTs[idx_min].parent=length;
        HTs[idx_2nd_min].parent=length;

        HTs[length]=*newParentNode;
        length++;
    }

    // for(int i=0;i<length;i++){
    //     std::cout<<"i:"<<i<<" w:"<<HTs[i].weight<<" p:"<<HTs[i].parent<<" lc:"<<HTs[i].lchild<<" rc:"<<HTs[i].rchild<<" v:"<<HTs[i].value<<std::endl;
    // }
}

int path[100];

void findPath(char c,int crt,int pathLen){
    if(HTs[crt].lchild==-1&&HTs[crt].rchild==-1){//叶子
        if(HTs[crt].value==c){
            for(int i=0;i<pathLen;i++){
                std::cout<<path[i];
            }
        }else{
            return;
        }
    }else{
        path[pathLen]=0;
        findPath(c,HTs[crt].lchild,pathLen+1);
        path[pathLen]=1;
        findPath(c,HTs[crt].rchild,pathLen+1);
    }
}

void encode(){
    char ch=0;
    while(1){
        ch=getchar();
        if(ch==' '){
            continue;
        }
        if(ch=='\n'){
            break;
        }
        findPath(ch,length-1,0);
    }
}

void decode(){
    char ch=0;
    int pointer=length-1,direction=0;
    while(1){
        ch=getchar();
        if(ch==' '){
            continue;
        }
        if(ch=='\n'){
            break;
        }
        direction=ch-'0';
        if(direction==0){
            if(HTs[HTs[pointer].lchild].lchild==-1 && HTs[HTs[pointer].lchild].rchild==-1){//左节点是叶子
                std::cout<<HTs[HTs[pointer].lchild].value;
                pointer=length-1;
            }else{//左节点不是叶子
                pointer=HTs[pointer].lchild;
            }
        }else{
            if(HTs[HTs[pointer].rchild].lchild==-1 && HTs[HTs[pointer].rchild].rchild==-1){//右节点是叶子
                std::cout<<HTs[HTs[pointer].rchild].value;
                pointer=length-1;
            }else{//右节点不是叶子
                pointer=HTs[pointer].rchild;
            }
        }
    }
}

int main(){
    int Q,T;
    std::cin>>Q;

    for(int i=0;i<Q;i++){
        std::cin>>T;
        switch(T){
            case 0:{
                createHuffmanTree();
                break;
            }
            case 1:{
                encode();
                std::cout<<std::endl;
                break;
            }
            case 2:{
                decode();
                std::cout<<std::endl;
                break;
            }
        }
    }
}