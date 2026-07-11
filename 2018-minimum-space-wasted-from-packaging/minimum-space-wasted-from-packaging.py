from bisect import bisect_right

class Solution:
    def minWastedSpace(self, packages, boxes):
        MOD = 10 ** 9 + 7

        packages.sort()

        n = len(packages)

        prefix = [0]
        for p in packages:
            prefix.append(prefix[-1] + p)

        ans = float('inf')

        for supplier in boxes:
            supplier.sort()

            if supplier[-1] < packages[-1]:
                continue

            waste = 0
            idx = 0

            for b in supplier:
                nxt = bisect_right(packages, b, idx)

                waste += (nxt - idx) * b - (prefix[nxt] - prefix[idx])

                idx = nxt
                if idx == n:
                    break

            ans = min(ans, waste)

        return -1 if ans == float('inf') else ans % MOD