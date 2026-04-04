class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        pivot = 0
        while left <= right:
            middle = (left + right) // 2
            if nums[middle] < nums[middle - 1]:
                pivot = middle
                break
            elif nums[middle] > nums[right]:
                left = middle + 1
            else:
                right = middle - 1

        print(pivot)

        def binary(left : int, right : int) -> int:
            while left <= right:
                mid = (left + right) // 2
                if target < nums[mid]:
                    right = mid - 1
                elif target > nums[mid]:
                    left = mid + 1
                else: 
                    return mid
            return -1
        
        if nums[pivot] <= target <= nums[len(nums) - 1]:
            return binary(pivot, len(nums) - 1)
        elif nums[len(nums) - 1] < target <= nums[pivot - 1]:
            return binary(0, pivot - 1)
        else:
            return -1



        