class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;

        for (int i = 0; i < heights.size(); i++) {
            int left = i;
            while (left >= 0 && heights[left] >= heights[i]) {
                left--;
            }
            int right = i;
            while (right < heights.size() && heights[right] >= heights[i]) {
                right++;
            }

            left++;
            right--;
            int area = (right - left + 1) * heights[i];
            res = max(res, area);
        }
        return res;
    }
};
