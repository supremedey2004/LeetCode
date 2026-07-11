class Solution {
  int minWastedSpace(List<int> packages, List<List<int>> boxes) {
    const int mod = 1000000007;

    packages.sort();

    int n = packages.length;

    List<int> prefix = List.filled(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + packages[i];
    }

    int ans = 1 << 62;

    for (var supplier in boxes) {
      supplier.sort();

      if (supplier.last < packages.last) continue;

      int waste = 0;
      int idx = 0;

      for (int b in supplier) {
        int next = upperBound(packages, idx, b);

        waste += (next - idx) * b - (prefix[next] - prefix[idx]);

        idx = next;
        if (idx == n) break;
      }

      if (waste < ans) ans = waste;
    }

    return ans == (1 << 62) ? -1 : ans % mod;
  }

  int upperBound(List<int> arr, int start, int target) {
    int l = start;
    int r = arr.length;

    while (l < r) {
      int mid = (l + r) >> 1;
      if (arr[mid] <= target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return l;
  }
}