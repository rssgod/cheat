#include<iostream>
using namespace std;
const int size=50;
int visited[size];

class Queue {
    int front, rear;
    int arr[size];
    public:
    
    Queue(){
        front=rear=-1;
    }
    
    bool empty(){
        if(front==-1 || front>rear)
            return true;
        return false;
    }
    void insert(int x){
        if(rear==size-1){
            cout<<"queue overflow \n";
            return;
        }
        
        if(front==-1)
            front=0;
            
        arr[++rear]=x;
    }
    
    int delitem(){
        if(empty())
            return -1;
        
        return arr[front++];
    }
};

void bfs(int g[size][size], int n, Queue &q){
    if(q.empty())
        return;
        
    int cn= q.delitem();
    
    for(int i=0;i<n;i++){
        if(g[cn][i]==1 && !visited[i]){
            cout<<i<<"\n";
            visited[i]=1;
            q.insert(i);
        }
    }
    bfs(g,n,q);
}

int main(){
    int g[size][size];
    int i,j,start,n;
    
    cout<<"enter no. of edges : \t";
    cin>>n;
    
    cout<<"enter adjecency matrix :\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    for(i=0;i<n;i++){
        visited[i]=0;
    }
    cout<<"start node enter: \t";
    cin>>start;
    
    Queue q;
    q.insert(start);
    visited[start]=1;
    
    cout<<"bfs is : "<<start<<"\n";
    bfs(g,n,q);
    
    return 0;
}
