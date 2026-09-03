var calculateMinimumHP = function(dungeon) {

    let n = dungeon.length;
    let m = dungeon[0].length;

    let dp = Array.from(
        { length: n },
        () => Array(m).fill(0)
    );

    // Bottom-right cell
    dp[n - 1][m - 1] = Math.max(
        1,
        1 - dungeon[n - 1][m - 1]
    );

    // Last row
    for (let j = m - 2; j >= 0; j--) {
        dp[n - 1][j] = Math.max(
            1,
            dp[n - 1][j + 1] - dungeon[n - 1][j]
        );
    }

    // Last column
    for (let i = n - 2; i >= 0; i--) {
        dp[i][m - 1] = Math.max(
            1,
            dp[i + 1][m - 1] - dungeon[i][m - 1]
        );
    }

    // Remaining cells
    for (let i = n - 2; i >= 0; i--) {
        for (let j = m - 2; j >= 0; j--) {

            let need = Math.min(
                dp[i + 1][j],
                dp[i][j + 1]
            );

            dp[i][j] = Math.max(
                1,
                need - dungeon[i][j]
            );
        }
    }

    return dp[0][0];
};