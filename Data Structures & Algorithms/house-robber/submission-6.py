class Solution:
    def rob(self, nums: List[int]) -> int:
        dp1 = [0] * (len(nums))

        dp1[0] = nums[0]

        if len(nums) >= 2:
            dp1[1] = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1])

        return dp1[-1]