class Solution {
//group same elements in a sub array
//sort them by size of the sub array
//return the k most
private:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        for (int num : nums) mp[num]++;

        vector<pair<int,int>> vt(mp.begin(), mp.end());

        sort(vt.begin(), vt.end(), comp); 

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(vt[i].first);
        }

        return ans;

    }
};
