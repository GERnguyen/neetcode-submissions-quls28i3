from statistics import median
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n = len(nums1)
        m = len(nums2)

        if m == 0:
            return median(nums1)
        if n == 0:
            return median(nums2)

        for num in nums1:
            left, right = 0, m - 1
            while left <= right:
                mid = (left + right) // 2
                if num < nums2[mid]:
                    if mid == 0:
                        nums2.insert(0, num)
                        break
                    if num > nums2[mid - 1]:
                        nums2.insert(mid, num)
                        break
                    right = mid - 1
                elif num > nums2[mid]:
                    if mid == m - 1:
                        nums2.append(num)
                        break
                    if num < nums2[mid + 1]:
                        nums2.insert(mid + 1, num)
                        break
                    left = mid + 1
                else:
                    nums2.insert(mid, num)
                    break

        return median(nums2)


