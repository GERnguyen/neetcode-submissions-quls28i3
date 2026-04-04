class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        map <int, int> mp;

        for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j <nums.size(); j++) {
                int tmp = -(nums[i] + nums[j]);
                if (mp[tmp] && mp[tmp] != i && mp[tmp] != j) {
                    vector<int> tmp2 = {nums[i], nums[j], tmp};
                    sort(tmp2.begin(), tmp2.end());
                    if (find(ans.begin(), ans.end(), tmp2) == ans.end())
                        ans.push_back(tmp2);
                }
            }
        }
        return ans;
    }
};
