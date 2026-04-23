#include <iostream>
using namespace std;
const int maxvertex=20, maxval=999;
struct graph{int v1,v2,wt;};
int parent[maxvertex];
int d[maxvertex];
int n;

void bellman(graph edges[maxvertex] , int ne, int nv , int source)
{
    int u,v,i,temp=1,flag; char x;
    d[source]=0;
    parent[source]=-1;
    while(temp<nv){
        flag=0;
        for(i=0;i<ne;i++){
            u=edges[i].v1;
            v=edges[i].v2;
            if(d[u]!= maxval && (d[u]+edges[i].wt)<d[v]){
                d[v]=d[u]+edges[i].wt;
                parent[v]=u;
                flag=1;
            }
        }
        
        cout<<"\n-------------- Iteration number: "<<temp<<endl;
        cout<<"vertex number ------ distance------parent\n";
        for(i=0;i<n;i++)
            cout<<"   "<<i<<"                   "<<d[i]<<"                  "<<parent[i]<<endl;
            cout<<"press any 1 to display next iteration \n ";cin>>x;
            temp++;
    }
    for(i = 0; i < ne; i++)
    {
        u = edges[i].v1;
        v = edges[i].v2;

    if(d[u] != maxval && d[u] + edges[i].wt < d[v])
        {
            cout << "Negative cycle exists\n";
            return;
        }
    
    }
    
}
int main()
{
    int G[maxvertex][maxvertex]={
      {0,4,5,0},
      {0,0,-2,4},
      {0,0,0,3},
      {0,0,0,0}
    };
    graph ingraph[100];
    int i,j,k=0;n=4;
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       if(G[i][j]!=0) { 
           ingraph[k].v1=i; 
           ingraph[k].v2=j; 
           ingraph[k].wt=G[i][j];
           k++;
       }
     
    
     for(i=0;i<k;i++)
     cout<<ingraph[i].v1<<"-"<<ingraph[i].v2<<"--->"<<ingraph[i].wt<<endl;
    
   
   for(i=0;i<n;i++)
   {
       parent[i]=-1;
       d[i]=maxval;
   }
   
   bellman(ingraph,k,n,0);
    return 0;
}