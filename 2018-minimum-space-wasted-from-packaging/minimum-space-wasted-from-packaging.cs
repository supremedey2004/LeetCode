public class Solution {
    public int MinWastedSpace(int[] packages, int[][] boxes) {
        const int MOD = 1000000007;

        Array.Sort(packages);

        int n = packages.Length;

        long[] prefix = new long[n + 1];

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + packages[i];

        long ans = long.MaxValue;

        foreach (var supplier in boxes) {
            Array.Sort(supplier);

            if (supplier[supplier.Length - 1] < packages[n - 1])
                continue;

            long waste = 0;
            int idx = 0;

            foreach (int b in supplier) {
                int next = UpperBound(packages, idx, b);

                waste += (long)(next - idx) * b - (prefix[next] - prefix[idx]);

                idx = next;
                if (idx == n) break;
            }

            ans = Math.Min(ans, waste);
        }

        return ans == long.MaxValue ? -1 : (int)(ans % MOD);
    }

    private int UpperBound(int[] arr, int start, int target) {
        int l = start, r = arr.Length;

        while (l < r) {
            int mid = (l + r) / 2;

            if (arr[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
}