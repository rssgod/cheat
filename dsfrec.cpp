#include <iostream>
using namespace std;

const int size = 20;
int visited[size];

void dfs(int gr[size][size], int n, int s){
    visited[s] = 1;
    cout << s << " -> ";

    for(int i = 0; i < n; i++){
        if(gr[s][i] == 1 && !visited[i]){
            dfs(gr, n, i);
        }
    }
}

int main()
{
    int gr[size][size];
    int i, j, n, start;

    cout << "Enter no. of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> gr[i][j];
        }
    }

    for(i=0;i<n;i++){
        visited[i] = 0;
    }

    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(gr, n, start);

    return 0;
}
