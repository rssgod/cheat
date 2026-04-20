//Pr 8. Write a program to implement Bellman-Ford Algorithm using Dynamic Programming and 
//verify the time complexity


#include <iostream>
using namespace std;
const int maxvertex=20, maxval=999;

struct graph{int v1,v2,wt;};
int parent[maxvertex];
int d[maxvertex];
int n;

void bellman_ford(graph edges[maxvertex],int ne,int nv,int source)
{
    int u,v,i,temp=1,flag; char x;
    d[source]=0;parent[source]=-1 ;
    while(temp<nv)
    {
        flag=0;
        for(i=0;i<ne;i++)
        {
            u=edges[i].v1; v=edges[i].v2; 
            if((d[u]+edges[i].wt)<d[v])
            {

                d[v]=d[u]+edges[i].wt; parent[v]=u; flag=1;
                
            }
        }

        cout<<"\n------------------ Iteration No: "<<temp<<endl;
        cout<<"vertex no. --- distance --- parent\n";
        for(i=0;i<n;i++)
         cout<<"    "<<i<<"          "<<d[i]<<"             "<<parent[i]<<endl;
         cout<<"Press any 1 to display next iteration\n";cin>>x;
         temp++;
    }
    if(flag==1)
    cout<<" The algorithm does not converge\n";
}

int main()
{

    int G[maxvertex][maxvertex] = {
        {  0,6,4,5,0,0, },
        {  0,0,0,0,-1,0  },
        {  0,-2,0,0,3,0,  },
        {  0,0,-2,0,0,-1 },
        {  0,0,0,0,0,3 },
        {  0,0,0,0,0,0, }
    };
    graph ingraph[100];
    int i,j,k=0;n=6;
    for(i=0;i<n;i++)
     for(j=0;j<n;j++)
       if(G[i][j]!=0) { ingraph[k].v1=i; ingraph[k].v2=j; ingraph[k].wt=G[i][j];k++;}
     
    
    for(i=0;i<k;i++)
    cout<<ingraph[i].v1<<"-"<<ingraph[i].v2<<"--->"<<ingraph[i].wt<<endl;
    
   
   for(i=0;i<n;i++)
   {
       parent[i]=-1;d[i]=maxval;
   }
   
   bellman_ford(ingraph,k,n,1);
   return 0;
}


/*
Output:


PS D:\ADS Exam> cd "d:\ADS Exam\" ; if ($?) { g++ bellman_ford.cpp -o bellman_ford } ; if ($?) { .\bellman_ford }
0-1--->6
0-2--->4
0-3--->5
1-4--->-1
2-1--->-2
2-4--->3
3-2--->-2
3-5--->-1
4-5--->3

------------------ Iteration No: 1
vertex no. --- distance --- parent
    0          0             -1
    1          2             2
    2          3             3
    3          5             0
    4          5             1
    5          4             3
Press any 1 to display next iteration
1

------------------ Iteration No: 2
vertex no. --- distance --- parent
    0          0             -1
    1          1             2
    2          3             3
    3          5             0
    4          1             1
    5          4             3
Press any 1 to display next iteration
1

------------------ Iteration No: 3
vertex no. --- distance --- parent
    0          0             -1
    1          1             2
    2          3             3
    3          5             0
    4          0             1
    5          3             4
Press any 1 to display next iteration
1

------------------ Iteration No: 4
vertex no. --- distance --- parent
    0          0             -1
    1          1             2
    2          3             3
    3          5             0
    4          0             1
    5          3             4
Press any 1 to display next iteration
1

------------------ Iteration No: 5
vertex no. --- distance --- parent
    0          0             -1
    1          1             2
    2          3             3
    3          5             0
    4          0             1
    5          3             4
Press any 1 to display next iteration
1
*/
