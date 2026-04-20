#include<iostream>
#define MAX 10
#define INF 99999
using namespace std;
int n;

// Function to reduce matrix and return reduction cost
int reduceMatrix(int mat[MAX][MAX]) {
    int rowMin, colMin, cost = 0;

    // Row reduction
    for (int i = 0; i < n; i++) {
        rowMin = INF;
        for (int j = 0; j < n; j++)
            if (mat[i][j] < rowMin)
                rowMin = mat[i][j];

        if (rowMin != INF && rowMin != 0) {
            cost += rowMin;
            for (int j = 0; j < n; j++)
                if (mat[i][j] != INF)
                    mat[i][j] -= rowMin;
        }
    }

    // Column reduction
    for (int j = 0; j < n; j++) {
        colMin = INF;
        for (int i = 0; i < n; i++)
            if (mat[i][j] < colMin)
                colMin = mat[i][j];

        if (colMin != INF && colMin != 0) {
            cost += colMin;
            for (int i = 0; i < n; i++)
                if (mat[i][j] != INF)
                    mat[i][j] -= colMin;
        }
    }

    return cost;
}

// Copy matrix
void copyMatrix(int src[MAX][MAX], int dest[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dest[i][j] = src[i][j];
}

// Solve TSP (simplified greedy + reduction)
void tsp(int mat[MAX][MAX]) {
    int cost = 0;
    int visited[MAX] = {0};
    int path[MAX + 1];

    int curr = 0;
    path[0] = 0;
    visited[0] = 1;

    int temp[MAX][MAX];
    copyMatrix(mat, temp);

    cost += reduceMatrix(temp);

    for (int step = 1; step < n; step++) {

        int next = -1, minCost = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && temp[curr][j] < minCost) {
                minCost = temp[curr][j];
                next = j;
            }
        }

        path[step] = next;
        visited[next] = 1;

        // Set row & column to INF
        for (int j = 0; j < n; j++)
            temp[curr][j] = INF;
        for (int i = 0; i < n; i++)
            temp[i][next] = INF;

        temp[next][0] = INF;

        cost += minCost;
        cost += reduceMatrix(temp);

        curr = next;
    }

    path[n] = 0;

    cout<<"\nApprox Minimum Cost:"; cout<< cost;
    cout<<"\nPath: ";
    for (int i = 0; i <= n; i++)
        cout<<path[i]<<"-";
        cout<<"\n";
}

int main() {
    int mat[MAX][MAX];

    cout<<"Enter number of cities: ";
    cin>>n;

    cout<<"Enter cost matrix (use  INF for large values):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>mat[i][j];

    tsp(mat);

    return 0;
}