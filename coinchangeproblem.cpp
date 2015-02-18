/********************
Coin change problem
********************/

// Recursive solution
// Returns the count of ways we can sum  S[0...m-1] coins to get sum n
int makeChangesRecursive(int S[], int m, int n) {
    // the sum is 0, only 1 solution
    if (n == 0)
        return 1;
    // the sum is less than 0, no solution
    if (n < 0)
        return 0;
    // the sum is greater than 0, and there is no coin, 0 solution
    if (m <= 0)
        return 0;
    // makeChangesRecursive(S, m - 1, n) is the number of solutions excluding S[m - 1]
    // makeChangesRecursive(S, m, n - S[m - 1]) is the number of solutions including at least 1 S[m - 1]
    return makeChangesRecursive(S, m - 1, n) + makeChangesRecursive(S, m, n - S[m - 1]);
}

// Dynamic programming solution
int makeChangesDP(int S[], int m, int n) {
    // need one more space because we need to store the result for n = 0
    vector<vector<int>> dp;
    for (int i = 0; i <= n; i++) {
        vector<int> row(m, 0);
        dp.push_back(row);
    }
    for (int i = 0; i < m; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int excluding = j >= 1? dp[i][j - 1]: 0;
            int including = i - S[j] >= 0? dp[i - S[j]][j]: 0;
            dp[i][j] = excluding + including;
        }
    }
    return dp[n][m - 1];
}

// Space optimized dp solution
int makeChangesOptSpace(int S[], int m, int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = S[i]; j <= n; j++)
            dp[j] += dp[j - S[i]];
    }
    return dp[n];
}

// Find the minimum number of coins
int minimumChange(int S[], int m, int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    int minimum = INT_MAX;
    for (int i = 1; i <= n; i++) {
        minimum = i;
        for (int j = 0; j < m; j++) {
            if (i >= S[j]) {
                minimum = std::min(minimum, dp[i - S[j]] + 1);
            }
        }
        dp[i] = minimum;
    }
    return dp[n];
}