#include "tsm.h"
string Traveling(int G[20][20], int n, char startNode) {
    int startIndex = vertexIndex(startNode);
    int maxs = 1 << n; // Shift left, maximum number of subsets (2^n)

    // Initialize dynamic programming table dp with appropriate initial values
    vector<vector<pair<int, string>>> dp(maxs, vector<pair<int, string>>(n, {INF, ""}));
    dp[1 << startIndex][startIndex] = {0, string(1, startNode)}; // Path containing just the start node

    for (int s = 1; s < maxs; s++) {
        // Skip subsets that do not include the chosen start node
        if (!(s & (1 << startIndex))) continue;
        
        for (int cur = 0; cur < n; cur++) {
            // Skip if cur is already in subset s
            if (s & (1 << cur)) continue;
            
            for (int prev = 0; prev < n; prev++) {
                if (prev == cur || !(s & (1 << prev)) || G[prev][cur] == 0) continue;
                
                auto& mindis = dp[s | (1 << cur)][cur];
                if (dp[s][prev].first + G[prev][cur] < mindis.first) {
                    mindis = {dp[s][prev].first + G[prev][cur], dp[s][prev].second + " " + (char)('A' + cur)};
                }
            }
        }
    }

    // Complete the cycle by returning to the chosen startNode
    int minCost = INF;
    string minPath = "";
    for (int end = 0; end < n; end++) {
        if (dp[maxs - 1][end].first + G[end][startIndex] < minCost && G[end][startIndex] != 0) {
            minCost = dp[maxs - 1][end].first + G[end][startIndex];
            minPath = dp[maxs - 1][end].second + " " + startNode; 
        }
    }
    
    if (minCost == INF) {
        return "No valid path exists";
    }
    cout << "The cost of shortest path(TSM): ";
    cout << minCost << endl;
    return minPath;
}