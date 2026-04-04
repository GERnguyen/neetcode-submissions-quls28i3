class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        int productR[nums.size()];
        int productL[nums.size()];

        //calculate the left side product of the i-th element
        int p = 1;
        for (int i = 0; i < nums.size(); i++) {
            productL[i] = p;
            p *= nums[i];
        }

        //calculate the right side product of the i-th element
        p = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            productR[i] = p;
            p *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(productR[i] * productL[i]);
        }

        return ans;
    }
};
