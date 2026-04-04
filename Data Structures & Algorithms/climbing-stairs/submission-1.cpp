class Solution {
public:
    int climbStairs(int n) {
        int dp1 = 1, dp2 = 2;
        if (n == 1) return 1;
        if (n == 2) return 2;
        for (int i = 3; i < n; i++) {
            int temp = dp1;
            dp1 = dp2;
            dp2 = temp + dp2;
        }
        return dp1 + dp2;
    }
};
