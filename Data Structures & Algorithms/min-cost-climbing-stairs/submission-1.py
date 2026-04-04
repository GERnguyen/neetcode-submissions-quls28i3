class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp1, dp2 = 0 , cost[0]

        for i in range(1 , len(cost)):
            temp = dp1
            dp1 = dp2
            dp2 = cost[i] + min(temp, dp1)

        return min(dp1,dp2)