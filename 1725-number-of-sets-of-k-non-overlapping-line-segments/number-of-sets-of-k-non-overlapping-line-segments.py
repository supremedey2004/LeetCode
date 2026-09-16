class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        MOD = 10**9 + 7

        # dp[i][j] = number of ways to draw j segments
        # using points 0 to i
        dp = [[0] * (k + 1) for _ in range(n)]

        # 0 segments -> 1 way
        for i in range(n):
            dp[i][0] = 1

        for j in range(1, k + 1):
            prefix = 0

            for i in range(1, n):
                # Add ways from dp[i-1][j-1]
                prefix = (prefix + dp[i - 1][j - 1]) % MOD

                # Either don't use point i,
                # or finish a segment at point i
                dp[i][j] = (dp[i - 1][j] + prefix) % MOD

        return dp[n - 1][k]