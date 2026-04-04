class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map <int, int> mp;

        for (auto num : nums) {
            if (mp[num] == 1) return true;
            mp[num] = 1;
        }

        return false;
    }
};
