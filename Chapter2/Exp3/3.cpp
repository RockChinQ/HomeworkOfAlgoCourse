// 3. 实验二：按层次顺序遍历二叉树
// 解题思路:
// 使用广度优先搜索,将root添加到queue数组,遍历queue数组所有元素,将其可用子节点添加到queue
// 重复遍历queue,直到queue没有元素
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

void BFS(CPNode *root,char target){
    cout<<root->value;
    if(root->value==target){
        return;
    }
    CPNode *queue[100];
    int queueLen=0;

    queue[0]=root;
    queueLen++;

    CPNode *tempQueue[100];
    int tempLen=0;

    //把queue中的所有节点的子节点放进queue
    for(;;){
        for(int i=0;i<queueLen;i++){
            if(queue[i]->left!=NULL){
                cout<<queue[i]->left->value;
                if(queue[i]->left->value==target){
                    return;
                }
                tempQueue[tempLen]=queue[i]->left;
                tempLen++;
            }

            if(queue[i]->right!=NULL){
                cout<<queue[i]->right->value;
                if(queue[i]->right->value==target){
                    return;
                }
                tempQueue[tempLen]=queue[i]->right;
                tempLen++;
            }
        }

        if(tempLen==0){
            return;
        }

        queueLen=0;
        //将temp里面的元素拷贝到queue
        for(int i=0;i<tempLen;i++){
            queue[queueLen]=tempQueue[i];
            queueLen++;
        }
        tempLen=0;
    }

}

int main(){
    CPNode *root;
    root=CreateTree(root);

    char target;
    cin>>target;

    BFS(root,target);
    return 0;
}