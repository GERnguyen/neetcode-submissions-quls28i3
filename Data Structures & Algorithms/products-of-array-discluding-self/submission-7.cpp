class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> prefix;
            vector<int> postfix;
            int pre = 1;
            for (int num : nums) {
                prefix.push_back(pre);
                pre *= num;
            }
            int post = 1;
            for (int i = nums.size()-1; i >= 0; i--) {
                postfix.push_back(post);
                post *= nums[i];
            }
            vector<int> ans;
            for (int i = 0; i < nums.size(); i++) {
                ans.push_back(prefix[i]*postfix[nums.size()-i-1]);
            }
            return ans;
    }
};
