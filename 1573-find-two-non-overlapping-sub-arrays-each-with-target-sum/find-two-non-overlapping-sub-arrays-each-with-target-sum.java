class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int INF = 1000000;

        // best[i] = minimum length of a valid subarray
        // completely inside indices 0 to i
        int[] best = new int[n];

        for (int i = 0; i < n; i++) {
            best[i] = INF;
        }

        int ans = INF;
        int minLen = INF;

        int left = 0;
        int sum = 0;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window if sum becomes greater than target
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            // If current subarray has target sum
            if (sum == target) {
                int len = right - left + 1;

                // Check if there is a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INF) {
                    ans = Math.min(ans, len + best[left - 1]);
                }

                // Store the shortest valid subarray ending at/before right
                minLen = Math.min(minLen, len);
            }

            // Carry forward the best answer
            best[right] = minLen;
        }

        return ans == INF ? -1 : ans;
    }
}