#include <iostream>
#include <string>
using namespace std;

const int N = 20, MAX = 9999;

int visited[N], parent[N], d[N];
int cost[N][N];
string landmark[N];

// Function declarations
void dijkstra(int n, int source);
void printPath(int j);
int findMin(int n);

int main()
{
    int n, source;

    cout << "Enter number of landmarks (vertices): ";
    cin >> n;

    // Input landmark names
    cout << "Enter landmark names:\n";
    for (int i = 0; i < n; i++)
        cin >> landmark[i];

    // Input adjacency matrix
    cout << "\nEnter adjacency matrix (0 if no direct path):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    // Display matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << cost[i][j] << "\t";
        cout << "\n";
    }

    cout << "\nEnter source landmark index: ";
    cin >> source;

    dijkstra(n, source);

    return 0;
}

// Print path using recursion
void printPath(int j)
{
    if (j == -1)
        return;

    printPath(parent[j]);
    cout << landmark[j] << " -> ";
}

// Find minimum distance vertex
int findMin(int n)
{
    int min = MAX, pos = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && d[i] < min)
        {
            min = d[i];
            pos = i;
        }
    }
    return pos;
}

// Dijkstra Algorithm
void dijkstra(int n, int source)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        visited[i] = 0;
        d[i] = MAX;
    }

    d[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int u = findMin(n);
        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && cost[u][v] != 0 &&
                d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    // Output shortest paths
    cout << "\nShortest Paths:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "From " << landmark[source] << " to " << landmark[i] << ":\n";

        if (i != source)
        {
            printPath(i);
            cout << "Cost = " << d[i];
        }
        else
        {
            cout << "Same location (Cost = 0)";
        }
        cout << "\n\n";
    }
}