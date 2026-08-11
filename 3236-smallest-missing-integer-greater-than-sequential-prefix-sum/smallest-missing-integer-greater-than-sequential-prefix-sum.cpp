class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Find the sum of the longest sequential prefix
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Find the smallest missing integer >= sum
        int x = sum;

        while (true) {
            bool found = false;

            for (int num : nums) {
                if (num == x) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return x;

            x++;
        }
    }
};