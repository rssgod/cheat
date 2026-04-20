
//Knapsack Dynamic approach
#include <iostream>
using namespace std;
const int maxsize=20; 
int wt[maxsize], profit[20];
int sack_cap;

int findmax(int x,int y){ if(x>y) return x; else return y;}
int main()
{
    int n,i,w,m,t,x; float total_profit;;
    int pm[maxsize][maxsize];
    cout<<"Enter number of objects for Knapsack\n"; cin>>n;
    cout<<"Enter max capacity of Knapsack\n"; cin>>sack_cap;
    cout<<"Ebter Profits of objects\n";
    for(i=1;i<=n;i++) 
    { cout<<" Profit of object --- "<<i<<" --- "; cin>>profit[i];}
    
    cout<<"Ebter weights of objects\n";
    for(i=1;i<=n;i++) 
    { cout<<" Weight of object --- "<<i<<" --- "; cin>>wt[i];}
    
    m=sack_cap;
    for(i=0;i<n+1;i++) pm[i][0]=0;
     for(w=0;w<m+1;w++) pm[0][w]=0;
     
    for(i=1;i<n+1;i++)
     for(w=0;w<m+1;w++)
     {
       t=w-wt[i];
       if(t>=0)
       pm[i][w]=findmax(pm[i-1][w], pm[i-1][t]+profit[i]);
       else
       pm[i][w]=pm[i-1][w];
       
     }
    
    for(i=0;i<n+1;i++)
    { for(w=0;w<m+1;w++)
      cout<<pm[i][w]<<"   ";
      cout<<"\n";
         
    }
    
    //total_profit=knapsack_g(n);
    //cout<<"Total profit="<<total_profit<<endl;
     
    return 0;
}

/*
Output :


Enter number of objects for Knapsack
5
Enter max capacity of Knapsack
7
Ebter Profits of objects
 Profit of object --- 1 --- 50
 Profit of object --- 2 --- 40
 Profit of object --- 3 --- 70
 Profit of object --- 4 --- 80
 Profit of object --- 5 --- 10
Ebter weights of objects
 Weight of object --- 1 --- 3
 Weight of object --- 2 --- 2
 Weight of object --- 3 --- 4
 Weight of object --- 4 --- 5
 Weight of object --- 5 --- 1 
0   0   0   0   0   0   0   0   
0   0   0   50   50   50   50   50
0   0   40   50   50   90   90   90
0   0   40   50   70   90   110   120
0   0   40   50   70   90   110   120
0   10   40   50   70   90   110   120
*/