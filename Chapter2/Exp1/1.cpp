// 1. 实验二：二叉树的创建与遍历
// 解题思路:
// 深度优先搜索
#include <iostream>
#include <malloc.h>

using namespace std;
struct CPNode {
    char value;
    CPNode *left,*right;
};
CPNode *CreateTree(CPNode *root){
    char ch;
    cin>>ch;
    if(ch=='#') root=NULL;
    else{
        root=(CPNode *)malloc(sizeof(CPNode));
        root->value=ch;
        root->left=CreateTree(root->left);
        root->right=CreateTree(root->right);
    }
    return root;
}

void PreOrderTree(CPNode *root){
    if(root!=NULL){
        cout<<root->value;
        PreOrderTree(root->left);
        PreOrderTree(root->right);
    }
}

void InOrderTree(CPNode *root){
    if(root!=NULL){
        InOrderTree(root->left);
        cout<<root->value;
        InOrderTree(root->right);
    }
}

void LaOrderTree(CPNode *root){
    if(root!=NULL){
        LaOrderTree(root->left);
        LaOrderTree(root->right);
        cout<<root->value;
    }
}

int main(){
    CPNode *root;
    root=CreateTree(root);
    PreOrderTree(root);
    cout<<endl;
    InOrderTree(root);
    cout<<endl;
    LaOrderTree(root);
    cout<<endl;
    return 0;
}