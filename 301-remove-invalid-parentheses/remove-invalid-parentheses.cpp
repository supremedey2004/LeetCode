class Solution {
public:

    unordered_set<string> ans;

    bool isValid(string s) {

        int balance = 0;

        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else if (ch == ')') {

                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void solve(string s, int start, int removeCount) {

        // If we have removed required number
        if (removeCount == 0) {

            if (isValid(s)) {
                ans.insert(s);
            }

            return;
        }

        for (int i = start; i < s.length(); i++) {

            // Skip duplicate parentheses
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove current character
            string next = s.substr(0, i) + s.substr(i + 1);

            solve(next, i, removeCount - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum number of removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        int totalRemove = leftRemove + rightRemove;

        solve(s, 0, totalRemove);

        return vector<string>(ans.begin(), ans.end());
    }
};