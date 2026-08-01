#define MOD 1000000007

int rearrangeSticks(int n, int k) {
    long long dp[k + 1];

    for (int i = 0; i <= k; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        int limit = (i < k) ? i : k;

        for (int j = limit; j >= 1; j--) {
            dp[j] = (dp[j - 1] + (long long)(i - 1) * dp[j]) % MOD;
        }

        dp[0] = 0;
    }

    return (int)dp[k];
}