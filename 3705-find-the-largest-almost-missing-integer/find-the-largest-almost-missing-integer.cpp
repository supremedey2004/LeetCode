#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        // Check every subarray of size k
        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_set<int> st;

            // Store unique elements of current subarray
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count this subarray for each unique element
            for (int x : st) {
                mp[x]++;
            }
        }

        int ans = -1;

        // Find largest element appearing in exactly one subarray
        for (auto& [x, count] : mp) {
            if (count == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};