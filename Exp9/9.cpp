//9. 实验一：迷宫问题
//递归解法,同时用链表存储路径
#include <iostream>
#include <malloc.h>

using namespace std;

/*
@00#20
##00#0
000#00
##000#

4 6
0 1 1 -1 2 1
-1 -1 1 1 -1 1
1 1 1 -1 1 1 
-1 -1 1 1 1 -1
*/

int maze[10][10]={};//-3默认值,-2已扫描

struct PNode {
    int x,y;
    PNode *next;
};

PNode *path=(PNode *)malloc(sizeof(PNode)),*workp;

int scan(int x,int y){
    maze[y][x]=-2;//把当前走的格子标记为-2
    for(int i=y-1<0?0:y-1;i<=(y+1>9?9:y+1);i++){//确定y范围
        for(int j=x-1<0?0:x-1;j<=(x+1>9?9:x+1);j++){//确定x范围
            if((i==y&&j==x)||(i==y-1&&j==x-1)||(i==y+1&&j==x-1)||(i==y-1&&j==x+1)||(i==y+1&&j==x+1)){//不走对角
                continue;
            }else if(maze[i][j]==2){//终点
                return 1;
            }else if(maze[i][j]==1){//可走路径
                int result=scan(j,i);
                if(result){//可用路径,添加到链表起点节点后一个
                    PNode *temp=(PNode *)malloc(sizeof(PNode));
                    temp->x=j;
                    temp->y=i;
                    temp->next=workp->next;

                    workp->next=temp;
                    return result;
                }
            }
        }
    }
    return 0;
}

int main(){
    int w,h;
    cin>>h>>w;//输入迷宫长宽

    int sx=0,sy=0,ex=0,ey=0;

    //!!!i是纵向遍历元,j是横向遍历元!!!!
    for(int i=0;i<10;i++){//每个格子的内容
        for(int j=0;j<10;j++){
            if(i<h&&j<w){
                cin>>maze[i][j];
                if(maze[i][j]==0){//记录起点坐标
                    sx=j;
                    sy=i;
                }else if(maze[i][j]==2){//记录终点坐标
                    ex=j;
                    ey=i;
                }
            }else{
                maze[i][j]=-3;
            }
        }
    }

    PNode *start=(PNode *)malloc(sizeof(PNode));
    start->x=sx;
    start->y=sy;
    start->next=NULL;

    //start起点节点,其之后的节点都是栈节点
    path->next=start;
    workp=start;

    int result=scan(sx,sy);

    //输出结果
    if(result){
        cout<<"YES"<<endl;
        PNode *work=path->next;
        while(work!=NULL){
            cout<<"("<<work->y<<","<<work->x<<")->";
            work=work->next;
        }
        cout<<"("<<ey<<","<<ex<<")"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}