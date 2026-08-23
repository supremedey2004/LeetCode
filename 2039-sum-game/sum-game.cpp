class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int qL = 0, qR = 0;

        // Left half
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                qL++;
            else
                diff += num[i] - '0';
        }

        // Right half
        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                qR++;
            else
                diff -= num[i] - '0';
        }

        // Odd number of '?' => Alice makes the last move
        if ((qL + qR) % 2 == 1)
            return true;

        // Bob can force equality only in this exact case.
        return 2 * diff != 9 * (qR - qL);
    }
};