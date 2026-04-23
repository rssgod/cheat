#include <iostream>
#include <limits.h>
#define MAX 20
using namespace std;

int n;
int dist[MAX][MAX] = {
    {0 ,10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0 }
};

int dp[1 << 20][20];

int tsp(int mask, int pos) {

    // Base case: all cities visited
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    // Memoization check
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // Try all unvisited cities
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] +
                         tsp(mask | (1 << city), city);

            ans = min(ans, newAns);
            cout<<city<<"-----"<<ans<<"\t";
        }
    }

    return dp[mask][pos] = ans;
}

int main() {

    n = 4;

    // Initialize DP table
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    int result = tsp(1, 0);

    cout << "Minimum Traveling Cost: " << result << endl;

    return 0;
}