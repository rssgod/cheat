#include <iostream>
using namespace std;

const int N = 20;
const int INF = 1e9;   // safer infinity value

int cost[N][N] = {
    {0, 3, INF, 7},
    {8, 0, 2, INF},
    {5, INF, 0, 1},
    {2, INF, INF, 0}
};

// Floyd–Warshall function
void floydWarshall(int n)
{
    for (int k = 0; k < n; k++)          // intermediate vertex
    {
        for (int i = 0; i < n; i++)      // source
        {
            for (int j = 0; j < n; j++)  // destination
            {
                // avoid overflow / invalid paths
                if (cost[i][k] != INF && cost[k][j] != INF)
                {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }
}

// Function to display matrix
void printMatrix(int n)
{
    cout << "\nShortest path matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] == INF)
                cout << "INF ";
            else
                cout << cost[i][j] << "   ";
        }
        cout << endl;
    }
}

// Check negative cycle
void detectNegativeCycle(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (cost[i][i] < 0)
        {
            cout << "\nNegative cycle detected!\n";
            return;
        }
    }
    cout << "\nNo negative cycle.\n";
}

int main()
{
    int n = 4;

    floydWarshall(n);
    printMatrix(n);
    detectNegativeCycle(n);

    return 0;
}