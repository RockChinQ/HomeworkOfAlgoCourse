// 线索化二叉树学习
#include <iostream>
#include <malloc.h>
#define null NULL

struct CPNode {
    char value;
    CPNode *left,*right;
    int ltag=-1,rtag=-1;
};

CPNode *CreateTree(CPNode *root){
    char ch;
    std::cin>>ch;
    if(ch=='#') root=NULL;
    else{
        root=(CPNode *)malloc(sizeof(CPNode));
        root->value=ch;
        root->left=CreateTree(root->left);
        if(root->left!=NULL){
            root->ltag=0;
        }
        root->right=CreateTree(root->right);
        if(root->right!=NULL){
            root->rtag=0;
        }
    }
    return root;
}

void InThreading(CPNode *node);

CPNode *pre;

CPNode *InOrderThreading(CPNode *raw){
    // 线索化二叉树的root节点
    CPNode *root=(CPNode *)malloc(sizeof(CPNode *));
    root->right=root;
    root->rtag=1;

    if(!raw){
        root->left=root;
        return root;
    }

    root->left=raw;
    root->ltag=0;

    pre=root;

    // 进行中序遍历并线索化
    InThreading(raw);

    pre->right=root;
    pre->rtag=1;
    root->right=pre;

    return root;
}

void InThreading(CPNode *node){
    if(node){
        InThreading(node->left);

        if(!node->left){
            node->ltag=1;
            node->left=pre;

            std::cout<<node->value<<" left"<<std::endl;
        }

        if(!node->right){
            pre->rtag=1;
            pre->right=node;
            std::cout<<node->value<<" right"<<std::endl;
        }

        pre=node;
        InThreading(node->right);
    }
}

int main(){
    CPNode *raw;
    raw=CreateTree(raw);

    CPNode *threadedBiTree=InOrderThreading(raw);
    std::cout<<"done"<<std::endl;

    return 0;
    
}