class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;

        // First two elements
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Distribute remaining elements
        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Concatenate arr1 and arr2
        vector<int> result = arr1;

        for (int x : arr2) {
            result.push_back(x);
        }

        return result;
    }
};