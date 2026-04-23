#include<iostream>
#include<climits>
using namespace std;
const int size=20;

int g[size][size];
int key[size];
int visited[size];
int parent[size];

int findmin(int n){
    int min= INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++){
        if(visited[i] == 0 && key[i]<min){
            min=key[i];
            index=i;
        }
    }
    return index;
}

void prim(int n){
    for(int i=0;i<n-1;i++){
        int u= findmin(n);
        visited[u]=1;
        
        for(int j=0;j<n;j++){
            if(g[u][j] && !visited[j] && g[u][j]<key[j]){
                key[j]=g[u][j];
                parent[j]=u;
            }
        }
    }
}
int main(){
    int n;
    cout<<"enter no. of edges :";
    cin>>n;
    
    cout<<"enter the matrix :";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        cin>>g[i][j];
    }
    }
    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        visited[i] =0;
    }
    key[0]=0;
    parent[0]=-1;
    
    prim(n);
    
    cout<<" edges in MST : :";
    int total= 0;
    
    for(int i=1;i<n;i++){
        cout<< parent[i] <<" -- "<<i<< " Weight  "<<g[i][parent[i]]<<endl;
        total+=g[i][parent[i]];
        
    }
   cout<<"total weight : "<<total;
   return 0;
   
}