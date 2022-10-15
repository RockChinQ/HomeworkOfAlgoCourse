// 2. 实验二：求二叉树中节点的路径
// 解题思路:
// 使用深度优先,通过一个数组path,其x下标元素对应路径中在树中第x层的元素
// 找到目标元素后,输出path中已存的所有元素
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

void findPath(CPNode *root,char *path,int pathLen,char target){
    if(root==NULL) return;
    path[pathLen++]=root->value;
    if(root->value==target){
        for(int i=0;i<pathLen;i++)
            cout<<path[i];
        cout<<endl;
    }
    findPath(root->left,path,pathLen,target);
    findPath(root->right,path,pathLen,target);
}

int main(){
    CPNode *root;
    root=CreateTree(root);
    char target;
    cin>>target;

    char path[100];
    findPath(root,path,0,target);

    return 0;
}