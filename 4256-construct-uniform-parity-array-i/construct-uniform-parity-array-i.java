class Solution {
    public boolean uniformArray(int[] nums1) {
        
        int oddCount = 0;

        for (int num : nums1) {
            if (num % 2 != 0) {
                oddCount++;
            }
        }

        // Always possible:
        // If all are even -> keep them as they are.
        // If there is at least one odd -> construct all odd.
        return true;
    }
}