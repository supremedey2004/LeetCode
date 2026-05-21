class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        current_sum = nums[0]
        max_sum = nums[0]

        for i in range(1, len(nums)):

            # Either start new subarray or extend current
            current_sum = max(nums[i], current_sum + nums[i])

            # Update maximum sum
            max_sum = max(max_sum, current_sum)

        return max_sum