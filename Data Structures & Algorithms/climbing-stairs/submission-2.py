class Solution:
    def climbStairs(self, n: int) -> int:
        dp1, dp2 = 0, 1
        for i in range(0, n):
            temp = dp1
            dp1 = dp2
            dp2 = temp + dp1
        
        return dp2