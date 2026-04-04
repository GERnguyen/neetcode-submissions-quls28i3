class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        res = 0
        n = len(heights)

        for i in range(n):
            left = i
            while left >= 0 and heights[left] >= heights[i]:
                left-=1
            right = i
            while right < n and heights[right] >= heights[i]:
                right+=1
            
            left+=1
            right-=1
            area = (right - left + 1) * heights[i]
            res = max(area, res)
        
        return res
            