class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)

        k, ans = 0, 0
        
        while left <= right:
            hour = 0
            k = (left + right) // 2
            for i in range(len(piles)):
                take = math.ceil(piles[i] / k)
                hour += take
                if hour > h:
                    left = k + 1
                    break
                if i == len(piles) - 1:
                    right = k - 1
                    ans = k

        return ans