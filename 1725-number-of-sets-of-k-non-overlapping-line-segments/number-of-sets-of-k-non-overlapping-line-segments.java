class Solution {
    public int numberOfSets(int n, int k) {
        long MOD = 1000000007;

        // dp[i][j] = number of ways to draw j segments
        // using points 0 to i
        long[][] dp = new long[n][k + 1];

        // 0 segments can always be made in 1 way
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 1; j <= k; j++) {

            long prefix = 0;

            for (int i = 1; i < n; i++) {

                // Add ways from dp[i-1][j-1]
                prefix = (prefix + dp[i - 1][j - 1]) % MOD;

                // Don't use point i OR finish a segment at i
                dp[i][j] = (dp[i - 1][j] + prefix) % MOD;
            }
        }

        return (int) dp[n - 1][k];
    }
}