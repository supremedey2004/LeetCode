class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_set<int> st;

        // Store all elements in set
        for (int num : nums) {
            st.insert(num);
        }

        // Check multiples of k
        int multiple = k;

        while (st.find(multiple) != st.end()) {
            multiple += k;
        }

        return multiple;
    }
};