class Solution {
//group same elements in a sub array
//sort them by size of the sub array
//return the k most
private:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second >= b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;

        vector<pair<int,int>> vt;

        vt.push_back({nums[0], 1});
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                vt[count].second++;
            }
            else {
                vt.push_back({nums[i], 1});
                count++;
            }
        }
        sort(vt.begin(), vt.end(), comp); 

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(vt[i].first);
        }

        return ans;

    }
};
