import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int num : nums)
            freq.put(num, freq.getOrDefault(num, 0) + 1);

        int ans = 0;

        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            int key = entry.getKey();
            if (freq.containsKey(key + 1)) {
                ans = Math.max(ans, entry.getValue() + freq.get(key + 1));
            }
        }

        return ans;
    }
}