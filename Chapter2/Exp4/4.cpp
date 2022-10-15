// 4. 实验二：求二叉树高度及宽度
// 解题思路:
// 建立density数组储存每层节点数量,maxLevel变量
// 深度优先遍历树,遍历到一个第x层元素时将density[x]加一,将level与maxLevel比较,较大值赋予maxLevel
// 重复操作直到遍历结束,从density中提取出最大密度
#include <iostream>
#include <malloc.h>

struct CPNode {
    char value;
    CPNode *left,*right;
};

int density[100]={0};
int maxLevel=0;

CPNode *CreateTree(CPNode *root){
    char ch;
    std::cin>>ch;
    if(ch=='#') root=NULL;
    else{
        root=(CPNode *)malloc(sizeof(CPNode));
        root->value=ch;
        root->left=CreateTree(root->left);
        root->right=CreateTree(root->right);
    }
    return root;
}

void DFS(CPNode *root,int level){
    maxLevel=level>maxLevel?level:maxLevel;

    density[level]++;

    if(root->left!=NULL){
        DFS(root->left,level+1);
    }

    if(root->right!=NULL){
        DFS(root->right,level+1);
    }
}

int main(){
    CPNode *root;
    root=CreateTree(root);

    if(root==NULL){
        std::cout<<"0 0";
        return 0;
    }

    DFS(root,1);

    int densityValue=0;
    for(int i=0;i<maxLevel;i++){
        densityValue=density[i]>densityValue?density[i]:densityValue;
    }

    std::cout<<maxLevel<<" "<<densityValue;
    return 0;
}