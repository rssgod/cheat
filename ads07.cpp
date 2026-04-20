//  Knapsack greedy approach - for fractional knapsack ( can do same code for 0/1 knapsack too )
#include <iostream>
using namespace std;
const int maxsize=20; 
float wt[maxsize], profit[20],pro_byw[maxsize];
float sack_cap;

void sort(int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
     for(j=0;j<n-1-i;j++)
        if(pro_byw[j+1]>pro_byw[j])
         { float t1=pro_byw[j]; pro_byw[j]=pro_byw[j+1];pro_byw[j+1]=t1;
           float t2=wt[j]; wt[j]=wt[j+1];wt[j+1]=t2;
           float t3=profit[j]; profit[j]=profit[j+1];profit[j+1]=t3;
         }
}


float knapsack_g(int n)
{
    float tp=0,temp_cap=sack_cap;
    
    for(int i=0;i<n;i++)
    {
    if(temp_cap>0&&wt[i]<=temp_cap)
      { tp=tp+profit[i];
      temp_cap=temp_cap-wt[i];}
    else
      { tp=tp+profit[i]*(temp_cap/wt[i]);break;}
        
    }
    return tp;
    
}
int main()
{
    int n,i; float total_profit;
    
    cout<<"Enter number of objects for Knapsack\n"; cin>>n;
    cout<<"Enter max capacity of Knapsack\n"; cin>>sack_cap;
    cout<<"Ebter Profits of objects\n";
    for(i=0;i<n;i++) 
    { cout<<" Profit of object --- "<<i<<" --- "; cin>>profit[i];}
    
    cout<<"Enter weights of objects\n";
    for(i=0;i<n;i++) 
    { cout<<" Weight of object --- "<<i<<" --- "; cin>>wt[i];}
    
    // First find all profit/weight ratio
    for(i=0;i<n;i++)
    { pro_byw[i]=profit[i]/wt[i];}
    
    // sort it
    sort(n);
    total_profit=knapsack_g(n);
    cout<<"Total profit="<<total_profit<<endl;
    // Display
   // for(i=0;i<n;i++)
    //{ cout<<pro_byw[i]<<" --- ";cout<<"\n"; cout<<profit[i]<<" --- "; cout<<"\n";cout<<wt[i]<<" --- ";}
    return 0;
}




// 0/1 Knapsack using Dynamic Programming
#include <iostream>
using namespace std;

const int maxsize = 20;

int wt[maxsize], profit[maxsize];
int sack_cap;

int findmax(int x, int y) {
    return (x > y) ? x : y;
}

int main() {
    int n, i, w;
    int pm[maxsize][maxsize];

    cout << "Enter number of objects for Knapsack: ";
    cin >> n;

    cout << "Enter max capacity of Knapsack: ";
    cin >> sack_cap;

    cout << "Enter Profits of objects:\n";
    for (i = 1; i <= n; i++) {
        cout << "Profit of object " << i << ": ";
        cin >> profit[i];
    }

    cout << "Enter Weights of objects:\n";
    for (i = 1; i <= n; i++) {
        cout << "Weight of object " << i << ": ";
        cin >> wt[i];
    }

    // Initialize table
    for (i = 0; i <= n; i++)
        pm[i][0] = 0;

    for (w = 0; w <= sack_cap; w++)
        pm[0][w] = 0;

    // Fill DP table
    for (i = 1; i <= n; i++) {
        for (w = 0; w <= sack_cap; w++) {
            int t = w - wt[i];

            if (t >= 0)
                pm[i][w] = findmax(pm[i - 1][w], pm[i - 1][t] + profit[i]);
            else
                pm[i][w] = pm[i - 1][w];
        }
    }

    // Display DP table
    cout << "\nDP Table:\n";
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= sack_cap; w++) {
            cout << pm[i][w] << "\t";
        }
        cout << "\n";
    }

    cout << "\nMaximum Profit = " << pm[n][sack_cap] << endl;

    return 0;
}