class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        int productR[nums.size()];

        //calculate the left side product of the i-th element
        int p = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            productR[i] = p;
            p *= nums[i];
        }

        p = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(p * productR[i]);
            p *= nums[i];
        }

        return ans;
    }
};
