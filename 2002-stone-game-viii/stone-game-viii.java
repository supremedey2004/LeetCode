class Solution {
    public int stoneGameVIII(int[] stones) {

        int n = stones.length;

        // Prefix sum
        long[] prefix = new long[n];

        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // If Alice takes all stones
        long dp = prefix[n - 1];

        // Try taking first i+1 stones
        for (int i = n - 2; i >= 1; i--) {
            dp = Math.max(dp, prefix[i] - dp);
        }

        return (int) dp;
    }
}