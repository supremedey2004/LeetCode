import java.util.*;

class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int n = s.length();

        // First and last occurrence of each character
        int[] first = new int[26];
        int[] last = new int[26];

        Arrays.fill(first, n);
        Arrays.fill(last, -1);

        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'a';
            first[c] = Math.min(first[c], i);
            last[c] = i;
        }

        List<int[]> intervals = new ArrayList<>();

        // Try to create a valid substring starting from
        // the first occurrence of every character
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1) continue;

            int l = first[c];
            int r = last[c];
            boolean valid = true;

            for (int i = l; i <= r; i++) {
                int x = s.charAt(i) - 'a';

                // This character appeared before l,
                // so substring cannot contain all its occurrences
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences of this character
                r = Math.max(r, last[x]);
            }

            if (valid) {
                intervals.add(new int[]{l, r});
            }
        }

        // Sort by ending position
        intervals.sort((a, b) -> a[1] - b[1]);

        List<String> ans = new ArrayList<>();
        int prevEnd = -1;

        // Greedily select intervals with earliest ending position
        for (int[] interval : intervals) {
            int l = interval[0];
            int r = interval[1];

            if (l > prevEnd) {
                ans.add(s.substring(l, r + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
}