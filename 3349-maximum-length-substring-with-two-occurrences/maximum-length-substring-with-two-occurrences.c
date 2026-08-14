int maximumLengthSubstring(char* s) {
    int freq[26] = {0};

    int left = 0;
    int right = 0;
    int ans = 0;

    while (s[right] != '\0') {

        freq[s[right] - 'a']++;

        while (freq[s[right] - 'a'] > 2) {
            freq[s[left] - 'a']--;
            left++;
        }

        int length = right - left + 1;

        if (length > ans) {
            ans = length;
        }

        right++;
    }

    return ans;
}