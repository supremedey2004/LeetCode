class Solution {
    fun rearrangeSticks(n: Int, k: Int): Int {
        val MOD = 1_000_000_007L
        val dp = LongArray(k + 1)
        dp[0] = 1L

        for (i in 1..n) {
            val limit = minOf(i, k)
            for (j in limit downTo 1) {
                dp[j] = (dp[j - 1] + (i - 1).toLong() * dp[j]) % MOD
            }
            dp[0] = 0L
        }

        return dp[k].toInt()
    }
}