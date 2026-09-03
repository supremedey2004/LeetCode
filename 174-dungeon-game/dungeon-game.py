class Solution:
    def calculateMinimumHP(self, dungeon):

        n = len(dungeon)
        m = len(dungeon[0])

        dp = [[0] * m for _ in range(n)]

        # Bottom-right cell
        dp[n - 1][m - 1] = max(
            1,
            1 - dungeon[n - 1][m - 1]
        )

        # Last row
        for j in range(m - 2, -1, -1):
            dp[n - 1][j] = max(
                1,
                dp[n - 1][j + 1] - dungeon[n - 1][j]
            )

        # Last column
        for i in range(n - 2, -1, -1):
            dp[i][m - 1] = max(
                1,
                dp[i + 1][m - 1] - dungeon[i][m - 1]
            )

        # Remaining cells
        for i in range(n - 2, -1, -1):
            for j in range(m - 2, -1, -1):

                need = min(
                    dp[i + 1][j],
                    dp[i][j + 1]
                )

                dp[i][j] = max(
                    1,
                    need - dungeon[i][j]
                )

        return dp[0][0]