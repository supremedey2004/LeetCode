class Solution:
    def longestSubsequence(self, nums):
        xr = 0
        has_nonzero = False

        for x in nums:
            xr ^= x
            if x != 0:
                has_nonzero = True

        # Entire array has non-zero XOR
        if xr != 0:
            return len(nums)

        # XOR is zero, but there is a non-zero element
        if has_nonzero:
            return len(nums) - 1

        # All elements are zero
        return 0