class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minl = prices[0], ans = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= minl) minl = prices[i];
            if (prices[i] - minl >= ans) ans = prices[i] - minl;
        }
        return ans;
    }
};
