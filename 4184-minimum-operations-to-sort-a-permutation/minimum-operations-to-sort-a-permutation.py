class Solution:
    def minOperations(self, nums: list[int]) -> int:
        n = len(nums)
        pos = nums.index(0)

        ans = float('inf')

        # Case 1: Rotate left until sorted
        if all(nums[(i + pos) % n] == i for i in range(n)):
            ans = min(ans, min(pos, n - pos + 2))

        # Case 2: Rotate left, then reverse
        k = (pos + 1) % n

        if all(nums[(k - 1 - i) % n] == i for i in range(n)):
            ans = min(ans, min(k + 1, n - k + 1))

        return ans if ans != float('inf') else -1