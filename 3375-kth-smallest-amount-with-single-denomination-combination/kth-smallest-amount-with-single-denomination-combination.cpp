#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    // Count how many distinct amounts are <= x
    long long countAmounts(long long x, vector<int>& coins) {
        int n = coins.size();
        long long total = 0;

        // Try every subset of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long currentLCM = 1;
            int bits = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    bits++;

                    currentLCM = lcm(currentLCM, coins[i]);

                    if (currentLCM > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long long cnt = x / currentLCM;

            // Odd number of elements -> add
            if (bits % 2 == 1)
                total += cnt;
            // Even number of elements -> subtract
            else
                total -= cnt;
        }

        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        int minCoin = *min_element(coins.begin(), coins.end());

        long long high = 1LL * minCoin * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k) {
                high = mid;
            } 
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};