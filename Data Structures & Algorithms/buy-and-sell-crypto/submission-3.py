class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min = prices[0]
        ans = 0

        for i in range(len(prices)):
            if prices[i] < min: min = prices[i]
            if (prices[i] - min) > ans: ans = prices[i] - min
        
        return ans
