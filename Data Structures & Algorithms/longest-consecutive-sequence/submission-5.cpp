class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        if (nums.empty()) return 0;

        for (int num : nums) {
            mp[num] = 1;
        }

        cout<<mp[0]<<" "<<mp[-1];

        int ans = 0;
        int cur = 1;
        for (int num : nums) {
            while (mp[++num]) {
                cur++;
            }
            if (cur > ans) ans = cur;
            cur = 1;
        }
        return ans;
    }
};
