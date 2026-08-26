class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            if (ones == k) {

                // Remove leading zeros to make the window shortest
                while (s[left] == '0')
                    left++;

                string curr = s.substr(left, right - left + 1);

                // Update answer
                if (ans == "" ||
                    curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }

                // Move past the first 1
                if (s[left] == '1') {
                    ones--;
                    left++;
                }
            }
        }

        return ans;
    }
};