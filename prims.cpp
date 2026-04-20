#include<iostream>
using namespace std;

int main()
{
    int key[100], parent[100];
    bool min_arr[100];

    int n = 5;

    // example adjacency matrix
    int adjancency_list[5][5] =
    {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    // initialize
    for(int i=0;i<n;i++)
    {
        key[i] = 999;
        min_arr[i] = false;   
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count=0;count<n-1;count++)
    {
        int min = 999;
        int u;

        // find minimum key vertex
        for(int i=0;i<n;i++)
        {
            if(!min_arr[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        min_arr[u] = true;

        // update keys
        for(int i=0;i<n;i++)
        {
            if(adjancency_list[u][i] != 0 && !min_arr[i] && adjancency_list[u][i] < key[i])
            {
                key[i] = adjancency_list[u][i];
                parent[i] = u;
            }
        }
    }

    cout<<"Edge   Weight\n";
    for(int i=1;i<n;i++)
    {
        cout << parent[i] << " - " << i << "    " 
             << key[i] << endl;
    }

    return 0;
}