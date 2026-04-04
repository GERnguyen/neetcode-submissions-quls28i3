class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1]:
            return nums[0]

        left, right = 0, len(nums) - 1

        while left <= right:
            middle = (left + right) // 2
            if nums[middle] < nums[middle - 1]:
                return nums[middle]
            elif nums[middle] > nums[right]:
                left = middle + 1
            else:
                right = middle - 1
            
        return nums[0]