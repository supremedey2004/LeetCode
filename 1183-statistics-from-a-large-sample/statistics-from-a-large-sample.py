from typing import List

class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        minimum = -1
        maximum = -1
        total = 0
        summ = 0
        mode = 0
        modeFreq = 0

        # Find min, max, sum, total count, and mode
        for i in range(256):
            if count[i]:
                if minimum == -1:
                    minimum = i
                maximum = i
                total += count[i]
                summ += i * count[i]
                if count[i] > modeFreq:
                    modeFreq = count[i]
                    mode = i

        mean = summ / total

        # Median positions (0-based)
        if total % 2 == 1:
            left = right = total // 2
        else:
            left = total // 2 - 1
            right = total // 2

        median1 = median2 = -1
        curr = 0

        for i in range(256):
            curr += count[i]
            if median1 == -1 and curr > left:
                median1 = i
            if median2 == -1 and curr > right:
                median2 = i
                break

        median = (median1 + median2) / 2.0

        return [
            float(minimum),
            float(maximum),
            mean,
            median,
            float(mode)
        ]