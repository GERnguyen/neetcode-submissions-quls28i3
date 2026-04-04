class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minl = prices[0], ans = 0;

        for (int i = 0; i < prices.size(); i++) {
            minl = min(prices[i], minl);
            ans = max(ans, prices[i] - minl);
        }
        return ans;
    }
};
