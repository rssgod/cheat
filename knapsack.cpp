#include<iostream>
using namespace std;
float pro_bywt[100];
float profit[100];
float wt[100];
int stack_cap;
int n;
void sort(int n)
{
    float temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(pro_bywt[j+1]>pro_bywt[j])
            {
                temp=pro_bywt[j];
                pro_bywt[j]=pro_bywt[j+1];
                pro_bywt[j+1]=temp;

                temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;

                temp=wt[j];
                wt[j]=wt[j+1];
                wt[j+1]=temp;
            }
        }
    }
}
float knapsack()
{
    int temp_stack=stack_cap;
    float prof=0;
    for(int i=0;i<n;i++)
    {
        if(temp_stack>0 && wt[i]<=temp_stack)
        {
            prof=prof+profit[i];
            temp_stack=temp_stack-wt[i];
        }
        else
        {
            prof=prof+profit[i] * (temp_stack/wt[i]);
            break;
        }
    }
    return prof;
    
}
int main()
{
    float total_profit;
    cout<<"Enter Number of object you want:";
    cin>>n;
    cout<<"Enter Stack Capacity:"<<endl;
    cin>>stack_cap;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Profit for object "<<i<<endl;
        cin>>profit[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Weight for object "<<i<<endl;
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        pro_bywt[i]=profit[i]/wt[i];
    }
    sort(n);
    for (int i = 0; i < n; i++)
    {
        cout<<"Object "<<i<<endl;
        cout<<"Profit: "<<profit[i]<<endl;
        cout<<"Weight: "<<wt[i]<<endl;
    }
    total_profit=knapsack();
    cout<<"total Profit:"<<total_profit;
}