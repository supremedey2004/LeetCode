class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key-value pairs
        for (auto &pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                int j = i + 1;

                // Find closing bracket
                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Check key in map
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }

                // Move i to closing bracket
                i = j;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};