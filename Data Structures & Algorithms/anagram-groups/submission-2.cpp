class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<int>> mp;

        int count = 0;

        for (int i = 0; i < strs.size(); i++) {
            string t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(i);
        }

        count = 0;
        vector<vector<string>> ans;
        for (auto m : mp) {
            vector<string> temp;
            for (int m2 : m.second) {
                temp.push_back(strs[m2]);
            }
            ans.push_back(temp); 
        }
        return ans;
    }
};
