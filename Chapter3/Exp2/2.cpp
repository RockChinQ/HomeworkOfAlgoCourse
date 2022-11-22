// 2. 实验三：教学计划编制问题
/*1）问题描述：软件专业的学生要学习一系列课程，其中有些课程必须在其先修课完成后才能学习。

2）实验要求：假设每门课程的学习时间为一个学期，试为该专业的学生设计教学计划，使他们能在最短时间内修完专业要求的全部课程。

3) 实现提示：

2  以顶点代表课程，弧代表课程的先后修关系，按课程先后关系建立有向无环图。

2  利用拓扑排序实现。*/
#include <iostream>

void PrintGraphMatrix(int n);

int * graphMatrix;

void CreateGraphMatrix(int n, int m)
{
    graphMatrix = new int[n * n];
    for (int i = 0; i < n * n; i++)
    {
        graphMatrix[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graphMatrix[a * n + b] = 1;
    }
}

void TopoPrint(int n){
    // 墓碑
    int * deleted = new int[n];
    int deletedCount=0;
    for (int i = 0; i < n; i++)
    {
        deleted[i] = 0;
    }

    while(1){
        for(int i = 0; i < n; i++){
            if(deleted[i]==0){//还存在的节点
                //检查是否是入度为0的节点
                int j;
                int zero=1;
                for(j = 0; j < n; j++){
                    if(graphMatrix[j*n+i]==1){//入度不为0 
                        zero=0;
                    }
                }
                if(zero==1){
                    //清除本节点的所有出度
                    for(j = 0; j < n; j++){
                        graphMatrix[i*n+j]=0;
                    }
                    deleted[i]=1;
                    deletedCount++;
                    std::cout<<i+1<<" ";
                    break;
                }
            }
        }
        if(deletedCount==n){
            break;
        }
    }
}

void PrintGraphMatrix(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout<<graphMatrix[i*n+j]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int n,m;
    //课程数，关系数
    std::cin >> n >> m;

    CreateGraphMatrix(n,m);

    TopoPrint(n);
}