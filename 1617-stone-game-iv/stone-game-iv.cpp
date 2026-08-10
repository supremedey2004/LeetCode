class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        // dp[0] = false
        // No stones -> current player cannot move -> loses

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                
                // Remove j*j stones
                // If opponent is in a losing position,
                // current player can win.
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};