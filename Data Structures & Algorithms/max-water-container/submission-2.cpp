class Solution {
public:
    int maxArea(vector<int>& heights) {
        int Max = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int mi = min(heights[left], heights[right]);
            int cur = (right - left) * mi;

            Max = max(Max, cur);

            if (heights[left] < heights[right]) left++;
            else right--; 
        }
        return Max;
    }
};
