class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const int MOD = 1e9 + 7;

        sort(packages.begin(), packages.end());

        int n = packages.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + packages[i];

        long long ans = LLONG_MAX;

        for (auto &supplier : boxes) {
            sort(supplier.begin(), supplier.end());

            if (supplier.back() < packages.back())
                continue;

            long long waste = 0;
            int idx = 0;

            for (int b : supplier) {
                int next = upper_bound(packages.begin() + idx, packages.end(), b) - packages.begin();

                long long sum = prefix[next] - prefix[idx];
                waste += 1LL * (next - idx) * b - sum;

                idx = next;
                if (idx == n) break;
            }

            ans = min(ans, waste);
        }

        return ans == LLONG_MAX ? -1 : ans % MOD;
    }
};