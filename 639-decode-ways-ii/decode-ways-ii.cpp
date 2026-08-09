class Solution {
public:
    static const long long MOD = 1000000007;

    int numDecodings(string s) {
        int n = s.size();

        long long prev2 = 1;
        long long prev1 = ways1(s[0]);

        for (int i = 1; i < n; i++) {
            long long curr = 0;

            // Decode s[i] as a single digit
            curr += prev1 * ways1(s[i]);
            curr %= MOD;

            // Decode s[i-1] and s[i] together
            curr += prev2 * ways2(s[i - 1], s[i]);
            curr %= MOD;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

private:
    // Number of ways to decode one character
    long long ways1(char c) {
        if (c == '*')
            return 9;

        if (c == '0')
            return 0;

        return 1;
    }

    // Number of ways to decode two characters
    long long ways2(char a, char b) {

        if (a == '*' && b == '*') {
            // 11-19 and 21-26
            return 15;
        }

        if (a == '*') {
            // * followed by 0-6 -> 20 possibilities
            // * followed by 7-9 -> 10 possibilities
            if (b >= '0' && b <= '6')
                return 2;
            return 1;
        }

        if (b == '*') {
            // 1* -> 11-19 (9 ways)
            if (a == '1')
                return 9;

            // 2* -> 21-26 (6 ways)
            if (a == '2')
                return 6;

            return 0;
        }

        // Both are normal digits
        int num = (a - '0') * 10 + (b - '0');

        if (num >= 10 && num <= 26)
            return 1;

        return 0;
    }
};