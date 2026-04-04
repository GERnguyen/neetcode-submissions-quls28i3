class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            index = (right + left) // 2
            if nums[index] == target:
                return index
            elif nums[index] < target:
                left = index + 1
            else:
                right = index - 1
        
        return -1
