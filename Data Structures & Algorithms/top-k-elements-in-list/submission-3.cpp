class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;

        vector<vector<int>> vt(nums.size() + 1);

        for (int num : nums) {
            mp[num]++;
        }

        for (auto i : mp) {
            vt[i.second].push_back(i.first);
        }

        vector<int> ans;
        for (int i = vt.size() - 1; i >= 0; i--) {
            if (vt[i].size() < 1) continue;
            for (auto s : vt[i]) {
                ans.push_back(s);
            }
            if (ans.size() == k) break;
        }

        return ans;

    }
};
