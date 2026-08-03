class Solution {
    public int[] searchRange(int[] arr, int target) {
        int[] ans = {-1, -1};
        int n = arr.length;

        // Lower Bound
        int lo = 0, hi = n - 1;
        int lb = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] >= target) {
                lb = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // Target not present
        if (lb == n || arr[lb] != target)
            return ans;

        // Upper Bound
        lo = 0;
        hi = n - 1;
        int ub = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (arr[mid] > target) {
                ub = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ans[0] = lb;
        ans[1] = ub - 1;

        return ans;
    }
}