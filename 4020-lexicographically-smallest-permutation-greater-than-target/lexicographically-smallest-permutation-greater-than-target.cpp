class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";
        string answer = "";

        for (int i = 0; i < s.size(); i++) {

            int x = target[i] - 'a';

            // Try to make the string greater at this position
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string candidate = prefix;
                    candidate += char('a' + c);

                    // Copy frequency so original is not changed
                    vector<int> temp = freq;
                    temp[c]--;

                    // Add remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (temp[j] > 0) {
                            candidate += char('a' + j);
                            temp[j]--;
                        }
                    }

                    answer = candidate;
                    break;
                }
            }

            // To continue matching target,
            // target[i] must be available.
            if (freq[x] == 0) {
                break;
            }

            prefix += target[i];
            freq[x]--;
        }

        return answer;
    }
};