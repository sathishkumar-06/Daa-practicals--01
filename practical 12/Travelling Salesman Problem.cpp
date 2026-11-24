
#include <iostream>
#include <climits>
using namespace std;

#define N 4

int tsp(int graph[N][N], int pos, int mask,
        int dp[N][1 << N]) {

    // All cities visited
    if (mask == (1 << N) - 1)
        return graph[pos][0];

    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    int ans = INT_MAX;

    for (int city = 0; city < N; city++) {

        // Check if city is not visited
        if ((mask & (1 << city)) == 0) {

            int cost = graph[pos][city] +
                tsp(graph, city, mask | (1 << city), dp);

            if (cost < ans)
                ans = cost;
        }
    }

    return dp[pos][mask] = ans;
}

int main() {

    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[N][1 << N];

    // Initialize DP table
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            dp[i][j] = -1;
        }
    }

    // Start from city 0
    int result = tsp(graph, 0, 1, dp);

    cout << "Minimum cost of Travelling Salesman: "
         << result << endl;

    return 0;
}
