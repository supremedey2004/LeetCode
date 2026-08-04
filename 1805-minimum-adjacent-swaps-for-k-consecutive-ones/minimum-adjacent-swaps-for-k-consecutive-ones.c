#include <stdlib.h>
#include <limits.h>

long long min(long long a, long long b) {
    return a < b ? a : b;
}

int minMoves(int* nums, int numsSize, int k) {
    int count = 0;

    // Count number of 1's
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1)
            count++;
    }

    long long *pos = (long long *)malloc(count * sizeof(long long));
    int idx = 0;

    // Store positions of 1's
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1)
            pos[idx++] = i;
    }

    // Adjust positions
    long long *adjusted = (long long *)malloc(count * sizeof(long long));
    for (int i = 0; i < count; i++) {
        adjusted[i] = pos[i] - i;
    }

    // Prefix sums
    long long *prefix = (long long *)calloc(count + 1, sizeof(long long));
    for (int i = 0; i < count; i++) {
        prefix[i + 1] = prefix[i] + adjusted[i];
    }

    long long ans = LLONG_MAX;

    // Sliding window of k ones
    for (int l = 0; l + k - 1 < count; l++) {
        int r = l + k - 1;
        int mid = (l + r) / 2;

        long long median = adjusted[mid];

        long long left = median * (mid - l) - (prefix[mid] - prefix[l]);
        long long right = (prefix[r + 1] - prefix[mid + 1]) - median * (r - mid);

        ans = min(ans, left + right);
    }

    free(pos);
    free(adjusted);
    free(prefix);

    return (int)ans;
}