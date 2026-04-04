class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int mi = min(heights[left], heights[right]);
            int cur = (right - left) * mi;

            if (cur > max) max = cur;

            if (heights[left] < heights[right]) left++;
            else right--; 
        }
        return max;
    }
};
