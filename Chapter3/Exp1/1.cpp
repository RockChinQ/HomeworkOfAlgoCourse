#include <iostream>


int * graphV;

int CreateGraph(){
    int n; //节点数量
    std::cin >> n;
    int * graph = new int[n*n];
    int m; //边的数量
    std::cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a;
        std::cin >> b;
        a--;
        b--;
        graph[a*n+b] = 1;
        graph[b*n+a] = 1;
    }
    graphV = graph;
    return n;
}

//深搜
void DFSGraph(int n, int v, int * visited){
    std::cout<<v<<" ";
    visited[v-1]=1;
    //遍历此节点连接的边
    int index=(v-1)*n;
    for(int i=0;i<n;i++){
        if(graphV[index+i]==1){
            if(visited[i]==0){//没走过
                DFSGraph(n,i+1,visited);
            }
        }        
    }
}

void BFSGraph(int * graph,int n){
    int * visited = new int[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int * queue = new int[n];
    int head=0;
    int tail=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            queue[tail]=i+1;
            tail++;
            while(head!=tail){
                int v=queue[head];
                head++;
                if(visited[v-1]==0){
                    std::cout<<v<<" ";
                    visited[v-1]=1;
                    int index=(v-1)*n;
                    for(int i=0;i<n;i++){
                        if(graph[index+i]==1){
                            if(visited[i]==0){//没走过
                                queue[tail]=i+1;
                                tail++;
                            }
                        }        
                    }
                }
            }
        }
    }
}

int main(){
    int n = CreateGraph();
    
    int * visited = new int[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    DFSGraph(n,1,visited);
    std::cout << std::endl;
    BFSGraph(graphV,n);
}