class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);

        vector<char> odd, even;

        // Separate odd and even digits
        for (char c : s) {
            if ((c - '0') % 2 == 0)
                even.push_back(c);
            else
                odd.push_back(c);
        }

        // Sort in descending order
        sort(odd.begin(), odd.end(), greater<char>());
        sort(even.begin(), even.end(), greater<char>());

        int i = 0, j = 0;

        // Rebuild the number
        for (char &c : s) {
            if ((c - '0') % 2 == 0)
                c = even[j++];
            else
                c = odd[i++];
        }

        return stoi(s);
    }
};