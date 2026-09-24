class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<long long, int> mp;
        int n = (int)nums.size();
        for (int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        vector<int> res;
        for (auto it : mp) {
            if (it.second > n/3) res.push_back(it.first);
        }
        return res;
    }
};