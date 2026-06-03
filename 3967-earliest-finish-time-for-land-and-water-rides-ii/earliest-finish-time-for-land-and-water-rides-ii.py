from typing import List
from bisect import bisect_right

class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int]
    ) -> int:

        def solve(firstStart, firstDuration, secondStart, secondDuration):
            second = sorted(zip(secondStart, secondDuration))

            starts = [s for s, d in second]
            n = len(second)

            # prefixMinDur[i] = minimum duration among second rides from 0 to i
            prefixMinDur = [0] * n
            prefixMinDur[0] = second[0][1]

            for i in range(1, n):
                prefixMinDur[i] = min(prefixMinDur[i - 1], second[i][1])

            # suffixMinFinish[i] = minimum start + duration from i to n-1
            suffixMinFinish = [0] * n
            suffixMinFinish[n - 1] = second[n - 1][0] + second[n - 1][1]

            for i in range(n - 2, -1, -1):
                suffixMinFinish[i] = min(
                    suffixMinFinish[i + 1],
                    second[i][0] + second[i][1]
                )

            ans = float("inf")

            for s, d in zip(firstStart, firstDuration):
                finishFirst = s + d

                idx = bisect_right(starts, finishFirst) - 1

                # Case 1: second ride already opened
                if idx >= 0:
                    ans = min(ans, finishFirst + prefixMinDur[idx])

                # Case 2: second ride opens after first ride finishes
                if idx + 1 < n:
                    ans = min(ans, suffixMinFinish[idx + 1])

            return ans

        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        )