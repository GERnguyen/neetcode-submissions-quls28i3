class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;

        int maxR[height.size()];
        int maxL[height.size()];

        //calculate the max in the left side of ith element
        int Max = 0;
        for (int i = 0; i < height.size(); i++) {
            Max = max(Max, height[i]);
            maxL[i] = Max;
        }

        //calculate the max in the right side of ith element
        Max = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            Max = max(Max, height[i]);
            maxR[i] = Max;
        }
        
        for (int i = 0; i < height.size(); i++) {
            int temp = min(maxR[i], maxL[i]) - height[i];
            if (temp < 0) temp = 0;
            ans += temp;
        }
        
        return ans;
    }
};
