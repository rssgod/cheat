#include<iostream>
using namespace std;
const int maxsize=20;
struct node { int level, node_wt, node_profit, node_bound;};
int wt[maxsize],profit[maxsize];

class Que
{
    node a[maxsize];
    int r,f;
    public: Que(){r=f=0;}
    void insert(node x) { a[r++]=x; }
    node delq() { return a[f++];}
    int empty(){ return f==r;}

};

float find_bound(node u,int n,int M)
{
    
    if (u.node_wt >= M)
    return 0;
    
    float ubound=u.node_profit;
    int j=u.level+1;
    
    int total_wt=u.node_wt;
    
    while(j<n&& total_wt+wt[j]<=M)
    { total_wt=total_wt+wt[j]; ubound=ubound+profit[j]; j++;}
    
    if(j<n)
    ubound=ubound+(M-total_wt)*((float)profit[j]/wt[j]);
    cout<<ubound<<endl;
    return ubound;
    
}

float knapsack_bb(int n, int M)
{
    node u,v;
    float maxp=0;
    Que q;
    
    u.level=-1; u.node_wt=u.node_profit=0;
    u.node_bound=find_bound(u,n,M);
    q.insert(u);
    
    while(!q.empty())
    {
        u=q.delq();
        
        if(u.level==n-1) continue;
        
        v.level=u.level+1;
        v.node_wt=u.node_wt+wt[v.level];
        v.node_profit=u.node_profit+profit[v.level];
        
        if(v.node_wt<=M&&v.node_profit>maxp)
        maxp=v.node_profit;
        v.node_bound=find_bound(v,n,M);
        if(v.node_bound>maxp)
        q.insert(v);
        
        v.node_wt=u.node_wt;
        v.node_profit=u.node_profit;
        
        v.node_bound=find_bound(v,n,M);
        if(v.node_bound>maxp)
        q.insert(v);
        
    }
    return maxp;
}


int main()
{
    wt[0]=7; wt[1]=5;wt[2]= 4; wt[3]= 2;
    profit[0]=28; profit[1]=30; profit[2]=20;profit[3]= 24;
    int n=4, M=12;
    float maxp=knapsack_bb(n,M);
    cout<<"Max profit="<<maxp;
}
