class Solution {
    public int totalNumbers(int[] digits) {
        int count = 0;

        for (int num = 100; num <= 998; num += 2) {

            int a = num / 100;          // hundreds digit
            int b = (num / 10) % 10;   // tens digit
            int c = num % 10;           // units digit

            int[] freq = new int[10];

            // Count available digits
            for (int d : digits) {
                freq[d]++;
            }

            // Check whether a, b, c are available
            if (freq[a] > 0) {
                freq[a]--;
            } else {
                continue;
            }

            if (freq[b] > 0) {
                freq[b]--;
            } else {
                continue;
            }

            if (freq[c] > 0) {
                count++;
            }
        }

        return count;
    }
}