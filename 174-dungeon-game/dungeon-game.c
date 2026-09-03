int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {

    int n = dungeonSize;
    int m = dungeonColSize[0];

    int dp[n][m];

    // Bottom-right cell
    dp[n - 1][m - 1] =
        (1 - dungeon[n - 1][m - 1] > 1)
        ? 1 - dungeon[n - 1][m - 1]
        : 1;

    // Last row
    for (int j = m - 2; j >= 0; j--) {
        int need = dp[n - 1][j + 1] - dungeon[n - 1][j];

        dp[n - 1][j] = (need > 1) ? need : 1;
    }

    // Last column
    for (int i = n - 2; i >= 0; i--) {
        int need = dp[i + 1][m - 1] - dungeon[i][m - 1];

        dp[i][m - 1] = (need > 1) ? need : 1;
    }

    // Remaining cells
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {

            // Choose the path requiring less health
            int need = (dp[i + 1][j] < dp[i][j + 1])
                       ? dp[i + 1][j]
                       : dp[i][j + 1];

            need = need - dungeon[i][j];

            dp[i][j] = (need > 1) ? need : 1;
        }
    }

    return dp[0][0];
}