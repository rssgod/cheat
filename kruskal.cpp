#include <iostream>
using namespace std;

struct edge
{
    int v1, v2;
    int weight;
};

const int SIZE = 100;

edge g[SIZE];
int parent[SIZE];

// Find function
int find_set(int k)
{
    while (parent[k] != k) 
    {
        k = parent[k]; 
    }
    return k;
}

// Union function
void union_set(int i, int j)
{
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

int main()
{
    int n, ne;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> ne;

    // Input edges
    for (int i = 0; i < ne; i++)
    {
        cout << "Enter vertex1 vertex2 weight: ";
        cin >> g[i].v1 >> g[i].v2 >> g[i].weight;
    }

    // Initialize parent array (Make_Set)
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Bubble Sort on weight
    for (int i = 0; i < ne - 1; i++)
    {
        for (int j = 0; j < ne - i - 1; j++)
        {
            if (g[j].weight > g[j + 1].weight)
            {
                edge temp = g[j];
                g[j] = g[j + 1];
                g[j + 1] = temp;
            }
        }
    }

    cout << "\nEdges in MST:\n";

    int count = 0;

    // Kruskal logic
    for (int i = 0; i < ne; i++)
    {
        int x = find_set(g[i].v1);
        int y = find_set(g[i].v2);

        if (x != y)
        {
            cout << g[i].v1 << " - "
                 << g[i].v2 << " : "
                 << g[i].weight << endl;

            union_set(x, y);
        }
    }

    return 0;
}