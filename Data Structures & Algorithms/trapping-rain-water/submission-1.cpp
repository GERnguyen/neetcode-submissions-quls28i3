class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int sum = 0;
        int maxL = 0, maxR = 0;

        while (left <= right) {
            if (maxL <= maxR) {
                if (height[left] >= maxL) maxL = height[left];
                else sum+= maxL - height[left];
                left++;
            }
            else {
                if (height[right] >= maxR) maxR = height[right];
                else sum+= maxR - height[right];
                right--;
            }
        }
        return sum;
    }
};
