class Solution {
    fun findLHS(nums: IntArray): Int {
        val freq = HashMap<Int, Int>()

        for (num in nums) {
            freq[num] = freq.getOrDefault(num, 0) + 1
        }

        var ans = 0

        for ((key, value) in freq) {
            if (freq.containsKey(key + 1)) {
                ans = maxOf(ans, value + freq[key + 1]!!)
            }
        }

        return ans
    }
}